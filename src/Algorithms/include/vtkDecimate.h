/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkDecimate.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.


     THIS CLASS IS PATENTED UNDER UNITED STATES PATENT NUMBER 5,559,388
     "Method for Reducting the Complexity of a Polygonal Mesh".
     Application of this software for commercial purposes requires 
     a license grant from GE. Contact:

         Carl B. Horton
         Sr. Counsel, Intellectual Property
         3000 N. Grandview Blvd., W-710
         Waukesha, WI  53188
         Phone:  (262) 513-4022
         E-Mail: Carl.Horton@med.ge.com

     for more information.

=========================================================================*/
// .NAME vtkDecimate - reduce the number of triangles in a mesh
// .SECTION Description
// vtkDecimate is a filter to reduce the number of triangles in a triangle 
// mesh, while preserving the original topology and a forming good 
// approximation to the original geometry. The input to vtkDecimate is a 
// vtkPolyData object, and only triangles are treated. If you desire to 
// decimate polygonal meshes, first triangulate the polygons with the 
// vtkTriangleFilter object.
//
// The algorithm proceeds as follows. Each vertex in the triangle
// list is evaluated for local planarity (i.e., the triangles using
// the vertex are gathered and compared to an "average" plane). If the
// region is locally planar, that is if the target vertex is within a
// certain distance of the average plane (i.e., the error), and
// there are no edges radiating from the vertex that have a dihedral angle
// greater than a user-specified edge angle (i.e., feature angle), and
// topology is not altered, then that vertex is deleted. The resulting
// hole is then patched by re-triangulation. The process continues over
// the entire vertex list (this constitutes an iteration). Iterations
// proceed until a target reduction is reached or a maximum iteration
// count is exceeded.
// 
// There are a number of additional parameters you can set to control
// the decimation algorithm. The Error ivar may be increased over each
// iteration with the ErrorIncrement. (These two variables have the
// largest effect.) Edge preservation (i.e., PreserveEdges ivar) may
// be disabled or enabled. You can turn on/off edge vertex deletion
// (i.e., BoundaryVertexDeletion ivar). (Edge vertices are vertices
// that lie along boundaries of meshes.) Sub iterations are iterations
// that are performed without changing the decimation criterion. The
// AspectRatio ivar controls the shape of the triangles that are
// created, and is the ratio of maximum edge length to minimum edge
// length. The Degree is the number of triangles using a single
// vertex. Vertices of high degree are considered "complex" and are
// never deleted.
//
// .SECTION Caveats
// This implementation has been adapted for a global error bound decimation
// criterion. That is, the error is a global bound on distance to original
// surface. This is an improvement over the original Siggraph paper ("Decimation
// of Triangle Meshes", Proc Siggraph `92.)
//
// The algorithm has been extended with a special flag to allow
// topology modification. When the PreserveTopology flag is on, then
// the algorithm will preserve the topology of the original mesh. If
// off, the algorithm may close holes and/or collapse tunnels (i.e.,
// form non-manifold attachments).

// .SECTION See Also
// vtkDecimatePro vtkQuadricClustering vtkQuadricDecimation

#ifndef __vtkDecimate_h
#define __vtkDecimate_h


#include <vtkDecimateConfigure.h>
#include "vtkPolyDataAlgorithm.h"

#include "vtkCell.h" // Needed for VTK_CELL_SIZE

#ifndef VTK_LARGE_INTEGER
#define 	VTK_LARGE_INTEGER   2147483647
#endif

#define VTK_NUMBER_STATISTICS 12

class vtkIdList;

