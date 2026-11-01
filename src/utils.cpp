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
