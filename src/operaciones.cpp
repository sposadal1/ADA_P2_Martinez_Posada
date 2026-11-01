#include "operaciones.h"
#include <algorithm>

BigInt sumar(const BigInt& A, const BigInt& B) {
    BigInt res;
    int carry = 0;
    size_t n = std::max(A.size(), B.size());
    
    for (size_t i = 0; i < n || carry; ++i) {
        int sum = carry;
        if (i < A.size()) sum += A[i];
        if (i < B.size()) sum += B[i];
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    return res;
}