//class VTK_DECIMATE_EXPORT vtkDecimate : public vtkPolyDataToPolyDataFilter
class  vtkDecimate : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro(vtkDecimate,vtkPolyDataAlgorithm);
  static vtkDecimate *New();
  //vtkTypeRevisionMacro(vtkDecimate,vtkPolyDataToPolyDataFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set the decimation error bounds. Expressed as a fraction of the longest
  // side of the input data's bounding box.
  vtkSetClampMacro(InitialError,double,0.0,1.0);
  vtkGetMacro(InitialError,double);

  // Description:
  // Set the value of the increment by which to increase the decimation
  // error after each iteration.
  vtkSetClampMacro(ErrorIncrement,double,0.0,1.0);
  vtkGetMacro(ErrorIncrement,double);

  // Description:
  // Set the largest decimation error that can be achieved 
  // by incrementing the error.
  vtkSetClampMacro(MaximumError,double,0.0,1.0);
  vtkGetMacro(MaximumError,double);

  // Description:
  // Specify the desired reduction in the total number of polygons. Because
  // of various constraints, this level of reduction may not be realizable.
  vtkSetClampMacro(TargetReduction,double,0.0,1.0);
  vtkGetMacro(TargetReduction,double);

  // Description:
  // Specify the maximum number of iterations to attempt. If decimation target
  // is reached first, this value will not be reached.
  vtkSetClampMacro(MaximumIterations,int,0,VTK_LARGE_INTEGER);
  vtkGetMacro(MaximumIterations,int);

  // Description:
  // Specify the maximum sub-iterations to perform. If no triangles are deleted
  // in a sub-iteration, the sub-iteration process is stopped.
  vtkSetClampMacro(MaximumSubIterations,int,1,VTK_LARGE_INTEGER);
  vtkGetMacro(MaximumSubIterations,int);
  
  // Description:
  // Specify the mesh feature angles.
  vtkSetClampMacro(InitialFeatureAngle,double,0.0,180.0);
  vtkGetMacro(InitialFeatureAngle,double);

  // Description:
  // Set/Get the angle by which to increase feature angle over each iteration.
  vtkSetClampMacro(FeatureAngleIncrement,double,0.0,180.0);
  vtkGetMacro(FeatureAngleIncrement,double);

  // Description:
  // Set the largest permissible feature angle.
  vtkSetClampMacro(MaximumFeatureAngle,double,0.0,180.0);
  vtkGetMacro(MaximumFeatureAngle,double);

  // Description:
  // Turn on/off the generation of error scalars.
  vtkSetMacro(GenerateErrorScalars,int);
  vtkGetMacro(GenerateErrorScalars,int);
  vtkBooleanMacro(GenerateErrorScalars,int);

  // Description:
  // Turn on/off the preservation of feature edges.
  vtkSetMacro(PreserveEdges,int);
  vtkGetMacro(PreserveEdges,int);
  vtkBooleanMacro(PreserveEdges,int);

  // Description:
  // Turn on/off the deletion of vertices on the boundary of a mesh.
  vtkSetMacro(BoundaryVertexDeletion,int);
  vtkGetMacro(BoundaryVertexDeletion,int);
  vtkBooleanMacro(BoundaryVertexDeletion,int);

  // Description:
  // Specify the maximum allowable aspect ratio during triangulation.
  vtkSetClampMacro(AspectRatio,double,1.0,1000.0);
  vtkGetMacro(AspectRatio,double);

  // Decsription:
  // Turn on/off whether to preserve the topology of the original mesh. If
  // off, hole elimination and non-manifold attachment can occur.
  vtkSetMacro(PreserveTopology,int);
  vtkGetMacro(PreserveTopology,int);
  vtkBooleanMacro(PreserveTopology,int);

  // Description:
  // If the number of triangles connected to a vertex exceeds "Degree", then 
  // the vertex is considered complex and is never deleted. (NOTE: the
  // complexity of the triangulation algorithm is proportional to Degree^2.)
  vtkSetClampMacro(Degree,int,25,VTK_CELL_SIZE);
  vtkGetMacro(Degree,int);
  
  // Description:
  // Control the printout of warnings. This flag limits the number of warnings
  // regarding non-manifold geometry and complex vertices. If set to zero, no
  // warnings will appear.
  vtkSetClampMacro(MaximumNumberOfSquawks,int,0,VTK_LARGE_INTEGER);
  vtkGetMacro(MaximumNumberOfSquawks,int);
  
