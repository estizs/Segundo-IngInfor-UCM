// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin, int num) {
    if (ini + 1 == fin) { // vector de un elemento
        if (ini + num == v[ini]) return v[ini]; // si la pos + el número coincide con la cifra del vector
        else return -1;
    }
    else if (ini + 2 == fin) // en el caso de 2 llamamos al caso de 1
        // cogemos el máximo entre los dos por si en algún caso lo ha encontrado
        // devuelve un -1 si no
        return std::max(resolver(v, ini, ini + 1, num), resolver(v, ini + 1, ini + 2, num));
    else {
        int m = (ini + fin) / 2;
        if (num + m < v[m]) return resolver(v, ini, m + 1, num);
        else return resolver(v, m, fin, num);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, num; std::cin >> n >> num;
    std::vector<int>v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    int sol = resolver(v, 0, n, num);
    // escribir sol
    if (sol == -1) std::cout << "NO\n";
    else std::cout << sol << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-35.in");
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