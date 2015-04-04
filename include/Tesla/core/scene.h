#ifndef SCENE_H
#define SCENE_H

#include <Tesla/core/core.h>
#include <Tesla/objects/object.h>
#include <Tesla/lights/light.h>
#include <Tesla/objects/aggregrate.h>

class Scene
{
protected:
	Real lpdf;
public:
	Aggregrate* aggregrate;
	std::vector<Light*> lights;

	Scene(std::vector<Object*> objects, std::vector<Light*> lights);
	void buildKdtree(std::vector<Object*> objects);
	void buildKdtree(std::vector<Object*> objects, std::vector<Light*> lights); // to be deprecated

	bool intersects(const Ray &ray, Intersection* inter = NULL) const;
	Light* getLight(Real &pdf); // sample a light
};

#endif