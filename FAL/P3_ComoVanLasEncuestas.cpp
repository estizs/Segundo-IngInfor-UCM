// Estibaliz Zubimendi
// A80

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;
// cada caso funciona de la siguiente manera:
/*

recorro el vector una sola vez --> voy a tener en cuenta cuál es el mínimo en cada momento
y cuántas veces aparece.
cada vez que aparezca un nuevo mínimo, a la suma total le añado el mínimo * las veces que ha aparecido
si aparece un número igual al mínimo entonces +1 a las veces que aparece el número
si el siguiente número es mayor, simplemente se le añade a la suma

*/

// Coste del algoritmo utilizado



// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
int resolver(int &cantNumeros, const vector<int> &v) {
    // Inicialización de variables
    // Codigo del alumno
    int suma = 0, minimo = v[0], vecesMinimo=1;

    for (int i = 1; i < v.size(); ++i) {

        if (v[i] < minimo) {
            suma += minimo * vecesMinimo;
            minimo = v[i];
            vecesMinimo = 1;
        }
        else if (v[i] == minimo)
            ++vecesMinimo;
        else
            suma += v[i];

    }
    cantNumeros = v.size() - vecesMinimo;
    return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem, cantNum=0;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    int s = resolver(cantNum, v);
    // Escribir los resultados
    std::cout << s << ' ' << cantNum << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("03sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
