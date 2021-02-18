

//
// Estibaliz Zubimendi
// A80

#include <iostream>
#include <fstream>

// Aqui ecuaciones recursivas (funci�n recursiva) que resuelven el problema. 
// Se puede elegir dar las ecuaciones para una recursi�n final 
// o para una no final.
//
//
//



// Funci�n recursiva no final
// Se pueden a�adir par�metros por valor a la funci�n
// Se pueden devolver m�s valores si se necesitan en el valor de retorno
int recursionNoFinal(int n1, int n2) {
    // Aqui el c�digo del alumno
    if (n1 < 10 && n2 < 10)
        return ((n1 + n2) % 10);
    else return recursionNoFinal(n1 / 10, n2 / 10) * 10 + ((n1 % 10) + (n2 % 10)) % 10;

}


// Funci�n recursiva final
// Se pueden a�adir par�metros por valor a la funci�n
// Se pueden devolver m�s valores si se necesitan en el valor de retorno
int recursionFinal(int n1, int n2, int s, int pot) {
    // Aqui el c�digo del alumno
    if (n1 < 10 && n2 < 10)
        return s + pot * ((n1 + n2) % 10);
    else return recursionFinal(n1 / 10, n2 / 10, s + pot * (((n1 % 10) + (n2 % 10)) % 10), pot * 10);

}


void  resuelveCaso() {
    // lectura de los datos
    int numero1, numero2;
    std::cin >> numero1 >> numero2;
    // LLamadas a las funciones recursivas
    // Modificar par�metros o tipo de retorno donde se necesite
    int s1 = recursionNoFinal(numero1, numero2);
    int s2 = recursionFinal(numero1, numero2, 0, 1);
    // Escribir los resultados. Modificar si se necesita
    std::cout << s1 << ' ' << s2 << '\n';
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("sample-301.in");
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
