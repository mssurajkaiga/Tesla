#ifndef COSINESAMPLER_H
#define COSINESAMPLER_H

#include <Tesla/samplers/directionsampler.h>

/* 
   Generates a cosine-weighted sampling of directions at (0,0,0)
   with normal facing in the direction (0,0,1)
   Transform accordingly after generating direction
*/
class CosineSampler : public DirectionSampler {
public:
	void getDirectionSample(Vector3f &direction, Real &pdf) const;
};

#endif