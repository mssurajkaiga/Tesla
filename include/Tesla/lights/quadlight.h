#ifndef QUADLIGHT_H
#define QUADLIGHT_H

#include <Tesla/lights/trianglemeshlight.h>

/*
Represents a quadrilateral area light.
This implementation assumes a uniform area light.
*/

class QuadLight : public TriangleMeshLight{
public:
	QuadLight(Point a, Point b, Point c, Point d, Spectrum s = Spectrum(1., 1., 1.), Real i = 1.);
};

#endif