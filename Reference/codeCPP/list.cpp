#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lst; // []

    // Añadir elementos al final
    lst.push_back(10); // [10]
    lst.push_back(20); // [10, 20]

    // Añadir elementos al inicio
    lst.push_front(30); // [30, 10, 20]

    // Acceder al primer elemento
    cout << lst.front() << "\n"; // 30

    // Acceder al último elemento
    cout << lst.back() << "\n"; // 20

    // Elimina el primer elemento
    lst.pop_front(); // [10, 20]

    // Elimina el último elemento
    lst.pop_back(); // [10]

    // Tamaño de la lista
    cout << lst.size() << "\n"; // 1

    // Vaciar la lista
    lst.clear();

    cout << "Lista vacía: " << (lst.empty() ? "Sí" : "No") << "\n";

    return 0;
}
