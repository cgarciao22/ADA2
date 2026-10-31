#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>
using namespace std;

string normalizar(const string &A);

string sumar(const string &A, const string &B);

string restar(const string A, const string B);

string desplazar(const string &A, int k);

void partir(const string &A, int m, string &izquierda, string &derecha);

#endif