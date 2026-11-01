#include "utils.h"

void imprimir(const BigInt& A) {
    if (A.empty()) {
        std::cout << 0;
        return;
    }
    for (int i = A.size() - 1; i >= 0; --i) {
        std::cout << A[i];
    }
    std::cout << std::endl;
}

void trim(BigInt& A) {
    while (A.size() > 1 && A.back() == 0) {
        A.pop_back();
    }
}

BigInt generarBigIntAleatorio(int digitos) {
    BigInt res(digitos);
    for (int i = 0; i < digitos; ++i) {
        res[i] = rand() % 10;
    }
    if (digitos > 1 && res.back() == 0) {
        res.back() = (rand() % 9) + 1; // Evita cero a la izquierda
    }
    return res;
}