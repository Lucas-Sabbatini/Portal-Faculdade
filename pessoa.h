#include "pilha.h"
#include "solicitacoes.h"
#include "ocorrencias.h"
#include "notasfaltas.h"

typedef struct listaOcorrencias ListaOcorrencias;
typedef struct listaMaterias ListaMaterias;
typedef struct listaNotas ListaNotas;

#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa {
  int mat;
  char senha[10];
  char nome[30];
  int type; // 1-> diretor 2-> aluno 3-> professor
} Pessoa;

typedef struct lista Lista;
typedef struct no No;

Lista *criar();
void limpa(Lista *l);

int inserirInicio(Lista *l, Pessoa it);
int inserirFim(Lista *l, Pessoa it);
int inserirPosicao(int pos, Lista *l, Pessoa it);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(int pos, Lista *l);
int removerItem(Lista *l, Pessoa it);

int buscarItemChave(Lista *l, int chave, Pessoa *retorno);
int buscarPosicao(Lista *l, int pos, Pessoa *retorno);

int listaVazia(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);

int existeAluno(Lista *l, int mat);
int nomeAluno(int mat, char *nome, Lista *pessoas);

void aluno(Lista *l, Pessoa it, Pilha *recados, Fila *solicitacoes,
           ListaMaterias *materias, ListaNotas *notas,
           ListaOcorrencias *ocorrencias);

void diretor(Lista *l, Pessoa it, Pilha *recados, Fila *solicitacoes,
             ListaMaterias *materias, ListaOcorrencias *ocorrencias);

void professor(Lista *l, Pessoa it, Pilha *recados, Fila *solicitacoes,
               ListaMaterias *materias, ListaNotas *notas,
               ListaOcorrencias *ocorrencias);

#endif