#include <Tesla/materials/mattematerial.h>

MatteMaterial::MatteMaterial(Spectrum R) {
	Lambertian l(R);
	bsdfs[0] = &l;
	nbsdfs = 1;
}

Spectrum MatteMaterial::sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const {
	return bsdfs[0]->sample(wo, wi, normal, pdf);
}

BSDF* MatteMaterial::getBSDF(Intersection* inter) const {
	return bsdfs[0];
}