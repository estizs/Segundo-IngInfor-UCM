// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(int m, std::vector<std::vector<int>> const& satis, int k, std::vector<int>& sol, int& s,
    std::vector<bool>& marcas, int& satisMax, std::vector<int> const& acumulados) {
    for (int i = 0; i < m; ++i) {
        sol[k] = i;
        if (!marcas[i]) {
            s += satis[k][i];
            marcas[i] = true;
            if (k == m - 1) {
                if (s < satisMax) {
                    satisMax = s;
                }
            }
            else {
                if(s + acumulados[k + 1] < satisMax)
                    resolver(m, satis, k + 1, sol, s, marcas, satisMax, acumulados);
            }
            marcas[i] = false;
            s -= satis[k][i];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m; std::cin >> m;
    if (m == 0)
        return false;
    std::vector<std::vector<int>> satis(m, std::vector<int>(m));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> satis[i][j];
    std::vector<int> acumulados(m);
    // primero guardamos el valor máximo de satisfacción que puede alcanzar un niño
    for (int i = 0; i < m; ++i) {
        // inicializamos el max al primer juguete
        int aux = satis[i][0];
        // recorremos el resto de juguetes
        for (int j = 1; j < m; ++j)
            // si la satisfacción es mayor entonces actualizamos el máximo
            if (aux > satis[i][j]) aux = satis[i][j];
        // guardamos en el vector la máxima satisfacción
        acumulados[i] = aux;
    }
    // ahora vamos acumulando los valores máximos (de manera descendente, ya que el árbol lo exploramos
    // desde la cima hasta las ramas) para luego usarlo en resolver
    for (int i = m - 1; i > 0; --i)
        acumulados[i - 1] += acumulados[i];
    // solución posible para la inicialización del máximo
    int satisMax = 0;
    // cogemos por ejemplo la diagonal (ya que para cada niño es un regalo y estos no se pueden repetir)
    for (int i = 0; i < m; ++i) {
        satisMax += satis[i][i];
    }

    std::vector<int> sol(m);
    sol.assign(m, 0);
    int s = 0;
    std::vector<bool> marcas(m);
    marcas.assign(m, false);
    resolver(m, satis, 0, sol, s, marcas, satisMax, acumulados);

    // escribir sol
    std::cout << satisMax << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-52A.in");
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