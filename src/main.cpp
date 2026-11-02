
#include <iostream>
#include <string>

#include "clasica.hpp"
#include "karatsuba.hpp"
#include "testMult.hpp"

using namespace std;

// Código hecho con apoyo de ChatGPT y revisión de Camila Garcia para probar algoritmo.

void probarMultiplicaciones()
{
    string A, B;

    cout << "\nIngrese el primer numero: ";
    cin >> A;

    cout << "Ingrese el segundo numero: ";
    cin >> B;

    cout << "\n========== RESULTADOS ==========\n";

    string resultadoClasico = multiplicacionClasica(A, B);
    string resultadoKaratsuba = karatsuba(A, B, 32);

    cout << "Multiplicacion clasica: " << resultadoClasico << endl;
    cout << "Multiplicacion Karatsuba: " << resultadoKaratsuba << endl;

    if (resultadoClasico == resultadoKaratsuba)
        cout << "\nLos resultados coinciden correctamente.\n";
    else
        cout << "\nERROR: Los resultados son diferentes.\n";

    cout << "================================\n";
}

int main()
{
    int opcion;

    do
    {
        cout << "\n====================================\n";
        cout << "     MULTIPLICACION DE ENTEROS\n";
        cout << "====================================\n";
        cout << "1. Probar multiplicaciones\n";
        cout << "2. Ejecutar pruebas de validacion\n";
        cout << "3. Salir\n";
        cout << "====================================\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            probarMultiplicaciones();
            break;

        case 2:
            cout << "\nEjecutando pruebas de validacion...\n\n";
            validar();
            break;

        case 3:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion no valida. Intente nuevamente.\n";
            break;
        }

    } while (opcion != 3);

    return 0;
}
