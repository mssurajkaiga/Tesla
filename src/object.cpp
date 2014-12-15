#include <Tesla/objects/object.h>

Object::Object() {
	/*
	material = NULL;
	bbox = NULL;
	*/
}

Material* Object::getMaterial() {
	return &material;
}

bool Object::isLight() const {
	/* If the object has emmitive coefficient in any direction, it is a light */
	Color ke = getMaterial()->ke;
	if (ke[0] > 0.0 || ke[1] > 0.0 || ke[2] > 0.0) {
		return true;
	}

	return false;
}

BBox* Object::getBBox() {
	return &bbox;
}