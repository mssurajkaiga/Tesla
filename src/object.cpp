#include <Tesla/objects/object.h>
#include <Tesla/materials/mattematerial.h>

void Object::setMaterial(Material *mat) {
	material = mat;
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

BBox* Object::getBBox() {
	return &bbox;
}

std::ostream& operator<<(std::ostream &os, Object &o) {
	if (o.getMaterial())
		return os << "Object(" << *(o.material) << ", " << o.bbox << "," << o.islight << ")";
	else 
		return os << "Object(No Material, " << o.bbox << ")";
}