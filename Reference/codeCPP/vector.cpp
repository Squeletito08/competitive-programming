#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec;

    // Añadir elementos
    vec.push_back(10); // [10]
    vec.push_back(20); // [10, 20]

    // Acceder a elementos
    cout << vec[0] << endl; // 10

    // Eliminar el último elemento
    vec.pop_back(); // [10]

    // Tamaño del vector
    cout << vec.size() << "\n"; // 1

    // Vaciar el vector
    vec.clear();

    cout << "Vector vacío: " << (vec.empty() ? "Sí" : "No") << endl;

    return 0;
}
