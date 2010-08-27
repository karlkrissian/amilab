//
// C++ Interface: LinearColorMap
//
// Description: Colormap with interpolation between points
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _LinearColorMap_h_
#define _LinearColorMap_h_

#include <vector>

/// position+color
class LinearColorMapPoint
{
  double pos;
  wxColour colour;

public:
  LinearColorMapPoint( const double& p=0, const wxColour& c = *wxBLACK ) {
    pos = p;
    colour = c;
  }

  void SetPosition(const double& position)
  {
    pos = position;
  }

  double GetPosition() const { return pos; }

  void SetColour(const wxColour& c)
  {
    colour = c;
  }

  wxColour GetColour() const { return colour; }
};

/// This class contains a list of position with RGB colors
class LinearColorMap
{
  std::vector<LinearColorMapPoint> points;

public:
  LinearColorMap() {}

  void AddPoint( const LinearColorMapPoint& cmpt)
  {
    points.push_back(cmpt);
  }

  LinearColorMapPoint& GetPoint( int index)
  {
    return points[index];
  }

  int size() const
  {
    return points.size();
  }

  void clear()
  {
    points.clear();
  }
};

#endif // _LinearColorMap_h_
