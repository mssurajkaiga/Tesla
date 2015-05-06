#include <Tesla/materials/mirrormaterial.h>
#include <Tesla/bsdfs/fresneldielectric.h>

MirrorMaterial::MirrorMaterial(Spectrum R) {
	bsdfs[0] = new FresnelDielectric(R);
	nbsdfs = 1;
}

Spectrum MirrorMaterial::sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const {
	return bsdfs[0]->sample(wo, wi, normal, pdf);
}

BSDF* MirrorMaterial::getBSDF(Intersection* inter) const {
	return bsdfs[0];
}