#ifndef PILHA_H
#define PILHA_H

typedef struct recado {
  char data[11];
  char descricao[2000];
} Recado;

typedef struct pilha Pilha;

Pilha *criarPilha();
void limparPilha(Pilha *p);
int push(Pilha *p, Recado it);
int pop(Pilha *p, Recado *it);
int pilhaVazia(Pilha *p);
void mostrarPilha(Pilha *p);

#endif