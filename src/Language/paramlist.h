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

//#include "inrimage.hpp"
#include "DefineClass.hpp"
#include "AMILabConfig.h"

#include "BasicVariable.h"
#include "amilab_messages.h"
//#include "Variable.hpp"

extern unsigned char GB_debug;


#include <string>
#include <vector>
//using namespace std;

template class AMI_DLLEXPORT std::vector<BasicVariable::ptr>;


/**
 * Stores a list of parameters from the scripting language
 **/
class AMI_DLLEXPORT ParamList {

  DEFINE_CLASS(ParamList);

private:
  
  // use here a std::list of Variable, no need to care of the order the variables are deleted since they don't have inter-dependance
  std::vector<BasicVariable::ptr>     params;

  // reference to the variable: should not be deleted
  // not needed because of smart pointers ...
  // unsigned char reference[MAX_PARAM];

 public:


  /**
   * Constructor
   */
  ParamList()
    {
    }

//  ~ParamList();


  /**
   * 
   * @return the number of parameters
   */
  int GetNumParam() { return params.size(); }

  /**
   * 
   * @param i 
   * @return the type of the parameter i
   */
  vartype GetType( int i) { 
    if (i<0) {
      fprintf(stderr,"ParamList:: GetType() negative param number \n");
      i=0; 
    }
    if (i>=GetNumParam()) {
      fprintf(stderr,"ParamList:: GetType()  param number too high \n");
      i = GetNumParam()-1; 
    }

    return params[i]->Type();
  }

  bool AddParam( const BasicVariable::ptr& var);

  // cannot use & because may return a empty pointer, should have a static pointer to empty variable at hand
  BasicVariable::ptr GetParam(int i);

};


/**  Declaration of the parameters list
 **/
class ParamListDecl {

  int         num_param;
  std::string name[MAX_PARAM];
  vartype     type[MAX_PARAM];

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
      return (char*) name[0].c_str(); 
    }
    if (i>=num_param) {
      fprintf(stderr,"ParamList:: GetName()  param number too high \n");
      return (char*) name[num_param-1].c_str(); 
    }
    return (char*) name[i].c_str();
  }

  unsigned char AddParam( const std::string& st, vartype t)
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

  unsigned char GetParam( int num, std::string& st, vartype& t, bool needed)
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

  bool CheckParam( ParamList* pl) 
  {
    int       i;
    //void*     p;
    //vartype t;
    if ( pl->GetNumParam() != GetNumParam() )
    {
      fprintf ( stderr,"Bad number of parameters \n" );
      return false;
    }

    // Can't be that strict since there can be automatic conversion ...
    for ( i=0;i<GetNumParam();i++ )
    {
      //  pl->GetParam( i, p, t);
      //  printf("%d: %d %d \n",i,t,type[i]);
      // treat numeric (float) type separately ...
      if (GetType(i) == type_float)
      {
        // only check that the parameter is of numeric type
        if (!pl->GetParam(i)->IsNumeric()) return false;
      } else
        if ( pl->GetType ( i ) !=GetType ( i ) )
        {
          fprintf ( stderr,"Parameter %d has incorrect type \n",i );
          return false;
        }
    }

  
    return true;
  }


}; // class ParamListDecl

#endif
