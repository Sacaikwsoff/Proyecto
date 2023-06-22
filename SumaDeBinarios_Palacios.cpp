//Autor Palacios Pérez Julio César
#include <iostream>
#include <vector>
#include <algorithm>

// Función para sumar dos números binarios
std::vector<int> sumarBinarios(const std::vector<int>& binario1, const std::vector<int>& binario2) {
    int tamaño1 = binario1.size();
    int tamaño2 = binario2.size();
    int tamañoMaximo = std::max(tamaño1, tamaño2);

    std::vector<int> resultado;
    int carry = 0;

    std::cout << "Suma de los números binarios:" << std::endl;
    std::cout << "  ";
    for (int i = tamaño1 - 1; i >= 0; --i) {
        std::cout << binario1[i];
    }
    std::cout << std::endl << "+ ";
    for (int i = tamaño2 - 1; i >= 0; --i) {
        std::cout << binario2[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < tamañoMaximo; ++i) {
        int bit1 = (i < tamaño1) ? binario1[i] : 0;
        int bit2 = (i < tamaño2) ? binario2[i] : 0;

        int suma = bit1 + bit2 + carry;
        int bitSuma = suma % 2;
        carry = suma / 2;

        resultado.push_back(bitSuma);
    }

    if (carry != 0) {
        resultado.push_back(carry);
    }

    std::reverse(resultado.begin(), resultado.end());

    std::cout << "--------------------" << std::endl;
    std::cout << "  ";
    for (int i = 0; i < resultado.size(); ++i) {
        std::cout << resultado[i];
    }
    std::cout << std::endl << std::endl;

    return resultado;
}

// Función para convertir un número binario a decimal
int binarioADecimal(const std::vector<int>& binario) {
    int decimal = 0;
    int tamaño = binario.size();
    int potencia = 1;
    for (int i = tamaño - 1; i >= 0; --i) {
        decimal += binario[i] * potencia;
        potencia *= 2;
    }
    return decimal;
}

int main() {
    std::vector<int> binario1;
    std::vector<int> binario2;
    char bit;

    std::cout << "Ingrese el primer número binario (bits de derecha a izquierda): ";
    std::cin >> bit;
    while (bit != '\n') {
        binario1.push_back(bit - '0');
        std::cin.get(bit);
    }

    std::cout << "Ingrese el segundo número binario (bits de derecha a izquierda): ";
    std::cin >> bit;
    while (bit != '\n') {
        binario2.push_back(bit - '0');
        std::cin.get(bit);
    }

    std::reverse(binario1.begin(), binario1.end());
    std::reverse(binario2.begin(), binario2.end());

    std::vector<int> resultado = sumarBinarios(binario1, binario2);

    std::cout << "¿Desea convertir el resultado a número decimal? (S/N): ";
    char opcion;
    std::cin >> opcion;

    if (opcion == 'S' || opcion == 's') {
        int decimal = binarioADecimal(resultado);
        std::cout << "El resultado en decimal es: " << decimal << std::endl;
    }

    return 0;
}
