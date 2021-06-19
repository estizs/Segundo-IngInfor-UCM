#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stdexcept>

using DNI = std::string;

class carnet_puntos {
private:
	std::unordered_map<DNI, int> conductores;
	std::unordered_map<int, int> puntos_conductores;
public:
	void nuevo(DNI dni) {
		auto it = conductores.find(dni);
		if (it != conductores.end())
			throw std::domain_error("Conductor duplicado");
		conductores.insert({ dni, 15 });
		auto a = puntos_conductores.find(15);
		if (a == puntos_conductores.end())
			puntos_conductores.insert({ 15, 1 });
		else
			++a->second;
	}

	void quitar(DNI dni, int puntos) {
		auto it = conductores.find(dni);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");
		auto a = puntos_conductores.find(it->second);
		--a->second;
		it->second = std::max(0, it->second - puntos);
		auto b = puntos_conductores.find(it->second);
		if (b == puntos_conductores.end())
			puntos_conductores.insert({ it->second, 1 });
		else
			++b->second;
	}

	int consultar(DNI dni) {
		auto it = conductores.find(dni);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");
		return it->second;
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos > 15)
			throw std::domain_error("Puntos no validos");
		auto it = puntos_conductores.find(puntos);
		if (it == puntos_conductores.end())
			return 0;
		else return it->second;
	}

};