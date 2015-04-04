#include <Tesla/samplers/cosinesampler.h>
#include <Tesla/core/randomizer.h>

void CosineSampler::getDirectionSample(Vector3f &direction, Real &pdf) const {
	const Real r2 = ung.generateRandom();
	const Real r = sqrt(r2);
	const Real theta = 2 * PI * ung.generateRandom();

	direction(0) = r * cos(theta);
	direction(1) = r * sin(theta);
	direction(2) = 1 - r2;

	pdf = PI_INV * direction.dot(Vector3f(0., 0., 1.));
}