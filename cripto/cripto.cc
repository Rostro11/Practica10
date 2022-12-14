/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author David Rostro Buide
 * @date 12 Dic 2022
 * @brief Este programa encripta y desencripta ficheros.
 */

#include "cripto.h"

void Usage(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << "-- Cifrado de ficheros." << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << argv[0] << "-- Cifrado de ficheros." << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << std::endl;
    std::cout << "fichero_entrada:  Fichero a codificar \n \
                  fichero_salida:   Fichero codificado \n \
                  método:           Indica el método de encriptado \n \
                                      1: Cifrado XOR \n \
                                      2: Cifrado de César \n \
                  password:         Palabra secreta en el caso del método 1, valor de k en el método 2 \n \
                  operación:        Operación a realizar en el fichero \n \
                                      +: encriptar el fichero \n \
                                      -: desencriptar el fichero \n";
    exit(EXIT_SUCCESS);
  }
}

char CodificarCaracterCaesar(const char letra, const int numero) {
  if (isalpha(letra)) {
    if (isupper(letra)) {
      return 'A' + (letra - 'A' + numero) % 26;
    } else {
      return 'a' + (letra - 'a' + numero) % 26;
    }
  } else if (letra == ',') {
    return '-';
  } else if (letra == ' ') {
    return '!';
  } 
  return letra;
}

char DescodificarCaracterCaesar(const char letra, const int numero) {
  if (isalpha(letra)) {
    if (isupper(letra)) {
      return 'A' + (letra - 'A' - numero) % 26;
    } else {
      return 'a' + (letra - 'a' - numero) % 26;
    }
  } else if (letra == '-') {
    return ',';
  } else if (letra == '!') {
    return ' ';
  } 
  return letra;
}

void EncriptarCaesar(const std::string& nombre_fichero_entrada, const std::string& nombre_fichero_salida, const int numero) {
  std::ifstream fichero_entrada{nombre_fichero_entrada, std::ios_base::in};
  std::ofstream fichero_salida{nombre_fichero_salida};
  std::string linea;
  while (getline(fichero_entrada, linea)) {
    for (const auto &caracter_actual : linea) {
      fichero_salida << CodificarCaracterCaesar(caracter_actual, numero);
    }
  }
}

void DesencriptarCaesar(const std::string& nombre_fichero_entrada, const std::string& nombre_fichero_salida, const int numero) {
  std::ifstream fichero_entrada{nombre_fichero_entrada, std::ios_base::in};
  std::ofstream fichero_salida{nombre_fichero_salida};
  std::string linea;
  while (getline(fichero_entrada, linea)) {
    for (const auto &caracter_actual : linea) {
      fichero_salida << DescodificarCaracterCaesar(caracter_actual, numero);
    }
  }
}

void EncriptarXOR(const std::string& nombre_fichero_entrada, const std::string& nombre_fichero_salida, const std::string& contrasena) {
  // std::cout << "Entra en la función XOR." << std::endl;
  std::ifstream fichero_entrada{nombre_fichero_entrada, std::ios_base::in};
  std::ofstream fichero_salida{nombre_fichero_salida, std::ios_base::app};
  std::string linea;
  while (getline(fichero_entrada, linea)) {
    // std::cout << "Linea que mira: " << linea << std::endl;
    std::string linea_encriptada = linea;
    // std::cout << "Linea encriptada (sin encriptar): " << linea_encriptada << std::endl;
    for (int i{0}; i < static_cast<int>(linea.length()); i ++) {
      // std::cout << "Ha entrado en el bucle for." << std::endl;
      linea_encriptada[i] = linea[i] ^ contrasena[i % (sizeof(contrasena) / sizeof(char))];
      // std::cout << "Ha encriptado esto: " << linea_encriptada[i] << std::endl;
    }
    fichero_salida << linea_encriptada;
  }
}

std::string OperarContrasena(const std::string& contrasena) {
  std::string nueva_contrasena;
  for (const auto &caracter_actual : contrasena) {
    nueva_contrasena += caracter_actual ^ 128;
  }
  return nueva_contrasena;
}
