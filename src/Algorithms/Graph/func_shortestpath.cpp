//
// C++ Implementation: func_shortestpath
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <limits.h>
#include <iostream>
using namespace std;

#include "dijkstra.h"
#include "func_shortestpath.h"
#include "inrimage.hpp"
#include "amilab_messages.h"

#ifdef WIN32
#include <limits>
#endif

#ifdef max
#undef max
#endif

SurfacePoly* Func_shortestpath( SurfacePoly* lines, 
                                float pt1_x, float pt1_y, float pt1_z,
                                float pt2_x, float pt2_y, float pt2_z)
{

  int last_point;
  int current_point,previous_point;
  Point3DPoly pt;
  Point3DPoly p0,p1;
  float dist1_min=0;
  float dist2_min=0;
  float dist;

  // found the closest points close to pt1 and pt2
  int selected_line1  = -1;
  int selected_point1 = -1;
  int selected_line2  = -1;
  int selected_point2 = -1;
  int p,l,n;

  if (lines->GetNumberOfLines()>0) {

    Pour(l,0,lines->GetNumberOfLines()-1)
      Pour(p,0,lines->GetLine(l).NbElts()-1)
        pt   = (*lines)[lines->GetLine(l)[p]];

        // check for first point
        dist = sqrt((pt.X()-pt1_x)*(pt.X()-pt1_x)+
                    (pt.Y()-pt1_y)*(pt.Y()-pt1_y)+
                    (pt.Z()-pt1_z)*(pt.Z()-pt1_z));
        Si selected_line1 == -1 Ou dist<dist1_min Alors
          dist1_min = dist;
          selected_line1 = l;
          selected_point1 = lines->GetLine(l)[p];
        FinSi

        // check for second point
        dist = sqrt((pt.X()-pt2_x)*(pt.X()-pt2_x)+
                    (pt.Y()-pt2_y)*(pt.Y()-pt2_y)+
                    (pt.Z()-pt2_z)*(pt.Z()-pt2_z));
        Si selected_line2 == -1 Ou dist<dist2_min Alors
          dist2_min = dist;
          selected_line2 = l;
          selected_point2 = lines->GetLine(l)[p];
        FinSi

      FinPour
    FinPour

  } else {
    FILE_ERROR("Input does not contain lines.");
    return NULL;
  }

  // Get the last selected point
  last_point = selected_point2;
  int num_lines = lines->GetNumberOfLines();

  // Create the graph
  Edge_vec    edges  (num_lines);
  weight_vec  weights(num_lines);

  // Iterate through the lines and create edges and weights
  for (l= 0; l< num_lines; l++ ) {
    T_Line& line = lines->GetLine(l);

    if (line.NbElts()>=2) {

      edges.push_back(Edge(line[0],line[line.NbElts()-1]));
      //cout << "Adding Edge " << line[0] << " " << line.NbElts()-1 << endl;

      double length=0;
      Point_3D<float> p0,p1;
      for(int i=1;i<line.NbElts();i++) {
        p0=lines->GetPoint(line[i-1]).pt;
        p1=lines->GetPoint(line[i]).pt;
        length += Norme(p0-p1);
      }
      weights.push_back((weight_type)length);
    }
  }

  if ((selected_line1==-1)||(selected_line2==-1)) {
    FILE_ERROR("Selected lines not found, aborting.");
    return NULL;
  }  else {
    cout << "initial line = " << selected_line1 << endl;
    cout << "final   line = " << selected_line2 << endl;
  }

  // Create the graph
  graph_ptr graph = CreateUndirectedGraph(
      lines->GetNumberOfPoints(),
      edges,
      weights);

  // run Dijkstra
  PathInfo path;
  ShortestPath(*graph,lines->GetLine(selected_line1)[0],path);

  // Create back the path from the seleted line to the last point
  // and select it
  T_Line line = lines->GetLine(selected_line2);
  float d1 = path.distance[line[0]];
  float d2 = path.distance[line[line.NbElts()-1]];

  if (d1>d2) 
    current_point = line[0];
  else
    current_point = line[line.NbElts()-1];

  // find the line of the current point
  if (path.distance[current_point]==
	  numeric_limits<weight_type>::max())
  {
    FILE_ERROR("No path between points.");
    return NULL;
  }

  int total_points=0;
  SurfacePoly* res = new SurfacePoly();
  res->NewLine();

  bool line1_included = false;
  cout << "Selecting the path " << endl;
  while (current_point!=lines->GetLine(selected_line1)[0]) {
    previous_point = path.previous[current_point];

    // not too efficient but accept it for now
    // look for the line number with extremities current and previous points
    for (p= 0; p< num_lines; p++ ) {
      T_Line& line = lines->GetLine(p);
      if (line.NbElts()>1) {
        if  ((line[0]==previous_point)&&
          (line[line.NbElts()-1]==current_point))
          break;
        if  ((line[0]==current_point)&&
          (line[line.NbElts()-1]==previous_point))
          break;
      }
    }
    if (p==num_lines) {
      cerr << "Not able to follow path: should not happen! " << endl;
      return NULL;
    }

    // Add line number p, in the right order
    if (p==selected_line1) line1_included=true;
    T_Line& line = lines->GetLine(p);
    if (line.NbElts()>1) {
      if (line[0]==current_point) 
        Pour(n,0,line.NbElts()-2)
          pt   = (*lines)[line[n]];
          res->AddPoint(pt.X(),pt.Y(),pt.Z());
          res->LineAddPointNumber(total_points);
          total_points++;
        FinPour
      else
        Pour(n,0,line.NbElts()-2)
          pt   = (*lines)[line[line.NbElts()-1-n]];
          res->AddPoint(pt.X(),pt.Y(),pt.Z());
          res->LineAddPointNumber(total_points);
          total_points++;
        FinPour
    }

    current_point = previous_point;
  } // end while

  pt = (*lines)[lines->GetLine(selected_line1)[0]];
  res->AddPoint(pt.X(),pt.Y(),pt.Z());
  res->LineAddPointNumber(total_points);

  // adding the starting line if needed
  if (!line1_included) {
    T_Line& line = lines->GetLine(selected_line1);
    Pour(n,1,line.NbElts()-1)
      pt   = (*lines)[line[n]];
      res->AddPoint(pt.X(),pt.Y(),pt.Z());
      res->LineAddPointNumber(total_points);
      total_points++;
    FinPour
  }

  //printf("scanres = %d (%f %f %f %f %f) \n",scanres,x,y,z,r,sd);
  res->EndLine();

  return res;

} // Func_shortestpath()


