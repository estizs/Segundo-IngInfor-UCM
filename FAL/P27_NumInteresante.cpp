// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>

using pbi = std::pair<bool, int>;

// función que resuelve el problema
 pbi resolver(int n, int derecha) {
     // comprobamos si es 0
     // la suma de la derecha (ya que a la izquierda no tiene nada)
     if (n < 10) {
         // no es un número interesante
         if (n == 0 || derecha % n != 0) return { false, n };
         // ¡interesante!
         else return { true, n };
    }
     else {
         // primero llamamos a la función
         pbi aux = resolver(n / 10, derecha + n % 10);
         // después calculamos el return
         // no es interesante, tenemos que devolver lo que ya teniamos a la izq + el dígito actual
         if (n % 10 == 0 || aux.second % (n % 10) != 0 || derecha % (n % 10) != 0) return { false, aux.second + n % 10 };
         // es interesante por lo que mantenemos el valor anterior (por si otro dígito no lo era)
         // la suma es la misma que el caso anterior
         else return { aux.first, aux.second + n % 10 };
     }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (resolver(n, 0).first) std::cout << "SI\n";
    else std::cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-27.1.in");
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