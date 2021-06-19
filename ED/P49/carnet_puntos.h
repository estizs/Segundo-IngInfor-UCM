#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stdexcept>

using DNI = std::string;
struct info_conductores {
	int puntos;
	std::list<DNI>::iterator it;
};

class carnet_puntos {
private:
	std::unordered_map<DNI, info_conductores> conductores;
	std::unordered_map<int, std::list<DNI>> puntos_conductores;
public:
	void nuevo(DNI dni) {
		// buscamos si existe el dni
		auto it = conductores.find(dni);
		if (it != conductores.end())
			throw std::domain_error("Conductor duplicado");
		// insertamos en los puntos el nuevo dni
		auto a = puntos_conductores.find(15);
		// si no existe creamos
		if (a == puntos_conductores.end())
			puntos_conductores.insert({ 15, {dni} });
		else
			// si existe lo insertamos al comienzo
			a->second.push_front(dni);
		// se ha insertado al comienzo de la lista
		conductores.insert({ dni, {15, puntos_conductores[15].begin()} });
	}

	void quitar(DNI dni, int puntos) {
		// buscamos si existe el conductor
		auto it = conductores.find(dni);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");
		if (std::max(0, it->second.puntos - puntos) != it->second.puntos) {
			// hay que eliminar de la lista de puntos el conductor
			auto a = puntos_conductores.find(it->second.puntos);
			// eliminar
			a->second.erase(it->second.it);
			// actualizamos los nuevos puntos
			it->second.puntos = std::max(0, it->second.puntos - puntos);
			// buscamos en los puntos los nuevos puntos
			auto b = puntos_conductores.find(it->second.puntos);
			// si los puntos no existen lo creamos e insertamos el dni
			if (b == puntos_conductores.end())
				puntos_conductores.insert({ it->second.puntos, {dni} });
			// si existen lo insertamos al comienzo de la lista
			else
				b->second.push_front(dni);
			// actualizamos el iterador del conductor
			it->second.it = puntos_conductores[it->second.puntos].begin();
		}
	}

	void recuperar(DNI dni, int puntos) {
		// buscamos en los conductores el del dni
		auto it = conductores.find(dni);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");
		if (std::min(15, it->second.puntos + puntos) != it->second.puntos) {
			// buscamos en los puntos los puntos de ese conductor
			auto a = puntos_conductores.find(it->second.puntos);
			// restamos el número de conductores de los puntos
			a->second.erase(it->second.it);
			// actualizamos los puntos del conductor
			it->second.puntos = std::min(15, it->second.puntos + puntos);
			// buscamos en los puntos los nuevos puntos del conductor
			auto b = puntos_conductores.find(it->second.puntos);
			if (b == puntos_conductores.end())
				puntos_conductores.insert({ it->second.puntos, {dni} });
			else
				b->second.push_front(dni);
			// actualizamos el iterador del conductor
			it->second.it = puntos_conductores[it->second.puntos].begin();
		}
		
	}

	int consultar(DNI dni) {
		auto it = conductores.find(dni);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");
		return it->second.puntos;
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos > 15)
			throw std::domain_error("Puntos no validos");
		auto it = puntos_conductores.find(puntos);
		if (it == puntos_conductores.end())
			return 0;
		else return it->second.size();
	}

	std::list<DNI> lista_por_puntos(int puntos) {
		if (puntos < 0 || puntos > 15)
			throw std::domain_error("Puntos no validos");
		auto it = puntos_conductores.find(puntos);
		std::list<DNI> lista;
		if (it == puntos_conductores.end())
			return lista;
		return it->second;
	}
};