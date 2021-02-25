// Estibaliz Zubimendi
// A79

#pragma once

#include <iostream>
#include <cmath>

class Complejo {
public:
	Complejo() {}
	Complejo(float r, float i) : real(r), imaginaria(i) {}

	Complejo& operator= (Complejo const& other) {
		if (this != &other) {
			real = other.real;
			imaginaria = other.imaginaria;
		}
		return *this;
	}
	Complejo operator+ (Complejo const& c) const {
		return Complejo(real + c.real, imaginaria + c.imaginaria);
	}
	Complejo operator* (Complejo const& c) const {
		return Complejo(real * c.real - imaginaria * c.imaginaria, real * c.imaginaria + c.real * imaginaria);
	}
	float mod() {
		return sqrt(real * real + imaginaria * imaginaria);
	}

private:
	float real, imaginaria;
};