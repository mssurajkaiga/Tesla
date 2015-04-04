#include <Tesla/bsdfs/lambertian.h>

Spectrum Lambertian::sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const {
	directionsampler->getDirectionSample(wi, pdf);
	wi = Quaternionf().setFromTwoVectors(Vector3f(0., 0., 1.), normal).toRotationMatrix() * wi;
	return this->R * PI_INV;
}

Spectrum Lambertian::eval(Vector3f &wo, Vector3f &wi) const {
		return this->R * PI_INV;
}