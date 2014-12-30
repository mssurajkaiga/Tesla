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
};

#endif