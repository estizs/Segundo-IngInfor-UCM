#pragma once
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <vector>
#include <unordered_set>
#include <list>

using nombre = std::string;
using empleo = std::string;

class oficinaEmpleo {
private:
	std::unordered_map<nombre, std::map<empleo, std::list<nombre>::iterator, std::less<>>> personas;
	std::unordered_map<empleo, std::list<nombre>> empleos;
public:
	// constructor
	oficinaEmpleo() {}

	void altaOficina(nombre n, empleo e) {
		// buscamos si la persona ya está registrada o no
		auto it = personas.find(n);
		// si no está
		if (it == personas.end()) {
			// buscamos el empleo
			auto a = empleos.find(e);
			// si no está
			if (a == empleos.end()) {
				empleos.insert({ e, {n} });
			}
			// si ya existe
			else {
				// añadimos la persona a la cola
				a->second.push_front(n);
			}
			// le añadimos a la lista de personas y el empleo 
			personas.insert({ n, {{e, empleos[e].begin()}} });
		}
		// la persona ya existía
		else {
			// hay que comprobar si ya estaba cualificada para este empleo
			auto a = it->second.find(e);
			// esta persona no estaba ya cualificada para este trabajo
			if (a == it->second.end()) {
				// buscamos si existe el empleo
				auto b = empleos.find(e);
				// no existía
				if (b == empleos.end()) {
					empleos.insert({ e, {n} });
				}
				// ya existía
				else {
					// añadimos la persona a la cola
					b->second.push_front(n);
				}
				// añadimos a la persona el nuevo trabajo
				it->second.insert({{e, empleos[e].begin()}});
			}
		}
	}

	nombre ofertaEmpleo(empleo e) {
		auto it = empleos.find(e);
		// comprobar si un trabajo tiene personas en la lista
		if (it == empleos.end())
			throw std::domain_error("No existen personas apuntadas a este empleo");
		// la persona que hay que devolver está al final 
		nombre n = it->second.back();
		// hay que eliminar todas las instancias de la persona
		for (auto a : personas[n]) {
			// buscamos el trabajo y eliminamos
			auto b = empleos.find(a.first);
			b->second.erase(a.second);
			// miramos si el trabajo se ha quedado sin personas en la lista
			if(b->second.empty())
				empleos.erase(b->first);
		}
		// eliminamos a la persona
		personas.erase(n);			
		return n;
	}

	std::vector<empleo> listadoEmpleos(nombre n) {
		auto it = personas.find(n);
		if (it == personas.end())
			throw std::domain_error("Persona inexistente");
		std::vector<empleo> dev;
		for (auto a : it->second)
			dev.push_back(a.first);
		return dev;
	}
};