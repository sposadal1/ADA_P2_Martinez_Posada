#include "operaciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    // Validacion 1: Casos fijos
    BigInt A = {2, 5}; // 52
    BigInt B = {3, 1}; // 13
    
    std::cout << "Prueba Clasica (52 x 13):   ";
    imprimir(multiplicacionClasica(A, B));
    std::cout << "Prueba Karatsuba (52 x 13): ";
    imprimir(karatsuba(A, B));

    // Validacion 2: Comparacion cruzada con 10 digitos aleatorios
    BigInt C = generarBigIntAleatorio(10);
    BigInt D = generarBigIntAleatorio(10);

    BigInt resClasico = multiplicacionClasica(C, D);
    BigInt resKaratsuba = karatsuba(C, D);

    std::cout << "\nPrueba de verificacion (10 digitos aleatorios):" << std::endl;
    std::cout << "Resultado Clasica:   ";
    imprimir(resClasico);
    std::cout << "Resultado Karatsuba: ";
    imprimir(resKaratsuba);

    if (resClasico == resKaratsuba) {
        std::cout << "\n[OK] Los resultados de Karatsuba y Clasica coinciden exitosamente." << std::endl;
    } else {
        std::cout << "\n[ERROR] Los resultados no coinciden." << std::endl;
    }

    return 0;
}