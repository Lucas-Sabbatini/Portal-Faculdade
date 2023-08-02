#include "notasfaltas.h"
#include "materias.h"
#include "pilha.h"
#include "ocorrencias.h"
#include "pessoa.h"
#include "solicitacoes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct noNotas {
  Nota valor;
  struct noNotas *prox;
} NoNotas;

typedef struct listaNotas {
  NoNotas *inicio;
} ListaNotas;

ListaNotas *criarListaNotasFaltas() {
  ListaNotas *ln = (ListaNotas *)malloc(sizeof(ListaNotas));
  ln->inicio = NULL;
  return ln;
}

int inserirNotas(ListaNotas *ln, ListaMaterias *lm, Lista *l) {
  int n1, n2, n3, n4, mate, matri;

  printf("Digite o código da matéria referente à nota que será adicionada: ");
  scanf("%d", &mate);
  while (existeMateria(lm, mate) != 0) {
    printf("Erro! Matéria não encontrada.\nDigite o código da matéria "
           "referente à nota que será adicionada: ");
    scanf("%d", &mate);
  }

  printf("Digite a matrícula do aluno referente à nota que será adicionada: ");
  scanf("%d", &matri);
  while (existeAluno(l, matri) != 0) {
    printf("Erro! Aluno não encontrado.\nDigite a matrícula do aluno referente "
           "à nota que será adicionada: ");
    scanf("%d", &matri);
  }

  printf("Digite a nota da primeira prova: ");
  scanf("%d", &n1);

  printf("Digite a nota da segunda prova prova: ");
  scanf("%d", &n2);

  printf("Digite a nota da terceira prova: ");
  scanf("%d", &n3);

  printf("Digite a nota da prova substituta: ");
  scanf("%d", &n4);

  if (ln == NULL) {
    return 1;
  } else {
    NoNotas *nn = (NoNotas *)malloc(sizeof(NoNotas));

    nn->prox = ln->inicio;
    ln->inicio = nn;

    nn->valor.nota[0] = n1;
    nn->valor.nota[1] = n2;
    nn->valor.nota[2] = n3;
    nn->valor.nota[3] = n4;
    nn->valor.materia = mate;
    nn->valor.matricula = matri;

    return 0;
  }
}

int inserirNotasAutomatico(ListaNotas *ln, ListaMaterias *lm, Lista *l,int n1, int n2,int  n3,int  n4,int  codMat,int  codAluno){
  
  if(ln == NULL) return 1;
  if(existeMateria(lm, codMat) != 0) return 2;
  if(existeAluno(l, codAluno) != 0) return 3;
  
  NoNotas *nn = (NoNotas *)malloc(sizeof(NoNotas));

  nn->prox = ln->inicio;
  ln->inicio = nn;

  nn->valor.nota[0] = n1;
  nn->valor.nota[1] = n2;
  nn->valor.nota[2] = n3;
  nn->valor.nota[3] = n4;
  nn->valor.materia = codMat;
  nn->valor.matricula = codAluno;

  return 0;
}

int removerNotas(ListaNotas *ln, Lista *l, ListaMaterias *lm) {
  int p, mate, matri;

  if (ln == NULL) {
    return 1;
  } else if (listaNotasVazia(ln) == 0) {
    return 2;
  } else {
    printf("Digite o código da matéria referente à nota que será removida: ");
    scanf("%d", &mate);
    while (existeMateria(lm, mate) != 0) {
      printf("Erro! Matéria não encontrada.\nDigite o código da matéria "
             "referente à nota que será removida: ");
      scanf("%d", &mate);
    }

    printf("Digite a matrícula do aluno referente à nota que será removida: ");
    scanf("%d", &matri);
    while (existeAluno(l, matri) != 0) {
      printf("Erro! Aluno não encontrado.\nDigite a matríccula do aluno "
             "referente à nota que será removida: ");
      scanf("%d", &matri);
    }

    NoNotas *nnant;
    NoNotas *nnatual = ln->inicio;

    while (mate != nnatual->valor.materia &&
           matri != nnatual->valor.matricula && nnatual->prox != NULL) {
      if (nnatual->prox == NULL)
        return 0;
      nnant = nnatual;
      nnatual = nnatual->prox;
    }

    nnant->prox = nnatual->prox;
    free(nnatual);
    return 0;
  }
}

int mostrarNotasFaltas(ListaNotas *ln, Pessoa p, ListaMaterias *lm) {

  int count = 0;
  if (ln == NULL) {
    return 1;
  } else if (listaNotasVazia(ln) == 0) {
    return 2;
  } else {
    NoNotas *nn1 = ln->inicio;
    NoNotas *nn2 = ln->inicio;
    while (nn1 != NULL) {
      if (p.mat == nn1->valor.matricula)
        count++;
      nn1 = nn1->prox;
    }

    if (count == 0) {
      return 3;
    } else {
      printf("Notas: \n");
      while (nn2 != NULL) {
        if (nn2->valor.matricula == p.mat) {
          char nome[50];
          nomeMateria(lm, nn2->valor.materia, &nome);
          printf("  %s:\n", nome);
          printf("    Faltas: %d\n", nn2->valor.faltas);
          printf("    Prova 1: %d\n", nn2->valor.nota[0]);
          printf("    Prova 2: %d\n", nn2->valor.nota[1]);
          printf("    Prova 3: %d\n", nn2->valor.nota[2]);
          printf("    Prova Substitutiva: %d\n", nn2->valor.nota[3]);
        }

        nn2 = nn2->prox;
      }
      return 0;
    }
  }
}

