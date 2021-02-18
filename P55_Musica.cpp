// Estibaliz Zubimendi
// A80
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

// Para una cancion
struct tCancion {
    int duracion;  // Duracion de la cancion
    int satisfaccion;  // Puntuacion dada a la cancion
};

// Lectura de los datos de una cancion
std::istream& operator>> (std::istream& in, tCancion& d) {
    in >> d.duracion >> d.satisfaccion;
    return in;
}

// Para los datos de entrada
struct tDatos {
    int numCanciones;  // Numero de canciones
    int tiempoViajeIda; // Duracion del viaje de ida
    int tiempoViajeVuelta;  // Duracion del viaje de vuelta
    std::vector<tCancion> canciones;  // Duracion y puntuacion de cada cancion
};

// Aqui las funciones implementadas por el alumno


void resolver(tDatos const& d, int k, std::vector<int>& sol, int &duracionCara1, int &duracionCara2, int &satisAct, std::vector<int>& mejorSol, int& satisMejor, bool &existeSol) {
    // lo cojo en la ida
    sol[k] = 1;
    duracionCara1 += d.canciones[k].duracion;
    satisAct += d.canciones[k].satisfaccion;
    if (duracionCara1 <= d.tiempoViajeIda) {
        if (k == sol.size() - 1) {
            if (duracionCara2 == d.tiempoViajeVuelta && duracionCara1 == d.tiempoViajeIda) {
                existeSol = true;
                if (satisAct > satisMejor) {
                    satisMejor = satisAct;
                    mejorSol = sol;
                }
            }
        }
        else resolver(d, k + 1, sol, duracionCara1, duracionCara2, satisAct, mejorSol, satisMejor, existeSol);
    }
    duracionCara1 -= d.canciones[k].duracion;
    satisAct -= d.canciones[k].satisfaccion;
    
    // en la vuelta
    sol[k] = 2;
    duracionCara2 += d.canciones[k].duracion;
    satisAct += d.canciones[k].satisfaccion;
    if (duracionCara2 <= d.tiempoViajeVuelta) {
        if (k == sol.size() - 1) {
            if (duracionCara2 == d.tiempoViajeVuelta && duracionCara1 == d.tiempoViajeIda) {
                existeSol = true;
                if (satisAct > satisMejor) {
                    satisMejor = satisAct;
                    mejorSol = sol;
                }
            }
        }
        else resolver(d, k + 1, sol, duracionCara1, duracionCara2, satisAct, mejorSol, satisMejor, existeSol);
    }
    duracionCara2 -= d.canciones[k].duracion;
    satisAct -= d.canciones[k].satisfaccion;

    // no lo cojo
    sol[k] = 0;
    if (k == sol.size() - 1) {
        if (duracionCara2 == d.tiempoViajeVuelta && duracionCara1 == d.tiempoViajeIda) {
            existeSol = true;
            if (satisAct > satisMejor) {
                satisMejor = satisAct;
                mejorSol = sol;
            }
        }
    }
    else resolver(d, k + 1, sol, duracionCara1, duracionCara2, satisAct, mejorSol, satisMejor, existeSol);
}


bool  resuelveCaso() {
    // lectura de datos
    tDatos d;
    std::cin >> d.numCanciones >> d.tiempoViajeIda >> d.tiempoViajeVuelta;
    if (d.numCanciones == 0 && d.tiempoViajeIda == 0 && d.tiempoViajeVuelta == 0) return false;
    d.canciones.resize(d.numCanciones);
    for (int i = 0; i < d.numCanciones; ++i)
        std::cin >> d.canciones[i];

    // Preparar los datos para llamada a VA
    std::vector<int>sol(d.numCanciones);
    std::vector<int>solMejor(d.numCanciones);
    sol.assign(d.numCanciones, 0);
    int duracionCara1 = 0, duracionCara2 = 0, satisAct = 0, satisMejor = 0;
    bool existeSol = false;

    // llamada a VA
    resolver(d, 0, sol, duracionCara1, duracionCara2, satisAct, solMejor, satisMejor, existeSol);

    // Escribir resultado
    if (!existeSol) std::cout << "Imposible\n";
    else std::cout << satisMejor << "\n";

    return true;
}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("sample-55.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
