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

BigInt desplazar(const BigInt& A, int k) {
    if (A.size() == 1 && A[0] == 0) return A;
    BigInt res = A;
    res.insert(res.begin(), k, 0);
    return res;
}

void partir(const BigInt& A, int m, BigInt& alta, BigInt& baja) {
    int n = A.size();
    if (n <= m) {
        baja = A;
        alta = {0};
    } else {
        baja = BigInt(A.begin(), A.begin() + m);
        alta = BigInt(A.begin() + m, A.end());
    }
    trim(alta);
    trim(baja);
}

BigInt multiplicacionClasica(const BigInt& A, const BigInt& B) {
    if ((A.size() == 1 && A[0] == 0) || (B.size() == 1 && B[0] == 0)) return {0};
    
    BigInt res(A.size() + B.size(), 0);
    for (size_t i = 0; i < A.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < B.size() || carry; ++j) {
            long long cur = res[i + j] + A[i] * 1LL * (j < B.size() ? B[j] : 0) + carry;
            res[i + j] = cur % 10;
            carry = cur / 10;
        }
    }
    trim(res);
    return res;
}

BigInt karatsuba(const BigInt& A, const BigInt& B) {
    if (A.size() <= 4 || B.size() <= 4) {
        return multiplicacionClasica(A, B);
    }

    int m = std::max(A.size(), B.size()) / 2;

    BigInt A_alta, A_baja;
    BigInt B_alta, B_baja;

    partir(A, m, A_alta, A_baja);
    partir(B, m, B_alta, B_baja);

    BigInt P1 = karatsuba(A_alta, B_alta);
    BigInt P2 = karatsuba(A_baja, B_baja);
    
    BigInt suma_A = sumar(A_alta, A_baja);
    BigInt suma_B = sumar(B_alta, B_baja);
    BigInt P3 = karatsuba(suma_A, suma_B);

    // P_medio = P3 - P1 - P2
    BigInt P_medio = restar(restar(P3, P1), P2);

    // Ensamblar: P1 * 10^(2m) + P_medio * 10^m + P2
    BigInt term1 = desplazar(P1, 2 * m);
    BigInt term2 = desplazar(P_medio, m);

    BigInt res = sumar(sumar(term1, term2), P2);
    trim(res);
    return res;
}