/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author David Rostro Buide
 * @date 12 Dic 2022
 * @brief Este programa, dado un fichero de texto que se pasa por parámetro,
 *        borra las líneas en blanco que contenga.
 */

#include "rotate.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  RuedaVocales(argv[1]);
  return 0;
}
