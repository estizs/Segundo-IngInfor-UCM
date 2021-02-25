#pragma once

#include "horas.h"

#include <iostream>
#include <string>

class Pelicula {
public:
	Pelicula() {}
	Pelicula(Horas d, Horas c, Horas f, std::string n) : duracion(d), comienzo(c), fin(f), nombre(n) {}

	Horas get_duracion() const { return duracion; };
	Horas get_comienzo() const { return comienzo; };
	Horas get_fin() const { return fin; };
	std::string get_nombre() const { return nombre; };

	Pelicula& operator= (Pelicula const& other) {
		if (this != &other) {
			duracion = other.duracion;
			comienzo = other.comienzo;
			fin = other.fin;
			nombre = other.nombre;
		}
		return *this;
	}
	bool operator< (Pelicula const& other) {
		if (fin < other.fin) return true;
		else if (fin > other.fin) return false;
		else {
			if (nombre < other.nombre) return true;
			else return false;
		}
	}
	bool operator== (Pelicula const& other) {
		return fin == other.fin && nombre == other.nombre;
	}
	bool operator<= (Pelicula const& other) {
		return fin < other.fin || fin == other.fin;
	}

private:
	Horas duracion, comienzo, fin;
	std::string nombre;
};

inline std::ostream& operator<< (std::ostream& out, Pelicula const& p) {
	out << p.get_fin() << p.get_nombre();
	return out;
}
inline std::istream& operator>> (std::istream& in, Pelicula& p) {
	Horas d, c;
	std::string n;
	in >> d >> c;
	std::getline(std::cin,n);
	p = Pelicula(d, c, d + c, n);
	return in;
}