#ifndef NOTAFALTAS_H
#define NOTAFALTAS_H
#include "materias.h"

typedef struct Nota {
  int nota[4];
  int materia;
  int matricula;
  int faltas;
} Nota;

typedef struct listaNotas ListaNotas;
typedef struct noNotas NoNotas;

ListaNotas *criarListaNotasFaltas();
int inserirNotas(ListaNotas *ln, ListaMaterias *lm, Lista *l);
int inserirNotasAutomatico(ListaNotas *ln, ListaMaterias *lm, Lista *l, int n1, int n2, int n3,int  n4, int codMat, int codAluno);
int removerNotas(ListaNotas *ln, Lista *l, ListaMaterias *lm);
int mostrarNotasFaltas(ListaNotas *ln, Pessoa p, ListaMaterias *lm);
int listaNotasVazia(ListaNotas *ln);

int adicionarFaltas(ListaNotas *ln, ListaMaterias *lm);
int removerFaltas(ListaNotas *ln, ListaMaterias *lm);

#endif