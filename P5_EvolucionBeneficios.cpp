// Estibaliz Zubimendi
// A80


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
máximo = primer número del vector
comparar con el siguiente --> si es mayor entonces hay un nuevo máximo y el año se añade al vector nuevo
devolver el nuevo vector
*/


// función que resuelve el problema
vector <int> resolver(const vector<int> &v, int start) {
    // el máximo se inicializa con el primer número del array
    int m = v[0];
    vector <int> sol;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > m) {
            m = v[i];
            sol.push_back(start + i);
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, start, end;
    // leemos los años
    cin >> start >> end;
    // calculamos el tamaño del array donde guardamos los valores
    n = end - start + 1;
    vector<int> v(n);
    // leemos los datos del array
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector <int> sol = resolver(v, start);
    // escribir sol
    for (int i = 0; i < sol.size(); ++i)
        cout << sol[i] << " ";
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("05sample.in");
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