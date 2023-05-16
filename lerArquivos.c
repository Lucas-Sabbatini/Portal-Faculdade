#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerArquivos.h"
#include "definicaoTipos.h"



void escreverMateria(Materia *person, char *filename){
  FILE *outfile;
  outfile = fopen(filename, "wb");
  if(outfile != NULL) {
    // Write the struct to file
    fwrite(person, sizeof(Materia), 1, outfile);
    fclose(outfile);
  }
}

void lerMateria(Materia *person, char *filename){
  FILE *infile;
  infile = fopen(filename, "rb");
  if(infile != NULL) {
    // Read the struct from file
    fread(person, sizeof (Materia), 1, infile);
    fclose(infile);
  }
}
