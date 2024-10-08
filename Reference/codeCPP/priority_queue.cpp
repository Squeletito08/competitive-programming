#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq; // es un heap máximo

    // Insertar elementos
    pq.push(10); 
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(25);

    // Imprimir el contenido de la priority_queue
    while (!pq.empty()) {
        cout << pq.top() << " "; // Mostrar el elemento con la máxima prioridad
        pq.pop(); // Eliminar el elemento con la máxima prioridad
    }
    cout << "\n";

    // Insertar elementos en una priority_queue de prioridad mínima (min-heap)
    priority_queue<int, vector<int>, greater<int>> min_pq; // Min-heap

    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(5);
    min_pq.push(25);

    // Imprimir el contenido de la min-heap priority_queue
    while (!min_pq.empty()) {
        cout << min_pq.top() << " "; // Mostrar el elemento con la mínima prioridad
        min_pq.pop(); // Eliminar el elemento con la mínima prioridad
    }
    cout << "\n";

    return 0;
}
