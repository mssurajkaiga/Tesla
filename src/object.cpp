#include <Tesla/objects/object.h>
#include <Tesla/materials/mattematerial.h>

Object::Object(Material *mat, LightSource* l) : material(mat), lightsource(l) {
	if (lightsource)
		islight = true;
	else
		islight = false;
	setBBox();
}

Object::Object(std::string id, Material *mat, LightSource* l) : id(id), material(mat), lightsource(l) {
	if (lightsource)
		islight = true;
	else
		islight = false;
	setBBox(); 
}

void Object::setMaterial(Material *mat) {
	material = mat;
}

void Object::setId(std::string id) {
	this->id = id;
}

/* to do */
Material* Object::getMaterial(Intersection* inter) const{
	return material;
}

Material* Object::getMaterial() {
	return material;
}

bool Object::isLight() const {
	return islight;
}

LightSource* Object::getLightSource() const {
	return lightsource;
}

BBox* Object::getBBox() {
	return &bbox;
}

std::ostream& operator<<(std::ostream &os, Object &o) {
	if (o.getMaterial())
		return os << "Object(" << o.id << *(o.material) << ", " << o.bbox << "," << o.islight << ")";
	else 
		return os << "Object(" << o.id << ", No Material, " << o.bbox << ")";
}