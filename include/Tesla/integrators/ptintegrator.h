#ifndef PTINTEGRATOR_H
#define PTINTEGRATOR_H

#include <Tesla/integrators/surfaceintegrator.h>
#include <Tesla/integrators/path.h>

class PTIntegrator : public SurfaceIntegrator
{
public:
	PTIntegrator(int min_depth = 1, int max_depth = 10, TerminationCriterion tc = MAX_DEPTH, Illumination i = GLOBAL);

	int min_depth, max_depth;
	TerminationCriterion tc;
	Illumination illumination;

	Spectrum getRadiance(Ray *ray, Intersection *isect, Scene *scene, Renderer *renderer, ImageSample *imagesample) const;
	Path generatePath(Ray *ray, Scene *scene) const;
};

#endif