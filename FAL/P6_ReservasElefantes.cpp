// Estibaliz Zubimendi
// A80

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

using lli = long long int;
// Calcula un vector con los valores acumulados
void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
    // Aqui codigo del estudiante

    // el primer valor del vector resultante es el primer dato sin más
    v[0] = 0;
    for (int i = 1; i < v.size(); ++i) {
        // vamos acumulando los valores de todos los años anteriores
        v[i] = v[i-1] + a[i-1];
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos y calcula el vector de acumulados

    // Aqui código del estudiante
    int n = a2 - a1 + 1;
    vector <int> data(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    vector <lli> sol(n + 1);
    resolver(data, sol);

    // Lectura de las preguntas
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        // Escribir la respuesta

        // Aqui codigo del estudiante
        cout << sol[f2 - a1 + 1] - sol[f1 - a1] << "\n";
    }
    std::cout << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("06sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



