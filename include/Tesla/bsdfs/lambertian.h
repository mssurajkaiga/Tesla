#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <Tesla/bsdfs/bsdf.h>
#include <Tesla/samplers/cosinesampler.h>

class Lambertian: public BSDF
{
private:
	Spectrum R;

public:
	Lambertian(Spectrum r) : BSDF(std::unique_ptr<CosineSampler>(new CosineSampler), BSDF_DIFFUSE_REFLECTION), R(r) {}
	Lambertian(Spectrum r, std::shared_ptr<DirectionSampler> ds) : BSDF(ds, BSDF_DIFFUSE_REFLECTION), R(r) {}
	Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const;
	Spectrum eval(Vector3f &wo, Vector3f &wi, Vector3f &normal) const;
};

#endif