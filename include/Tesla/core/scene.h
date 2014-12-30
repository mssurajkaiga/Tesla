#ifndef SCENE_H
#define SCENE_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>
#include <Tesla/lights/light.h>
#include <Tesla/objects/aggregrate.h>

class Scene
{
public:
	Aggregrate* objects;
	std::vector<Light*> lights;

	Scene(std::vector<Object*> objects, std::vector<Light*> lights);
	void buildKdtree(std::vector<Object*> objects);
};

#endif