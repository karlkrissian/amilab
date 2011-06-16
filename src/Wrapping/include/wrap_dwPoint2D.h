//
// C++ Interface: _wrap_dwPoint2D_h_
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_dwPoint2D_h_
#define _wrap_dwPoint2D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "dwPoint2D.h"

AMI_DECLARE_TYPE(dwPoint2D);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwPoint2D>::CreateVar( ParamList* p, bool quiet );


class WrapClass_dwPoint2D: public WrapClass<dwPoint2D>
{
  DEFINE_CLASS(WrapClass_dwPoint2D);

  public:

    /// Constructor
    WrapClass_dwPoint2D(dwPoint2D::ptr si): WrapClass<dwPoint2D>(si) { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( dwPoint2D, "Wrapping of dwPoint2D." );

    // wrapping of other methods
    ADD_CLASS_SETGET(double,X,"X position");
    ADD_CLASS_SETGET(double,Y,"Y position");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<dwPoint2D>::ptr this_ptr )
    {
      AddVar_SetGetX(              this_ptr);
      AddVar_SetGetY(              this_ptr);

      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_dwPoint2D_h_
