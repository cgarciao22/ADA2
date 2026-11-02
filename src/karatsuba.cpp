#include "karatsuba.hpp"
#include "clasica.hpp"
#include "operaciones.hpp"
#include <string>
#include <algorithm>

using namespace std;

string rellenarCeros(const string &A, size_t longitud)
{
    if (A.length() >= longitud)
        return A;
    return string(longitud - A.length(), '0') + A;
}

static string karatsubaRec(const string &A, const string &B, int umbral)
{
    size_t n = max(A.length(), B.length());

    // Caso base: clásico para tamaños pequeños
    // mejora al algortimo del umbral sugerida por Claude e implementada debido a la ventaja
    // del método clásico en n pequeños frente a Karatsuba
    if (n <= (size_t)umbral)
        return multiplicacionClasica(A, B);

    if (A.length() != B.length())
        return karatsubaRec(rellenarCeros(A, n), rellenarCeros(B, n), umbral);

    size_t h = n / 2;
    string x1, x0, y1, y0;
    partir(A, n - h, x1, x0);
    partir(B, n - h, y1, y0);

    string pHigh = karatsubaRec(x1, y1, umbral);
    string pLow = karatsubaRec(x0, y0, umbral);
    // CAMBIO CLAVE: recursión interna, sin normalizar ni redondear a 2^k
    string pMid = karatsubaRec(sumar(x1, x0), sumar(y1, y0), umbral);

    string t = restar(restar(pMid, pHigh), pLow);

    return sumar(sumar(desplazar(pHigh, 2 * h), desplazar(t, h)), pLow);
}

string karatsuba(const string &A, const string &B, int umbral)
{
    string a = normalizar(A);
    string b = normalizar(B);
    if (a == "0" || b == "0")
        return "0";
    return karatsubaRec(a, b, max(umbral, 3));
}