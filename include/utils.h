#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>

using BigInt = std::vector<int>;

void imprimir(const BigInt& A);
void trim(BigInt& A);
BigInt generarBigIntAleatorio(int digitos);

#endif
