#ifndef LIGHT_H
#define LIGHT_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>

/*
Represents a light which uses geometric routines from object.
*/
class Light : public Object
{
public:

	Light() : Object(NULL, true) {}
	virtual bool intersects(const Ray &ray, Intersection* inter) const { return false; };
	/* Change it to support spectrum class */
	virtual Spectrum getSample(const Vector3f &point, Vector3f &wi, Real &pdf) const = 0;
	virtual Spectrum getIntensity(const Point &p) const = 0;
	void setBBox();
	friend std::ostream& operator<<(std::ostream &os, Light &l);

};

#endif