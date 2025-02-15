#include <bits/stdc++.h>
using namespace std;

int main() {

    // std::find
    vector<int> vec = {10, 20, 30, 40, 50};
    auto it = find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        cout << "Posición: " << distance(vec.begin(), it) << "\n"; // 2
    } else {
        cout << "No encontrado.\n";
    }

    // std::lower_bound
    sort(vec.begin(), vec.end()); // Necesario para usar lower_bound 
    auto lb = lower_bound(vec.begin(), vec.end(), 35);
    cout << "Primer elemento >= 35: " << (lb != vec.end() ? to_string(*lb) : "No encontrado") << "\n"; // 40

    // std::upper_bound
    auto ub = upper_bound(vec.begin(), vec.end(), 35);
    cout << "Primer elemento > 35: " << (ub != vec.end() ? to_string(*ub) : "No encontrado") << "\n"; // 40

    // std::binary_search
    bool found = binary_search(vec.begin(), vec.end(), 40);
    cout << (found ? "encontrado" : "no encontrado") << "\n";

    // std::sort (ascendente)
    vector<int> unsorted = {5, 3, 8, 6, 2}; // [2, 3, 5, 6, 8]
    sort(unsorted.begin(), unsorted.end());

    // std::sort (descendente)
    sort(unsorted.begin(), unsorted.end(), greater<int>()); // [8, 6, 5, 3, 2]

    // std::swap
    vector<int> swp = {10, 20, 30, 40, 50};
    swap(swp[0], swp[4]); // [50, 20, 30, 40, 10]

    // std::reverse
    vector<int> to_reverse = {1, 2, 3, 4, 5};
    reverse(to_reverse.begin(), to_reverse.end()); // [5, 4, 3, 2, 1]

    return 0;
}
