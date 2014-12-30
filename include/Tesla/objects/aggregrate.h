#ifndef AGGREGRATE_H
#define AGGREGRATE_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>

class Aggregrate
{
public:
	virtual bool intersects(const Ray &ray, Intersection* inter) const = 0;
	virtual BBox* getBBox() = 0;
	virtual void setBBox() = 0;
};

#endif