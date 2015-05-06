#ifndef MIRRORMATERIAL_H
#define MIRRORMATERIAL_H

#include <Tesla/materials/material.h>

class MirrorMaterial : public Material {
public:
	MirrorMaterial(Spectrum R = Spectrum(1.0, 1.0, 1.0));
	MirrorMaterial(BSDF* bsdf[], int n = 0) : Material(bsdf, n) {}
	Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const;
	BSDF* getBSDF(Intersection* inter) const;
};

#endif