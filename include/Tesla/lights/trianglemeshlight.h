#ifndef TRIANGLEMESHLIGHT_H
#define TRIANGLEMESHLIGHT_H

#include <Tesla/objects/trianglemesh.h>
#include <Tesla/lights/pointlightsource.h>

/*
Represents a triangle mesh light.
Currently supports a uniform light emission by modeling it as a mesh composed of infinite point lights on surface.
todo - add support for textured lights and complex light distributions
*/
class TriangleMeshLight : public TriangleMesh {

public:
	TriangleMeshLight(int nv = 0, int nt = 0, int *ind = NULL, Vertex *ver = NULL, Spectrum s = Spectrum(1., 1., 1.), Real i = 1.) : TriangleMesh(nv, nt, ind, ver, NULL, new PointLightSource(s, i)) {}
	Spectrum getSample(const Point &point, Point &sample, Real &pdf) const;
};

#endif