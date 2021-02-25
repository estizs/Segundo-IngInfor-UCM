// Estibaliz Zubimendi
// A80

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

/*
--COSTE DEL ALGORITMO--
El coste de la función del algoritmo es el máximo entre el número de veces que los amigos han tirado los dados y el máximo que se puede conseguir con las tiradas.
Tengo 4 bucles en la función resolver pero tres de ellos tienen el mismo coste --> O(aux.size()). El otro bucle tiene coste O(v.size()).
El primer bucle se ejecuta tantas veces como el número de caras que tiene el dado que han tirado. Dentro de este bucle solo hay una instucción, que es una asignación
con coste lineal. Por lo que el primer bucle tiene coste O(aux.size())
El segundo bucle se ejecuta tantas veces como veces han tirado los dados los amigos. Dento del bucle solo hay una instrucción con coste lineal, por lo que O(v.size()).
El tercer bucle es como el primero.
EL último es un poco diferente ya que hay una comparación pero además utilizo el push_back(). Esta función tiene coste constante porque se amortiza (Isabel también 
lo explicó en clase). Así que como las instrucciones de dentro del bucle son constantes, el bucle en sí tiene coste O(aux.size()).

--EXPLICACIÓN DEL ALGORITMO--
En mi algoritmo no ordeno el vector porque entonces tendría coste O(nlogn) siendo n el número de veces que han tirado el dado.
Lo que yo hago es inicializar el vector auxiliar a 0 que va a servir para almacenar el número de veces que aparece un número.
¿Cómo almaceno estos datos en el vector? Si el valor que han conseguido es el 10 entonces añadiré un 1 en la posición 10 del vector.
Luego tengo que buscar el máximo de las frecuencias dentro de aux, o sea, el máximo de vece que ha aparecido un número.
Guardo esas frecuencias de mayor a menor (recorro el vector aux de derecha a izquierda) ya que el enunciado dice que los valores deben ser puestos de derecha a izquierda.
Y luego simplemente hago cout de los valores de sol.
*/

// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {
    // Aqui codigo del estudiante
    // el vector auxiliar tiene un tamaño de los máximos valores del dado + 1
    std::vector<int> aux(maximoValores+1), sol;
    // inicializo el vector auxiliar
    for (int i = 0; i < aux.size(); ++i) aux[i] = 0;
    // sumo las veces que aparece un número en v y lo guardo en la posición del valor
    for (int i = 0; i < v.size(); ++i) ++aux[v[i]];
    // ahora tengo que buscar los valores máximos en el array aux, solo buscamos el valor max
    int maxN = aux[0];
    for (int i = 1; i < aux.size(); ++i) 
        if (aux[i] > maxN) maxN = aux[i];
    // ahora voy a recorrer aux y guardar en sol los índices que conincidan con el max
    // empiezo de detrás hacia delante para que así en sol tengo los valores de mayor a menor
    for (int i = aux.size()-1; i > 0; --i)
        if (aux[i] == maxN) sol.push_back(i);
    return sol;
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces

                // Codigo
    std::vector<int>sol = resolver(v, valorMax);

    // Escribir los valores del vector que ha calculado resolver

                // Codigo
    for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
    std::cout << "\n";

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("sample-08.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

