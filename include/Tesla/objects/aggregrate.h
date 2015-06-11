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
	bool destroyattached; // if true, then destroy all attached objects and lights when scene is destroyed

public:
	Aggregrate(bool d = false) : destroyattached(d) {}
	virtual bool intersects(const Ray &ray, Intersection* inter) = 0;
	BBox* getBBox() { return &bbox; }
	virtual void setBBox() = 0;
	virtual void add(Object *object) = 0;
	virtual void add(LightSource* lightsource) = 0;
	virtual int getNumObjects() const { return 0; }
	virtual int getNumLights() const { return 0; }
	virtual int getNumLightSources() const { return 0; }
	virtual LightSource* getLightSource(Real &pdf) const { return NULL; }
	virtual Object* getLight(Real &pdf) const { return NULL; }
};

#endif