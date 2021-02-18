// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

using pis = std::pair<int, std::string>;

bool esValida(std::vector<pis> const& juguetes, int k, std::vector<int>sol, std::vector<int> const& marcas,
    std::vector<std::vector<int>> const& satis, int s) {
    if (k % 2 != 0 && juguetes[sol[k]].second <= juguetes[sol[k - 1]].second) return false;
    else if (juguetes[sol[k]].first < marcas[sol[k]]) return false;
    else if (k % 2 != 0 && ((satis[k/2][sol[k]] + satis[k/2][sol[k-1]]) < s)) return false;
    else return true;
}

// función que resuelve el problema
int resolver(std::vector<pis> const& juguetes, int m, int n, int s, int k, 
    std::vector<std::vector<int>> const& satis, std::vector<int>sol, std::vector<int> &marcas, int satisAct) {
    int aux = 0;
    for (int i = 0; i < m; ++i) {
        sol[k] = i;
        ++marcas[sol[k]];
        satisAct += satis[k/2][i];
        if (esValida(juguetes, k, sol, marcas, satis, s)) {
            if (k == 2 * n - 1) {
                ++aux;
                for (int j = 0; j < sol.size(); ++j)
                    std::cout << sol[j] << " ";
                std::cout << "\n";
            }
            else aux += resolver(juguetes, m, n, s, k + 1, satis, sol, marcas, satisAct);
        }
        satisAct -= satis[k/2][i];
        --marcas[sol[k]];
    }
    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n, s; std::cin >> m >> n >> s;
    if (!std::cin)
        return false;
    std::vector<pis> juguetes(m);
    for (int i = 0; i < m; ++i) std::cin >> juguetes[i].first;
    for (int i = 0; i < m; ++i) std::cin >> juguetes[i].second;
    // satis[i][j] = satisfacción que le da el juguete j al niño i
    std::vector<std::vector<int>> satis(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> satis[i][j];
    std::vector<int>sol(2 * n);
    std::vector<int> marcas(m);
    marcas.assign(m, 0);
    int solucion = resolver(juguetes, m, n, s, 0, satis, sol, marcas, 0);

    // escribir sol
    if (solucion == 0) std::cout << "SIN SOLUCION\n\n";
    else std::cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-50B.in");
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