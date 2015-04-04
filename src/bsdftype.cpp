#include <Tesla/bsdfs/bsdftype.h>
#include <string>

BSDFType::BSDFType() {
	type = BSDF_DIFFUSE_REFLECTION;
}

bool BSDFType::hasType(Type t) {
	return (type & t);
}

bool BSDFType::isDiffuse() {
	return hasType(BSDF_DIFFUSE);
}

bool BSDFType::isSpecular() {
	return hasType(BSDF_SPECULAR);
}

bool BSDFType::isGlossy() {
	return hasType(BSDF_GLOSSY);
}

bool BSDFType::isReflective() {
	return hasType(BSDF_REFLECTION);
}

bool BSDFType::isTransmissive() {
	return hasType(BSDF_TRANSMISSION);
}

std::ostream& operator<<(std::ostream &os, BSDFType &b) {
	std::string typestring;
	if (b.isDiffuse())
		typestring.append("DIFFUSE ");
	if (b.isGlossy())
		typestring.append("GLOSSY ");
	if (b.isSpecular())
		typestring.append("SPECULAR ");
	if (b.isReflective())
		typestring.append("REFLECTIVE ");
	if (b.isTransmissive())
		typestring.append("TRANSMISSIVE ");
	return os << typestring;
}