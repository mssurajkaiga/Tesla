#ifndef SURFACEINTEGRATOR_H
#define SURFACEINTEGRATOR_H

#include <Tesla/integrators/integrator.h>
#include <Tesla/core/spectrum.h>
#include <Tesla/renderers/renderer.h>
#include <Tesla/core/intersection.h>

class SurfaceIntegrator: public Integrator
{
public:
	virtual Spectrum getRadiance(Ray *ray, Intersection *isect, Scene *scene, Renderer *renderer, ImageSample *imagesample) const = 0;
};

#endif