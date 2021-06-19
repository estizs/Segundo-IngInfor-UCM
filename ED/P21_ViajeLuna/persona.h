// A79
#pragma once

#include <iostream>

class Persona {
public:
	Persona(){}
	Persona(int e, std::string n) : edad(e), nombre(n) {}

	int get_edad() const { return edad; }

	std::string get_nombre() const { return nombre; }
private:
	int edad;
	std::string nombre;
};