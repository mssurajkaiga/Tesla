#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <Tesla/core/core.h>
#include <Tesla/bsdfs/bsdf.h>
#include <Tesla/samplers/cosinesampler.h>

class Lambertian: public BSDF
{
public:
	Lambertian(Spectrum r) : BSDF(new CosineSampler, BSDF_DIFFUSE_REFLECTION), R(r) {}
	Lambertian(Spectrum r, DirectionSampler *ds) : BSDF(ds, BSDF_DIFFUSE_REFLECTION), R(r) {}
	Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const;
	Spectrum eval(Vector3f &wo, Vector3f &wi) const;

private:
	Spectrum R;
};

#endif