class voxel_pos {
public:
  int x,y,z;
  voxel_pos(int _x, int _y, int _z) {
    x=_x; y=_y; z=_z;
  }
};

//-----------------------------------------------------------------------------
// looks for shortest path within an image
// where each voxel has a positive value
// voxels of intensity value higher that the threshold are not taken into account
SurfacePoly* Func_shortestpath_image( InrImage* imweights,
                                      double threshold,
                                      float pt1_x, float pt1_y, float pt1_z,
                                      float pt2_x, float pt2_y, float pt2_z)
{

  long current_point,previous_point;
  Point3DPoly pt;
  Point3DPoly p0,p1;

  // create a list of voxels that will be nodes for the graph
  InrImage::ptr     inside_voxels;
  vector<voxel_pos> vox_positions;
  int      num_vertices=0;

/*
  int dx = 1;
  int dy = imweights->DimX();
  int dz = dy*imweights->DimY();
*/

  // found the closest points close to pt1 and pt2
  int start[3];
  start[0] = (int) round(imweights->SpaceToVoxelX(pt1_x));
  start[1] = (int) round(imweights->SpaceToVoxelY(pt1_y));
  start[2] = (int) round(imweights->SpaceToVoxelZ(pt1_z));
  cout  << "start " 
        << start[0] << " "
        << start[1] << " "
        << start[2] << endl;

  int end[3];
  end[0] = (int) round(imweights->SpaceToVoxelX(pt2_x));
  end[1] = (int) round(imweights->SpaceToVoxelY(pt2_y));
  end[2] = (int) round(imweights->SpaceToVoxelZ(pt2_z));
  cout  << "end " 
        << end[0] << " "
        << end[1] << " "
        << end[2] << endl;

  if  (
        (start[0]<0)||(start[0]>imweights->DimX()-2) 
        ||
        (start[1]<0)||(start[1]>imweights->DimY()-2) 
        ||
        (start[2]<0)||(start[2]>imweights->DimZ()-2) 
      )
  {
    cerr << "Func_shortestpath() \t Wrong position for the first point" << endl;
    return NULL;
  }

  if  (
      (end[0]<0)||(end[0]>imweights->DimX()-2) 
      ||
      (end[1]<0)||(end[1]>imweights->DimY()-2) 
      ||
      (end[2]<0)||(end[2]>imweights->DimZ()-2) 
      )
  {
    cerr << "Func_shortestpath() \t Wrong position for the second point" << endl;
    return NULL;
  }
    

  // create image of voxels within graph
  inside_voxels = InrImage::ptr(new InrImage(WT_SIGNED_INT,1,"insidegraph.ami.gz",imweights));
  inside_voxels->InitImage(0);

  // adds an useless vertex to start indices with 1
  vox_positions.push_back(voxel_pos(0,0,0)); 

  imweights->InitBuffer();
  inside_voxels->InitBuffer();
  for(int z=0;z<imweights->DimZ();z++)
  for(int y=0;y<imweights->DimY();y++)
  for(int x=0;x<imweights->DimX();x++) {
    if (imweights->ValeurBuffer()<threshold) {
      if (num_vertices==std::numeric_limits<int>::max()) {
        cerr << "too many points within graph " << endl;
      } else {
        num_vertices++;
        inside_voxels->FixeValeur(num_vertices);
        vox_positions.push_back(voxel_pos(x,y,z));
      }
    }
    imweights     ->IncBuffer();
    inside_voxels ->IncBuffer();
  }


  int startpos = (int) (*inside_voxels)(start[0],start[1],start[2]);
  int endpos   = (int) (*inside_voxels)(end[0],  end[1],  end[2]);
  if ((startpos==0)||(endpos==0)) {
    cerr << "Problem with start or end point " << endl;
    return NULL;
  }

  cout << "Func_shortestpath_image() total vertices " << num_vertices << endl;

  // Get the last selected point
  // Compute the number of edges (lines):
  // for each voxel link it to the 7 neighbors in the positive quadrant
  int edges_per_voxel = 13;
  long num_edges = num_vertices*edges_per_voxel;


  // Create the graph
  Edge_vec    edges  (num_edges);
  weight_vec  weights(num_edges);

  // Iterate through the lines and create edges and weights

  // iterate through vertices
  std::vector<voxel_pos>::iterator Iter;
  for ( Iter  = vox_positions.begin();
        Iter != vox_positions.end()  ;
        Iter++)
  {
    // add corresponding edges
    int x0,y0,z0;
    int x1,y1,z1;
    int x2,y2,z2;
    int v1,v2;
    x0 = Iter->x;
    y0 = Iter->y;
    z0 = Iter->z;
    if (
        !imweights->CoordOK(x0+1,y0+1,z0+1)
        ||
        !imweights->CoordOK(x0-1,y0-1,z0-1)
      ) continue;

    //  (x,y,z) --- (x+1, y,   z  )
    x1 = x0;   y1 = y0; z1 = z0;
    x2 = x0+1; y2 = y0; z2 = z0;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x,   y+1, z  )
    x1 = x0; y1 = y0;   z1 = z0;
    x2 = x0; y2 = y0+1; z2 = z0;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x+1,   y+1, z  )
    x1 = x0;   y1 = y0;   z1 = z0;
    x2 = x0+1; y2 = y0+1; z2 = z0;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y+1,z) --- (x+1,   y, z  )
    x1 = x0;   y1 = y0+1; z1 = z0;
    x2 = x0+1; y2 = y0;   z2 = z0;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x,   y,   z+1)
    x1 = x0; y1 = y0; z1 = z0;
    x2 = x0; y2 = y0; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x+1,   y,   z+1)
    x1 = x0;   y1 = y0; z1 = z0;
    x2 = x0+1; y2 = y0; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x+1,y,z) --- (x,   y,   z+1)
    x1 = x0+1; y1 = y0; z1 = z0;
    x2 = x0;   y2 = y0; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x,   y+1,   z+1)
    x1 = x0; y1 = y0;   z1 = z0;
    x2 = x0; y2 = y0+1; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y+1,z) --- (x,   y,   z+1)
    x1 = x0; y1 = y0+1; z1 = z0;
    x2 = x0; y2 = y0;   z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x+1,   y+1,   z+1)
    x1 = x0;    y1 = y0; z1 = z0;
    x2 = x0+1; y2 = y0+1; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x-1,   y+1,   z+1)
    x1 = x0;    y1 = y0; z1 = z0;
    x2 = x0-1; y2 = y0+1; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x+1,   y-1,   z+1)
    x1 = x0;   y1 = y0; z1 = z0;
    x2 = x0+1; y2 = y0-1; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

    //  (x,y,z) --- (x-1,   y-1,   z+1)
    x1 = x0;   y1 = y0; z1 = z0;
    x2 = x0-1; y2 = y0-1; z2 = z0+1;
    v1 = (int) (*inside_voxels)(x1,y1,z1);
    v2 = (int) (*inside_voxels)(x2,y2,z2);
    if ((v1>0)&&(v2>0)) {
      edges.push_back(Edge(v1,v2));
      double w = (*imweights)(x1,y1,z1)+(*imweights)(x2,y2,z2);
      weights.push_back((weight_type)w);
    }

  }

  cout << "Func_shortestpath_image() edges created " << endl;

  // Create the graph
  graph_ptr graph = CreateUndirectedGraph(
      num_vertices+1,
      edges,
      weights);

  cout << "Func_shortestpath_image() starting shortest path algo "  << endl;

  // run Dijkstra
  PathInfo path;
  ShortestPath(*graph,startpos,path);

  // Create back the path from the seleted line to the last point
  // and select it
  current_point = endpos;

  // find the line of the current point
  if (path.distance[current_point]==
      numeric_limits<weight_type>::max())
  {
    cerr << "SurfacePoly::SelectMinPath() \tNo path between points " << endl;
    return NULL;
  }

  int total_points=0;
  SurfacePoly* res = new SurfacePoly();
  res->NewLine();

  bool line1_included = false;
  cout << "Selecting the path " << endl;
  while (current_point!=startpos) {
    previous_point = path.previous[current_point];

    // Add current point to the line
    int pz = vox_positions[current_point].z;
    int py = vox_positions[current_point].y;
    int px = vox_positions[current_point].x;
    res->AddPoint(imweights->SpacePosX(px),
                  imweights->SpacePosY(py),
                  imweights->SpacePosZ(pz));
    res->LineAddPointNumber(total_points);
    total_points++;
    current_point = previous_point;
  } // end while

  int pz = vox_positions[current_point].z;
  int py = vox_positions[current_point].y;
  int px = vox_positions[current_point].x;
  res->AddPoint(imweights->SpacePosX(px),
                imweights->SpacePosY(py),
                imweights->SpacePosZ(pz));
  res->LineAddPointNumber(total_points);

  res->EndLine();

  cout << "finished !" << endl;
  return res;

} // Func_shortestpath_image()


