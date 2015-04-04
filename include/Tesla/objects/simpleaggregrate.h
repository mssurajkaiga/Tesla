#ifndef SIMPLEAGGREGRATE_H
#define SIMPLEAGGREGRATE_H

#include <Tesla/objects/aggregrate.h>
#include <Tesla/lights/light.h>

/* Simple Aggregrate: simple storage of objects or lights without any acceleration techniques
   ---Only for testing purposes---
   to do - move to different directory for acceleration along with aggregrate class
*/
class SimpleAggregrate : public Aggregrate {
private:
	std::vector<Object*> objects;
	std::vector<Light*> lights;
public:
	SimpleAggregrate();
	~SimpleAggregrate() { printf("SA destroyed\n"); }
	SimpleAggregrate(std::vector<Object*> o) : objects(o) { setBBox(); }
	SimpleAggregrate(std::vector<Object*> o, std::vector<Light*> l) : objects(o), lights(l) { setBBox(); }
	bool intersects(const Ray &ray, Intersection* inter);
	BBox* getBBox();
	void setBBox();
	void setBBox(Object* object);
	void add(Object* object);
	void add(Light* light);
};

#endif