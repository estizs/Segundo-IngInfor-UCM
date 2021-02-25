
// Estibaliz Zubimendi
// A80

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicaci�n del algoritmo utilizado
/*
El algoritmo que he utilizado es el que Isabel nos di� en clase para resolver los problemas de tipo Desplazar elementos de un vector.
El algoritmo funciona de la siguiente manera:
tenemos un �ndice vb (valores buenos) que nos servir� para, al final del bucle que recorre todos los elementos del vector, saber qu� valores
del vector debemos guardar y cu�les "eliminar". Los elementos que queden a la izquiera del �ndice vb ser�n los que queremos guardar
y los que se quedan a la derecha (vb inclusive) ser�n los valores que no nos importan.
Para ello hacemos un bucle que recorra todos los elementos del vector de DNIs y vb lo inicializamos a 0.
Si encontramos un DNI par (un valor bueno) entonces copiamos ese valor en el �ndice siguiente a donde est� el �ltimo valor bueno
y aumentamos vb ya que ahora hay un valor bueno m�s.
Si el DNI es impar entonces simplemente seguimos recorriendo el array.
*/


// Coste del algoritmo utilizado
/*
El coste de la funci�n resolver es lineal respecto al n�mero de DNIs de la entrada.
En esta funci�n solo tenemos un bucle que va a dar n vueltas siendo n el n�mero de DNIs. Dento de este bucle tenemos una 
instucci�n condicional (que es constante) y dentro dos instrucciones con coste constante. Dicho todo eso, el coste del bucle es n.
Luego tenemos la funci�n resize(). Esta funci�n tiene coste constante cuando queremos cambiar el tama�o del vector a uno m�s peque�o.
As� que el coste total de la funci�n es la del bucle O(n) siendo n el tama�o del vector (DNIs).
*/


// Esta funci�n recibe un vector con los n�meros de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int>& v) {
    // Codigo del alumno
    int vb = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) {
            v[vb] = v[i];
            ++vb;
        }
    }
    v.resize(vb);
}

// Funcion que lee de la entrada, 
// LLama a la funci�n que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la funci�n resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-10.1.in");
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
