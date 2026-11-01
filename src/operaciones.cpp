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

// Precondicion: A >= B
BigInt restar(const BigInt& A, const BigInt& B) {
    BigInt res = A;
    int borrow = 0;
    for (size_t i = 0; i < res.size(); ++i) {
        int sub = borrow;
        if (i < B.size()) sub += B[i];
        
        if (res[i] < sub) {
            res[i] += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res[i] -= sub;
    }
    trim(res);
    return res;
}
