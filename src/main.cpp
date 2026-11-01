#include "operaciones.h"
#include <iostream>

int main() {
    BigInt A = {2, 5}; // 52 (representado en Little-Endian)
    BigInt B = {3, 1}; // 13 (representado en Little-Endian)
    
    std::cout << "Prueba Multiplicacion Clasica: 52 x 13 = ";
    imprimir(multiplicacionClasica(A, B)); // Debe imprimir 676
    
    return 0;
}