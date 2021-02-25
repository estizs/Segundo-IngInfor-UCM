// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

const std::vector<std::string> COLORES = {"azul", "rojo", "vector"};

// función que comrpueba las condiciones de construcción de la torre (mientras se construye)
bool esValida(int a, int r, int v, int nA, int nR, int nV, int k, std::vector<std::string> const&sol) {
    if (k > 0 && sol[k-1] == "verde" && sol[k] == "verde") return false;
    else if (nV > nA) return false;
    else if (nA > a || nR > r || nV > v) return false;
    else return true;
}

// función que resuelve el problema
int resolver(int n, int a, int r, int v, int k, std::vector<std::string>& sol, int& nA, int& nR, int& nV) {
    int var = 0;
    for (std::string s : {"azul", "rojo", "verde"}) {
        sol[k] = s;
        if (s == "azul") ++nA;
        else if (s == "rojo") ++nR;
        else ++nV;
        if (esValida(a, r, v, nA, nR, nV, k, sol)) {
            if (k == n - 1) {
                if (nR > nA + nV) {
                    for (std::string t : sol)
                        std::cout << t << " ";
                    std::cout << "\n";
                    ++var;
                }
            }
            else var += resolver(n, a, r, v, k + 1, sol, nA, nR, nV);
        }
        if (s == "azul") --nA;
        else if (s == "rojo") --nR;
        else --nV;
    }
    return var;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, r, v; std::cin >> n >> a >> r >> v;
    if (n == 0 && a == 0 && r == 0 && v == 0)
        return false;
    std::vector<std::string> sol(n);
    int nA = 0, nR = 1, nV = 0;
    sol[0] = "rojo";
    int s = resolver(n, a, r, v, 1, sol, nA, nR, nV);

    // escribir sol
    if (s == 0) std::cout << "SIN SOLUCION\n";
    std::cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-47C.in");
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
