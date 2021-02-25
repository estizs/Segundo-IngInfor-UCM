// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> const&v, int&suma, int&diaComienzo, int &lon) {
    int sumaActual = 0, sumaMax = 0, ultMax = 0, lonActual = 0;
    suma = 0, diaComienzo = 0, lon = 0;
    for (int i = 0; i < v.size(); ++i) {
        sumaActual += v[i];
        if (sumaActual > 0) {
            ++lonActual;
            if (sumaMax < sumaActual) {
                sumaMax = sumaActual;
                ultMax = i;
                lon = lonActual;
            }
            else if (sumaMax == sumaActual)
                // para quedarnos con el de menos longitud en el caso de que la suma sea igual
                if (lonActual < lon) {
                    sumaMax = sumaActual;
                    ultMax = i;
                    lon = lonActual;
                }
        }
        else {
            sumaActual = 0;
            lonActual = 0;
        }
    }
    suma = sumaMax;
    diaComienzo = ultMax - lon + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    std::vector<int> v(n);
    int suma, diaComienzo, lon;
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    resolver(v, suma,diaComienzo, lon);

    // escribir sol

    std::cout << suma << " " << diaComienzo << " " << lon << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-15.1.in");
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