#include "popularBaseDeDados.h"
#include "definicaoTipos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Materia *criaMateria(){
    int soma,i;
    Materia *m = (Materia *) malloc(sizeof(Materia));

    m->qtAlunos = 0;
    printf("Digite o nome da Matéria: ");
    fgets(m->nome,100,stdin);
    setbuf(stdin,NULL);

    printf("Digite o a quantidade de avaliações que serão feitas:");
    scanf("%d",&m->qtNotas);
    m->notasMaximas = (float *) malloc(m->qtNotas*sizeof(float));

    printf("Digite o valor de cada avaliação: \n");

    do{
        soma = 0;
        for(i=0;i<m->qtNotas;i++){
            printf("[%d] - ",i+1);
            scanf("%f",m->notasMaximas+i);
            soma+=m->notasMaximas[i];
        }
        if(soma!=100){
            printf("Ops, parece qu e a soma das notas é não totaliza 100 pontos, por favor digite as notas novamente");
        }
    }while(soma!=100);
    

    return m;
}

MateriaAluno *criaMateriaAluno(Materia *m){
    int i;
    MateriaAluno *mA = (MateriaAluno *) malloc(sizeof(MateriaAluno));
    mA->materiaDirecao = m;
    mA->notas = (float *) malloc(m->qtNotas*sizeof(float));

    for(i=0;i<m->qtNotas;i++){
        mA->notas[i] = 0;
    }
    
    return mA;
}


Aluno *criaAluno(){
    
}