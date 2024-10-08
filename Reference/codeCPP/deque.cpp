#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> deq; //[]

    // Añadir elementos al final 
    deq.push_back(10); // [10]
    deq.push_back(20); // [10, 20]

    // Añadir elementos al inicio
    deq.push_front(30); // [30, 10, 20]

    // Acceder al primer elemento 
    cout << deq.front() << "\n"; // 30

    // Acceder al último elemento 
    cout << deq.back() << "\n"; // 20

    // Elimina el primer elemento 
    deq.pop_front(); // [10, 20]

    // Elimina el último elemento 
    deq.pop_back(); // [10]

    // Tamaño de la deque
    cout << deq.size() << "\n"; // 1

    // Vaciar la deque
    deq.clear();

    cout << "Deque vacío: " << (deq.empty() ? "Sí" : "No") << "\n";

    return 0;
}
