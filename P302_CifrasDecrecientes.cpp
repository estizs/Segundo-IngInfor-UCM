


//
// Estibaliz Zubimendi
// A80

#include <iostream>
#include <fstream>

// Aqui ecuaciones recursivas (función recursiva) que resuelven el problema. 
// Se puede elegir dar las ecuaciones para una recursión final 
// o para una no final.
//
//


// Función recursiva no final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionNoFinal(int n1, int maxDigito, int pot) {
    // Aqui el código del alumno
    if (n1 < 10) {
        if (n1 >= maxDigito) return n1 * pot;
        else return 0;
    }
    else {
        if (n1 % 10 >= maxDigito) return recursionNoFinal(n1 / 10, n1 % 10, pot * 10) + pot * (n1 % 10);
        else return recursionNoFinal(n1 / 10, maxDigito, pot);
    }
}


// Función recursiva final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionFinal(int n1, int maxDigito, int pot, int s) {
    // Aqui el código del alumno
    if (n1 < 10) {
        if (n1 >= maxDigito) return s + n1 * pot;
        else return s;
    }
    else {
        if (n1 % 10 >= maxDigito) return recursionFinal(n1 / 10, n1 % 10, pot * 10, s + pot * (n1 % 10));
        else return recursionFinal(n1 / 10, maxDigito, pot, s);
    }
}


void  resuelveCaso() {
    // lectura de los datos
    int numero;
    std::cin >> numero;
    // LLamadas a las funciones recursivas
    // Modificar parámetros o tipo de retorno donde se necesite
    int s1 = recursionNoFinal(numero / 10, numero % 10, 10) + numero % 10;
    int s2 = recursionFinal(numero / 10, numero % 10, 10, 0) + numero % 10;
    // Escribir los resultados. Modificar si se necesita
    std::cout << s1 << ' ' << s2 << '\n';
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("sample-302.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
