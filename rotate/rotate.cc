/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author David Rostro Buide
 * @date 12 Dic 2022
 * @brief Este programa, dado un fichero de texto que se pasa por parámetro,
 *        rota las vocales minúsculas que encuentra. Cambia a por e, e por i, 
 *        i por o, o por u, u por a.
 */

#include "rotate.h"

void Usage(int argc, char *argv[]) {
  if (argc > 2) {
    std::cout << argv[0] << ": Ha introducido más de un parámetro." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc != 2) {
    std::cout << argv[0] << ": Falta un fichero como parámetro." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
}

bool EsVocalMinuscula(const char letra) {
  return (letra == 'a' or letra == 'e' or letra== 'i' or letra == 'o' or letra == 'u');
}

char VocalRodada(const char vocal) {
  const char kAMinus{'a'}, kEMinus{'e'}, kIMinus{'i'}, kOMinus{'o'}, kUMinus{'u'};
  if (vocal == kAMinus) {
    return kEMinus;
  }
  if (vocal == kEMinus) {
    return kIMinus;
  }
  if (vocal == kIMinus) {
    return kOMinus;
  }
  if (vocal == kOMinus) {
    return kUMinus;
  }
  if (vocal == kUMinus) {
    return kAMinus;
  }
  return 0;
}

int RuedaVocales(const std::string& nombre_fichero) {
  /// Abrimos el fichero de entrada en modo lectura
  std::ifstream fichero_entrada{nombre_fichero, std::ios_base::in};
  /// Leemos las líneas del fichero y las añadimos
  std::string linea;
  std::string texto_con_vocales_rodadas{""};
  while (getline(fichero_entrada, linea)) {
    for (const auto &caracter_actual : linea) {
      if (EsVocalMinuscula(caracter_actual)) {
        texto_con_vocales_rodadas += VocalRodada(caracter_actual);
      } else {
        texto_con_vocales_rodadas += caracter_actual;
      }
    }
    texto_con_vocales_rodadas += '\n';
  }
  /// Abrimos el fichero de entrada en modo escritura para sobreescribirlo
  std::ofstream fichero_sobreescrito{nombre_fichero};
  fichero_sobreescrito << texto_con_vocales_rodadas;
  return 0;
}
