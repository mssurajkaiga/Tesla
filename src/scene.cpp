#include <Tesla/core/scene.h>

Scene::Scene(std::vector<Object*> objects, std::vector<Light*> lights) {
	this->buildKdtree(objects);
	this->lights = lights;
}

void Scene::buildKdtree(std::vector<Object*> objects) {
	// build kdtree and set it to aggregrate pointer
}