#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m; // []

    // Insertar elementos
    m[1] = "uno"; // [1->uno]
    m[2] = "dos"; // [1->uno, 2->dos]
    m[3] = "tres"; // [1->uno, 2->dos, 3->tres]

    // Acceder a un valor usando una clave
    cout << m[2] << "\n"; // dos

    // Iterar sobre el mapa e imprimir pares clave-valor
    for (const auto& p : m) {
        cout << p.first << " -> " << p.second << "\n";
    }

    // Usar count para verificar la existencia de una clave
    cout << m.count(2) << "\n"; // 1
    cout << m.count(4) << "\n"; // 0

    // Eliminar un elemento por clave
    m.erase(2); // [1->uno, 3->tres]

    // Verificar existencia de un elemento después de eliminar
    if (m.find(2) == m.end()) {
        cout << "Elemento encontrado.\n"; 
    }

    // Usar iterador para eliminar un elemento
    auto it = m.find(3); 
    if (it != m.end()) {
        m.erase(it);  // [1->uno]
    }

    // Tamaño del mapa
    cout << m.size() << "\n"; // 1

    // Vaciar el mapa
    m.clear();

    cout << "Mapa vacío: " << (m.empty() ? "Sí" : "No") << "\n"; // Sí

    return 0;
}
