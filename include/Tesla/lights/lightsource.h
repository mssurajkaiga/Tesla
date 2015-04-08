#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <Tesla/core/core.h>
//#include <Tesla/objects/object.h>

/*
Represents a light source.
A light source can be attached with an object to form a light.
*/
class LightSource
{
public:
	LightSource() {}
	virtual Spectrum getSample(const Vector3f &point, Point &sample, Real &pdf) const = 0;
	virtual Spectrum getIntensity(const Point &p) const = 0;
};

#endif