// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using pii = std::pair<int, int>;

// superficie por unidad de coste
bool comparar(pii const& p1, pii const& p2) {
    return (float)p1.second / p1.first > (float)p2.second / p2.first;
}

int estimar(std::vector<pii>objetos, int costeMax, int costeAct, int k) {
    int i = k + 1, sumaCoste = costeAct, sumaArea = 0;
    while (i < objetos.size() && sumaCoste + objetos[i].first <= costeMax) {
        sumaCoste += objetos[i].first;
        sumaArea += objetos[i].second;
        ++i;
    }
    // puede que se haya quedado una parte sin recorrer (si la condición que no se ha cumplido es la segunda)
    if (i < objetos.size() && sumaCoste < costeMax)
        sumaArea += objetos[i].second * (costeMax - sumaCoste) / (float)objetos[i].first + 1;
    return sumaArea;
}

int initArea(std::vector<pii>objetos, int presupuesto) {
    int i = 0, sumArea = 0, sumCoste = 0;
    while (i < objetos.size() && sumCoste + objetos[i].first <= presupuesto) {
        sumCoste += objetos[i].first;
        sumArea += objetos[i].second;
        ++i;
    }
    return sumArea;
}

class comparador {
public:
    bool operator()(pii p1, pii p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

// función que resuelve el problema
void resolver(std::vector<pii>objetos, int presupuesto, int k, std::vector<bool>& sol, int costeAct,
    int areaAct, std::vector<bool> mejorSol, int& areaMax) {
    // el objecto se compra
    sol[k] = true;
    costeAct += objetos[k].first;
    areaAct += objetos[k].second;
    if (costeAct <= presupuesto) {  // solución válida
        if (k == sol.size() - 1) { // es solución
            if (areaAct > areaMax) {// es mejor
                areaMax = areaAct;
                mejorSol = sol;
            }
        }
        else resolver(objetos, presupuesto, k + 1, sol, costeAct, areaAct, mejorSol, areaMax);
    }
    sol[k] = false;
    costeAct -= objetos[k].first;
    areaAct -= objetos[k].second;
    if (k == sol.size() - 1) {
        if (areaAct > areaMax) {
            areaMax = areaAct;
            mejorSol = sol;
        }
    }
    else
        if (estimar(objetos, presupuesto, costeAct, k) + areaAct > areaMax)
            resolver(objetos, presupuesto, k + 1, sol, costeAct, areaAct, mejorSol, areaMax);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, presupuesto; std::cin >> n >> presupuesto;
    if (!std::cin)
        return false;
    std::vector<pii>objetos(n);
    for (int i = 0; i < n; ++i) std::cin >> objetos[i].first >> objetos[i].second;
    
    std::sort(objetos.begin(), objetos.end(), comparador());
    std::vector<bool>sol(n);
    int costeAct = 0, areaAct = 0;
    int areaMax = initArea(objetos, presupuesto);
    std::vector<bool>mejorSol(n);
    resolver(objetos, presupuesto, 0, sol, costeAct, areaAct, mejorSol, areaMax);

    // escribir sol
    std::cout << areaMax << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-54B.in");
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