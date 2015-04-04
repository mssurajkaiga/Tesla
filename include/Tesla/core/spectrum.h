#ifndef SPECTRUM_H
#define SPECTRUM_H
#define NSAMPLES 1000

#include <Eigen/Dense>
using namespace Eigen;

typedef ArrayXf GeneralSpectrum;
typedef Array3f RGBSpectrum;
typedef RGBSpectrum Spectrum; /* modify as per need to choose appropriate representations */

inline std::ostream& operator<<(std::ostream &os, Spectrum &a) {
	return os << "Spectrum(" << a(0) << ", " << a(1) << ", " << a(2) << ")";
}

#endif