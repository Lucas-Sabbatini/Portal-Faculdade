#include <stdio.h>
#include <stdlib.h>
#include "lerArquivos.h"
#include "definicaoTipos.h"
#include "popularBaseDeDados.h"


int main() {
  
  Materia *m = criaMateria();
  escreverMateria(m,"data/materias/teste");
  Materia *teste = (Materia *) malloc(sizeof(Materia));
  lerMateria(teste,"data/materias/teste");
  printf("%s",teste->nome);
  return 0;
}