#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Verifica si x está presente en mid
        if (arr[mid] == x)
            return mid;

        // Si x es mayor, ignorar la mitad izquierda
        if (arr[mid] < x)
            low = mid + 1;
        // Si x es menor, ignorar la mitad derecha
        else
            high = mid - 1;
    }

    // Si llegamos aquí, el elemento no estaba presente
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = binarySearch(arr, 0, arr.size() - 1, x);
    
    // Mostrar el resultado
    if (result == -1) {
        cout << "El elemento no está presente en el arreglo." << endl;
    } else {
        cout << "El elemento está presente en el índice " << result << "." << endl; // 0 indezado
    }
    return 0;
}
