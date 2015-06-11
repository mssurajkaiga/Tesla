#ifndef BSDF_H
#define BSDF_H

#include <Tesla/core/core.h>
#include <Tesla/core/spectrum.h>
#include <Tesla/bsdfs/bsdftype.h>
#include <Tesla/samplers/directionsampler.h>

class BSDF
{
protected:
	BSDFType type;
	std::shared_ptr<DirectionSampler> directionsampler;

public:
	BSDF(std::shared_ptr<DirectionSampler> ds, BSDFType t) : directionsampler(ds), type(t) {}
	inline BSDFType getType() const { return type; }
	virtual Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const = 0; // samples a direction wi from the brdf at a location
	virtual Spectrum eval(Vector3f &wo, Vector3f &wi, Vector3f &normal) const = 0; // evaluates the brdf at a location between directions wo and wi
	inline friend std::ostream& operator<<(std::ostream &os, BSDF &b) {
		return os << b.type;
	}
};

#endif