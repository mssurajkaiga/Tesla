#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

class Randomizer {
public:
	Randomizer(Real b, Real e): begin(b), end(e){
		generator = new std::mt19937(rd());
		distribution = new std::uniform_real_distribution<Real>(begin, end);
	}
	~Randomizer() {
		if (generator)
			delete generator;
		if (distribution)
			delete distribution;
	}

	inline Real generateRandom() {
		return (*distribution)(*generator);
	}

private:
	const Real begin, end;
	std::random_device rd;
	std::mt19937 *generator; // Mersenne twister based random number generator
	std::uniform_real_distribution<Real> *distribution;
};

static Randomizer ung(0, 1); /* uniform number generator between 0. and 1.)*/

#endif