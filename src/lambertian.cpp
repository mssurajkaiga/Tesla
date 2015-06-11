#include <Tesla/bsdfs/lambertian.h>

Spectrum Lambertian::sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const {
	directionsampler->getDirectionSample(wi, pdf);
	wi = Quaternionf().setFromTwoVectors(Vector3f(0., 0., 1.), normal).toRotationMatrix() * wi;
	return eval(wo, wi, normal);
}

Spectrum Lambertian::eval(Vector3f &wo, Vector3f &wi, Vector3f &normal) const {
	// check if -wo and wi lie on the same side of the normal
	//if ((-wo).dot(normal) > 0. && wi.dot(normal) > 0.)
		return R * PI_INV;
	//else
		//return Spectrum(0., 0., 0.);
}