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