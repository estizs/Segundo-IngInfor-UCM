// Estibaliz Zubimendi Solaguren
// A80

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>	

using namespace std;

vector <int> resolver(vector <int>& cto1, vector <int>& cto2) {

	//devolvemos el conjunto resultante
	vector <int> ctoResultante;

	//ordenamos los conjuntos
	sort(cto1.begin(), cto1.end());
	sort(cto2.begin(), cto2.end());

	int i = 0, j = 0;
	while (i < cto1.size() && j < cto2.size()) {
		if (cto2[j] < cto1[i])
			++j;
		else if (cto2[j] == cto1[i]) {
			ctoResultante.push_back(cto2[j]);
			++j;
			++i;
		}
		else
			++i;
	}

	return ctoResultante;
}

void resuelveCaso() {

	vector <int> cto1, cto2, ctoR;

	//primer conjunto
	int aux;
	cin >> aux;
	while (aux != 0) {
		cto1.push_back(aux);
		cin >> aux;
	}

	//segundo conjunto
	cin >> aux;
	while (aux != 0) {
		cto2.push_back(aux);
		cin >> aux;
	}

	ctoR = resolver(cto1, cto2);

	//ahora tenemos que imprimir 
	for (int i = 0; i < ctoR.size(); ++i) {
		cout << ctoR[i] << " ";
	}
	cout << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}