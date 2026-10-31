#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Declaración de auxiliares existentes
string normalizar(const string &A);
string sumar(const string &A, const string &B);
string restar(string A, string B);
string desplazar(const string &A, int k);
void partir(const string &A, int m, string &izquierda, string &derecha);

int nextDos(int n)
{
    int potencia = 1;
    while (potencia < n)
    {
        potencia *= 2;
    }
    return potencia;
}

string rellenarCeros(const string &A, int longitud)
{
    if (A.length() >= longitud)
        return A;

    return string(longitud - A.length(), '0') + A;
}

string karatsuba(const string &A, const string &B);

static string karatsubaRec(const string &A, const string &B)
{
    int n = A.length();

    // base
    if (n == 1)
    {
        int prod = (A[0] - '0') * (B[0] - '0');
        return to_string(prod);
    }

    int m = n / 2;
    string x1, x0, y1, y0;

    partir(A, m, x1, x0);
    partir(B, m, y1, y0);

    string pHigh = karatsubaRec(x1, y1); // P2 (alta * alta)
    string pLow = karatsubaRec(x0, y0);  // P0 (baja * baja)

    // (x1 + x0) * (y1 + y0)
    string xSum = sumar(x1, x0);
    string ySum = sumar(y1, y0);

    string pMid = karatsuba(xSum, ySum);

    string t1 = restar(pMid, pHigh);
    string t2 = restar(t1, pLow);

    // P_high * 10^(2m) + t2 * 10^m + P_low
    string term1 = desplazar(pHigh, 2 * m);
    string term2 = desplazar(t2, m);

    string sumaParcial = sumar(term1, term2);
    return sumar(sumaParcial, pLow);
}

string karatsuba(const string &A, const string &B)
{
    string aNorm = normalizar(A);
    string bNorm = normalizar(B);

    if (aNorm == "0" || bNorm == "0")
    {
        return "0";
    }

    int n = max(aNorm.length(), bNorm.length());
    int longitud = nextDos(n);

    string X = rellenarCeros(aNorm, longitud);
    string Y = rellenarCeros(bNorm, longitud);

    return karatsubaRec(X, Y);
}