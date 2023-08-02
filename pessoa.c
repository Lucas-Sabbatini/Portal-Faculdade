#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  Pessoa valor;
  struct no *prox;
} No;

typedef struct lista {
  No *inicio;
} Lista;

Lista *criar() {
  Lista *l = (Lista *)malloc(sizeof(Lista));
  l->inicio = NULL;
  return l;
}

void limpa(Lista *l) {
  while (listaVazia(l) != 0) {
    removerInicio(l);
  }
}

int listaVazia(Lista *l) {
  if (l == NULL) {
    return 2;
  }
  if (l->inicio == NULL) {
    return 0;
  }
  return 1;
}

int inserirInicio(Lista *l, Pessoa it) {
  if (l == NULL) {
    return 2;
  }
  No *n = (No *)malloc(sizeof(No));
  n->prox = l->inicio;
  l->inicio = n;
  n->valor = it;
  return 0;
}

int inserirFim(Lista *l, Pessoa it) {
  if (l == NULL) {
    return 2;
  }

  if (l->inicio == NULL)
    return inserirInicio(l, it);

  No *n = (No *)malloc(sizeof(No));
  No *noatual = l->inicio;
  while (noatual->prox != NULL) {
    noatual = noatual->prox;
  }
  n->valor = it;
  n->prox = NULL;
  noatual->prox = n;
  return 0;
}

int inserirPosicao(int pos, Lista *l, Pessoa it) {
  if (l == NULL)
    return 2;

  if (pos < 0)
    return 3;

  if (l->inicio == NULL)
    return inserirInicio(l, it);

  int count = 0;
  No *n = (No *)malloc(sizeof(No));
  No *noatual = l->inicio;

  while (count < pos - 1) {
    if (noatual->prox == NULL && count != pos)
      return 1;
    noatual = noatual->prox;
    count++;
  }

  n->valor = it;

  n->prox = noatual->prox;
  noatual->prox = n;
  return 0;
}

int removerInicio(Lista *l) {
  if (l == NULL) {
    return 2;
  }
  if (listaVazia(l) == 0) {
    return 1;
  }
  No *salvo = l->inicio;
  l->inicio = l->inicio->prox;
  free(salvo);
  return 0;
}

int removerFim(Lista *l) {
  if (l == NULL) {
    return 2;
  }
  if (listaVazia(l) == 0) {
    return 1;
  }
  No *noatual = l->inicio;
  No *noanterior;

  while (noatual->prox != NULL) {
    noanterior = noatual;
    noatual = noatual->prox;
  }

  noanterior->prox = NULL;
  free(noatual);
  return 0;
}

int removerPosicao(int pos, Lista *l) {
  if (l == NULL)
    return 2;

  if (listaVazia(l) == 0)
    return 1;

  int count = 0;
  No *noatual = l->inicio;
  No *noanterior;

  while (count < pos) {
    if (noatual->prox == NULL && count != pos)
      return 3;
    noanterior = noatual;
    noatual = noatual->prox;
    count++;
  }

  noanterior->prox = noatual->prox;
  free(noatual);
  return 0;
}

int removerItem(Lista *l, Pessoa it) {
  if (l == NULL)
    return 2;
  if (listaVazia(l) == 0)
    return 1;

  int pos = buscarItemChave(l, it.mat, &it);
  return removerPosicao(pos, l);
}

int buscarItemChave(Lista *l, int chave, Pessoa *retorno) {
  if (l == NULL)
    return 2;
  if (listaVazia(l) == 0)
    return 1;

  int pos = 0;
  No *noatual = l->inicio;

  while (noatual != NULL) {
    if (noatual->valor.mat == chave) {
      *retorno = noatual->valor;
      return pos;
    }
    noatual = noatual->prox;
    pos++;
  }

  return -1;
}

