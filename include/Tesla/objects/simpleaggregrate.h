#ifndef SIMPLEAGGREGRATE_H
#define SIMPLEAGGREGRATE_H

#include <Tesla/objects/aggregrate.h>
#include <Tesla/lights/lightsource.h>

/* Simple Aggregrate: simple storage of objects or lightsources without any acceleration techniques
   ---Only for testing purposes---
   to do - move to different directory for acceleration along with aggregrate class
*/
class SimpleAggregrate : public Aggregrate {
protected:
	std::vector<Object*> objects;
	std::vector<Object*> lights;
	std::vector<LightSource*> lightsources; // for independent light-sources like pointlightsource
public:

	SimpleAggregrate() {}
	SimpleAggregrate(std::vector<Object*> o) : objects(o) { setBBox(); }
	SimpleAggregrate(std::vector<Object*> o, std::vector<LightSource*> l) : objects(o), lightsources(l) { setBBox(); }
	bool intersects(const Ray &ray, Intersection* inter);
	BBox* getBBox();
	void setBBox();
	void setBBox(Object* object);
	void add(Object* object);
	void add(LightSource* lightsource);
	int getNumObjects() const;
	int getNumLights() const;
	int getNumLightSources() const;
	LightSource* getLightSource(Real &pdf) const;
	Object* getLight(Real &pdf) const;
};

#endif