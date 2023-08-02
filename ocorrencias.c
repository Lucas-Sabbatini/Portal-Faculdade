#include "ocorrencias.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  Ocorrencia valor;
  struct no *prox;
} No;

typedef struct listaOcorrencias {
  No *topo;
} ListaOcorrencias;

ListaOcorrencias *criarOcorrencias() {
  ListaOcorrencias *p = (ListaOcorrencias *)malloc(sizeof(ListaOcorrencias));
  p->topo = NULL;
  return p;
}

void limparOcorrencias(ListaOcorrencias *p) {
  Ocorrencia o;
  if (p == NULL)
    return;
  Recado r;
  while (listaOcorrenciaVazia(p) != 0)
    removerInicioOcorrencia(p, &o);
  free(p);
  p = NULL;
}

int inserirInicioOcorrencia(ListaOcorrencias *p, Ocorrencia it) {
  if (p == NULL)
    return 2;
  No *no = (No *)malloc(sizeof(No));
  no->valor = it;
  no->prox = p->topo;
  p->topo = no;
  return 0;
}

int removerInicioOcorrencia(ListaOcorrencias *p, Ocorrencia *it) {
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

int listaOcorrenciaVazia(ListaOcorrencias *p) {
  if (p == NULL)
    return 2;
  if (p->topo == NULL)
    return 0;
  else
    return 1;
}

void adicionarOcorrencia(ListaOcorrencias *p) {
  Ocorrencia o;
  printf("Digite o numero de matrícula do aluno ");
  scanf("%d", &o.matAluno);
  fgetc(stdin);
  printf("Agora digite a data da ocorrencia: ");
  fgets(o.data, 11, stdin);
  fgetc(stdin);
  printf("Agora digite a descrição da ocorrencia:  ");
  fgets(o.descricao, 2000, stdin);

  inserirInicioOcorrencia(p, o);
}

void mostrarOcorrencias(ListaOcorrencias *p, int matAluno) {
  if (p == NULL)
    return;
  No *noatual = p->topo;
  int i = 1;
  while (noatual != NULL) {
    if (noatual->valor.matAluno == matAluno) {
      printf("Ocorrencia [%d]---------\n", i);
      printf("Data: %s\n", noatual->valor.data);
      printf("Descrição: %s\n", noatual->valor.descricao);
      i++;
    }
    noatual = noatual->prox;
  }
  if (i == 1)
    printf("Você não tem ocorrencias na sua ficha!");
}

void removerOcorrencia(ListaOcorrencias *p) {
  if (p == NULL)
    return;
  No *noatual = p->topo;
  No *noanterior;
  int matAluno;

  printf("Digite o numero de matricula do aluno para remover uma ocorrencia da "
         "sua ficha: ");
  scanf("%d", &matAluno);

  while (noatual != NULL) {
    if (noatual->valor.matAluno == matAluno) {
      noanterior->prox = noatual->prox;
      free(noatual);
      printf("Ocorrencia removida\n");
      return;
    }
    noanterior = noatual;
    noatual = noatual->prox;
  }
  printf("Aluno não encontrado");
}