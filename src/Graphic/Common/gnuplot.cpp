/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.3 $
 * $Log: gnuplot.cpp,v $
 * Revision 1.3  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.2  2005/09/28 17:30:33  karl
 * adding title
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:09:46  karl
 * Sources code
 *
 *
 ***************************************************************************/



#include "gnuplot.hpp"
#include <iostream>
#include <boost/format.hpp>
#include<stdio.h>

ami::GnuPlot::ErreurLecture::ErreurLecture( std::string message)
{
  std::cerr << "GnuPlot Erreur de Lecture " << message << std::endl;
}

//----------------------------------------------------------------------
ami::GnuPlot ::  GnuPlot( )
//
{

  
//    int i;

  _nb_courbes_max = 10;

  _nb_points   = new int[_nb_courbes_max];

  _tabx = new float*[_nb_courbes_max];
  _taby = new float*[_nb_courbes_max];

  _nb_courbes     = 0;

  _xmin = _ymin = 0.0;
  _xmax = _ymax = 0.0;
 
  _xtics = _ytics = -1;
  _grid = false;

  _auto_sup = true;
  _auto_inf = true;

} // Constructor


//----------------------------------------------------------------------
ami::GnuPlot :: ~GnuPlot()
//
{

   
    int i;

  Pour(i,0,_nb_courbes-1)
    delete [] _tabx[i];
    delete [] _taby[i];
  FinPour

  delete [] _tabx;
  delete [] _taby;

  delete [] _nb_points;


} // Destructor


//----------------------------------------------------------------------
///
int ami::GnuPlot :: AddCurve( int nb_points, float* tabx, float* taby, 
                               std::string nom, std::string title)
//
{

   
    int i,n;

  _nb_courbes++;
  Si _nb_courbes>_nb_courbes_max Alors
    std::cerr << "ami::GnuPlot::AddCurve() \t Trop de courbes \n";
    return 0;
  FinSi

  n = _nb_courbes - 1;
  
  _data_names.push_back(nom);
  _data_filenames.push_back(nom+".dat");

  if (title != "")
    _titles.push_back(title);
  else
    _titles.push_back(_data_names[n]);

  _nb_points[n] = nb_points;

  _tabx[n] = new float[_nb_points[n]];
  _taby[n] = new float[_nb_points[n]];


  Pour(i,0,_nb_points[n]-1)
    _tabx[n][i] = tabx[i];
    _taby[n][i] = taby[i];
  FinPour  

  return n;

} // AddCurve()

//------------------------------------------------------------------------------
int ami::GnuPlot::AddCurve( InrImage::ptr im, 
                            std::string name, std::string title)
{
    float* tabx;
    float* taby;
    int x;
    std::string fname;

    tabx = new float[im->DimX()];
    taby = new float[im->DimX()];

    for (int y=0; y<im->DimY(); y++) {
      for(x=0;x<im->DimX();x++) {
        tabx[x] = im->SpacePosX(x);
        taby[x] = (*im)(x,y,0);
      }
      //num_courbe = 
      this->AddCurve( im->DimX(), tabx, taby, name);
    }

    fname =  (boost::format("%s.gnuplot")%name.c_str()).str();

    delete [] tabx;
    delete [] taby;
}

