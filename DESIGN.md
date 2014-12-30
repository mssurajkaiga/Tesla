Objects and intersection acceleration
=====================================

Object -> primitives like triangle, sphere, cylinders with materials
Aggregrates -> primitives organized together for intersection acceleration

Since Object stores the primitive and the material itself rather than references to them, memory requirement is very high. This can be significantly reduced by storing references to atleast materials in Object