int buscarPosicao(Lista *l, int pos, Pessoa *retorno) {
  if (l == NULL)
    return 2;
  if (listaVazia(l) == 0)
    return 1;

  int count = 0;
  No *noatual = l->inicio;

  while (count < pos) {
    if (noatual->prox == NULL && count != pos)
      return 3;
    noatual = noatual->prox;
    count++;
  }

  retorno = &(noatual->valor);
  return 0;
}

int tamanho(Lista *l) {
  if (l == NULL)
    return -1;

  int count = 1;
  No *noatual = l->inicio;

  while (noatual->prox != NULL) {
    count++;
    noatual = noatual->prox;
  }

  return count;
}

void mostrar(Lista *l) {
  if (l == NULL || listaVazia(l) == 0) {
    printf("A lista está vazia :(");
  } else {
    printf("\n\n-----------------------------------\n");
    No *noatual = l->inicio;
    int count = 0;
    while (noatual != NULL) {
      printf("[%d] ------ %s\n", count + 1, (noatual->valor).nome);
      printf("Matricula: %d\n\n", (noatual->valor).mat);
      noatual = noatual->prox;
      count++;
    }
  }
}

int existeAluno(Lista *l, int mat) {
  if (l == NULL)
    return 2;
  if (listaVazia(l) == 0)
    return 1;

  int P = -1;
  No *noatual = l->inicio;

  while (noatual != NULL) {
    if (noatual->valor.mat == mat) {
      P = 0;
    }
    noatual = noatual->prox;
  }
  if (P == -1)
    return 3;
  else if (P != -1)
    return 0;
}

int nomeAluno(int mat, char *nome, Lista *pessoas) {
  if (pessoas == NULL)
    return 2;
  if (listaVazia(pessoas) == 0)
    return 1;

  No *n = (No *)malloc(sizeof(No));
  n = pessoas->inicio;

  while (n->valor.mat != mat || n != NULL) {
    n = n->prox;
  }
  if (n->valor.mat == mat) {
    for (int i = 0; i < strlen(n->valor.nome); i++) {
      nome[i] = n->valor.nome[i];
    }
    free(n);
    return 0;
  } else {
    printf("Aluno não encontrado.\n");
    free(n);
    return 3;
  }
}

void aluno(Lista *l, Pessoa it, Pilha *recados, Fila *solicitacoes,
           ListaMaterias *materias, ListaNotas *notas,
           ListaOcorrencias *ocorrencias) {
  int ver;
  char ent;
  Materia materia;
  while (1) {
    printf("\nBem vindo, o que gostraia de fazer:\n");
    printf("[1]- Consultar notas e faltas de alguma matéria.\n");
    printf("[2]- Fazer matrícula em alguma matéria.\n");
    printf("[3]- Solicitar trancamento de alguma matéria.\n");
    printf("[4]- Consultar sua ficha de aluno.\n");
    printf("[5]- Ver recados\n");
    printf("[6]- Sair");
    printf("(1,2,3,4,5,6): ");
    scanf(" %c", &ent);
    setbuf(stdin, NULL);

    if (ent == '1') {
      int X;
      X = mostrarNotasFaltas(notas, it, materias);
      if (X != 0) {
        printf("Erro ao mostrar as notas.\n");
      }
    }
    else if (ent == '2') {
      int op;
      printf("\nEm qual matéria vc deseja se matricular?\n");
      for(int i=1; i<100; i++){
        ver = buscarMateria(materias, i, &materia);
        if (ver == -3){
          break;
        }
        printf("[%d]- %s.\n", i, materia.nome);
      }
      scanf("%d", &op);
      solicitarMatricula(solicitacoes, it.mat, op);
    } else if (ent == '3') {
      int op;
      printf("\nEm qual matéria vc deseja solicitar trancamento?\n");
      for(int i=1; i<100; i++){
        ver = buscarMateria(materias, i, &materia);
        if (ver == -3){
          break;
        }
        printf("[%d]- %s.\n", i, materia.nome);
      }
      scanf("%d", &op);
      solicitarTrancamento(solicitacoes, it.mat, op);
    } else if (ent == '4') {
      printf("\nSua ficha de aluno é essa:\n");
      mostrarOcorrencias(ocorrencias, it.mat);
    } else if (ent == '5') {
      printf("\n2Os recados pendentes são: \n");
      mostrarPilha(recados);
    } else if (ent == '6') {
      break;
    } else {
      printf("Opção inválida.");
    }
  }
}