//-------------------------------------------------------
SurfacePoly* Func_path_from_displ( InrImage* displ,
                                   int startx, int starty, int startz)
{
  int px = startx;
  int py = starty;
  int pz = startz;
  int dx,dy,dz;
  int num_points=0;
  int track,tx,ty,tz;
  bool end_reached=false;

  if (!displ->CoordOK(px,py,pz)) {
    cerr << "Func_path_from_displ() \t initial point not within image domain "
          << endl;
    return NULL;
  }

  SurfacePoly* res = new SurfacePoly();
  res->NewLine();

  tx = displ->DimX();
  ty = displ->DimY();
  tz = displ->DimZ();

  while (!end_reached) {
    track = (int) round((*displ)(px,py,pz));

    dz = (int) floor(track/(1.0*tx*ty));
    dy = (int) floor((track-dz*ty*tx)/(1.0*tx));
    dx = (int) (track-(dz*ty+dy)*tx);
    dx -= px;
    dy -= py;
    dz -= pz;

    cout  << " point " << num_points
          << " track " << track
          << " p:"
          << "  " << px
          << "  " << py
          << "  " << pz
          << " d:  "  << dx
          << "  "     << dy
          << "  "     << dz
          << endl;
    end_reached = ((track==0)||((dx==0)&&(dy==0)&&(dz==0)));
    if (!end_reached) {
      res->AddPoint(displ->SpacePosX(px),
                    displ->SpacePosY(py),
                    displ->SpacePosZ(pz));
      res->LineAddPointNumber(num_points);
      num_points++;
      px += dx;
      py += dy;
      pz += dz;
      end_reached = !displ->CoordOK(px,py,pz);
    }
  } // end while

  res->EndLine();

  return res;
}



