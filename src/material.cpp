#include <Tesla/materials/material.h>

Material::Material(BSDF *b[], int n) : nbsdfs(n) {
	for (int i = 0; i < n; ++i) {
		bsdfs[i] = b[i];
	}
}

void Material::add(BSDF *b) {
	if (nbsdfs < MAX_BSDFS) {
		bsdfs[nbsdfs++] = b;
	}
}

Spectrum Material::eval(Vector3f &wo, Vector3f &wi, Vector3f &normal) const{
	Spectrum f(0., 0., 0.);
	for (int i = 0; i < nbsdfs; ++i) {
		f += bsdfs[i]->eval(wo, wi, normal);
	}
	return f;
}

std::ostream& operator<<(std::ostream &os, Material &m){
	os << "Material(" << m.nbsdfs << ", ";
	for (int i = 0; i < m.nbsdfs; ++i) {
		os << *(m.bsdfs[i]) << ", ";
	}
	os << ")";
	return os;
}