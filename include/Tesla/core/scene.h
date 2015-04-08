#ifndef SCENE_H
#define SCENE_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>
#include <Tesla/lights/lightsource.h>
#include <Tesla/objects/aggregrate.h>

class Scene
{
public:
	Aggregrate* aggregrate;

	Scene();
	bool intersects(const Ray &ray, Intersection* inter = NULL) const;
	LightSource* getLightSource(Real &pdf); // sample an independent light source
	Object* getLight(Real &pdf); // sample an object light

	void add(Object *obj);
	void add(LightSource *light);
};

#endif