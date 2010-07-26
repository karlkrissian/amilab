//
// C++ Interface: dw_Curve
//
// Description: 2D curve as a list of points.
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _dw_Curve_h
#define _dw_Curve_h

#include "dw_Point2D.h"
#include <vector>

/**
 * 2D Curve for wxDrawingWindow class.
 */
class dw_Curve {

    //! curve points as a vetor of 2D points dw_Point2D
    std::vector<dw_Point2D> points;

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
    dw_Curve() : color(*wxRED), style(wxSOLID), width(1), drawlines(true), drawpoints(false) {}

    void SetDrawLines(bool val) { drawlines = val; }
    bool GetDrawLines() { return drawlines; }
    
    void SetDrawPoints(bool val) { drawpoints=val; }
    bool GetDrawPoints() { return drawpoints; }

    /**
     * 
     * @param c , color of the curve
     */
    void SetColor( const wxColour& c)    { color = c; }

    /**
     * 
     * @return Curve color
     */
    const wxColour& GetColor() const { return color; }

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
    std::vector<dw_Point2D>& GetPoints() { return points; }

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
    dw_Point2D GetPoint(int i) const
    {
      if (i<GetNumberOfPoints()) 
        return points[i];
    }

    /**
     * Add a point to the curve.
     * @param p 
     */
    void AddPoint(const dw_Point2D& p )
    {
      points.push_back(p);
    }
};

#endif // _dw_Curve_h
