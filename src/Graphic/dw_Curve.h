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

  public:
    //! simple Constructor
    dw_Curve() {}

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
