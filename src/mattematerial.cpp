#include <Tesla/materials/mattematerial.h>
#include <Tesla/bsdfs/lambertian.h>

MatteMaterial::MatteMaterial(Spectrum R) {
	bsdfs[0] = new Lambertian(R);
	nbsdfs = 1;
}

Spectrum MatteMaterial::sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const {
	return bsdfs[0]->sample(wo, wi, normal, pdf);
}

BSDF* MatteMaterial::getBSDF(Intersection* inter) const {
	return bsdfs[0];
}