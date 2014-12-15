#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <Tesla/lights/light.h>
#include <Tesla/core/ray.h>

class PointLight: public Light {
private:
	Vector3f position;
	Color color;
	double intensity;

public:
	PointLight();
	PointLight(const Vector3f &pos, const Vector3f &col, double inten);
	Color getSample(const Vector3f point, Vector3f *wi);
};

#endif