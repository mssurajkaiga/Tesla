#include <Tesla/lights/light.h>

void Light::setBBox() { 
	bbox = BBox(Point(0., 0., 0.), Point(0., 0., 0.)); 
}

std::ostream& operator<<(std::ostream &os, Light &l) {
	return os << "Light(" << l.bbox << ")";
}