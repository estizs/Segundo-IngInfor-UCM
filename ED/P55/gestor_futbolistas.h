#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include <vector>
#include <unordered_set>

struct info_jugador {
	int numEquipos;
	std::string equipoAct;
	std::list<std::string>::iterator it;
	std::unordered_set<std::string> equipos;
};

class gestor_futbolistas {
private:
	std::unordered_map<std::string, info_jugador> jugadores;
	std::unordered_map<std::string, std::list<std::string>> equipos;
public:
	// constructor vacío
	gestor_futbolistas() {}

	void fichar(std::string j, std::string e) {
		// buscamos si el jugador existe o no
		auto it = jugadores.find(j);
		// no existe
		if (it == jugadores.end()) {
			// buscamos si el equipo existe
			auto a = equipos.find(e);
			// no existe
			if (a == equipos.end())
				// hay que registrar el equipo nuevo
				equipos.insert({ e, {j} });
			else
				// insertamos por el frente
				a->second.push_front(j);
			// insertamos en los jugadores
			// respecto al iterador va a ser el comienzo de la lista de ese equipo
			auto b = equipos[e].begin(); // depurar
			jugadores.insert({ j, {1, e, b, {e} } });
		}
		// el jugador ya existía
		else {
			// el equipo es diferente
			if (it->second.equipoAct != e) {
				// buscamos si el nuevo equipo existe
				auto a = equipos.find(e);
				// no existe
				if (a == equipos.end())
					//equipos[e] = { j };
					equipos.insert({e, {j}});
				else
					// insertamos al comienzo
					a->second.push_front(j);
				// hay que borrar el jugador del equipo anterior
				auto b = equipos.find(it->second.equipoAct);
				b->second.erase(it->second.it);
				// actualizamos la info del jugador
				// cambia de equipo
				it->second.equipoAct = e;
				// un equipo más en el que ha estado
				auto c = it->second.equipos.find(e);
				// no ha estado en este equipo
				if(c == it->second.equipos.end())
					it->second.numEquipos += 1;
				// el iterador apunta al comienzo de la lista del nuevo equipo
				it->second.it = equipos[e].begin();
				it->second.equipos.insert(e);
			}
		}
	}

	std::string equipo_actual(std::string j) {
		auto it = jugadores.find(j);
		if (it == jugadores.end())
			throw std::domain_error("Jugador inexistente");
		return it->second.equipoAct;
	}

	int fichados(std::string e) {
		auto it = equipos.find(e);
		if (it == equipos.end())
			throw std::domain_error("Equipo inexistente");
		return it->second.size();
	}

	std::vector<std::string> ultimos_fichajes(std::string e, int n) {
		auto it = equipos.find(e);
		if (it == equipos.end())
			throw std::domain_error("Equipo inexistente");
		std::vector<std::string> dev;
		// recorremos la lista de jugadores del equipo
		int i = 0;
		for (auto a : it->second) {
			if (i == n)
				break;
			dev.push_back(a);
			++i;
		}
		return dev;
	}

	int cuantos_equipos(std::string j) {
		auto it = jugadores.find(j);
		if (it == jugadores.end())
			return 0;
		return it->second.numEquipos;
	}
};