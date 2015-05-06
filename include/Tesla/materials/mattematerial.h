#ifndef MATTEMATERIAL_H
#define MATTEMATERIAL_H

#include <Tesla/materials/material.h>

class MatteMaterial : public Material {
public:
	MatteMaterial(Spectrum R = Spectrum(1.0, 1.0, 1.0));
	MatteMaterial(BSDF* bsdf[], int n = 0) : Material(bsdf, n) {}
	Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const;
	BSDF* getBSDF(Intersection* inter) const;
};

#endif