// Estibaliz Zubimendi
// A80

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
/*
He usado el algoritmo dado por Isabel para resolver problemas del tipo Segmento máximo.
Este algoritmo consiste en llevar la cuenta del segmento actual para comparalo con el max.
Los segmentos deben cumplir una condición necesaria y si se cumple entonces hay que actualizar el segmento actual
porque tiene un valor más. Y luego se compara con el segmento que teníamos antes. Hasta que hayamos recorrido todos
los valores del vector. Entonces tendremos la posición última del segmento maximo y podremos calcular la posición inicial.
*/


// Coste del algoritmo utilizado
/*
El coste de la función resolver es lineal respecto al número de edificios de la entrada.
En esta función tenemos un bucle y algunas instrucciones previas y posteriores al bucle, sin embargo son constantes.
El bucle va a dar tantas vueltas como edificios haya. Dentro del bucle hay un if-else. En el caso del else
se hace una asignación que es constante. En el caso del if hay otro if-else dentro y todas las instrucciones son constantes
por lo que cada vuelta del bucle tiene coste constante. En consecuencia la función resolver tiene coste n siendo n
el número de edificios, del orden O(n).
*/


// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int& posIni, int& posFin) {

// Codigo del alumno
    // tenemos que guardar la longitud del segmento más grande y del actual
    int longMax = 0, longActual = 0;
    // inicializamos las posiciones a 0
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > alturaNave) { // el dato cumple la condición
            ++longActual;
            if (longMax < longActual) { // miramos si supera la longitud max que teníamos hasta ahora
                longMax = longActual;
                posFin = i;
            }
        }
        else longActual = 0; // si no lo cumple entonces el segmento se ha terminado y empezamos de 0
    }
    // calcular la posición inicial con la diferencia entre la última posición y la longitud del segmento
    posIni = posFin - longMax + 1;
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-11.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
