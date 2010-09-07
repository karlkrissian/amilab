//
// C++ Interface: dwPoint2D
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _dwPoint2D_h
#define _dwPoint2D_h

#include "DefineClass.hpp"

/**
  *  A Class for 2D Points in wxDrawingWindow.
  *  Points a stored in World coordinates and not in the displayed image coordinates.
  */
class dwPoint2D {

  DEFINE_CLASS(dwPoint2D);

  protected:
    //! X position
    double _x;

    //! Y position
    double _y;
  public:
    /**
     * Constructor, initialize the point to (0,0).
     */
    dwPoint2D() :_x(0),_y(0) {}

    /**
     * Constructor.
     * @param x 
     * @param y 
     */
    dwPoint2D(double x, double y) :_x(x),_y(y) {}

    /**
     * 
     * @return X position.
     */
    double GetX() const { return _x;}

    /**
     * 
     * @return Y position.
     */
    double GetY() const { return _y;}

    /**
     * Set the X position.
     * @param x 
     */
    void SetX(double x) { _x = x; }
 
   /**
     * Set the Y position.
     * @param y 
     */
    void SetY(double y) { _y = y; }

    /**
     * Copy of points
     * @param pt 
     */
    void operator = (const dwPoint2D& pt) {
      _x = pt._x;
      _y = pt._y;
    }
};

#endif // _dwPoint2D_h
