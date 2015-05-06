#include <Tesla/bsdfs/fresneldielectric.h>
#include <cmath>
#include <Tesla/core/randomizer.h>

Real FresnelDielectric::reflectance(Real cosi, Real cost) const {
	Real r1 = (iort * cosi - iori * cost) / (iort * cosi + iori * cost);
	Real r2 = (iori * cosi - iort * cost) / (iori * cosi + iort * cost);
	return (r1*r1 + r2*r2) * 0.5;
}

Spectrum FresnelDielectric::sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const {
	if (!getType().isSpecular())
		return Spectrum(0., 0., 0.);

	Real cosi = wo.normalized().dot(normal.normalized());
	Real sini = sqrtf(std::max(0., 1. - cosi * cosi));
	Real sint, cost, r;

	if (cosi > 0.) {
		sint = iori / iort * sini;		
	}
	else {
		sint = iort / iori * sini;
	}

	if (sint >= 1.) {
		r = 1.; // total internal reflection
	}
	else {
		cost = sqrtf(std::max(0., 1. - sint * sint));
		r = reflectance(fabs(cosi), cost);
	}
	
	pdf = 1.;
	if (getType().isReflective()){
		wi = -2 * wo.dot(normal) * normal + wo;
		return r * R / fabs(cosi);
		/*
		if (getType().isTransmissive()){
			// both transmissive and reflective
			if (ung.generateRandom() < r) {
				wi = - 2 * wo.dot(normal) * normal + wo;	
				return r * R / fabs(cosi);
			}
		}
		else {

		}
		*/
	}
}

Spectrum FresnelDielectric::eval(Vector3f &wo, Vector3f &wi) const {
	return Spectrum(0., 0., 0.);
}