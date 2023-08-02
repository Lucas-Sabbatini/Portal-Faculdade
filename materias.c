#include "notasfaltas.h"
#include "materias.h"
#include "pilha.h"
#include "ocorrencias.h"
#include "pessoa.h"
#include "solicitacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noMateria {
  Materia valor;
  struct noMateria *prox;
} NoMateria;

typedef struct listaMaterias {
  NoMateria *inicio;
} ListaMaterias;

ListaMaterias *criarListaMaterias() {
  ListaMaterias *lm = (ListaMaterias *)malloc(sizeof(ListaMaterias));
  lm->inicio = NULL;
  return lm;
}

int adicionarMateria(ListaMaterias *lm) {
  if (lm == NULL) {
    return 1;
  } else {
    int cod, prof;
    char nome[50];

    printf("Digite o nome da matéria que você deseja adicionar: ");
    fgets(nome, 50, stdin);
    setbuf(stdin, NULL);

    printf("Digite o código da matéria: ");
    scanf("%d", &cod);

    printf("Digite o código do professor que lecionará a matéria: ");
    scanf("%d", &prof);

    NoMateria *nm = (NoMateria *)malloc(sizeof(NoMateria));
    nm->prox = lm->inicio;
    lm->inicio = nm;

    strcpy(nm->valor.nome, nome);
    nm->valor.codigo = cod;
    nm->valor.professor = prof;
    for (int i = 0; i < 60; i++) {
      nm->valor.alunos[i] = 0;
    }

    return 0;
  }
}

int adicionarMateriaAutomatico(ListaMaterias *lm, int cod, int prof, char *nome) {
  if (lm == NULL) {
    return 1;
  } else {
    NoMateria *nm = (NoMateria *)malloc(sizeof(NoMateria));
    nm->prox = lm->inicio;
    lm->inicio = nm;

    strcpy(nm->valor.nome, nome);
    nm->valor.codigo = cod;
    nm->valor.professor = prof;
    for (int i = 0; i < 60; i++) {
      nm->valor.alunos[i] = 0;
    }

    return 0;
  }
}

int adicionarAlunoMateria(ListaMaterias *lm) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    int cod, mat;

    printf("Digite o código da matéria: ");
    scanf("%d", &cod);

    printf("Digite a matrícula do aluno que deseja adicionar: ");
    scanf("%d", &mat);

    NoMateria *nm = lm->inicio;
    while (nm->valor.codigo != cod && nm != NULL) {
      nm = nm->prox;
    }
    if (nm == NULL) {
      return 3;
    } else {
      for (int i = 0; i < 60; i++) {
        if (nm->valor.alunos[i] == 0) {
          nm->valor.alunos[i] = mat;
          return 0;
        }
      }
      return 4;
    }
  }
}

int adicionarAlunoMateriaAutomatico(ListaMaterias *lm, int matAluno, int matMateria) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    NoMateria *nm = lm->inicio;
    while (nm->valor.codigo != matMateria && nm != NULL) {
      nm = nm->prox;
    }    
    if (nm == NULL) {
      return 3;
    } else {
      for (int i = 0; i < 60; i++) {
        if (nm->valor.alunos[i] == 0) {
          nm->valor.alunos[i] = matAluno;
          return 0;
        }
      }
      return 4;
    }
  }
}

int removerMateria(ListaMaterias *lm) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    int cod;
    printf("Digite o código da matéria que você desja excluir: ");
    scanf("%d", &cod);

    NoMateria *nmatual = lm->inicio;
    NoMateria *nmanterior;

    while (nmatual->valor.codigo != cod || nmatual != NULL) {
      nmanterior = nmatual;
      nmatual = nmatual->prox;
    }

    if (nmatual == NULL) {
      return 3;
    } else {
      nmanterior->prox = nmatual->prox;
      free(nmatual);
      return 0;
    }
    return 4;
  }
}

