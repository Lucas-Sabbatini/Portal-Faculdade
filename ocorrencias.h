#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H
#include "materias.h"

typedef struct ocorrencia {
  int matAluno;
  char data[11];
  char descricao[2000];
} Ocorrencia;

typedef struct listaOcorrencias ListaOcorrencias;

ListaOcorrencias *criarOcorrencias();
void limparOcorrencias(ListaOcorrencias *p);
int inserirInicioOcorrencia(ListaOcorrencias *p, Ocorrencia it);
int removerInicioOcorrencia(ListaOcorrencias *p, Ocorrencia *it);
int listaOcorrenciaVazia(ListaOcorrencias *p);

void adicionarOcorrencia(ListaOcorrencias *p);
void removerOcorrencia(ListaOcorrencias *p);

void mostrarOcorrencias(ListaOcorrencias *p, int matAluno);

#endif