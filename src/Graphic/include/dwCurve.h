//
// C++ Interface: dwCurve
//
// Description: 2D curve as a list of points.
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _dwCurve_h
#define _dwCurve_h

#include "dwPoint2D.h"
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

/**
 * 2D Curve for wxDrawingWindow class.
 */
class dwCurve {

  DEFINE_CLASS(dwCurve);

    //! curve points as a vetor of 2D points dwPoint2D
    std::vector<dwPoint2D> points;

    //! Colour of the curve
    wxColour color;

    /** Style of the curve
     * supported styles are
     * 0: wxSOLID   Solid style.
     * 1: wxDOT   Dotted style.
     * 2: wxLONG_DASH   Long dashed style.
     * 3: wxSHORT_DASH  Short dashed style.
     * 4: wxDOT_DASH  Dot and dash style. 
     **/
    int style;

    //! Thickness of the curve
    int width;
    
    //! draw lines
    bool drawlines;
    
    //! draw points
    bool drawpoints;

  public:
    //! simple Constructor

    dwCurve() : 
        color(*wxRED), 
          style(PENSTYLE_SOLID), 
          width(1), 
          drawlines(true), 
          drawpoints(false) {}

    void SetDrawLines(bool val) { drawlines = val; }
    bool GetDrawLines() { return drawlines; }
    
    void SetDrawPoints(bool val) { drawpoints=val; }
    bool GetDrawPoints() { return drawpoints; }

    /**
     * 
     * @param c , color of the curve
     */
    void SetColour( const wxColour& c)    { color = c; }

    /**
     * 
     * @return Curve color
     */
    const wxColour& GetColour() const { return color; }

    /**
     * @param s , style of the curve see wxPen documentation
     */
    void SetStyle( int s) { style = s; }

    /**
     * 
     * @return style of the curve
     */
    int GetStyle() const { return style; }

    /**
     * 
     * @param  width of the curve
     */
    void SetWidth( int w) { width = w; }

   /**
    * 
    * @return width of the curve
    */
   int GetWidth() const { return width; }

    /**
     * 
     * @return the vector of points
     */
    std::vector<dwPoint2D>& GetPoints() { return points; }

    /**
     * 
     * @return  number of points of the curve
     */
    int GetNumberOfPoints() const
    {
      return points.size();
    }

    /**
     * 
     * @param i 
     * @return the point number i
     */
    dwPoint2D GetPoint(int i) const
    {
      if (i<GetNumberOfPoints()) 
        return points[i];
    }

    /**
     * Add a point to the curve.
     * @param p 
     */
    void AddPoint(const dwPoint2D& p )
    {
      points.push_back(p);
    }
    
    dwCurve& operator=(const dwCurve& c1)
    {
      points      = c1.points;
      color       = c1.color;
      style       = c1.style;
      width       = c1.width;
      drawlines   = c1.drawlines;
      drawpoints  = c1.drawpoints;
    }
};

typedef std::vector<dwCurve>           vector_dwCurve;


#endif // _dwCurve_h
