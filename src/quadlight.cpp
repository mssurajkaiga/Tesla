#include <Tesla/lights/quadlight.h>

Spectrum QuadLight::getSample(const Vector3f &point, Vector3f &wi, Real &pdf) const {
	// to do - implement area function for trianglemesh/quad and use it for pdf here
	return Spectrum(0., 0., 0.);
}

Spectrum QuadLight::getIntensity(const Point &point) const {
	return spectrum * intensity;
}

bool QuadLight::intersects(const Ray &ray, Intersection* inter) const {
	return Quad::intersects(ray, inter);
}