#ifndef LER_ARQUIVOS_H
#define LER_ARQUIVOS_H
#include "definicaoTipos.h"

void escreverAluno(Aluno * person, char* filename);
void lerAluno(Aluno* person, char* filename);

void escreverProfessor(Professor * person, char* filename);
void lerProfessor(Professor* person, char* filename);

void escreverMateria(Materia * person, char* filename);
void lerMateria(Materia* person, char* filename);

void escreverDiretor(Diretor * person, char* filename);
void lerDiretor(Diretor * person, char* filename);

#endif