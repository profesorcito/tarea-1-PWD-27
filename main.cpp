#include <iostream>
#include <cmath>

//condiciones tarifa
double calcularTarifa(int H, int D) {
    //orbitas + de 24 muestra error
    if (H > 24) {
        std::cout << "ERROR: su tarifa pasa las 24 orbitas marcianas" << std::endl;
        return -1;  //-1 = error
    }

    double costoBase;

    if (H == 1) {
        costoBase = 6; //1
    } else if (H >= 2 && H <= 3) {
        costoBase = 6 + (H - 1) * 4; //1 a 3
    } else if (H >= 4 && H <= 5) {
        costoBase = 6 + 2 * 4 + (H - 3) * 3; //3 a 5
    } else {
        costoBase = 22; //+5
    }

    //sabado - domingo
    if (D == 6 || D == 7) {
        costoBase *= 1.15;
    }

    //calcular H
    int sumaDigitos = 0;
    if (H >= 10) {
        sumaDigitos = (H / 10) + (H % 10); //si hay 2 digitos en H
    } else {
        sumaDigitos = H;
    }

    //descuento por multiplo de 3
    if (sumaDigitos % 3 == 0) {
        costoBase *= 0.95; //5%
    }

    return costoBase;
}

//estructura principal
int main() {
    int H, D;
    int opcion;

    do {
        std::cout << "\nCalculadora de Tarifas Marciana:\n";
        std::cout << "1. Ingresar las orbitas y el dia de la semana\n";
        std::cout << "2. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "\nIngrese el numero de orbitas para su estadia: \n";
            std::cin >> H;

            std::cout << "\nDias de la semana en Marte:\n";
            std::cout << "1. Lunes\n";
            std::cout << "2. Martes\n";
            std::cout << "3. Miercoles\n";
            std::cout << "4. Jueves\n";
            std::cout << "5. Viernes\n";
            std::cout << "6. Sabado\n";
            std::cout << "7. Domingo\n";
            std::cout << "Seleccione el dia (1-7): \n";
            std::cin >> D;

            double resultado = calcularTarifa(H, D); //calcula la tarifa

            //-1 = error
            if (resultado == -1) {
                //error programado dentro de la funcion
            } else {
                //resultado con 2 decimales
                std::printf("\nEl costo de las orbitas es: %.2f\n", resultado);
            }
        } else if (opcion == 2) {
            std::cout << "Saliendo del programa...\n";
        } else {
            std::cout << "Opcion invalida, por favor selecciona una opcion entre (1 o 2).\n";
        }

    } while (opcion != 2); //si es 2 sale

    return 0;
}