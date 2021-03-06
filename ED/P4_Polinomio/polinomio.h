// Estibaliz Zubimendi 
// A79
// Modificado de la tutoría del día 3 de marzo de 2021
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using pii = std::pair<int64_t, int64_t>;

class Polinomio {
	std::vector<std::pair<int, int>> poli;

	class compExponente {
	public:
		bool operator()(pii const& p1, pii const& p2) {
			return p1.second < p2.second;
		}
	};

public:
	Polinomio() {};

	void anyadirMonomio(pii const& m) {
		// comprobar si el monomio está o no está
		if (!std::binary_search(poli.begin(), poli.end(), m, compExponente())) { // el exponente no está
			// desplazar todos hacia la derecha
			// insertar pos ahí
			// hacer hueco
			poli.push_back(m);
			for (int i = (int)poli.size() - 1; i > 0 && poli[i].second < poli[i - 1].second; --i)
				std::swap(poli[i], poli[i - 1]);
		}
		else { // sí que está
			auto pos = std::lower_bound(poli.begin(), poli.end(), m, compExponente());
			(*pos).first += m.first;
		}
	}

	int64_t evaluar(int valor) {
		int64_t suma = 0;
		int64_t exAnterior = 0, potencia = 1;

		for (int i = 0; i < poli.size(); ++i) {
			for (int j = exAnterior; j < poli[i].second; ++j) {
				potencia *= valor;
			}
			suma += poli[i].first * potencia;
			exAnterior = poli[i].second;
		}
		return suma;
	}
};