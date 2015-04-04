#ifndef PTINTEGRATOR_H
#define PTINTEGRATOR_H

#include <Tesla/integrators/surfaceintegrator.h>
#include <Tesla/integrators/path.h>

enum TerminationCriterion {
		RUSSIAN_ROULETTE, MAX_DEPTH, BOTH
	};

class PTIntegrator : public SurfaceIntegrator
{
public:
	PTIntegrator(TerminationCriterion tc, int md);

	int max_depth;
	TerminationCriterion tc;

	Spectrum getRadiance(Ray *ray, Intersection *isect, Scene *scene, Renderer *renderer, ImageSample *imagesample) const;
	Path generatePath(Ray *ray, Scene *scene) const;
};

#endif