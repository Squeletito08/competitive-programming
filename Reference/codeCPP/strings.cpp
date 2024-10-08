#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "Hello World";
    string s2 = s1; 

    char c1 = s1[0]; // Primer carácter

    // Manipulación de cadenas

    s1.append(" hi"); // s1 = "Hello World hi"
    s1 = s2; 

    s1.append(" Wonderful", 8); // Añade los primeros 8 caracteres de la cadena " Wonderful", s1 = "Hello World Wonderf"
    s1 = s2;

    s1.append(5, '!'); // s1 = Hello!!!!!
    s1 = s2; 

    s1.insert(6, "Beautiful"); // Insertar en la posición 6, s1 = "Hello BeautifulWorld"
    s1 = s2; 

    s1.erase(6, 10); // Borrar 10 caracteres desde la posición 6, s1 = "Hello "
    s1 = s2; 

    string sub = s1.substr(6, 7); // Extraer subcadena de 7 caracteres desde la posición 6, sub = "World"

    // Búsqueda y comparación
    size_t pos1 = s1.find("Amazing"); // Encontrar "Amazing"
    size_t pos2 = s1.rfind("a"); // Encontrar la última aparición de 'a'

    if (pos1 != string::npos) {
        cout << "Encontrado 'Amazing' en la posición: " << pos1 << "\n";
    } else {
        cout << "'Amazing' no encontrado\n";
    }

    if (pos2 != string::npos) {
        cout << "Última aparición de 'a' en la posición: " << pos2 << "\n";
    } else {
        cout << "'a' no encontrado\n";
    }

    // Comparación de cadenas
    int compareResult = s1.compare("Hello Amazing");
    if (compareResult == 0) {
        cout << "Las cadenas son iguales\n";
    } else if (compareResult < 0) {
        cout << "s1 es menor que 'Hello Amazing'\n";
    } else {
        cout << "s1 es mayor que 'Hello Amazing'\n";
    }

    // Transformaciones y limpieza
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower); // Convertir a minúsculas

    // Convertir de nuevo a mayúsculas
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);

    // Espacios y otros caracteres no deseados
    s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end()); // Eliminar espacios


    // Conversiones
    string intStr = "12345";
    string longStr = "123456789012345";
    
    // Convertir cadena a entero (int)
    int intVal = stoi(intStr);

    // Convertir cadena a entero largo largo (long long)
    long long longLongVal = stoll(longStr);

    return 0;
}
