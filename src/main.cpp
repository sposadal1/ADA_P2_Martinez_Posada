#include "operaciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>

void medirTiempos(int digitos) {
    BigInt A = generarBigIntAleatorio(digitos);
    BigInt B = generarBigIntAleatorio(digitos);

    // Medicion Clasica
    auto inicioClasico = std::chrono::high_resolution_clock::now();
    BigInt resClasico = multiplicacionClasica(A, B);
    auto finClasico = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempoClasico = finClasico - inicioClasico;

    // Medicion Karatsuba
    auto inicioKaratsuba = std::chrono::high_resolution_clock::now();
    BigInt resKaratsuba = karatsuba(A, B);
    auto finKaratsuba = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempoKaratsuba = finKaratsuba - inicioKaratsuba;

    // Verificación de corrección
    bool correcto = (resClasico == resKaratsuba);

    std::cout << std::setw(10) << digitos 
              << std::setw(18) << std::fixed << std::setprecision(3) << tiempoClasico.count()
              << std::setw(18) << std::fixed << std::setprecision(3) << tiempoKaratsuba.count()
              << std::setw(15) << (correcto ? "PASO" : "ERROR") << std::endl;
}

int main() {
    srand(time(0));

    std::cout << "      BENCHMARK: MULTIPLICACION CLASICA VS KARATSUBA      " << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::setw(10) << "Digitos (N)" 
              << std::setw(18) << "Clasica (ms)" 
              << std::setw(18) << "Karatsuba (ms)" 
              << std::setw(15) << "Estado" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    std::vector<int> tamanos = {100, 500, 1000, 2000, 5000};
    for (int n : tamanos) {
        medirTiempos(n);
    }

    return 0;
}