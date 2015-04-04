Cameras
=======
Two types currently supported - pinhole and finite-aperture cameras.
Each camera has a world-space position, target point (lookat) and an up vector to specify orientation. There is an image plane located at distance given by depth-of-field(dof).
The ImageSample returns a 2D location lying in the range [(xmin,ymin), (xmax, ymax)]on the image plane and this needs to be used to generate a ray. So the ray direction needs to be generated according to the camera coordinates.


Objects and intersection acceleration
=====================================

Object -> primitives like triangle, sphere, cylinders with materials
Aggregrates -> primitives organized together for intersection acceleration

Since Object stores the primitive and the material itself rather than references to them, memory requirement is very high. This can be significantly reduced by storing references to atleast materials in Object

Radiometry
==========
Spectrum class can represent a spectrum with any number of samples. Appropriate functions to convert it into RGBSpectrum/XYZSpectrum is yet to be added.

PathTracingIntegrator (PTIntegrator)
====================================
Termination criterion can be either purely russian-roulette, purely max_depth or both.
<Learning>
A path is generated from camera ray till it is terminated. While generating, the brdf value at each vertex for the generated direction is stored along with appropriate pdfs so that they need not be recomputed again. Now the actual radiance computation is done from the terminal vertex to the eye vertex(camera ray vertex) - because the integrator is iterative instead of recursive. So just compute direct lighting at terminal vertex and just progressively compute complete radiance (direct + indirect) at each of the previous vertices, resulting in final radiance in the eye vertex.
Note: inverting the generated path and then iterating will waste lot of precious computation time in long run. So, use the reverse iterator instead.

Sampling
========
Renderers have samplers attached to it for sampling directions, brdf, etc. As required, call the appropriate sampler which returns a sample and pdf for the sample. The sample is essentially an abstraction that can store any kind of sample - direction, brdf

Material
========
A material consists of a collection of bsdfs and as required returns the appropriate bsdf for a location for sampling and shading.

Random References and points
============================
* Random number generation currently uses Mersenne twister - 
* http://stackoverflow.com/questions/19665818/best-way-to-generate-random-numbers-using-c11-random-library
* http://stackoverflow.com/questions/1046714/what-is-a-good-random-number-generator-for-a-game
* Pre-increment is faster than post-increment http://stackoverflow.com/questions/1077026/incrementing-iterators-it-more-efficient-than-it
* TO TRY: Use intersection details of ray-boundingbox to accelerate calculation of ray-object intersection

Additional Libraries included
=============================
Eigen for math
MiniEXR - https://github.com/aras-p/miniexr
