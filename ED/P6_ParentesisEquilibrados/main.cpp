// Estibaliz Zubimendi
// A79

#include <stack>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string expresion; getline(std::cin, expresion);
    if (!std::cin)
        return false;
    std::stack<char> s;
    for (char c : expresion) {
        if (c == '(' || c == '{' || c == '[') s.push(c); // si es de apertura entonces push 
        // si son de cierre entonces miramos si lo último que hay es el caracter de apertura que le corresponde
        else if (c == ')') {
            if (!s.empty() && s.top() == '(')
                s.pop();
            else
                s.push(c);
        }   
        else if (c == '}') {
            if (!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(c);
        }
        else if (c == ']') {
            if (!s.empty() && s.top() == '[')
                s.pop();
            else
                s.push(c);
        }
    }

    if (s.empty()) std::cout << "SI\n";
    else std::cout << "NO\n";
  
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-06.in");
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