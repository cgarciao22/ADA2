#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string multiplicacionClasica(const string &A, const string &B)
{

    if (A == "0" || B == "0")
    {
        return "0";
    }

    vector<int> parcial(A.length() + B.length(), 0);

    for (int i = A.length() - 1; i >= 0; i--)
    {

        for (int j = B.length() - 1; j >= 0; j--)
        {
            // Convertir los caracteres en numeros
            int digitoA = A[i] - '0';
            int digitoB = B[j] - '0';

            int producto = digitoA * digitoB;

            int posicion = i + j + 1;

            int suma = producto + parcial[posicion];

            parcial[posicion] = suma % 10;

            // acumulado
            parcial[posicion - 1] += suma / 10;
        }
    }

    string sol = "";

    for (int i = 0; i < parcial.size(); i++)
    {
        sol += char('0' + parcial[i]);
    }

    int i = 0;

    while (i < sol.length() && sol[i] == '0')
    {
        i++;
    }

    sol = sol.substr(i);

    return sol;
}