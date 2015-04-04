#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <Tesla/lights/light.h>
#include <Tesla/core/ray.h>

class PointLight: public Light {
private:
	Vector3f position;
	Spectrum spectrum;
	Real intensity;

public:
	PointLight();
	PointLight(const Vector3f position, const Spectrum spectrum, Real intensity);
	Spectrum getSample(const Vector3f &point, Vector3f &wi, Real &pdf) const;
	Spectrum getIntensity(const Point &point) const;
};

#endif