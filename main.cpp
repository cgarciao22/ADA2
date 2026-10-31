#include <iostream>
#include <string>

using namespace std;

// Declaraciones de las funciones a probar
string multiplicacionClasica(const string &A, const string &B);
string karatsuba(const string &A, const string &B);

int main()
{
    string num1 = "12345678";
    string num2 = "87654321";

    cout << "=== PRUEBA DE MULTIPLICACIÓN ===" << endl;
    cout << "Número 1: " << num1 << endl;
    cout << "Número 2: " << num2 << endl
         << endl;

    string resClasica = multiplicacionClasica(num1, num2);
    cout << "Resultado Clásica:  " << resClasica << endl;

    string resKaratsuba = karatsuba(num1, num2);
    cout << "Resultado Karatsuba: " << resKaratsuba << endl;

    if (resClasica == resKaratsuba)
    {
        cout << "\n Coinciden" << endl;
    }
    else
    {
        cout << "\n Hay diferencia entre los algoritmos." << endl;
    }

    return 0;
}