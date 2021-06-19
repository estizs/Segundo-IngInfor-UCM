// A79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
/*
EXPLICACIÓN:
Se empieza recorriendo el listado de capitulos hasta encontrar uno repetido.
Si se encuentra un repetido:
- Hay que acortar el intervalo actual (quitar los caps anteriores al capitulo repetido, este inclusive)
  Empieza en el capítulo siguiente al que se ha repetido
- Añadir el cap al intervalo actual
Guardar el mejor intervalo hasta el momento y el mejor sufijo 
Cuando nos encontramos con un nuevo elemento (posición i) hay que mirar cuándo apareció ese nuevo
elemento por última vez
Si esa vez es anterior al comienzo del sufijo: se añade
Si esa vez está dentro del sufijo entonces hay que recortar
i - p + 1 vs long mejor segmento
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, cap; std::cin >> n;
    std::unordered_map<int, int> capitulos; // clave: número del cap valor: última vez que apareció
    int maxi = 0;
    int ini = 0; // comienzo del sufijo
    // recorremos la entrada
    for (int i = 0; i < n; ++i) {
        std::cin >> cap;
        if (capitulos.count(cap) && capitulos[cap] >= ini) // la última vez está dentro del sufijo
            ini = capitulos[cap] + 1;
        maxi = std::max(maxi, i - ini + 1);
        capitulos[cap] = i;
    }
    // escribir sol
    std::cout << maxi << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-44.in");
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