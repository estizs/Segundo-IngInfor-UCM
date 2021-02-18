// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

/* 
--ANÁLISIS DEL COSTE--
El coste de la función del algoritmo es lineal respecto al número de los metros de la valla de los datos de entrada.
Tenemos dos bucles en la función resolver, el primer bucle se ejcuta tantas veces como la longitud de la ventana, dentro del bucle hay una comparación
y un incremento. Ya que las dos instrucciones tienen coste lineal,  el coste de cada vuelta del bucle es lineal. El coste del bucle primero es del orden O(n)
donde n es la longitud del intervalo (ventana).
El segundo bucle recorre los elementos desde el final del vector - la longitud del intervalo hasta el principio del bulce. El número de vueltas que da es
v.size() - invtervalo. Por cada vuelta se hacen tres comparaciones y dentro de las comparaciones un incremento o una asignación (dichas instrucciones tienen
coste lineal) por lo que el coste de cada vuelta es lineal. Así que el coste de este bucle es del orden O(v.size-intervalo) en el caso peor el intervalo = 1
así que se quedaría O(v.size()).

--EXPLICACIÓN ALGORITMO--
He utilizado la explicación dada en la clase del 20/10 donde Isabel explicó el algoritmo para resolver los problemas de tipo intervalo.
En este caso lo he adaptado para que en el primer bucle calcule el número de ceros empezando desde la derecha (ya que en el problema se especifica que la respuesta deseada
es la que esté más lejos de la casa, o sea, los elementos del vector del final).
En zerosMax he calculado el número máximo de ceros y en zeros el nuevo máximo una vez cogido otro intervalo, para luego comprarlos y quedarme con la posición
más a la derecha del vector.
*/

// función que resuelve el problema
void resolver(const std::vector <int> &v, int longitud, int &sol) {
    int zeros = 0, zerosMax=0;
    // cuento en número de 0 en el primer intervalo
    for (int i = v.size(); i > v.size() - longitud; --i)
        if (v[i-1] == 0) ++zerosMax;
    // si tenemos algún 0 entonces cogemos esa posición como posible
    if (zerosMax > 0) { 
        sol = v.size() - longitud; 
        zeros = zerosMax;
    }
    // bucle principal
    for (int i = v.size() - longitud - 1; i >= 0; --i) {
        // elimina el 0 de la derecha
        if (v[i + longitud] == 0) --zeros;
        // añade el 0 de la izquierda
        if (v[i] == 0) ++zeros;
        // comprobamos si el intervalo tiene más 0 que el anterior
        if (zeros > zerosMax) {
            zerosMax = zeros;
            sol = i;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    int ventana; std::cin >> ventana;
    std::vector<int>v(n);
    for (int &i : v) std::cin >> i;
    int sol = -1;
    resolver(v, ventana, sol);

    // escribir sol
    if (sol == -1) std::cout << "No hace falta";
    else std::cout << sol;
    std::cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-09.1.in");
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