int listaNotasVazia(ListaNotas *ln) {
  if (ln->inicio == NULL)
    return 0;
  return 1;
}

int adicionarFaltas(ListaNotas *ln, ListaMaterias *lm) {
  int cod, matr, f, conf, mat;
  char op = 's';
  Materia X;
  
  if (ln == NULL) {
    return 1;
  }
  else if (listaNotasVazia(ln) == 0) {
    return 2;
  }
    printf("Digite o código da materia em que você deseja adicionar a falta: ");
    scanf("%d", &cod);

    buscarMateria(lm, cod, &X);
    NoNotas *nn2 = ln->inicio;
    conf = 0;
    while(nn2->valor.materia != cod && nn2 != NULL){
      nn2 = nn2->prox;
    }

    while (op != 'n' && op != 'N') {
      if (X.codigo == cod) {
        printf("Digite a matrícula do aluno no qual as faltas serão "
               "adicionadas:\n");
        scanf("%d", &matr);
        for (int i = 0; i < 60; i++) {
          if (X.alunos[i] == matr) {
            printf("Quantas faltas deseja adicionar para esse aluno: ");
            scanf("%d", &f);
            while (nn2->valor.matricula != matr||nn2->valor.materia != cod) {
              nn2 = nn2->prox;
            }
            nn2->valor.faltas = nn2->valor.faltas + f;  
            conf++;
          }
        }
        if (conf != 0) {
          printf("Faltas adicionadas com sucesso.\n");
        } 
        else {
          printf("Não foi possível achar a matrícula do aluno nessa matéria.\n");
        }
      }
      else if (mat == -3) {
        printf("Materia não encontrada.\n");
        printf("Deseja tentar novamente? (s/n)\n");
        scanf(" %c", &op);
        if (op == 's' || op == 'S') {
          adicionarFaltas(ln, lm);
        } else if (op == 'n' || op == 'N') {
          return 0;
        } else {
          printf("Opção inválida.\n");
          printf("Voltando para o menu.\n");
          return 0;
        }
      }
      printf("Deseja adicionar mais faltas para algum aluno? (s/n)\n");
      scanf(" %c", &op);
      if (op == 'n' || op == 'N') {
        printf("Tudo bem, voltando para o menu.\n");
        break;
      } else if (op == 's' || op == 'S') {
        NoNotas *nn2 = ln->inicio;
        conf = 0;
      } else {
        printf("Opção inválida. Voltando para o menu.\n");
      }
    }
    return 0;
}

int removerFaltas(ListaNotas * ln, ListaMaterias * lm) {
  int cod, matr, f, conf, mat;
  char op = 's';
  Materia X;
  
    if (ln == NULL) {
      return 1;
    }
    else if (listaNotasVazia(ln) == 0) {
      return 2;
    }
      printf("Deseja remover as faltas em qual materia?\n");
      printf("Digite o código da materia: ");
      scanf("%d", &cod);

      buscarMateria(lm, cod, &X);
      NoNotas *nn2 = ln->inicio;
      conf = 0;
      while(nn2->valor.materia != cod && nn2 != NULL){
      nn2 = nn2->prox;
      }

      while (op == 's' || op == 'S') {
        if (X.codigo == cod) {
          printf("Digite a matrícula do aluno no qual as faltas serão "
                 "removidas:\n");
          scanf("%d", &matr);
          for (int i = 0; i < 60; i++) {
            if (X.alunos[i] == matr) {
              printf("Quantas faltas deseja remover para esse aluno: ");
              scanf("%d", &f);
              while (nn2->valor.matricula != matr||nn2->valor.materia != cod) {
                nn2 = nn2->prox;
              }
              nn2->valor.faltas = nn2->valor.faltas - f;
              conf++;
            }
          }
          if (conf != 0) {
            printf("Faltas removidas com sucesso.\n");
          } 
          else {
            printf(
                "Não foi possível achar a matrícula do aluno nessa matéria.\n");
          }
        }
        else if (mat == -3) {
          printf("Materia não encontrada.\n");
          printf("Deseja tentar novamente? (s/n)\n");
          scanf(" %c", &op);
          if (op == 's' || op == 'S') {
            adicionarFaltas(ln, lm);
          }
          else if (op == 'n' || op == 'N') {
            return 0;
          }
          else {
            printf("Opção inválida.\n");
            printf("Voltando para o menu.\n");
            return 0;
          }
        }
        printf("Deseja remover mais faltas para algum aluno? (s/n)\n");
        scanf(" %c", &op);
        if (op == 'n' || op == 'N') {
          printf("Tudo bem, voltando para o menu.\n");
        }
        else if (op == 's' || op == 'S') {
          NoNotas *nn2 = ln->inicio;
          conf = 0;
        }
        else {
          printf("Opção inválida. Voltando para o menu.\n");
        }
      }
      return 1;
}