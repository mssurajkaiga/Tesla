#include <Tesla/core/scene.h>
#include <Tesla/objects/simpleaggregrate.h>
#include <Tesla/core/randomizer.h>

Scene::Scene(std::vector<Object*> o, std::vector<Light*> l) : lights(l) {
	lpdf = 1. / lights.size();
	this->buildKdtree(o, l);
}

bool Scene::intersects(const Ray &ray, Intersection *inter) const {
	return aggregrate->intersects(ray, inter);
}

void Scene::buildKdtree(std::vector<Object*> o, std::vector<Light*>  l) {
	/* 
	todo - build kdtree and set it to aggregrate pointer
	for now, use simple aggregrate
	*/
	aggregrate = new SimpleAggregrate(o, l);
}

Light* Scene::getLight(Real &pdf) {
	pdf = lpdf;
	return lights[rand() % lights.size()];
}