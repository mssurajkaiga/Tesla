#ifndef MATERIAL_H
#define MATERIAL_H

#include <Tesla/bsdfs/bsdf.h>
#include <Tesla/core/intersection.h>
#define MAX_BSDFS 10

struct Intersection;

class Material
{
protected:
	BSDF *bsdfs[MAX_BSDFS];
	int nbsdfs;
public:
	Material() : nbsdfs(0) {}
	Material(BSDF *b[], int n = 0);
	void add(BSDF *b);
	inline int getnBSDFs() { return nbsdfs; }
	virtual BSDF* getBSDF(Intersection* inter = NULL) const = 0;
	virtual Spectrum sample(Vector3f &wo, Vector3f &wi, Vector3f &normal, Real &pdf) const = 0; // samples a direction wi from bsdf at a location
	Spectrum eval(Vector3f &wo, Vector3f &wi) const; // evaluates the bsdf at a location between directions wo and wi
	friend std::ostream& operator<<(std::ostream &os, Material &m);
};

#endif