#include <iostream>

// Función para calcular el factorial de un número
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Función para calcular permutaciones
unsigned long long calcularPermutaciones(int n, int r) {
    std::cout << "Calculando permutaciones..." << std::endl;
    std::cout << "P(" << n << ", " << r << ") = " << n << "! / (" << n << " - " << r << ")!" << std::endl;
    std::cout << "P(" << n << ", " << r << ") = " << factorial(n) << " / (" << factorial(n - r) << ")" << std::endl;
    return factorial(n) / factorial(n - r);
}

// Función para calcular combinaciones
unsigned long long calcularCombinaciones(int n, int r) {
    std::cout << "Calculando combinaciones..." << std::endl;
    std::cout << "C(" << n << ", " << r << ") = " << n << "! / (" << r << "!) * (" << n << " - " << r << ")!" << std::endl;
    std::cout << "C(" << n << ", " << r << ") = " << factorial(n) << " / (" << factorial(r) << " * " << factorial(n - r) << ")" << std::endl;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    std::cout << "Calculadora de permutaciones, combinaciones y coeficientes binomiales" << std::endl;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;
    std::cout << "Ingrese el valor de r: ";
    std::cin >> r;

    // Calcular y mostrar permutaciones
    unsigned long long permutaciones = calcularPermutaciones(n, r);
    std::cout << "Permutaciones (P): " << permutaciones << std::endl;

    // Calcular y mostrar combinaciones
    unsigned long long combinaciones = calcularCombinaciones(n, r);
    std::cout << "Combinaciones (C): " << combinaciones << std::endl;

    return 0;
}
