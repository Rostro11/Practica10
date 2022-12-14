/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author David Rostro Buide
 * @date 13 Dic 2022
 * @brief Este programa lee un fichero con especificación sobre un autómata finito
 *        determinista e imprime por pantalla las características del mismo.
 */

#include "read_DFA.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string kNombreFichero{argv[1]};
  ImprimeCardinal(kNombreFichero);
  ImprimeFuncionTransicion(kNombreFichero);
  return 0;
}
