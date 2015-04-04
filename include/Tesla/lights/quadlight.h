#ifndef QUADLIGHT_H
#define QUADLIGHT_H

#include <Tesla/lights/light.h>
#include <Tesla/objects/quad.h>

/*
Represents a quadrilateral area light.
This implementation assumes a uniform area light.
*/

class QuadLight : public Light{
protected:
	Spectrum spectrum;
	Real intensity;
public:
	QuadLight(Point a, Point b, Point c, Point d, Spectrum s = Spectrum(1., 1., 1.), Real i = 1.) :Light(), Quad(a, b, c, d, NULL, true), spectrum(s), intensity(i) {}
	Spectrum getSample(const Vector3f &point, Vector3f &wi, Real &pdf) const;
	Spectrum getIntensity(const Point &point) const;
	bool intersects(const Ray &ray, Intersection* inter) const;
};

#endif