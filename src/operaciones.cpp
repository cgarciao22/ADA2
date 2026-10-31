#include "operaciones.hpp"
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

string normalizar(const string &A)
{
    int i = 0;
    while (i < A.length() && A[i] == '0')
    {
        i++;
    }
    if (i == A.length())
    {
        return "0";
    }
    string resultado = "";
    while (i < A.length())
    {
        resultado += A[i];
        i++;
    }
    return resultado;
}

string sumar(const string &A, const string &B)
{
    int i = A.length() - 1;
    int j = B.length() - 1;

    string sol = "";
    int acumulado = 0;

    while (i >= 0 || j >= 0 || acumulado > 0)
    {

        int digitoA = (i >= 0) ? A[i] - '0' : 0;
        int digitoB = (j >= 0) ? B[j] - '0' : 0;

        int suma = digitoA + digitoB + acumulado;

        int digito = suma % 10;
        acumulado = suma / 10;

        sol += char('0' + digito);

        i--;
        j--;
    }

    reverse(sol.begin(), sol.end());

    return normalizar(sol);
}

// Devuelve 1 si A > B, 0 si A == B y -1 si A < B.
static int comparar(const string &A, const string &B)
{
    if (A.size() > B.size())
        return 1;
    if (A.size() < B.size())
        return -1;

    if (A > B)
        return 1;
    if (A < B)
        return -1;

    return 0;
}

string restar(string A, string B)
{
    string a = normalizar(A);
    string b = normalizar(B);

    if (comparar(a, b) < 0)
    {
        throw invalid_argument("La resta requiere A >= B");
    }

    int i = a.size() - 1;
    int j = b.size() - 1;

    int prestamo = 0;

    string resultado = "";

    while (i >= 0)
    {

        int digitoA = (a[i] - '0') - prestamo;
        int digitoB = (j >= 0) ? b[j] - '0' : 0;

        prestamo = 0;

        if (digitoA < digitoB)
        {
            digitoA += 10;
            prestamo = 1;
        }

        int resta = digitoA - digitoB;

        resultado += char('0' + resta);

        i--;
        j--;
    }

    // Invertir y eliminar ceros a la izquierda.
    reverse(resultado.begin(), resultado.end());

    return normalizar(resultado);
}

string desplazar(const string &A, int k)
{
    if (k < 0)
    {
        throw invalid_argument("El desplazamiento debe ser no negativo");
    }
    string numero = normalizar(A);

    if (numero == "0")
    {
        return "0";
    }
    return numero + string(k, '0');
}

void partir(const string &A, int m, string &izquierda, string &derecha)
{
    izquierda = "";

    for (int i = 0; i < m; i++)
    {
        izquierda += A[i];
    }

    derecha = "";

    for (int i = m; i < A.length(); i++)
    {
        derecha += A[i];
    }
}
