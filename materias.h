#include "pessoa.h"
#ifndef MATERIAS_H
#define MATERIAS_H

typedef struct materia {
  int codigo;
  char nome[50];
  int alunos[60];
  int professor;
} Materia;

typedef struct listaMaterias ListaMaterias;
typedef struct noMateria NoMateria;

ListaMaterias *criarListaMaterias(); 

int adicionarMateria(ListaMaterias *lm);
int adicionarMateriaAutomatico(ListaMaterias *lm, int cod, int prof, char *nome);
int adicionarAlunoMateria(ListaMaterias *lm);
int adicionarAlunoMateriaAutomatico(ListaMaterias *lm, int matAluno,
                                    int matMateria);

int buscarMateria(ListaMaterias *lm, int codMateria, Materia *retorno); 

int removerMateria(ListaMaterias *lm); 
int removerAlunoMateria(ListaMaterias *lm);
int removerAlunoMateriaAutomatico(ListaMaterias *lm, int matAluno,
                                  int matMateria); 

int existeMateria(ListaMaterias *lm, int Cod);     
void nomeMateria(ListaMaterias *lm, int cod, char *nome);
int mostrarAlunosMateria(ListaMaterias *lm, int codProfessor,
                         Lista *pessoas);                          
int numeroAlunos(ListaMaterias *lm, int cod);                      
int mostrarMateriasMatriculadas(ListaMaterias *lm, int matricula); 

int numerodeMaterias(ListaMaterias *lm);  
int listaMateriasVazia(ListaMaterias *lm); 
#endif