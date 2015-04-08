#include <Tesla/core/scene.h>
#include <Tesla/objects/simpleaggregrate.h>
#include <Tesla/core/randomizer.h>

Scene::Scene() {
	/* 
	todo - build kdtree and set it to aggregrate pointer
	for now, use simple aggregrate
	*/
	aggregrate = new SimpleAggregrate;
}

bool Scene::intersects(const Ray &ray, Intersection *inter) const {
	return aggregrate->intersects(ray, inter);
}

LightSource* Scene::getLightSource(Real &pdf) {
	return aggregrate->getLightSource(pdf);
}

Object* Scene::getLight(Real &pdf) {
	return aggregrate->getLight(pdf);
}

void Scene::add(Object *obj) {
	aggregrate->add(obj);
}

void Scene::add(LightSource *light){
	aggregrate->add(light);
}