void diretor(Lista *l, Pessoa it, Pilha *recados, Fila *solicitacoes,
             ListaMaterias *materias, ListaOcorrencias *ocorrencias) {
  char ent;
  while (1) {
    printf("\n\nEscolha uma das opções abaixo: \n");
    printf("[1]- Adicionar ou remover um recado.\n");
    printf("[2]- Solicitações de Matrícula ou Trancamento.\n");
    printf("[3]- Adicionar ocorrência.\n");
    printf("[4]- Sair");
    printf("(1,2,3,4):  ");
    scanf(" %c", &ent);
    setbuf(stdin, NULL);

    if (ent == '1') {
      Recado r;
      while (1) {

        printf("\nEscolha uma das opções:\n");
        printf("[1]- Adicionar um recado.\n");
        printf("[2]- Remover um recado.\n");
        scanf(" %c", &ent);
        fgetc(stdin);

        if (ent == '1') {
          printf("Digite a data do recado (dd/mm/aaaa):\n");
          fgets(r.data, 11, stdin);
          fgetc(stdin);
          printf("Digite a descrição do recado:\n");
          fgets(r.descricao, 2000, stdin);
          push(recados, r);
          printf("\nRecado adicionado!");
          break;
        } else if (ent == '2') {
          pop(recados, &r);
          printf("Os recados mais recentes são removidos primeiro.\n");
          printf("Recado removido: \n");
          printf("Data do recado removido: %s\n", r.data);
          printf("Descricao do recado removido: %s\n", r.descricao);
          break;
        } else {
          printf("Opção inválida");
        }
      }
      mostrarPilha(recados);
    } else if (ent == '2') {
      Solicitacao retorno;
      Pessoa alunoSolicitado;
      Materia materiaSolicitada;
      removerFila(solicitacoes, &retorno);
      printf("\nSolicitação atual: \n");
      buscarItemChave(l, retorno.matAluno, &alunoSolicitado);
      buscarMateria(materias, retorno.matMateria, &materiaSolicitada);
      printf("Nome do aluno: %s\n", alunoSolicitado.nome);
      printf("Nome da materia: %s\n", materiaSolicitada.nome);
      printf("Tipo da solicitacao: ");
      if (retorno.tipo == 1) {
        printf("matricula\n");
      } else if (retorno.tipo == 2) {
        printf("trancamento\n");
      }
      printf("Você deseja aprovar ou desaprovar a solicitação (1,2) "
             "respectivamente");
      scanf(" %c", &ent);
      fgetc(stdin);
      if (ent == '1' && retorno.tipo == 1) {
        adicionarAlunoMateriaAutomatico(materias, alunoSolicitado.mat,
                                        materiaSolicitada.codigo);
        printf("Aluno adicionado em %s\n", materiaSolicitada.nome);
      } else if (ent == '1' && retorno.tipo == 2) {
        removerAlunoMateriaAutomatico(materias, alunoSolicitado.mat,
                                      materiaSolicitada.codigo);
        printf("Aluno removido de %s\n", materiaSolicitada.nome);
      } else if (ent == '2') {
        printf("Solicitação Desaprovada\n");
      }

    } else if (ent == '3') {
      int op;
      while (1) {
        printf("\nO que deseja fazer: \n");
        printf("[1]- Adicionar ocorrência na ficha do aluno.\n");
        printf("[2]- Remover ocorrência na ficha do aluno.\n");
        scanf("%d", &op);
        if (op == 1) {
          adicionarOcorrencia(ocorrencias);
          break;
        } else if (op == 2) {
          removerOcorrencia(ocorrencias);
          break;
        }
      }
    } else if (ent == '4') {
      return;
    } else {
      printf("Opção inválida.\n");
    }
  }
}

