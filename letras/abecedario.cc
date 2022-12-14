/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author David Rostro Buide
 * @date 12 Dic 2022
 * @brief Este programa, almacena las palabras de un fichero pasado por parámetro
 *        el ficheros con nombre A.txt, B.txt ... Z.txt. Estos ficheros contienen
 *        las palabras que empiezan por esas letras.
 */

#include "abecedario.h"

void Usage(int argc, char *argv[]) {
  if (argc > 3) {
    std::cout << argv[0] << ": Ha introducido más de dos parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 2) {
    std::cout << argv[0] << ": Falta un fichero como parámetro." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 1) {
    std::cout << argv[0] << ": Faltan dos ficheros como parámetros." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
}

std::string TextoSinCaracteres(const std::string& nombre_fichero) {
  const char kEspacio{' '};
  std::string textolimpio{""};
  std::ifstream fichero{nombre_fichero, std::ios_base::in};
  /// Leemos las líneas del fichero
  std::string linea;
  while (getline(fichero, linea)) {
    for (const auto &caracter_actual : linea) {
      if (isalpha(caracter_actual) or caracter_actual == kEspacio) { /// Quitamos todo lo que no sea espacios o letras
        textolimpio += caracter_actual;
      }
    }
    textolimpio += kEspacio;
  }
  return textolimpio;
}

void SeparaEnFicherosAlfabeticamente(const std::string& texto) {
  const char kEspacio{' '};
  std::string palabra{""};
  for (const auto &caracter_actual : texto) { 
    if (caracter_actual == kEspacio) { /// Terminamos una palabra
      std::string primera_letra;
      primera_letra = toupper(palabra.at(0));
      std::ofstream fichero_salida{(primera_letra + ".txt"), std::ios_base::app}; /// Almacenamos en su fichero
      fichero_salida << palabra << std::endl;
      palabra = ""; /// Reiniciamos la palabra
    } else {
      palabra += caracter_actual;
    }
  }
}
