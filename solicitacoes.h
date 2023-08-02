#ifndef SOLICITACOES_H
#define SOLICITACOES_H

typedef struct solicitacao {
  int matMateria;
  int matAluno;
  int tipo; // 1- Matricula 2- Trancamento
} Solicitacao;

typedef struct fila Fila;

Fila *criarFila();
void limparFila(Fila *f);
int inserirFila(Fila *f, Solicitacao it);
int removerFila(Fila *f, Solicitacao *retorno);
int filaVazia(Fila *f);

void solicitarMatricula(Fila *solicitacoes, int matAluno, int matMateria);
void solicitarTrancamento(Fila *solicitacoes, int matAluno, int matMateria);
#endif