//-------------------------------------------------------
// delta is the small increment used to estimate the derivatives
// based on linear interpolation
// only for 3D images
SurfacePoly* Func_path_from_vectfield(  InrImage::ptr displ,
                                        double start[3],
                                        double step_size,
                                        double max_length,
                                        double delta)
{
  double p[3] = {start[0],start[1],start[2]};
  double q[3];
  double vox_p[3];

  double vx,vy,vz,nv;
  double I,Ixp,Ixm,Iyp,Iym,Izp,Izm;
  int num_points=0;
  bool end_reached=false;
  double distance = 0.0, prev_dist = 0.0;
  bool   vectorfield = false;
  double closest_point_intensity;

  vectorfield = ((displ->GetVDim() ==3));

  vox_p[0] = displ->SpaceToVoxelX(p[0]);
  vox_p[1] = displ->SpaceToVoxelY(p[1]);
  vox_p[2] = displ->SpaceToVoxelZ(p[2]);

  if (!displ->CoordOK((int)vox_p[0],
                      (int)vox_p[1],
                      (int)vox_p[2])) {
    cerr  << "Func_path_from_vectfield() \t "
          << "initial point not within image domain "
          << endl;
    return NULL;
  }

  SurfacePoly* res = new SurfacePoly();
  res->NewLine();
  for(int i=0;i<2;i++) q[i] = p[i];

  while (!end_reached) {

    res->AddPoint(p[0],p[1],p[2]);
    res->LineAddPointNumber(num_points);
    num_points++;

    if (vectorfield) {
      vx = displ->InterpLinIntensite(
                  vox_p[0],vox_p[1],vox_p[2],0);
      vy = displ->InterpLinIntensite(
                  vox_p[0],vox_p[1],vox_p[2],1);
      vz = displ->InterpLinIntensite(
                  vox_p[0],vox_p[1],vox_p[2],2);
      nv = sqrt(vx*vx+vy*vy+vz*vz);
    } else {
      double step = delta;
      float vpx = vox_p[0];
      float vpy = vox_p[1];
      float vpz = vox_p[2];
      // Compute downwind gradient to ensure evolution toward lower intensities
      I   = displ->InterpLinIntensite(vpx,vpy,vpz);
      Ixp = displ->InterpLinIntensite(vpx+step,vpy,vpz);
      Ixm = displ->InterpLinIntensite(vpx-step,vpy,vpz);
      Iyp = displ->InterpLinIntensite(vpx,vpy+step,vpz);
      Iym = displ->InterpLinIntensite(vpx,vpy-step,vpz);
      Izp = displ->InterpLinIntensite(vpx,vpy,vpz+step);
      Izm = displ->InterpLinIntensite(vpx,vpy,vpz-step);

      // go in the oposite direction of the gradient and towards lower values
      if ((Ixp<=Ixm)&&(Ixp<I)) 
        vx = (I-Ixp)/(step*displ->VoxSizeX());
      else
      if ((Ixm<Ixp)&&(Ixm<I)) 
        vx = (Ixm-I)/(step*displ->VoxSizeX());
      else
        vx = 0;

      if ((Iyp<=Iym)&&(Iyp<I)) 
        vy = (I-Iyp)/(step*displ->VoxSizeY());
      else
      if ((Iym<Iyp)&&(Iym<I)) 
        vy = (Iym-I)/(step*displ->VoxSizeY());
      else
        vy = 0;

      if ((Izp<=Izm)&&(Izp<I)) 
        vz = (I-Izp)/(step*displ->VoxSizeZ());
      else
      if ((Izm<Izp)&&(Izm<I)) 
        vz = (Izm-I)/(step*displ->VoxSizeZ());
      else
        vz = 0;

      nv = sqrt(vx*vx+vy*vy+vz*vz);
      // if the gradient is strong enough, normalize it
      if (nv>1E-4) {
        vx /= nv;
        vy /= nv;
        vz /= nv;
      } else {
        FILE_ERROR( 
          format(" local maximul found at %1% %2% %3% :") % vpx % vpy % vpz
          << format(" I I{x,y,z}{p,m} = %1% %2% %3% %4% %5% %6% %7%")
          % I % Ixp % Ixm % Iyp % Iym % Izp % Izm
          );
        // look for the minimal over the neighbors
        int xpos = round(vpx);
        int ypos = round(vpy);
        int zpos = round(vpz);
        float valmin = I;
        bool  minfound = false;
        int xmin,ymin,zmin;
        for (int i=-1;i<=1;i++)
        for (int j=-1;j<=1;j++)
        for (int k=-1;k<=1;k++)  {
          if (displ->CoordOK(xpos+i,ypos+j,zpos+k))
            if ((*displ)(xpos+i,ypos+j,zpos+k)<valmin) 
            {
              valmin = (*displ)(xpos+i,ypos+j,zpos+k);
              xmin = xpos+i;
              ymin = ypos+j;
              zmin = zpos+k;
              minfound = true;
            }
        }
        if (minfound) {
          // move toward the neighbor point with lower intensity
          vx = (xmin-vpx)*displ->VoxSizeX();
          vy = (ymin-vpy)*displ->VoxSizeY();
          vz = (zmin-vpz)*displ->VoxSizeZ();
          nv = sqrt(vx*vx+vy*vy+vz*vz);
         FILE_ERROR(  format(" minimum found at  %1% %2% %3% :") % xmin % ymin % zmin
          << format(" new vector %1% %2% %3% norm %4%")
          % vx % vy % vz % nv
          );
        } else  {
          FILE_ERROR(" no minimum found among neighbors !");
        }
        if (nv>1E-4) {
          /*
          vx /= nv;
          vy /= nv;
          vz /= nv;
          */
          // jump to new point !!!
          vx /=step_size;
          vy /=step_size;
          vz /=step_size;
        }
      }
    }

    displ->BufferPos((int)  round(vox_p[0]),
                     (int)  round(vox_p[1]),
                     (int)  round(vox_p[2]));
    closest_point_intensity = displ->ValeurBuffer();

    distance += step_size;

    // debug information
    int xpos = round(vox_p[0]);
    int ypos = round(vox_p[1]);
    int zpos = round(vox_p[2]);
    if ((xpos==74)&(ypos==78)&(zpos==72)) {
      FILE_MESSAGE( format(" point %1% ") % num_points
                    << format(" ( %0.2f, %0.2f %0.2f )") 
                           % p[0] % p[1] % p[2]
                    << format(" ( %0.2f, %0.2f %0.2f )") 
                           % vox_p[0] % vox_p[1] % vox_p[2] 
                    << format(" ( %0.2f, %0.2f %0.2f )") 
                     % vx % vy % vz
                    << format("  nv %0.3f") %  nv 
            << format("  current val %0.4f %0.4f")
              % displ->InterpLinIntensite(vox_p[0],vox_p[1],vox_p[2])
              % closest_point_intensity
            << format("  d= %0.3f mm") %  distance );
    }
    if ((distance>=prev_dist+10)||(distance<2)) {
      prev_dist = distance;
      for(int i=0;i<2;i++) q[i] = p[i];
      FILE_MESSAGE( format(" point %1% ") % num_points
                    << format(" ( %0.2f, %0.2f %0.2f )") 
                           % p[0] % p[1] % p[2]
                    << format(" ( %0.2f, %0.2f %0.2f )") 
                           % vox_p[0] % vox_p[1] % vox_p[2] 
                    << format(" ( %0.2f, %0.2f %0.2f )") 
                     % vx % vy % vz
                    << format("  nv %0.3f") %  nv 
            << format("  current val %0.4f %0.4f")
              % displ->InterpLinIntensite(vox_p[0],vox_p[1],vox_p[2])
              % closest_point_intensity
            << format("  d= %0.3f mm") %  distance );
    }

    p[0] += vx*step_size;
    p[1] += vy*step_size;
    p[2] += vz*step_size;

    vox_p[0] = displ->SpaceToVoxelX(p[0]);
    vox_p[1] = displ->SpaceToVoxelY(p[1]);
    vox_p[2] = displ->SpaceToVoxelZ(p[2]);

    end_reached = !displ->CoordOK(  (int)vox_p[0],
                                    (int)vox_p[1],
                                    (int)vox_p[2])
                    || (nv<1E-5)
                    || (distance>max_length)
                    || (closest_point_intensity<0)
                    ;
    // small fix for stopping vessel in CTA challenge, need to be done more properly ...
    end_reached = end_reached 
                  || (vox_p[0]<0) 
                  || (vox_p[1]<0) 
                  || (vox_p[2]<0);

  } // end while

  res->EndLine();

  // cannot check for end point here
  cout  << " Finished point " << num_points 
        << format(" ( %0.2f, %0.2f %0.2f )") 
              % p[0] % p[1] % p[2]
        << format(" ( %0.2f, %0.2f %0.2f )") 
              % vox_p[0] % vox_p[1] % vox_p[2]
        << format(" ( %0.2f, %0.2f %0.2f )") 
              % vx % vy % vz
        << format("  nv %0.3f") %  nv
        << format("  current val %0.2f %0.2f")
          % displ->InterpLinIntensite(vox_p[0],vox_p[1],vox_p[2])
          % closest_point_intensity
        << format("  d= %0.3f mm") %  distance
        << endl;

  return res;

} // Func_path_from_vectfield()


