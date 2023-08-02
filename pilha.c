#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  Recado valor;
  struct no *prox;
} No;

typedef struct pilha {
  No *topo;
} Pilha;

Pilha *criarPilha() {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}

void limparPilha(Pilha *p) {
  if (p == NULL)
    return;
  Recado r;
  while (pilhaVazia(p) != 0)
    pop(p, &r);
  free(p);
  p = NULL;
}

int push(Pilha *p, Recado it) {
  if (p == NULL)
    return 2;
  No *no = (No *)malloc(sizeof(No));
  no->valor = it;
  no->prox = p->topo;
  p->topo = no;
  return 0;
}

int pop(Pilha *p, Recado *it) {
  if (p == NULL)
    return 2;
  if (pilhaVazia(p) == 0)
    return 1;
  No *temp = p->topo;
  *it = temp->valor;
  p->topo = temp->prox;
  free(temp);
  return 0;
}

int pilhaVazia(Pilha *p) {
  if (p == NULL)
    return 2;
  if (p->topo == NULL)
    return 0;
  else
    return 1;
}

void mostrarPilha(Pilha *p) {
  if (p != NULL) {
    No *no = p->topo;
    while (no != NULL) {
      printf("Data: %s\n", no->valor.data);
      printf("Descição: %s\n\n", no->valor.descricao);
      no = no->prox;
    }
  }
}