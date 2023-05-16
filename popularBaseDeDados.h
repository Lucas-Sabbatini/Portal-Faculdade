#ifndef POPULAR_BASE_DE_DADOS_H
#define POPULAR_BASE_DE_DADOS_H


#include "definicaoTipos.h"

Aluno *criaAluno();
Professor *criaProfessor();
Materia *criaMateria();
Diretor *criaDiretor();
MateriaAluno *criaMateriaAluno(Materia *m);
Ocorrencia *criaOcorrencia();

#endif