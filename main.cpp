//CDSC Tarea_1 "Marciana"
#include <iostream>

using namespace std;

//calculadora de tarifa
int sumaDigitos(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

//parametros de tarifa
double calcularTarifa(int orbitas, int dia) {
    const double TARIFA_PRIMERA_ORBITA = 6.00;
    const double TARIFA_1_A_3 = 4.00;
    const double TARIFA_3_A_5 = 3.00;
    const double TARIFA_FIJA = 22.00;
    const int LIMITE_ORBITAS = 24;
    const double INCREMENTO_FIN_SEMANA = 1.15;
    const double DESCUENTO_DIGITOS = 0.95;

    //lim horas
    if (orbitas > LIMITE_ORBITAS) {
        return -1;
    }

    double totalPagar = 0.0;

    //tarifas entre semana
    if (orbitas == 1) {
        totalPagar = TARIFA_PRIMERA_ORBITA;
    } else if (orbitas > 1 && orbitas <= 3) {
        totalPagar = TARIFA_PRIMERA_ORBITA + (orbitas - 1) * TARIFA_1_A_3;
    } else if (orbitas > 3 && orbitas <= 5) {
        totalPagar = TARIFA_PRIMERA_ORBITA + 2 * TARIFA_1_A_3 + (orbitas - 3) * TARIFA_3_A_5;
    } else {
        totalPagar = TARIFA_FIJA;
    }

    //sabados o domingos
    if (dia == 6 || dia == 7) {
        totalPagar *= INCREMENTO_FIN_SEMANA;
    }

    //multiplo de 3
    if (sumaDigitos(orbitas) % 3 == 0) {
        totalPagar *= DESCUENTO_DIGITOS;
    }

    return totalPagar;
}

int main() {
    int orbitas, dia;

    //valores de entrada
//    cout << "Ingrese el número de orbitas y el día de la semana: ";
    cin >> orbitas >> dia;

    double resultado = calcularTarifa(orbitas, dia);
    if (resultado == -1) {
        cout << "ERROR" << endl;
    } else {
        printf("%.2f\n", resultado);
    }

    return 0;
}
