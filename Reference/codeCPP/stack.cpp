#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s; // []

    // Insertar elementos en la pila
    s.push(10); // [10]
    s.push(20); // [10, 20]
    s.push(30); // [10, 20, 30]
    s.push(40); // [10, 20, 30, 40]

    // Acceder al elemento superior de la pila
    cout << s.top() << "\n"; // 40

    // Eliminar el elemento superior de la pila
    s.pop(); // Elimina 40

    // Tamaño de la pila
    cout << s.size() << "\n"; // 3

    // Imprimir el contenido de la pila e irlos eliminando 
    while (!s.empty()) {
        cout << s.top() << " "; 
        s.pop(); 
    }
    cout << "\n"; 

    cout << "¿La pila está vacía después de vaciar?: " << (s.empty() ? "Sí" : "No") << "\n"; // Sí

    return 0;
}
