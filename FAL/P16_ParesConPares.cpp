// Estibaliz Zubimendi Solaguren
// A80


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
void resolver(std::vector<int> &v) {
    int valoresPares = 0, valoresImpares = 1;
    while (valoresPares < v.size() && valoresImpares < v.size()) {
        if (v[valoresPares] % 2 == 0) valoresPares += 2;
        else if (v[valoresImpares] % 2 == 1) valoresImpares += 2;
        else {
            std::swap(v[valoresPares], v[valoresImpares]);
            valoresPares += 2; valoresImpares += 2;
        }
    }
    // 2 cosas pueden pasar:
    // valoresPares llega al final y se pasa por 2 en v.size()
    // valoresImpares llega al final y se pasa por 2 en v.size()
    int paux = valoresPares + 2;
    while (paux < v.size()) {
        if (v[paux] % 2 == 0) {
            std::swap(v[paux], v[valoresPares]);
            valoresPares += 2;
        }
        paux += 2;
    }
    // si entra en este bucle es porque valoresPares antes no ha llegado al final --> sobran impares
    int qaux = valoresImpares + 2;
    while (qaux < v.size()) {
        if (v[qaux] % 2 != 0) {
            std::swap(v[qaux], v[valoresImpares]);
            valoresImpares += 2;
        }
        qaux += 2;
    }
    std::cout << valoresPares << " " << valoresImpares << "\n";
    v.resize(std::min(valoresPares, valoresImpares - 1));
    // si entra en este bucle es porque valoresImpares no ha llegado al final --> sobran pares

    // valoresImpares > valoresPares -> sobran Impares
    // valoresPares > valoresImpares -> sobran Pares
    
    //v.resize(std::min(valoresPares, valoresImpares - 1));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    resolver(v);

    // escribir sol
    for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-16.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}