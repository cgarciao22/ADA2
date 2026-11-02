#include "testMult.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "clasica.hpp"
#include "karatsuba.hpp"

using namespace std;

struct CasoPrueba
{
    string nombre;
    string A;
    string B;
};

void validar()
{
    vector<CasoPrueba> casos = {
        // 1. Números de 1 dígito
        {"1 dígito simples", "7", "8"},
        {"1 dígito ceros", "0", "5"},

        // 2. Operandos con muchos ceros a la izquierda
        {"Ceros a la izquierda", "00001234", "005678"},
        {"Ceros a la izquierda", "00000001234", "00000054878"},

        // 3. Factores con ceros intercalados
        {"Ceros intercalados", "1005", "2003"},
        {"Ceros intercalados", "102030", "405060"},

        // 4. Longitudes impares antes del relleno
        {"Longitudes impares", "123", "456"},
        {"Longitudes impares asimétricas", "7", "989"},

        // 5. Producto grande
        {
            "Producto grande",
            "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210"
            "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210"
            "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210",

            "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
            "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
            "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"}};

    int pasadas = 0;
    int fallidas = 0;
    vector<string> failed;

    for (size_t i = 0; i < casos.size(); i++)
    {
        cout << "\n[Prueba " << (i + 1) << "] " << casos[i].nombre << endl;
        cout << "  A: " << casos[i].A << endl;
        cout << "  B: " << casos[i].B << endl;

        string resClasico = multiplicacionClasica(casos[i].A, casos[i].B);
        string resKaratsuba = karatsuba(casos[i].A, casos[i].B, 62);

        cout << "  Clásico:   " << resClasico << endl;
        cout << "  Karatsuba: " << resKaratsuba << endl;

        if (resClasico == resKaratsuba)
        {
            cout << "  [ÉXITO] Los resultados coinciden." << endl;
            pasadas++;
        }
        else
        {
            cout << "  [FALLO] Los resultados difieren" << endl;
            fallidas++;
            failed.push_back(casos[i].nombre);
        }
    }

    cout << "\n                 RESUMEN DE PRUEBAS               " << endl;

    cout << "Pruebas exitosas: " << pasadas << "/" << casos.size() << endl;
    cout << "Pruebas fallidas: " << fallidas << "/" << casos.size() << endl;

    if (fallidas == 0)
    {
        cout << "\n ¡TODAS LAS PRUEBAS PASARON EXITOSAMENTE!" << endl;
    }
    else
    {
        cout << "\n Hay errores que revisar en la implementación." << endl;
        cout << "Pruebas fallidas: " << fallidas << "/" << casos.size() << endl;
        for (string nombre : failed)
        {
            cout << nombre << " " << '\n';
        }
    }
}
