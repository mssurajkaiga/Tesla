#ifndef AGGREGRATE_H
#define AGGREGRATE_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>
#include <Tesla/objects/bbox.h>


/*
Represents an aggregration of objects and intersectable lights.
All acceleration structures derive from this.
*/
class Aggregrate
{
protected:
	BBox bbox;
public:
	virtual bool intersects(const Ray &ray, Intersection* inter) = 0;
	BBox* getBBox() { return &bbox; }
	virtual void setBBox() = 0;
};

#endif