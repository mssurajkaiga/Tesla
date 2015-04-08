#include <Tesla/lights/trianglemeshlight.h>
#include <Tesla/objects/triangle.h>

Spectrum TriangleMeshLight::getSample(const Vector3f &point, Point &sample, Real &pdf) const {
	if (!cache) {
		generateCache();
	}
	// randomly choose a triangle
	int t = std::rand() % numtriangles;
	// now sample a location on the chosen triangle
	cache[t].getSample(point, sample, pdf);
	pdf /= numtriangles;
	return lightsource->getIntensity(point);
}