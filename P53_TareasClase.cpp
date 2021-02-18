// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

bool esValida(int k, int i, int t, std::vector<int>& sol, std::vector<int>& marcas) {
    // el niño k y k + 1 no es el mismo
    // ningún niño tiene más de t tareas (mirar i actual)
    return (k % 2 == 0 || sol[k] != sol[k - 1]) && marcas[i] <= t;
}

// función que resuelve el problema
void resolver(std::vector<std::vector<int>>const& pref, int a, int k, std::vector<int> &sol, int &s,
              std::vector<int> &marcas, int& satisMax, int t) {
    for (int i = 0; i < a; ++i) {
        sol[k] = i;
        ++marcas[i];
        s += pref[i][k/2];
        if (esValida(k, i, t, sol, marcas)) {
            if (k == sol.size() - 1) {
                if (s > satisMax)
                    satisMax = s;
            }
            else resolver(pref, a, k + 1, sol, s, marcas, satisMax, t);
        }
        --marcas[i];
        s -= pref[i][k/2];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, t; std::cin >> n >> a >> t;
    if (n == 0 && a == 0 && t == 0)
        return false;
    std::vector<std::vector<int>>pref(a, std::vector<int>(n));
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> pref[i][j];
    // la satisfacción mejor inicial es un 0 ya que al ser un problema de maximización
    // hay que poner un número pequeño
    int satisMejor = 0;
    std::vector<int>sol(2 * n);
    sol.assign(2 * n, 0);
    std::vector<int>marcas(a);
    marcas.assign(a, 0);
    int s = 0;
    resolver(pref, a, 0, sol, s, marcas, satisMejor, t);

    // escribir sol
    std::cout << satisMejor << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-53.in");
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
