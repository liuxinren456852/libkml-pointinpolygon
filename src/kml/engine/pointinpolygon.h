//
//  pointinpolygon.h
//  LibKML
//
//  Created by G, Raj Pawan (external) on 5/6/13.
//
//

#ifndef LibKML_pointinpolygon_h
#define LibKML_pointinpolygon_h

#include <assert.h>
#include <iostream>
#include <string>

#include "kml/base/vec3.h"
#include "kml/dom.h"

using kmlbase::Vec3;
using kmldom::CoordinatesPtr;
using kmldom::ElementPtr;
using kmldom::LinearRingPtr;
using kmldom::OuterBoundaryIsPtr;
using kmldom::PointPtr;
using kmldom::PolygonPtr;
using std::cout;
using std::endl;

bool IsPointInKMLPolygon(const char *filePath, kmldom::PointPtr& point);

// Returns Negative floating point value if the point is inside the polygon. Otherwise it returns the shortest distance to the polygon
float DistanceToPolygon(const char *filePath, kmldom::PointPtr& point);

#endif
