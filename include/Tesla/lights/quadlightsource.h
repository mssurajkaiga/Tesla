#ifndef QUADLIGHTSOURCE_H
#define QUADLIGHTSOURCE_H

#include <Tesla/lights/lightsource.h>

extern class Quad;
/*
Represents a quadrilateral area light source.
This implementation assumes a uniform area light.
*/

class QuadLightSource : public LightSource{
protected:
	Spectrum spectrum;
	Real intensity;
	Quad* quad;
public:
	QuadLightSource(Spectrum s = Spectrum(1., 1., 1.), Real i = 1.) :LightSource(), spectrum(s), intensity(i) {}
	Spectrum getSample(const Vector3f &point, Point &sample, Real &pdf) const;
	Spectrum getIntensity(const Point &point) const;
};

#endif