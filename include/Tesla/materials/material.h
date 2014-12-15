#ifndef MATERIAL_H
#define MATERIAL_H

#include <Tesla/core/color.h>

struct Material {
	Color kd;
	Color ks;
	Color ke;
	double specexp;
	double kr;
};

#endif