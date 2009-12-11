//
// C++ Interface: ParamList
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef PARAMLIST_H
#define PARAMLIST_H



#define MAX_PARAM 20

#include "chaine.hpp"
#include "inrimage.hpp"
#include "DefineClass.hpp"
#include "amilab_messages.h"
#include "Variable.hpp"

extern unsigned char GB_debug;

#include <string>
using namespace std;



/**
 * Stores a list of parameters from the scripting language
 **/
class ParamList {

  DEFINE_CLASS(ParamList);

private:
  int       num_param;
  void*     params[MAX_PARAM];
  vartype   type[MAX_PARAM];

  // reference to the variable: should not be deleted
  unsigned char reference[MAX_PARAM];

 public:


  /**
   * Constructor
   */
  ParamList()
    {
      num_param = 0;
    }

  virtual ~ParamList();

  template <class T>
  bool FreeMemory( int i)
  {
    if (params[i]==NULL) {
      cerr << format("%s::FreeMemory<T>\t") % get_name();
      cerr << "pointer is NULL !\n";
      return false;
    }
    boost::shared_ptr<T>* ptr = (boost::shared_ptr<T>*) params[i];
    if ((ptr->use_count()>1)&&(GB_debug)) {
      cerr << format("%s::FreeMemory<T>\t") % get_name();
      cerr << format("variable %1% is referenced %2% times")  % i % ptr->use_count() << endl;
    }
    delete (boost::shared_ptr<T>*) params[i];
    params[i] = NULL;
    return true;
  }

  /**
   * 
   * @return the number of parameters
   */
  int GetNumParam() { return num_param; }

  /**
   * 
   * @param i 
   * @return the type of the parameter i
   */
  vartype GetType( int i) { 
    if (i<0) {
      fprintf(stderr,"ParamList:: GetType() negative param number \n");
      return type[0]; 
    }
    if (i>=num_param) {
      fprintf(stderr,"ParamList:: GetType()  param number too high \n");
      return type[num_param-1]; 
    }
    return type[i];
  }

  /**
   * 
   * @param i 
   * @return returns if the parameter number i is a reference
   */
  unsigned char IsReference( int i) { 
    if (i<0) {
      fprintf(stderr,"ParamList:: IsReference() negative param number \n");
      return reference[0]; 
    }
    if (i>=num_param) {
      fprintf(stderr,"ParamList:: IsReference()  param number too high \n");
      return reference[num_param-1]; 
    }
    return reference[i];
  }

  unsigned char AddParam( vartype t, void* paramp, unsigned char ref=0);

  void*         GetParam(int i);
  unsigned char GetParam( int num, void*& paramp, vartype& t, bool needed=true);

  template <class T>
  boost::shared_ptr<T> GetParamPtr(vartype t, int num, bool needed=true)
  {
    unsigned char OK;
    void* param;
    vartype type;

    OK = GetParam(num,param,type,needed);
    if (!OK) {
      if (needed)
        cerr << format("ParamList::GetParam<>(%1%)\t Using default value") % num << endl;
      return boost::shared_ptr<T>();
    }

    if (type==t)
        return *((boost::shared_ptr<T>*) param);
    else
        return boost::shared_ptr<T>();
  }

};


//----------------------------------------------------------------------
//  Declaration of the parameters list
//
class ParamListDecl {

  int       num_param;
  Chaine    name[MAX_PARAM];
  vartype   type[MAX_PARAM];

 public:
  ParamListDecl()
    {
      num_param = 0;
    }

  ~ParamListDecl()
    {
    }

  int GetNumParam() { return num_param; }

  vartype GetType( int i) { 
    if (i<0) {
      fprintf(stderr,"ParamList:: GetType() negative param number \n");
      return type[0]; 
    }
    if (i>=num_param) {
      fprintf(stderr,"ParamList:: GetType()  param number too high \n");
      return type[num_param-1]; 
    }
    return type[i];
  }

  char* GetName( int i) { 
    if (i<0) {
      fprintf(stderr,"ParamList:: GetName() negative param number \n");
      return (char*) name[0]; 
    }
    if (i>=num_param) {
      fprintf(stderr,"ParamList:: GetName()  param number too high \n");
      return (char*) name[num_param-1]; 
    }
    return (char*) name[i];
  }

  unsigned char AddParam( Chaine st, vartype t)
  {
    if ( num_param<MAX_PARAM-2 )
    {
      name[num_param] = st;
      type[num_param] = t;
      num_param++;
      return 1;
    }
    else
    {
      fprintf ( stderr,"ParamListDecl::AddParam() \t too many parameters \n" );
      return 0;
    }
  }

  unsigned char GetParam( int num, Chaine& st, vartype& t, bool needed)
  {
    if ((num>=0)&&(num<num_param)) {
      st = name[num];
      t  = type[num];
      return 1;
    }
    else {
      if (needed)
        fprintf(stderr,"ParamListDecl::GetParam()\t bad parameter number\n");
      return 0;
    }
  }

  int CheckParam( ParamList* pl) 
  {
    int       i;
    //void*     p;
    //vartype t;
  
    if ( pl->GetNumParam() != GetNumParam() )
    {
      fprintf ( stderr,"Bad number of parameters \n" );
      return 0;
    }
    for ( i=0;i<GetNumParam();i++ )
    {
      //  pl->GetParam( i, p, t);
      //  printf("%d: %d %d \n",i,t,type[i]);
      if ( pl->GetType ( i ) !=GetType ( i ) )
      {
        fprintf ( stderr,"Parameter %d has incorrect type \n",i );
        return 0;
      }
    }
  
    return 1;
  }


}; // class ParamListDecl

#endif
