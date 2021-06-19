// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map> // diccionarios de deportes y alumnos
#include <unordered_set> // para la lista de alumnos
#include <vector> // para la salida
#include <algorithm> // sort

/*
EXPLICACIÓN --> vídeo del profesor alberto
Dos mapas: uno en el que las claves sean los deportes y los valores sea un cjto de nombres
           otro en el que las claves sean los nombres y los valores el deporte en el que se han apuntado
Cuando aparece un nuevo nombre, comprobamos si está en el segundo diccionario y si no está lo añadimos
Y en el deporte añadimos el nombre
Si aparece, no se añade al deporte actual y se tiene que borrar del primer diccionario en el deporte que estaba
Para la salida, crear un vector de pares donde estén los deportes y el número de alumnos apuntados
*/

class ordDeportes {
public:
    bool operator()(std::pair<std::string, int> const& p1, std::pair<std::string, int> const& p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string deporte, estudiante;
    std::cin >> deporte;
    if (!std::cin)
        return false;
    std::unordered_map<std::string, std::unordered_set<std::string>> deportes;
    std::unordered_map<std::string, std::string> alumnos;

    // se añade el primer deporte (de momento vacío)
    deportes.insert({ deporte, {} });

    while (std::cin >> estudiante && estudiante != "_FIN_") {
        // si lo que entra es mayúscula es que es un deporte
        if (isupper(estudiante[0])) {
            deporte = estudiante;
            // y se añade el nuevo deporte a su diccionario
            deportes.insert({ deporte, {} });
        }
        else {
            // pair<iterator, bool> insert 
            auto a = alumnos.insert({ estudiante, deporte }); // si se inserta es que no estaba 
            if (a.second) // no está (se ha insertado)
                deportes[deporte].insert(estudiante); // se añade al deporte
            else { // si está hay que comprobar si el deporte es el mismo
                // en a.first->first está el nombre
                // a.first->second el deporte
                if (a.first->second != deporte)
                    deportes[a.first->second].erase(estudiante);
            }
        }
    }
    // <deporte, num alumnos>
    std::vector<std::pair<std::string, int>> sol;
    for (auto it = deportes.begin(); it != deportes.end(); ++it)
        sol.push_back({ it->first, it->second.size() });
    // ordenar
    std::sort(sol.begin(), sol.end(), ordDeportes());
    for (int i = 0; i < sol.size(); ++i)
        std::cout << sol[i].first << " " << sol[i].second << "\n";
    std::cout << "---\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-45.in");
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
