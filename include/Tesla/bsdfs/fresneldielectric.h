#ifndef FRESNELDIELECTRIC_H
#define FRESNELDIELECTRIC_H

#include <Tesla/bsdfs/bsdf.h>
#include <Tesla/samplers/cosinesampler.h>

class FresnelDielectric : public BSDF
{
private:
	Spectrum R, T; // reflection, transmission scales
	Real iori, iort; // indices of refraction, absorption coefficient k
	Real reflectance(Real cosi, Real cost) const; // computes Fresnel reflectance for given cosines of incident and transmitted angles
public:
	FresnelDielectric(Spectrum R = Spectrum(0., 0., 0.), Spectrum T = Spectrum(0., 0., 0.), Real iori = 1., Real iort = 1.) : BSDF(std::unique_ptr<CosineSampler>(new CosineSampler), BSDF_SPECULAR_ALL), R(R), T(T), iori(iori), iort(iort) {}
	FresnelDielectric(Spectrum R, Spectrum T, Real iori, Real iort, std::shared_ptr<DirectionSampler> ds, BSDFType type) : BSDF(ds, type), R(R), T(T), iori(iori), iort(iort) {}
	Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const;
	Spectrum eval(Vector3f &wo, Vector3f &wi, Vector3f &normal) const;
};

#endif