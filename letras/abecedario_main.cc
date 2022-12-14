/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Esther M. Quintero
 * @date 12 Dic 2021
 * @brief Este programa, almacena las palabras de un fichero pasado por parámetro
 *        el ficheros con nombre A.txt, B.txt ... Z.txt. Estos ficheros contienen
 *        las palabras que empiezan por esas letras.
 */
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author David Rostro Buide
 * @date 12 Dic 2022
 * @brief Este programa lee un fichero con especificación sobre un autómata finito
 *        determinista e imprime por pantalla las características del mismo.
 */

#include "abecedario.h"

int main(int argc, char* argv[]) {
  // Usage(argc, argv);
  const std::string kNombreFichero{argv[1]};
  std::string textoficherosolopalabras{TextoSinCaracteres(kNombreFichero)};
  SeparaEnFicherosAlfabeticamente(textoficherosolopalabras);
  return 0;
}
