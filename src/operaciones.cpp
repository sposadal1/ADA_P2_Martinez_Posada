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

// Devuelve A * 10^k insertando k ceros al inicio (representacion Little-Endian)
BigInt desplazar(const BigInt& A, int k) {
    if (A.size() == 1 && A[0] == 0) return A;
    BigInt res = A;
    res.insert(res.begin(), k, 0);
    return res;
}

// Separa A en su mitad alta y baja respecto a la posicion m.
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

// Algoritmo de multiplicacion clasica de orden cuadratico.
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

// Algoritmo de multiplicacion de Karatsuba O(n^1.585)
BigInt karatsuba(const BigInt& A, const BigInt& B) {
    // Caso base: Para numeros pequeños (<= 4 digitos), la multiplicacion clasica es mas eficiente
    if (A.size() <= 4 || B.size() <= 4) {
        return multiplicacionClasica(A, B);
    }

    // Proximos commits: division en mitades y llamadas recursivas
    return {0}; 
}