protected:

  //
  // Special classes for manipulating data
  //
  //BTX - begin tcl exclude
  //
  // Special structures for building loops
  class LocalVertex
  {
  public:
    vtkIdType     id;
    double   x[3];
    double   FAngle;
    int     deRefs; //monitor memory requirements; new only when necessary
    int     newRefs;
  };
  typedef LocalVertex *LocalVertexPtr;
    
  class LocalTri
  {
  public:
    vtkIdType     id;
    double   area;
    double   n[3];
    vtkIdType     verts[3];
  };
  typedef LocalTri *LocalTriPtr;

  class VertexArray;
  friend class VertexArray;
  class VertexArray { //;prevent man page generation
  public:
    VertexArray(const vtkIdType sz) 
      {this->MaxId = -1; this->Array = new LocalVertex[sz];};
    ~VertexArray() {if (this->Array) {delete [] this->Array;}};
    vtkIdType GetNumberOfVertices() {return this->MaxId + 1;};
    void InsertNextVertex(LocalVertex& v) 
      {this->MaxId++; this->Array[this->MaxId] = v;};
    LocalVertex& GetVertex(vtkIdType i) {return this->Array[i];};
    void Reset() {this->MaxId = -1;};

    LocalVertex *Array;  // pointer to data
    vtkIdType MaxId;             // maximum index inserted thus far
  };

  class TriArray;
  friend class TriArray;
  class TriArray { //;prevent man page generation
  public:
    TriArray(const vtkIdType sz) 
      {this->MaxId = -1; this->Array = new LocalTri[sz];};
    ~TriArray() {if (this->Array) {delete [] this->Array;}};
    vtkIdType GetNumberOfTriangles() {return this->MaxId + 1;};
    void InsertNextTriangle(LocalTri& t) 
      {this->MaxId++; this->Array[this->MaxId] = t;};
    LocalTri& GetTriangle(vtkIdType i) {return this->Array[i];};
    void Reset() {this->MaxId = -1;};

    LocalTri *Array;  // pointer to data
    vtkIdType MaxId;            // maximum index inserted thus far
  };
  //ETX - end tcl exclude
  //

 public:
  vtkDecimate();
  ~vtkDecimate();
 protected:

  void Execute();

  double InitialFeatureAngle; // dihedral angle constraint
  double FeatureAngleIncrement;
  double MaximumFeatureAngle;
  int PreserveEdges; // do/don't worry about feature edges
  int BoundaryVertexDeletion;  
  double InitialError; // decimation error in fraction of bounding box
  double ErrorIncrement; // each iteration will bump error this amount
  double MaximumError; // maximum error
  double TargetReduction; //target reduction of mesh (fraction)
  int MaximumIterations; // maximum number of passes over data
  int MaximumSubIterations; // maximum non-incrementing passes
  double AspectRatio; // control triangle shape during triangulation
  int Degree; // maximum number of triangles incident on vertex
  int Stats[VTK_NUMBER_STATISTICS]; // keep track of interesting statistics
  int GenerateErrorScalars; // turn on/off vertex error scalar generation
  int MaximumNumberOfSquawks; //control number of error messages
  int PreserveTopology; //control whether mesh topology is preserved
  vtkIdList *Neighbors; // to replace static
  VertexArray *V; //to replace static
  TriArray *T; //to replace static
  
  void CreateOutput(vtkIdType numPts, vtkIdType numTris,
                    vtkIdType numEliminated, vtkPointData *pd,
                    vtkPoints *inPts);
  int BuildLoop(vtkIdType ptId, unsigned short int nTris, vtkIdType* tris);
  void EvaluateLoop(int& vtype, vtkIdType& numFEdges,
                    LocalVertexPtr fedges[]);
  int CanSplitLoop(LocalVertexPtr fedges[2], vtkIdType numVerts, 
                   LocalVertexPtr verts[], vtkIdType& n1,
                   LocalVertexPtr l1[], vtkIdType& n2,
                   LocalVertexPtr l2[], double& ar);
  void SplitLoop(LocalVertexPtr fedges[2], vtkIdType numVerts, 
                 LocalVertexPtr *verts, vtkIdType& n1,
                 LocalVertexPtr *l1, vtkIdType& n2, LocalVertexPtr *l2);
  void Triangulate(vtkIdType numVerts, LocalVertexPtr verts[]);
  int CheckError();
private:
  vtkDecimate(const vtkDecimate&);  // Not implemented.
  void operator=(const vtkDecimate&);  // Not implemented.
};

#endif


