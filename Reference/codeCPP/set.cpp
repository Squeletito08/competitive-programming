#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s; // []

    // Insertar elementos
   
    s.insert(40); // [40]
    s.insert(10); // [10, 40]
    s.insert(20); // [10, 20, 40]
    s.insert(30); // [10, 20, 30, 40]
    s.insert(50); // [10, 20, 30, 40, 50]

    // Acceder e imprimir elementos
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << "\n";

    // Obtener el primer elemento
    cout << *s.begin() << "\n"; // 10

    // Obtener el último elemento
    cout << *prev(s.end()) << "\n"; // 50

    // Usar count para verificar la existencia de un elemento
    cout << s.count(20) << "\n"; // 1
    cout << s.count(60) << "\n"; // 0

    // Eliminar un elemento
    s.erase(20); // [10, 30, 40, 50]

    // Verificar existencia de un elemento después de eliminar
    if (s.find(20) == s.end()) {
        cout << "Elemento no encontrado.\n"; 
    }

    // Tamaño del conjunto
    cout << s.size() << "\n"; // 4

    // Vaciar el conjunto
    s.clear();

    cout << "Conjunto vacío: " << (s.empty() ? "Sí" : "No") << "\n"; // Sí

    return 0;
}