//----------------------------------------------------------------------
///
int ami::GnuPlot :: ReadData( std::string nom_donnees, std::string title) throw ( ErreurLecture)
//                          --------
{
    FILE*  fic_donnees;    
    int i,n, nb_pts;
    float   x,y;

  _nb_courbes++;
  Si _nb_courbes>_nb_courbes_max Alors
    std::cerr << "ami::GnuPlot::AddCurve() \t Trop de courbes \n";
    return 0;
  FinSi

  n = _nb_courbes - 1;
  
  _data_names.push_back(nom_donnees);
  _data_filenames.push_back(nom_donnees+".dat");
  if (title!="")
    _titles.push_back(title);
  else
    _titles.push_back(nom_donnees);

  // Premiere lecture pour connaitre le nombre de points
  fic_donnees = fopen(  _data_names[n].c_str(), "r");

  Si fic_donnees == NULL Alors
     throw ErreurLecture( nom_donnees);
  FinSi
  
  nb_pts = 0;

  fscanf( fic_donnees, "%f\t%f\n", &x,&y);

  TantQue Non(feof(fic_donnees)) Faire
    nb_pts++;
    fscanf( fic_donnees, "%f\t%f\n", &x,&y);
  FinTantQue

  // Allocation

  _nb_points[n] = nb_pts;

  _tabx[n] = new float[_nb_points[n]];
  _taby[n] = new float[_nb_points[n]];

  // Lecture
  rewind(fic_donnees);
  
  Pour( i, 0, nb_pts-1)
    fscanf( fic_donnees, "%f\t%f\n", &_tabx[n][i],&_taby[n][i]);
  FinPour

  return n;

} // ReadData()


//----------------------------------------------------------------------
///
void ami::GnuPlot :: SaveData( int num_courbe, int type)
//                        --------
{

    FILE*  fic_donnees;    
    int i;

  Si (num_courbe < 0) Ou (num_courbe>_nb_courbes-1) Alors
    std::cerr << "ami::GnuPlot::SaveData()\t Erreur numero de courbe non valide ...\n";
    return;
  FinSi

  switch ( type ){  
    case TYPE_GNUPLOT: _data_filenames[num_courbe] = _data_names[num_courbe] + ".dat";
    break;
    case TYPE_SECTION: _data_filenames[num_courbe] = _data_names[num_courbe] + ".sec";
    break;
  } // end switch

  Si _auto_inf Alors  
    _xmin = _tabx[0][0];
    _ymin = _taby[0][0];
  FinSi

  Si (fic_donnees = fopen(  _data_filenames[num_courbe].c_str(), "w")) != NULL Alors
    Pour(i,0,_nb_points[num_courbe]-1)

      Si _auto_sup Et _tabx[num_courbe][i]>_xmax AlorsFait _xmax = _tabx[num_courbe][i];
      Si _auto_sup Et _taby[num_courbe][i]>_ymax AlorsFait _ymax = _taby[num_courbe][i];

      Si _auto_inf Et _tabx[num_courbe][i]<_xmin AlorsFait _xmin = _tabx[num_courbe][i];
      Si _auto_inf Et _taby[num_courbe][i]<_ymin AlorsFait _ymin = _taby[num_courbe][i];

      switch ( type ){  
        case TYPE_GNUPLOT:
          fprintf( fic_donnees, "%f\t%f\n", _tabx[num_courbe][i], _taby[num_courbe][i]);
        break;
        case TYPE_SECTION:
          fprintf( fic_donnees, "%f\n", _taby[num_courbe][i]);
        break;
      } // end switch

    FinPour
    fclose( fic_donnees);

  Sinon
    std::cerr << " ami::GnuPlot::XPlot() \t Erreur dans l'ouverture du fichier de donnees\n";
    return;

  FinSi

} // SaveData()


//----------------------------------------------------------------------
void ami::GnuPlot::FillCommands( )
{
  std::string cmd;
  _cmdlist.clear();
  
  if (_xtics > 0) {
    cmd = (boost::format("set xtics 0,%f") % _xtics).str();
    _cmdlist.push_back(cmd);
  }
  if (_ytics > 0) {
    cmd = (boost::format("set ytics 0,%f") % _ytics).str();
    _cmdlist.push_back(cmd);
  }
  if (_grid > 0) {
    cmd = (boost::format("set grid")).str();
    _cmdlist.push_back(cmd);
  }

  cmd = (boost::format("plot [%f:%f] [%f:%f] ")
            % _xmin 
            % _xmax 
            % _ymin 
            % _ymax  //*1.2
            ).str();
  for(int i=0; i<_nb_courbes;i++)
  {
    if ((i<_data_filenames.size())&&(i<_titles.size())) {
      if (i>0) cmd += ",";
      cmd += (boost::format(" \"%s\" title \"%s\"  with lines")
                % _data_filenames[i].c_str() % _titles[i].c_str()).str();
    }
  }
  _cmdlist.push_back(cmd);
  
}

