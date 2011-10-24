//
// C++ Interface: dwControlledCurve
//
// Description: 2D curve as a list of points.
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _dwControlledCurve_h
#define _dwControlledCurve_h

#include "dwPoint2D.h"
#include "dwControlPoint.h"
#include "dwCurve.h"
#include <vector>

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/colour.h>

#if ((wxMAJOR_VERSION==2)&&(wxMINOR_VERSION>=9))||(wxMAJOR_VERSION>=3)
  #define PENSTYLE_SOLID wxPENSTYLE_SOLID 
#else
  #define PENSTYLE_SOLID wxSOLID 
#endif

#include "DefineClass.hpp"
#include <vector>

typedef enum {
 normal_curve = 0,
 colormap_curve,
 //colormap_curveLimit,
} ControlledCurveType;



/**
 * 2D Curve for wxDrawingWindow class.
 */
class dwControlledCurve {

  DEFINE_CLASS(dwControlledCurve);

  boost::shared_ptr<dwCurve> _curve;
  
  /** std:vector of dwPoint2D: list of control points
     within a shared pointer to facilitate the wrapping
    */
  boost::shared_ptr<vector_dwControlPoint> _controlpoints;

  bool appliedlimits;
  ControlledCurveType type;

  public:
    //! simple Constructor
    dwControlledCurve() 
    {
      _curve = dwCurve::ptr(new dwCurve());
      _controlpoints = boost::shared_ptr<vector_dwControlPoint>(
          new vector_dwControlPoint()
        );
      type = normal_curve;
      appliedlimits=false;
    }

    //!copy Constructor
    dwControlledCurve( const dwControlledCurve& c) 
    {
      _curve = dwCurve::ptr(new dwCurve());
      _controlpoints = boost::shared_ptr<vector_dwControlPoint>(
          new vector_dwControlPoint()
        );
      *_curve = *c._curve;
      *_controlpoints = *c._controlpoints; 
      type = c.type;
      appliedlimits= c.appliedlimits;
    }

    dwControlledCurve& operator = (const dwControlledCurve& c)
    {
      *_curve = *c._curve;
      *_controlpoints = *c._controlpoints;
      type = c.type; 
      appliedlimits= c.appliedlimits;
      return *this;
    }

    boost::shared_ptr<vector_dwControlPoint>& GetControlPoints() {
      return _controlpoints;
    }
  
    boost::shared_ptr<dwCurve> GetCurve() {
      return _curve;
    }

    /**
     * The curve depends on the control points, to start with set linear interpolation between the points
     */
    void ComputeCurve();

    void  SetLimits( bool v) { appliedlimits = v; }
    bool  isLimited() { return appliedlimits; }
    int   GetType() const { return (int)type; }
    void  SetType( const int t) 
    { 
      type = (ControlledCurveType)t; 
      //if (type==colormap_curve) appliedlimits=true;
    }
};

typedef std::vector<dwControlledCurve> vector_dwControlledCurve;

#endif // _dwControlledCurve_h