void professor(Lista *l, Pessoa it, Pilha *recados, Fila *solicitacoes,
               ListaMaterias *materias, ListaNotas *notas,
               ListaOcorrencias *ocorrencias) {
  char ent;
  while (1) {
    printf("\nBem vindo, o que gostraia de fazer:\n");
    printf("[1]- Lançar notas ou faltas para os alunos.\n");
    printf("[2]- Consultar os alunos matriculados em alguma matéria.\n");
    printf("[3]- Adicionar uma ocorrencia à ficha de algum aluno.\n");
    printf("[4]- Adicionar ou remover um recado.\n");
    printf("[5]- Sair.\n");
    printf("(1,2,3,4,5): ");
    scanf(" %c", &ent);
    setbuf(stdin, NULL);
    if (ent == '1') {
      while (1) {
        int op;
        printf("\nO que deseja fazer: \n");
        printf("[1]- Lançar notas.\n");
        printf("[2]- Remover notas.\n");
        printf("[3]- Adicionar faltas.\n");
        printf("[4]- Remover faltas.\n");
        scanf("%d", &op);
        if (op == 1) {
          int X;
          X = inserirNotas(notas, materias, l);
          if (X != 0) {
            printf("Erro ao fazer essa função.\n");
          }
          break;
        } else if (op == 2) {
          int X;
          X = removerNotas(notas, l, materias);
          if (X != 0) {
            printf("Erro ao fazer essa função.\n");
          }
          break;
        } else if (op == 3) {
          int X;
          X = adicionarFaltas(notas, materias);
          if (X != 0) {
            printf("Erro ao fazer essa função.\n");
          }
          break;
        } else if (op == 4) {
          int X;
          X = removerFaltas(notas, materias);
          if (X != 0) {
            printf("Erro ao fazer essa função.\n");
          }
          break;
        } else {
          printf("Opção inválida.\n");
        }
      }
    } 
    else if (ent == '2') {
      int cod;
      printf("Digite o codigo da matéria que deseja conferir:\n");
      scanf("%d", &cod);
      mostrarAlunosMateria(materias, it.mat, l);
    } 
    else if (ent == '3') {
      int op;
      while (1) {
        printf("\nO que deseja fazer: \n");
        printf("[1]- Adicionar ocorrência na ficha do aluno.\n");
        printf("[2]- Remover ocorrência na ficha do aluno.\n");
        scanf("%d", &op);
        if (op == 1) {
          adicionarOcorrencia(ocorrencias);
          break;
        } else if (op == 2) {
          removerOcorrencia(ocorrencias);
          break;
        } else {
          printf("Opção inválida.");
        }
      }
    } 
    else if (ent == '4') {
      Recado r;
      while (1) {

        printf("\nEscolha uma das opções:\n");
        printf("[1]- Adicionar um recado.\n");
        printf("[2]- Remover um recado.\n");
        scanf(" %c", &ent);
        fgetc(stdin);

        if (ent == '1') {
          printf("Digite a data do recado (dd/mm/aaaa):\n");
          fgets(r.data, 11, stdin);
          fgetc(stdin);
          printf("Digite a descrição do recado:\n");
          fgets(r.descricao, 2000, stdin);
          push(recados, r);
          printf("Recado adicionado!\n1");
          break;
        } 
        else if (ent == '2') {
          pop(recados, &r);
          printf("Os recados mais recentes são removidos primeiro.\n");
          printf("Recado removido: \n");
          printf("Data do recado removido: %s\n", r.data);
          printf("Descricao do recado removido: %s\n", r.descricao);
          break;
        } else {
          printf("Opção inválida");
        }
      }
      mostrarPilha(recados);
    } 
    else if (ent == '5') {
      break;
    }
    else {
      printf("Opção inválida.");
    }
  }
}
