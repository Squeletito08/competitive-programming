#include <iostream>
#include <bitset>
using namespace std;

int main() {
    
    bitset<8> bset1;  // Declara un bitset de tamaño 8, inicialmente todos los bits están en 0
    bitset<8> bset2(12); // Inicializa el bitset con el valor binario de 12 (00001100)

    cout << "bset1: " << bset1 << endl;  // Salida: 00000000
    cout << "bset2: " << bset2 << endl;  // Salida: 00001100
    cout << endl;

    bitset<8> bset3(5);  // 00000101
    cout << "El bit en la posición 2: " << bset3[2] << endl;  // Salida: 1

    bset3.set(2, 0);  // Cambia el bit en la posición 2 a 0
    cout << "Después de modificar: " << bset3 << endl;  // Salida: 00000001
    cout << endl;

    bitset<8> bset4(string("1100"));  // Inicializa con un valor binario dado como string
    bitset<8> bset5(string("1010"));  // Otro bitset para la demostración de operaciones

    cout << "bset4: " << bset4 << endl;  // Salida: 00001100
    cout << "bset5: " << bset5 << endl;  // Salida: 00001010

    cout << "bset4 & bset5: " << (bset4 & bset5) << endl;  // AND: 00001000
    cout << "bset4 | bset5: " << (bset4 | bset5) << endl;  // OR:  00001110
    cout << "bset4 ^ bset5: " << (bset4 ^ bset5) << endl;  // XOR: 00000110

    cout << "Todos los bits de bset4 están en 1? " << (bset4.all() ? "Sí" : "No") << endl;  // No
    cout << "Algún bit de bset4 está en 1? " << (bset4.any() ? "Sí" : "No") << endl;  // Sí
    cout << "Ningún bit de bset4 está en 1? " << (bset4.none() ? "Sí" : "No") << endl;  // No
    cout << "Número de bits en 1 en bset4: " << bset4.count() << endl;  // 2

    bset4.flip();  // Invierte todos los bits
    cout << "Después de invertir bset4: " << bset4 << endl;  // Salida: 11110011

    bitset<8> bset6(string("10010101"));  // 10010101
    cout << "bset6: " << bset6 << endl;  // Salida: 10010101

    // Convertir a unsigned long
    cout << "Como número entero (unsigned long): " << bset6.to_ulong() << endl;  // Convierte a unsigned long: 149

    // Convertir a int (deberás asegurarte de que el valor esté dentro del rango de int)
    cout << "Como número entero (int): " << static_cast<int>(bset6.to_ulong()) << endl;  // Convierte a int: 149

    // Convertir a long long
    cout << "Como número entero (long long): " << static_cast<long long>(bset6.to_ulong()) << endl;  // Convierte a long long: 149

    cout << "Como string: " << bset6.to_string() << endl;  // Convierte a string: "10010101"
    
    return 0;
}
