#include "clasica.hpp"
#include "karatsuba.hpp"

#include <chrono>
#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

size_t sink = 0;

string randomNum(int n, mt19937 &gen)
{
    uniform_int_distribution<int> primero(1, 9), resto(0, 9);
    string s(n, '0');
    s[0] = '0' + primero(gen);
    for (int i = 1; i < n; i++)
        s[i] = '0' + resto(gen);
    return s;
}

template <class F>
double medirNs(F f, const string &A, const string &B)
{
    // Calentamiento + calibración: duplicar reps hasta que el lote dure >= 20 ms
    long long reps = 1;
    while (true)
    {
        auto t0 = steady_clock::now();
        for (long long i = 0; i < reps; i++)
            sink += f(A, B).back();
        auto t1 = steady_clock::now();
        if (duration_cast<milliseconds>(t1 - t0).count() >= 20)
            break;
        reps *= 2;
    }

    vector<double> tandas;
    for (int k = 0; k < 5; k++)
    {
        auto t0 = steady_clock::now();
        for (long long i = 0; i < reps; i++)
            sink += f(A, B).back();
        auto t1 = steady_clock::now();
        tandas.push_back(duration<double, nano>(t1 - t0).count() / reps);
    }
    sort(tandas.begin(), tandas.end());
    return tandas[2]; // mediana
}

int main()
{
    cout << "INICIANDO ANALISIS EXPERIMENTAL DE ALGORITMOS" << endl;

    mt19937 gen(42);
    ofstream csv("experiments/resultados.csv");
    if (!csv.is_open())
    {
        cerr << "No se pudo abrir experiments/resultados.csv (¿existe la carpeta?)\n";
        return 1;
    }
    csv << "n,clasica_ns,karatsuba_ns\n";

    for (int n = 2; n <= 4096; n *= 2)
    {
        string A = randomNum(n, gen);
        string B = randomNum(n, gen);

        if (multiplicacionClasica(A, B) != karatsuba(A, B))
        {
            cerr << "Resultados distintos para n=" << n << endl;
            return 1;
        }

        double tc = medirNs(multiplicacionClasica, A, B);
        double tk = medirNs(karatsuba, A, B);

        cout << n << "\t\t" << tc << "\t\t" << tk << endl;
        csv << n << "," << tc << "," << tk << "\n";
    }

    csv.close();
    cout << "sink=" << sink << endl;
    return 0;
}