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

//----------------------------------------------------------------------
GnuPlot ::  GnuPlot( )
//
{

  
//    int i;

  _nb_courbes_max = 10;

  _nom_donnees = new Chaine[_nb_courbes_max];
  _titles      = new Chaine[_nb_courbes_max];

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
GnuPlot :: ~GnuPlot()
//
{

   
    int i;

  Pour(i,0,_nb_courbes-1)
    delete [] _tabx[i];
    delete [] _taby[i];
  FinPour

  delete [] _tabx;
  delete [] _taby;

  delete [] _nom_donnees;
  delete [] _titles;

  delete [] _nb_points;


} // Destructor


//----------------------------------------------------------------------
///
int GnuPlot :: AddCourbe( int nb_points, float* tabx, float* taby, Chaine nom, Chaine title)
//
{

   
    int i,n;

  _nb_courbes++;
  Si _nb_courbes>_nb_courbes_max Alors
    cerr << "GnuPlot::AddCourbe() \t Trop de courbes \n";
    return 0;
  FinSi

  n = _nb_courbes - 1;
  
  _nom_donnees[n] = nom;

  if (title != "")
    _titles[n] = title;
else
_titles[n] = _nom_donnees[n];

  _nb_points[n] = nb_points;

  _tabx[n] = new float[_nb_points[n]];
  _taby[n] = new float[_nb_points[n]];


  Pour(i,0,_nb_points[n]-1)
    _tabx[n][i] = tabx[i];
    _taby[n][i] = taby[i];
  FinPour  

  return n;

} // AddCourbe()


//----------------------------------------------------------------------
///
int GnuPlot :: ReadData( Chaine nom_donnees, Chaine title) throw ( ErreurLecture)
//                          --------
{

  
    FILE*  fic_donnees;    
    int i,n, nb_pts;
    float   x,y;

  _nb_courbes++;
  Si _nb_courbes>_nb_courbes_max Alors
    cerr << "GnuPlot::AddCourbe() \t Trop de courbes \n";
    return 0;
  FinSi

  n = _nb_courbes - 1;
  
  _nom_donnees[n] = nom_donnees;
if (title!="")
  _titles[n]      = title;
else
_titles[n] = nom_donnees;

  // Premiere lecture pour connaitre le nombre de points
  fic_donnees = fopen( (char*) _nom_donnees[n], "r");

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
void GnuPlot :: SaveData( int num_courbe, int type)
//                        --------
{

  
    Chaine nom_donnees;
    FILE*  fic_donnees;    
    int i;

  Si (num_courbe < 0) Ou (num_courbe>_nb_courbes-1) Alors
    cerr << "GnuPlot::SaveData()\t Erreur numero de courbe non valide ...\n";
    return;
  FinSi

  switch ( type ){  
    case TYPE_GNUPLOT: nom_donnees = _nom_donnees[num_courbe] + ".dat";
    break;
    case TYPE_SECTION: nom_donnees = _nom_donnees[num_courbe] + ".sec";
    break;
  } // end switch

  Si _auto_inf Alors  
    _xmin = _tabx[0][0];
    _ymin = _taby[0][0];
  FinSi

  Si (fic_donnees = fopen( (char*) nom_donnees, "w")) != NULL Alors
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
    cerr << " GnuPlot::XPlot() \t Erreur dans l'ouverture du fichier de donnees\n";
    return;

  FinSi

} // SaveData()


//----------------------------------------------------------------------
void GnuPlot :: XPlot( Chaine nom, int pause)
//
{

  
    int i;
    Chaine commande;


  Pour(i,0,_nb_courbes-1)
    SaveData(i);
  FinPour

  nom_script = nom;
  nom_script += ".gnuplot";

  Si (fic_script = fopen( (char*) nom_script, "w")) != NULL Alors
    fprintf( fic_script, "plot [%f:%f] [%f:%f] ",
	     _xmin, _xmax, _ymin, _ymax*1.2);

    Pour(i,0,_nb_courbes-1)
      Si i>0 AlorsFait fprintf( fic_script, ",");
      fprintf( fic_script, " \"%s\" title \"%s\"  with lines", 
	        (char*) (_nom_donnees[i]+".dat"), (char*) _titles[i]);
    FinPour
    
    fprintf( fic_script, "\n");

    fprintf( fic_script, "pause %d\n",pause);
    fclose( fic_script);
  Sinon
    cerr << " GnuPlot::XPlot() \t ";
    cerr << " Erreur dans l'ouverture du fichier gnuplot\n";
    return;
  FinSi
  
  cout << "nom_script = " << nom_script << endl;
  commande  = "gnuplot  -geometry 700x200+50+600 ";
  commande += nom_script;
  commande += "&";
  system( commande);

} // Xplot()


//----------------------------------------------------------------------
void GnuPlot :: PSPlot( Chaine nom)
//
{

  
    int i;
    Chaine commande;


  Pour(i,0,_nb_courbes-1)
    SaveData(i);
  FinPour

  nom_script = nom;
  nom_script += "-ps.gnuplot";

  Si (fic_script = fopen( (char*) nom_script, "w")) != NULL Alors

    fprintf( fic_script, "set terminal postscript portrait\n");
    fprintf( fic_script, "set size %s \n", (char*) this->size);
    fprintf( fic_script, "set output \"%s\" \n", (char*)(nom+".ps"));

    Si _xtics > 0 AlorsFait
      fprintf( fic_script, "set xtics 0,%f\n", _xtics);
    Si _ytics > 0 AlorsFait
      fprintf( fic_script, "set ytics 0,%f\n", _ytics);
    Si _grid AlorsFait
      fprintf( fic_script, "set grid\n");

    fprintf( fic_script, "plot [%f:%f] [%f:%f] ",
	     _xmin, _xmax, _ymin, _ymax);

    Pour(i,0,_nb_courbes-1)
      Si i>0 AlorsFait fprintf( fic_script, ",");
      fprintf( fic_script, " \"%s\" title \"%s\"  with lines", 
	        (char*) _nom_donnees[i], (char*) _titles[i]);
    FinPour
    
    fprintf( fic_script, "\n");

    fprintf( fic_script, "pause 2\n");
    fclose( fic_script);
  Sinon
    cerr << " GnuPlot::PSPlot() \t ";
    cerr << " Erreur dans l'ouverture du fichier gnuplot " << nom_script << "\n";
    return;
  FinSi
  
  cout << "nom_script = " << nom_script << endl;
  commande  = "gnuplot " + nom_script;
//  commande += "&";
  system( commande);

} // PSplot()
