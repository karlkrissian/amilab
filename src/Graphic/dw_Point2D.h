//
// C++ Interface: dw_Point2D
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _dw_Point2D_h
#define _dw_Point2D_h


/**
  *  A Class for 2D Points in wxDrawingWindow.
  *  Points a stored in World coordinates and not in the displayed image coordinates.
  */
class dw_Point2D {

    //! X position
    double _x;

    //! Y position
    double _y;
  public:
    /**
     * Constructor, initialize the point to (0,0).
     */
    dw_Point2D() :_x(0),_y(0) {}

    /**
     * Constructor.
     * @param x 
     * @param y 
     */
    dw_Point2D(double x, double y) :_x(x),_y(y) {}

    /**
     * 
     * @return X position.
     */
    double GetX() { return _x;}

    /**
     * 
     * @return Y position.
     */
    double GetY() { return _y;}

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
};

#endif // _dw_Point2D_h
