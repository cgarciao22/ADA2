#include <string>
#include <vector>
using namespace std;

static string normalizar(const string& A) {

    int i = 0;

    while (i < A.length() && A[i] == '0') {
        i++;
    }

    if (i == A.length()) {
        return "0";
    }

    string resultado = "";

    while (i < A.length()) {
        resultado += A[i];
        i++;
    }

    return resultado;
}


string sumar(const string& A, const string& B){
    int i = A.length() - 1;
    int j = B.length() - 1;
    string sol = "";

    int  acumulado = 0;

    while (i >= 0 || j >= 0 || acumulado > 0) {

        int digitoA = (i >= 0) ? A[i] - '0' : 0;
        int digitoB = (j >= 0) ? B[j] - '0' : 0;

        int suma = digitoA + digitoB + acarreo;

        int digito = suma % 10;
        acumulado = suma / 10;

        resultado += char('0' + digito);

        i--;
        j--;
    }
    
    reverse(sol.begin(), sol.end()); 
    return normalizar(sol); 

}
string restar (string A, string B){

}
string multiplicacionClasica(string A, string B) {  

}

const int b = 10; //base
