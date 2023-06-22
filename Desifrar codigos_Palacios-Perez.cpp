#include <iostream>
#include <string>

// Función para cifrar un mensaje utilizando el cifrado César
std::string cifrarCesar(const std::string& mensaje, int clave) {
    std::string mensajeCifrado = "";
    for (char caracter : mensaje) {
        if (std::isalpha(caracter)) {
            char cifrado = std::isupper(caracter) ? 'A' : 'a';
            cifrado = (caracter - cifrado + clave) % 26 + cifrado;
            mensajeCifrado += cifrado;
        } else {
            mensajeCifrado += caracter;
        }
    }
    return mensajeCifrado;
}

// Función para descifrar un mensaje cifrado con el cifrado César
std::string descifrarCesar(const std::string& mensajeCifrado, int clave) {
    return cifrarCesar(mensajeCifrado, 26 - clave);
}

// Función para cifrar un mensaje utilizando el cifrado de Vigenère
std::string cifrarVigenere(const std::string& mensaje, const std::string& clave) {
    std::string mensajeCifrado = "";
    int claveIndex = 0;
    for (char caracter : mensaje) {
        if (std::isalpha(caracter)) {
            char cifrado = std::isupper(caracter) ? 'A' : 'a';
            int desplazamiento = clave[claveIndex] - 'a';
            cifrado = (caracter - cifrado + desplazamiento) % 26 + cifrado;
            mensajeCifrado += cifrado;
            claveIndex = (claveIndex + 1) % clave.length();
        } else {
            mensajeCifrado += caracter;
        }
    }
    return mensajeCifrado;
}

// Función para descifrar un mensaje cifrado con el cifrado de Vigenère
std::string descifrarVigenere(const std::string& mensajeCifrado, const std::string& clave) {
    std::string mensajeDescifrado = "";
    int claveIndex = 0;
    for (char caracter : mensajeCifrado) {
        if (std::isalpha(caracter)) {
            char cifrado = std::isupper(caracter) ? 'A' : 'a';
            int desplazamiento = clave[claveIndex] - 'a';
            cifrado = (caracter - cifrado - desplazamiento + 26) % 26 + cifrado;
            mensajeDescifrado += cifrado;
            claveIndex = (claveIndex + 1) % clave.length();
        } else {
            mensajeDescifrado += caracter;
        }
    }
    return mensajeDescifrado;
}

// Función para cifrar un mensaje utilizando el algoritmo RSA
std::string cifrarRSA(const std::string& mensaje, int clavePublica, int modulo) {
    std::string mensajeCifrado = "";
    for (char caracter : mensaje) {
        int caracterCifrado = static_cast<int>(caracter);
        caracterCifrado = (caracterCifrado * clavePublica) % modulo;
        mensajeCifrado += std::to_string(caracterCifrado) + " ";
    }
    return mensajeCifrado;
}

// Función para descifrar un mensaje cifrado con el algoritmo RSA
std::string descifrarRSA(const std::string& mensajeCifrado, int clavePrivada, int modulo) {
    std::string mensajeDescifrado = "";
    std::string num;
    for (char caracter : mensajeCifrado) {
        if (caracter != ' ') {
            num += caracter;
        } else {
            int caracterDescifrado = std::stoi(num);
            caracterDescifrado = (caracterDescifrado * clavePrivada) % modulo;
            mensajeDescifrado += static_cast<char>(caracterDescifrado);
            num = "";
        }
    }
    return mensajeDescifrado;
}

int main() {
    int opcion;
    std::string mensaje, clave;
    int claveCesar, clavePublica, clavePrivada, modulo;

    std::cout << "Seleccione el algoritmo de cifrado:" << std::endl;
    std::cout << "1. Cifrado César" << std::endl;
    std::cout << "2. Cifrado de Vigenère" << std::endl;
    std::cout << "3. RSA" << std::endl;
    std::cout << "Ingrese su elección (1-3): ";
    std::cin >> opcion;

    if (opcion == 1) {
        std::cout << "Cifrado César seleccionado." << std::endl;
        std::cout << "Ingrese el mensaje a cifrar: ";
        std::cin.ignore();
        std::getline(std::cin, mensaje);
        std::cout << "Ingrese la clave (un número entero): ";
        std::cin >> claveCesar;

        std::string mensajeCifrado = cifrarCesar(mensaje, claveCesar);
        std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;

        std::string mensajeDescifrado = descifrarCesar(mensajeCifrado, claveCesar);
        std::cout << "Mensaje descifrado: " << mensajeDescifrado << std::endl;
    } else if (opcion == 2) {
        std::cout << "Cifrado de Vigenère seleccionado." << std::endl;
        std::cout << "Ingrese el mensaje a cifrar: ";
        std::cin.ignore();
        std::getline(std::cin, mensaje);
        std::cout << "Ingrese la clave (una palabra en minúsculas): ";
        std::cin >> clave;

        std::string mensajeCifrado = cifrarVigenere(mensaje, clave);
        std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;

        std::string mensajeDescifrado = descifrarVigenere(mensajeCifrado, clave);
        std::cout << "Mensaje descifrado: " << mensajeDescifrado << std::endl;
    } else if (opcion == 3) {
        std::cout << "RSA seleccionado." << std::endl;
        std::cout << "Ingrese el mensaje a cifrar: ";
        std::cin.ignore();
        std::getline(std::cin, mensaje);
        std::cout << "Ingrese la clave pública: ";
        std::cin >> clavePublica;
        std::cout << "Ingrese el módulo: ";
        std::cin >> modulo;

        std::string mensajeCifrado = cifrarRSA(mensaje, clavePublica, modulo);
        std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;

        std::cout << "Ingrese la clave privada: ";
        std::cin >> clavePrivada;
        std::string mensajeDescifrado = descifrarRSA(mensajeCifrado, clavePrivada, modulo);
        std::cout << "Mensaje descifrado: " << mensajeDescifrado << std::endl;
    } else {
        std::cout << "Opción inválida. Saliendo del programa." << std::endl;
    }

    return 0;
}
