#include "operaciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>

BigInt stringToBigInt(const std::string& str) {
    BigInt res;
    for (int i = str.size() - 1; i >= 0; --i) {
        res.push_back(str[i] - '0');
    }
    trim(res);
    return res;
}

void probarCaso(const std::string& nombre, const std::string& sA, const std::string& sB) {
    BigInt A = stringToBigInt(sA);
    BigInt B = stringToBigInt(sB);
    
    BigInt resC = multiplicacionClasica(A, B);
    BigInt resK = karatsuba(A, B);
    
    bool ok = (resC == resK);
    std::cout << "  - " << std::left << std::setw(38) << nombre << ": " 
              << (ok ? "[OK] PASO" : "[ERROR] FALLO") << std::endl;
}

void ejecutarValidacionesObligatorias() {
    std::cout << "==========================================================" << std::endl;
    std::cout << "     PRUEBAS DE VALIDACION     " << std::endl;
    std::cout << "==========================================================" << std::endl;
    
    probarCaso("1. Numeros de 1 digito", "7", "8");
    probarCaso("2. Ceros intercalados", "1005", "4002");
    probarCaso("3. Longitudes impares (3 vs 5 digitos)", "987", "12345");
    probarCaso("4. Operandos con ceros a la izquierda", "0045", "0120");

    BigInt granA = generarBigIntAleatorio(250);
    BigInt granB = generarBigIntAleatorio(250);
    BigInt resC = multiplicacionClasica(granA, granB);
    BigInt resK = karatsuba(granA, granB);
    std::cout << "  - " << std::left << std::setw(38) << "5. Producto grande (250 digitos)" << ": " 
              << ((resC == resK) ? "[OK] PASO" : "[ERROR] FALLO") << std::endl;
    
    std::cout << "==========================================================" << std::endl << std::endl;
}

void ejecutarBenchmark() {
    std::cout << "==========================================================" << std::endl;
    std::cout << "    BENCHMARK   " << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::setw(10) << "Digitos (N)" 
              << std::setw(18) << "Clasica (ms)" 
              << std::setw(18) << "Karatsuba (ms)" 
              << std::setw(12) << "Estado" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    std::vector<int> tamanos = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    
    for (int n : tamanos) {
        int repeticiones = (n <= 128) ? 50 : (n <= 1024 ? 10 : 2);
        
        double sumaTiempoClasico = 0;
        double sumaTiempoKaratsuba = 0;
        bool todoCorrecto = true;
        volatile size_t preventOptimize = 0;

        for (int r = 0; r < repeticiones; ++r) {
            BigInt A = generarBigIntAleatorio(n);
            BigInt B = generarBigIntAleatorio(n);

            // Medición con std::chrono::steady_clock
            auto t1 = std::chrono::steady_clock::now();
            BigInt resC = multiplicacionClasica(A, B);
            auto t2 = std::chrono::steady_clock::now();
            sumaTiempoClasico += std::chrono::duration<double, std::milli>(t2 - t1).count();

            auto t3 = std::chrono::steady_clock::now();
            BigInt resK = karatsuba(A, B);
            auto t4 = std::chrono::steady_clock::now();
            sumaTiempoKaratsuba += std::chrono::duration<double, std::milli>(t4 - t3).count();

            if (resC != resK) todoCorrecto = false;
            preventOptimize += resC.size() + resK.size();
        }

        double promedioC = sumaTiempoClasico / repeticiones;
        double promedioK = sumaTiempoKaratsuba / repeticiones;

        std::cout << std::setw(10) << n 
                  << std::setw(18) << std::fixed << std::setprecision(4) << promedioC
                  << std::setw(18) << std::fixed << std::setprecision(4) << promedioK
                  << std::setw(12) << (todoCorrecto ? "PASO" : "ERROR") << std::endl;
    }
    std::cout << "==========================================================" << std::endl;
}

int main() {
    srand(time(0));
    ejecutarValidacionesObligatorias();
    ejecutarBenchmark();
    return 0;
}