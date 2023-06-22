#include <iostream>
#include <vector>
#include <cmath>

// Función para convertir un número decimal a binario
std::vector<int> decimalABinario(int decimal) {
    std::vector<int> binario;
    std::cout << "Para convertir el número decimal " << decimal << " a binario, seguimos estos pasos:" << std::endl;
    std::cout << "Dividimos el número decimal " << decimal << " entre 2:" << std::endl;
    while (decimal > 0) {
        int residuo = decimal % 2;
        decimal /= 2;
        std::cout << "División: " << decimal << " cociente, " << residuo << " residuo" << std::endl;
        binario.insert(binario.begin(), residuo);
    }
    std::cout << std::endl;
    return binario;
}

// Función para convertir un número binario a decimal
int binarioADecimal(const std::vector<int>& binario) {
    int decimal = 0;
    int tamaño = binario.size();
    std::cout << "Para convertir el número binario ";
    for (int i = 0; i < tamaño; ++i) {
        std::cout << binario[i];
        if (i != tamaño - 1)
            std::cout << " ";
        decimal += binario[i] * std::pow(2, tamaño - 1 - i);
    }
    std::cout << " a decimal, seguimos estos pasos:" << std::endl;

    std::cout << "Multiplicamos cada bit por la potencia correspondiente de 2:" << std::endl;
    for (int i = 0; i < tamaño; ++i) {
        std::cout << binario[i] << " * 2^" << tamaño - 1 - i;
        if (i != tamaño - 1)
            std::cout << " + ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return decimal;
}

int main() {
    int opcion;
    bool continuar = true;

    std::cout << "¡Bienvenido al convertidor decimal-binario!" << std::endl;

    do {
        std::cout << "Por favor, seleccione una opción:" << std::endl;
        std::cout << "1. Convertir de decimal a binario" << std::endl;
        std::cout << "2. Convertir de binario a decimal" << std::endl;
        std::cout << "3. Salir del programa" << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int decimal;
                std::cout << "Introduzca el número decimal que desea convertir: ";
                std::cin >> decimal;
                std::vector<int> binario = decimalABinario(decimal);
                std::cout << "El número decimal " << decimal << " en binario es: ";
                for (int i = 0; i < binario.size(); ++i) {
                    std::cout << binario[i];
                }
                std::cout << std::endl;
                break;
            }
            case 2: {
                std::vector<int> binario;
                char bit;
                std::cout << "Introduzca el número binario que desea convertir (bits de izquierda a derecha): ";
                std::cin >> bit;
                while (bit != '\n') {
                    binario.push_back(bit - '0');
                    std::cin.get(bit);
                }
                int decimal = binarioADecimal(binario);
                std::cout << "El número binario ";
                for (int i = 0; i < binario.size(); ++i) {
                    std::cout << binario[i];
                }
                std::cout << " en decimal es: " << decimal << std::endl;
                break;
            }
            case 3:
                continuar = false;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
                break;
        }

        if (continuar) {
            char decision;
            std::cout << "¿Desea sumar más números? (S/N): ";
            std::cin >> decision;
            if (decision != 'S' && decision != 's') {
                continuar = false;
            }
            std::cout << std::endl;
        }
    } while (continuar);

    std::cout << "¡Gracias por usar el convertidor! ¡Hasta luego!" << std::endl;

    return 0;
}
