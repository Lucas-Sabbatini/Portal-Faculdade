#include "solicitacoes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  Solicitacao valor;
  struct no *proximo;
} No;

typedef struct fila {
  No *inicio;
  No *fim;
  int qtd;
} Fila;

Fila *criarFila() {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->qtd = 0;
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

void limparFila(Fila *f) {
  if (f == NULL)
    return;
  while (filaVazia(f) != 0)
    removerFila(f, NULL);
  free(f);
  f = NULL;
}

int inserirFila(Fila *f, Solicitacao it) {
  if (f == NULL)
    return 2;
  No *no = (No *)malloc(sizeof(No));
  no->valor = it;
  no->proximo = NULL;
  if (filaVazia(f) == 0)
    f->inicio = no;
  else
    f->fim->proximo = no;
  f->fim = no;
  f->qtd++;
  return 0;
}

int removerFila(Fila *f, Solicitacao *retorno) {
  if (f == NULL)
    return 2;
  if (filaVazia(f) == 0)
    return 1;
  No *temp = f->inicio;
  f->inicio = temp->proximo;
  *retorno = temp->valor;
  free(temp);
  if (f->inicio == NULL)
    f->fim = NULL;
  f->qtd--;
  return 0;
}

int filaVazia(Fila *f) {
  if (f == NULL)
    return 2;
  if (f->qtd == 0)
    return 0;
  else
    return 1;
}

void solicitarMatricula(Fila *solicitacoes, int matAluno, int matMateria) {
  Solicitacao s;
  s.tipo = 1;
  s.matAluno = matAluno;
  s.matMateria = matMateria;
  inserirFila(solicitacoes, s);
  printf("Matrícula solicitada\n");
}

void solicitarTrancamento(Fila *solicitacoes, int matAluno, int matMateria) {
  Solicitacao s;
  s.tipo = 2;
  s.matAluno = matAluno;
  s.matMateria = matMateria;
  inserirFila(solicitacoes, s);
  printf("Trancamento solicitado\n");
}