#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "utils.h"

BigInt sumar(const BigInt& A, const BigInt& B);
BigInt restar(const BigInt& A, const BigInt& B); 
BigInt desplazar(const BigInt& A, int k);
void partir(const BigInt& A, int m, BigInt& alta, BigInt& baja);

#endif