//------------------------------------------------------------------------------
void ami::GnuPlot::OpenSession( )
{
  FILE* f = popen("gnuplot -persist","w");
  if (f) {
    _session = boost::shared_ptr<FILE>(f,pfile_deleter());
  } else {
    std::cerr << "failed to open gnuplot with popen" << std::endl;
  }
}

//------------------------------------------------------------------------------
void ami::GnuPlot::SessionFillCommands( )
{
  if (_session.get()) {
    for(int i=0; i<_nb_courbes; i++)
      SaveData(i);

    FillCommands();
    for(int n=0; n<_cmdlist.size();n++) 
      fprintf( _session.get(), "%s\n", _cmdlist[n].c_str());
  }
  fflush(_session.get());
}

//------------------------------------------------------------------------------
void ami::GnuPlot::SessionRun( std::string cmd)
{
  if (_session.get()) {
    fprintf( _session.get(), "%s\n", cmd.c_str());
  }
  fflush(_session.get());
}

//------------------------------------------------------------------------------
void ami::GnuPlot::CloseSession( )
{
  _session.reset();
}

//----------------------------------------------------------------------
void ami::GnuPlot :: XPlot( std::string nom, int pause)
//
{
    int i;
    std::string commande;


  Pour(i,0,_nb_courbes-1)
    SaveData(i);
  FinPour

  nom_script = nom;
  nom_script += ".gnuplot";

  Si (fic_script = fopen( nom_script.c_str(), "w")) != NULL Alors
    FillCommands();
    for(int n=0; n<_cmdlist.size();n++) 
      fprintf( fic_script, "%s\n", _cmdlist[n].c_str());

    fprintf( fic_script, "pause %d\n",pause);
    fclose( fic_script);
  Sinon
    std::cerr << " ami::GnuPlot::XPlot() \t ";
    std::cerr << " Erreur dans l'ouverture du fichier gnuplot\n";
    return;
  FinSi
  
 std::cout << "nom_script = " << nom_script << std::endl;
  commande  = "gnuplot  -geometry 700x200+50+600 ";
  commande += nom_script;
  commande += "&";
  system( commande.c_str());

} // Xplot()


//----------------------------------------------------------------------
void ami::GnuPlot :: PSPlot( std::string nom)
//
{
  int i;
  std::string commande;

  Pour(i,0,_nb_courbes-1)
    SaveData(i);
  FinPour

  nom_script = nom;
  nom_script += "-ps.gnuplot";

  Si (fic_script = fopen( nom_script.c_str(), "w")) != NULL Alors

    fprintf( fic_script, "set terminal postscript portrait\n");
    fprintf( fic_script, "set size %s \n", this->size.c_str());
    fprintf( fic_script, "set output \"%s\" \n", (nom+".ps").c_str());

    FillCommands();
    for(int n=0; n<_cmdlist.size();n++) 
      fprintf( fic_script, _cmdlist[n].c_str());
    
    fprintf( fic_script, "\n");

    fprintf( fic_script, "pause 2\n");
    fclose( fic_script);
  Sinon
    std::cerr << " ami::GnuPlot::PSPlot() \t ";
    std::cerr << " Erreur dans l'ouverture du fichier gnuplot " << nom_script << "\n";
    return;
  FinSi
  
 std::cout << "nom_script = " << nom_script << std::endl;
  commande  = "gnuplot " + nom_script;
//  commande += "&";
  system( commande.c_str());

} // PSplot()
