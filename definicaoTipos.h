#ifndef DEFINICAO_TIPOS_H
#define DEFINICAO_TIPOS_H


typedef struct materia{
    char nome[100];
    int qtAlunos;
    struct aluno *alunos;
    int qtNotas;
    float *notasMaximas;
}Materia;

typedef struct materiaAluno{
    struct materia *materiaDirecao;
    int faltas;
    float *notas;
}MateriaAluno;

typedef struct ocorrencia{
    char data[11];
    char descricao[200];
}Ocorrencia;

typedef struct aluno{
    char nome[30];
    char senha[11];
    char mat[11];
    int qtMaterias;
    struct materiaAluno *materias;
    int qtOcorrencias;
    struct ocorrencia *ocorrencias;
}Aluno;

typedef struct professor{
    char nome[30];
    char senha[11];
    char mat[11];
    int qtMaterias;
    struct materia *materias;
}Professor;

typedef struct diretor{
    char nome[30];
    char senha[11];
    char mat[11];
}Diretor;

#endif