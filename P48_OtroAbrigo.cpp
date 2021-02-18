// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>
/*
Condiciones para que la solución que se está construyendo sea válida:
    - El tipo de abrigo aguanta la lluvia de ese día
    - Un abrigo no se puede llevar dos días seguidos
    - Se cumple la fórmula: marcas[i] (días que he llevado el abrigo) <= 2 + i (el número de días que llevo) / 3
*/
bool valida(int k, int i, std::vector<int> const& precipitaciones, std::vector<int> const& abrigos,
            std::vector<int> const& solucion, std::vector<int> const&marcas) {
    if (precipitaciones[k] > abrigos[i]) return false;
    // como k empieza en 0 entonces tenemos que comprobar que sea > 0 para no buscar en solucion[-1]
    else if (k > 0 && solucion[k - 1] == solucion[k]) return false;
    else if (marcas[i] > 2 + k / 3) return false;
    else return true;
}


// función que resuelve el problema
int resolver(int k, std::vector<int> const& precipitaciones, std::vector<int> const& abrigos, 
             std::vector<int> &solucion, std::vector<int> &marcas) {
    int sol = 0;
    for (int i = 0; i < abrigos.size(); ++i) {
        solucion[k] = i;
        ++marcas[i];
        // lo que tenemos hasta ahora cumple
        if (valida(k, i, precipitaciones, abrigos, solucion, marcas)) { 
            if (k == precipitaciones.size() - 1) {
                // el primer abrigo y el último no son iguales
                if (solucion[0] != solucion[k]) {
                    ++sol;
                }
            }
            else sol += resolver(k + 1, precipitaciones, abrigos, solucion, marcas);
        }
        --marcas[i];
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a; std::cin >> n >> a;
    if (n == 0 && a == 0)
        return false;
    std::vector<int> v(n), abrigos(a);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    for (int j = 0; j < a; ++j) std::cin >> abrigos[j];

    std::vector<int> marcas(a);
    // solucion es donde se va a ir costruyendo la posible combinación de vestidos
    std::vector<int> solucion(n);
    // inicializamos el vector de marcas a 0
    marcas.assign(a, 0);
    int sol = resolver(0, v, abrigos, solucion, marcas);

    // escribir sol
    if (sol == 0) std::cout << "Lo puedes comprar\n";
    else std::cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-48.in");
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