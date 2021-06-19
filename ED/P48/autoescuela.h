#pragma once

#include <iostream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <vector>

using nombre = std::string;
struct info_alumno {
	int puntos;
	nombre profe;
};

class autoescuela {
private:
	std::unordered_map<nombre, info_alumno> alumnos;
	std::unordered_map<nombre, std::map<nombre, int>> profes;
public:
	// constructora
	autoescuela() {}

	void alta(nombre alumno, nombre profe) {
		// busco al alumno
		auto a = alumnos.find(alumno);
		// busco al profe
		auto p = profes.find(profe);
		// si el alumno no existe
		if (a == alumnos.end()) {
			// se inserta el nuevo alumno en el mapa de alumnos
			alumnos.insert({ alumno, { 0, profe } });
			// si el profe no existe
			if (p == profes.end())
				// se inserta el nuevo profe en el mapa de profes
				profes.insert({ profe, { { alumno, 0 } } });
			// si el profe ya existe
			else
				// le añadimos el nuevo alumno al profe
				p->second.insert({ {alumno, 0} });
		}
		// si el alumno ya existe
		else {
			// si el profe es diferente
			if (profe != a->second.profe) {
				// profe antiguo
				auto it = profes.find(a->second.profe);
				// le borro el alumno
				it->second.erase(a->first);
				// si el profe se ha quedado sin alumnos
				if (it->second.size() == 0)
					// lo borro
					profes.erase(a->second.profe);
				// le cambio de profe al alumno
				a->second.profe = profe;
				// el profe nuevo no existe
				if (p == profes.end())
					// se le inserta el nuevo alumno con la puntuación antigua
					profes.insert({ profe, { {alumno, a->second.puntos} } });
				// el profe nuevo ya existe
				else
					// se le inserta el nuevo alumno
					p->second.insert({ { alumno, a->second.puntos } });
			}
		}
	}

	bool es_alumno(nombre alumno, nombre profe) {
		auto it = alumnos.find(alumno);
		return it->second.profe == profe;
	}

	int puntuacion(nombre alumno) {
		auto it = alumnos.find(alumno);
		if(it == alumnos.end())
			throw std::domain_error("ERROR");
		return it->second.puntos;
	}

	void actualizar(nombre alumno, int n) {
		auto it = alumnos.find(alumno);
		if (it == alumnos.end())
			throw std::domain_error("ERROR");
		// actualizamos en el mapa de alumnos
		it->second.puntos += n;
		// actualizamos en el mapa de profes
		auto p = profes.find(it->second.profe);
		auto a = p->second.find(alumno);
		a->second += n;
	}

	std::vector<nombre> examen(nombre profe, int n) {
		std::vector<nombre> dev;
		auto it = profes.find(profe);
		// si no existe la lista está vacía
		if (it == profes.end())
			return dev;
		// si existe entonces recorremos sus alumnos
		for (auto a : it->second)
			if (a.second >= n)
				dev.push_back(a.first);
		return dev;
	}

	void aprobar(nombre alumno) {
		// busco al alumno
		auto a = alumnos.find(alumno);
		if (a == alumnos.end())
			throw std::domain_error("ERROR");
		// busco el profesor que le corresponde
		auto p = profes.find(a->second.profe);
		// lo elimino de la lista de alumnos del profe
		p->second.erase(a->first);
		// borro al alumno del mapa de alumnos
		alumnos.erase(alumno);
	}

};