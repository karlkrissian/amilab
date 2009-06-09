/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: Duree.hpp,v $
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.2  2003/09/09 10:35:15  karl
 * updated file
 *
 * Revision 1.1.1.1  2003/08/14 07:16:10  karl
 * Source code
 *
 * Revision 1.1.1.1  2000/04/07 16:12:52  karl
 * Sources code
 *
 * Revision 1.1  1999/07/09 13:57:10  kkrissia
 * *** empty log message ***
 *
 * Revision 1.1  1998/12/03 16:18:05  kkrissia
 * *** empty log message ***
 *
 *
 ***************************************************************************/

#ifndef _DUREE_
#define _DUREE_


#if defined(_MSC_VER) || defined(__MINGW32__)
#include <windows.h>
#include <time.h>
#else
#include <sys/time.h>
#endif
#include "style.hpp"

#ifdef AMI_USE_OPENMP
  #include <omp.h>
#endif

#include <iostream>


double am_timer(void);


#if defined(_MSC_VER) || defined(__MINGW32__)
int gettimeofday(struct timeval* tp, void* tzp);
#endif

#include <iostream>
#include <string>
using namespace std;


//======================================================================
class Duree
//     -----
{

  unsigned char          debut_OK, fin_OK;
  struct timeval   time1, time2;

  double timer_t1;
  double timer_t2;
  double diff_timer;
  double cumul_timer;

  int           diff_sec;
  int           diff_microsec;

  long       cumul_diff_sec;
  long       cumul_diff_microsec;
  string     name;
  
public:

  Constructeur Duree( const std::string& _name = "")
  //
  {
    debut_OK = fin_OK = false;
    diff_sec      = 0; 
    diff_microsec = 0; 
    name = _name;
    InitCumul();
    diff_timer = 0;
  } 

  void InitCumul()
  {
    cumul_diff_sec = 0;
    cumul_diff_microsec = 0;
    cumul_timer = 0;
  }

  void AddCumul()
  {
    cumul_diff_sec += diff_sec;
    cumul_diff_microsec += diff_microsec;
    cumul_timer += diff_timer;
  }

  double GetCumulTimer() { return cumul_timer; }

  void AfficheCumul(ostream& o);

  void GetCumul(long& heures, long& minutes, long& secondes )
  {

    heures = minutes = secondes = 0;

    secondes = cumul_diff_sec;
    Si secondes > 60 Alors
       minutes  = secondes / 60;
       secondes = secondes % 60;
    FinSi

    Si minutes        > 60 Alors
       heures   = minutes / 60;
       minutes  = minutes % 60;
    FinSi
    

  }

  void Debut()
  {
    debut_OK = (gettimeofday( &time1, NULL ) != -1);
    fin_OK   = false;
    diff_sec      = 0;
    diff_microsec = 0;
    timer_t1 = am_timer();
  }


  void Fin()
  {
    fin_OK = (gettimeofday( &time2, NULL ) != -1);
    Si debut_OK Et fin_OK Alors
      diff_sec      = time2.tv_sec  - time1.tv_sec;
      diff_microsec = time2.tv_usec - time1.tv_usec;
    FinSi

    timer_t2 = am_timer();
    diff_timer = timer_t2-timer_t1;
  }

  ///
  friend ostream& operator<<(ostream& o, const Duree& d);

};



#endif
