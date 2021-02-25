// Estibaliz Zubimendi
// A80

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicaci�n del algoritmo utilizado
/*
He usado el algoritmo dado por Isabel para resolver problemas del tipo Segmento m�ximo.
Este algoritmo consiste en llevar la cuenta del segmento actual para comparalo con el max.
Los segmentos deben cumplir una condici�n necesaria y si se cumple entonces hay que actualizar el segmento actual
porque tiene un valor m�s. Y luego se compara con el segmento que ten�amos antes. Hasta que hayamos recorrido todos
los valores del vector. Entonces tendremos la posici�n �ltima del segmento maximo y podremos calcular la posici�n inicial.
*/


// Coste del algoritmo utilizado
/*
El coste de la funci�n resolver es lineal respecto al n�mero de edificios de la entrada.
En esta funci�n tenemos un bucle y algunas instrucciones previas y posteriores al bucle, sin embargo son constantes.
El bucle va a dar tantas vueltas como edificios haya. Dentro del bucle hay un if-else. En el caso del else
se hace una asignaci�n que es constante. En el caso del if hay otro if-else dentro y todas las instrucciones son constantes
por lo que cada vuelta del bucle tiene coste constante. En consecuencia la funci�n resolver tiene coste n siendo n
el n�mero de edificios, del orden O(n).
*/


// La funci�n recibe un vector con las alturas de los edificios, y la altura de la nave que realizar� el rescate
// Devuelve las posiciones de inicio y fin del segmento m�ximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int& posIni, int& posFin) {

// Codigo del alumno
    // tenemos que guardar la longitud del segmento m�s grande y del actual
    int longMax = 0, longActual = 0;
    // inicializamos las posiciones a 0
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > alturaNave) { // el dato cumple la condici�n
            ++longActual;
            if (longMax < longActual) { // miramos si supera la longitud max que ten�amos hasta ahora
                longMax = longActual;
                posFin = i;
            }
        }
        else longActual = 0; // si no lo cumple entonces el segmento se ha terminado y empezamos de 0
    }
    // calcular la posici�n inicial con la diferencia entre la �ltima posici�n y la longitud del segmento
    posIni = posFin - longMax + 1;
}

// Funcion que lee de la entrada, 
// LLama a la funci�n que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la funci�n resolver
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