int removerAlunoMateira(ListaMaterias *lm) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    int cod, mat;
    printf("Digite o código da matéria que o aluno será removido: ");
    scanf("%d", &cod);

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &mat);

    NoMateria *nm = lm->inicio;

    while (nm->valor.codigo != cod || nm == NULL) {
      nm = nm->prox;
    }

    if (nm == NULL) {
      return 3;
    } else {
      for (int i = 0; i < 60; i++) {
        if (nm->valor.alunos[i] == mat) {
          nm->valor.alunos[i] = 0;

          for (int j = i; j < 60; j++) {
            if (j == 59)
              nm->valor.alunos[j] = 0;
            nm->valor.alunos[j] = nm->valor.alunos[j + 1];
          }

          return 0;
        }
      }
    }

    return 4;
  }
}

int removerAlunoMateriaAutomatico(ListaMaterias *lm, int matAluno,
                                  int matMateria) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    NoMateria *nm = lm->inicio;

    while (nm->valor.codigo != matMateria || nm == NULL) {
      nm = nm->prox;
    }

    if (nm == NULL) {
      return 3;
    } else {
      for (int i = 0; i < 60; i++) {
        if (nm->valor.alunos[i] == matAluno) {
          nm->valor.alunos[i] = 0;
          return 0;
        }
      }
    }

    return 4;
  }
}

int existeMateria(ListaMaterias *lm, int cod) {
  NoMateria *nm = lm->inicio;
  while (nm->valor.codigo != cod && nm != NULL) {
    nm = nm->prox;
  }
  if (nm->valor.codigo == cod) {
    return 0;
  } else {
    return 1;
  }
}

void nomeMateria(ListaMaterias *lm, int cod, char *nome) {
  NoMateria *nm = lm->inicio;
  while (nm->valor.codigo != cod) {
    nm = nm->prox;
  }

  for (int i = 0; i < 50; i++) {
    nome[i] = nm->valor.nome[i];
  }
}

int numerodeMaterias(ListaMaterias *lm) {
  if (lm == NULL || listaMateriasVazia(lm) == 0) {
    return 0;
  } else {
    int count = 0;
    NoMateria *nm = lm->inicio;

    while (nm != NULL) {
      count++;
      nm = nm->prox;
    }

    return count;
  }
}

int listaMateriasVazia(ListaMaterias *lm) {
  if (lm->inicio == NULL)
    return 0;
  return 1;
}

int mostrarAlunosMateria(ListaMaterias *lm, int codProfessor, Lista *pessoas) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    NoMateria *nm = lm->inicio;
    while (nm->valor.professor != codProfessor && nm != NULL) {
      nm = nm->prox;
    }
    if (nm == NULL) {
      return 3;
    } else {
      int j = numeroAlunos(lm, nm->valor.codigo);
      char nome[50];

      printf("Os alunos da matéria %s são: ", nm->valor.nome);
      for (int i = 0; i < j; i++) {
        nomeAluno(nm->valor.alunos[i], &nome, pessoas);
        printf("%s | %d\n", nome, nm->valor.alunos[i]);
      }

      return 0;
    }

    return 4;
  }
}

int numeroAlunos(ListaMaterias *lm, int cod) {
  int i = 0, count = 0;
  NoMateria *nm = lm->inicio;

  while (nm->valor.codigo != cod) {
    nm = nm->prox;
  }

  while (nm->valor.alunos[i] != 0) {
    count++;
    i++;
  }

  return count;
}

int mostrarMateriasMatriculadas(ListaMaterias *lm, int matricula) {
  if (lm == NULL) {
    return 1;
  } else if (listaMateriasVazia(lm) == 0) {
    return 2;
  } else {
    NoMateria *nm = lm->inicio;

    printf("Matérias matriculadas: ");
    while (nm != NULL) {
      for (int i = 0; i < 60; i++) {
        if (nm->valor.alunos[i] == matricula) {
          printf("  %s\n", nm->valor.nome);
        }
      }

      nm = nm->prox;
    }

    return 0;
  }
}

int buscarMateria(ListaMaterias *lm, int codMateria, Materia *retorno) {
  if (lm == NULL)
    return -2;
  if (listaMateriasVazia(lm) == 0)
    return -1;

  int pos = 0;
  NoMateria *noatual = lm->inicio;

  while (noatual != NULL) {
    if (noatual->valor.codigo == codMateria) {
      *retorno = noatual->valor;
      return pos;
    }
    noatual = noatual->prox;
    pos++;
  }

  return -3;
}