//-------------------------------------------------------
// delta is the small increment used to estimate the derivatives
// based on linear interpolation
// only for 3D images
SurfacePoly* Func_path_from_vectfield( InrImage::ptr displ,
                                      double start[3],
                                      double end[3],
                                      double step_size,
                                      double max_length,
                                      double delta)
{

  FILE_MESSAGE(format(" expected endpoint %0.2f %0.2f %0.2f ") 
                      % end[0] % end[1] % end[2] );

  SurfacePoly* res = Func_path_from_vectfield(displ,start,step_size,max_length,delta);

  // check that we are close to the expected endpoint
  if (res->GetNumberOfLines() !=1) {
    FILE_ERROR(" Polydata should contain exactly 1 line");
    return res;
  }

  // get the last point of the line
  T_Line&      l = res->GetLine(0);
  if (l.NbElts()>0) {
    Point3DPoly& pt = res->GetPoint(l[l.NbElts()-1]);
    float p[3] = { pt.pt.x, pt.pt.y, pt.pt.z };

    double dist_end;
    dist_end = sqrt ( (p[0]-end[0])*(p[0]-end[0]) +
                      (p[1]-end[1])*(p[1]-end[1]) +
                      (p[2]-end[2])*(p[2]-end[2])
                    );
    double voxdis = sqrt( displ->VoxSizeX()*displ->VoxSizeX() +
                          displ->VoxSizeY()*displ->VoxSizeY() +
                          displ->VoxSizeZ()*displ->VoxSizeZ() 
                        );
    if (dist_end<voxdis) {
      cout << "*** Could Add reached end point ***" << endl;
    } else
      cout << "*** End point not reached  ***" 
            << format(" %1% > %2% ") % dist_end % voxdis
            << endl;
  
  } else
    FILE_ERROR("Resulting line has no point");

  return res;

} // Func_path_from_vectfield()

