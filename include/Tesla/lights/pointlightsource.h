#ifndef POINTLIGHTSOURCE_H
#define POINTLIGHTSOURCE_H

#include <Tesla/lights/lightsource.h>
#include <Tesla/core/ray.h>

class PointLightSource: public LightSource {
protected:
	Point position;
	Spectrum spectrum;
	Real intensity;

public:
	PointLightSource(Spectrum s = Spectrum(0., 0., 0.), Real i = 0.);
	PointLightSource(const Point position, const Spectrum spectrum = Spectrum(0., 0., 0.), Real intensity = 0.);
	Spectrum getSample(const Point &point, Point &sample, Real &pdf) const;
	Spectrum getIntensity(const Point &point) const;
};

#endif