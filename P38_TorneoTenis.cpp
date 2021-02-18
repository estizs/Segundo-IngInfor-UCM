// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
    std::string jugador;
    int jugados;
    int rondas;
};

// función que resuelve el problema
tSol resolver(std::vector<std::string> const& v, int ini, int fin, int ronda) {
    if (ini + 2 == fin) { // dos elementos
        if (v[ini] != "NP" && v[ini + 1] != "NP")
            return { "JUGADOR" , 1, 1 };
        else if (v[ini] == "NP" && v[ini + 1] == "NP")
            return { "NP" , 0, 1 };
        else
            return { "JUGADOR", 0, 1 };
    }
    else { // 4 o más elementos (siempre potencia de 2)
        int m = (ini + fin) / 2;
        tSol izq = resolver(v, ini, m, ronda);
        tSol dcha = resolver(v, m, fin, ronda);
        if (izq.rondas != ronda) { // todavía no se han jugado todas las rondas de la entrada
            if (izq.jugador != "NP" && dcha.jugador != "NP")
                return { "JUGADOR", izq.jugados + dcha.jugados + 1, izq.rondas + 1 };
            else if (izq.jugador == "NP" && dcha.jugador == "NP")
                return { "NP", izq.jugados + dcha.jugados, izq.rondas + 1 };
            else
                return { "JUGADOR", izq.jugados + dcha.jugados, izq.rondas + 1 };
        }
        else
            return { "JUGADOR", izq.jugados + dcha.jugados, izq.rondas };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    int ronda; std::cin >> ronda;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    tSol sol = resolver(v, 0, v.size(), ronda);

    // escribir sol
    std::cout << sol.jugados << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-38.in");
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