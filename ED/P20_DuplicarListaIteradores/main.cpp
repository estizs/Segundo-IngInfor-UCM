// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// función que resuelve el problema
template <class T>
void duplicarNodosLista(std::list<T>& l) {
    for (auto it = l.cbegin(); it != l.cend(); ++it) {
        l.insert(it, *it);
    }
}

template <class T>
void mostrar(std::list<T> const& l) {
    for (T const& elem : l)
        std::cout << elem << " ";
    std::cout << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    std::list<int> l;
    while (n != 0) {
        l.push_front(n);
        std::cin >> n;
    }
    std::list<int> lista;
    for (int const& elem : l)
        lista.push_front(elem);
    
    // escribir sol
    duplicarNodosLista(lista);
    mostrar(lista);

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-20.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}