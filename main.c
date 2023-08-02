#include "materias.h"
#include "notasfaltas.h"
#include "ocorrencias.h"
#include "pessoa.h"
#include "pilha.h"
#include "solicitacoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int demonstracao(ListaMaterias *materias, Lista *l, Pilha *p, Fila *solicitacoes, ListaOcorrencias *ocorrencias, ListaNotas *notas);

int senhacmp(char *l1,char *l2);

int main() {

  char ent;
  Pessoa entrada, retorno;
  Lista *l = criar();
  int mat;
  char senha[10];
  Pilha *p = criarPilha(); // recados
  int i;
  Fila *solicitacoes = criarFila();
  ListaMaterias *materias = criarListaMaterias();
  ListaOcorrencias *ocorrencias = criarOcorrencias();
  ListaNotas *notas = criarListaNotasFaltas();

  demonstracao(materias, l, p, solicitacoes, ocorrencias, notas);

  while (1) {
    printf("\n\nDeseja adicionar uma Pessoa ao sistema? (S/N): ");
    scanf("%c", &ent);
    setbuf(stdin, NULL);
    if (ent == 'S' || ent == 's') {
      printf("Digite a sua matricula:  ");
      scanf("%d", &entrada.mat);
      setbuf(stdin, NULL);
      printf("Digite a sua senha:  ");
      fgets(entrada.senha, 10, stdin);
      setbuf(stdin, NULL);
      printf("Digite o seu nome: ");
      fgets(entrada.nome, 30, stdin);
      setbuf(stdin, NULL);
      printf("Digite se a pessoa será diretor, aluno, professor (1,2,3) "
             "respectivamente: ");
      scanf("%d", &entrada.type);
      setbuf(stdin, NULL);
      inserirFim(l, entrada);
    } else if (ent == 'N' || ent == 'n') {
      break;
    } else {
      printf("Opção inválida, digite novamente\n");
    }
  }
  //mostrar(l);
  while (1) {
    printf("Digite a sua matricula: ");
    scanf("%d", &mat);
    setbuf(stdin, NULL);
    printf("Digite a senha: ");
    fgets(senha, 10, stdin);
    if (buscarItemChave(l, mat, &retorno) == -1) {
      printf("Nenhum aluno encontrado, matricula errada\n\n");
    } else if (senhacmp(retorno.senha,senha) == 1) {
      switch (retorno.type) {
      case 1:
        diretor(l, retorno, p, solicitacoes, materias, ocorrencias);
        break;
      case 2:
        aluno(l, retorno, p, solicitacoes, materias, notas, ocorrencias);
        break;
      case 3:
        professor(l, retorno, p, solicitacoes, materias, notas, ocorrencias);
        break;
      }
      system("clear");
    } else {
      printf("Senha incorreta\n\n");
    }
  }

  return 0;
}

int demonstracao(ListaMaterias *materias, Lista *l, Pilha *p,
                 Fila *solicitacoes,ListaOcorrencias *ocorrencias, ListaNotas *notas) {
  int retorno, i;
  char nomeMateria[50];
  Pessoa alunos[10], professores[12], diretores[2];
  Recado recados[4];
  Solicitacao solicit[3];
  Ocorrencia ocor[3];

  strcpy(nomeMateria, "Empreendedorismo em Informática");
  retorno = adicionarMateriaAutomatico(materias, 1, 1, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Cálculo Diferencial e Integral 1");
  retorno = adicionarMateriaAutomatico(materias, 2, 2, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Geometria Analítica e Álgebra Linear");
  retorno = adicionarMateriaAutomatico(materias, 3, 3, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Programação Procedimental");
  retorno = adicionarMateriaAutomatico(materias, 4, 4, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Introdução à Ciência da Computação");
  retorno = adicionarMateriaAutomatico(materias, 5, 5, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Lógica para Computação");
  retorno = adicionarMateriaAutomatico(materias, 6, 6, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Algoritmos e Estruturas de Dados 1");
  retorno = adicionarMateriaAutomatico(materias, 7, 7, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Profissão em Computação e Informática");
  retorno = adicionarMateriaAutomatico(materias, 8, 8, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Cálculo Diferencial e Integral 2");
  retorno = adicionarMateriaAutomatico(materias, 9, 9, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Matemática para a Ciência da Computação");
  retorno = adicionarMateriaAutomatico(materias, 10, 10, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Programação Lógica");
  retorno = adicionarMateriaAutomatico(materias, 11, 11, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  strcpy(nomeMateria, "Sistemas Digitais");
  retorno = adicionarMateriaAutomatico(materias, 12, 12, &nomeMateria[0]);
  if (retorno == 1)
    printf("Erro! Lista não existe.\n");

  alunos[0].mat = 13;
  strcpy(alunos[0].senha, "1234\0");
  strcpy(alunos[0].nome, "Lucas\0");
  alunos[0].type = 2;

  alunos[1].mat = 14;
  strcpy(alunos[1].senha, "4321\0");
  strcpy(alunos[1].nome, "Gustavo\0");
  alunos[1].type = 2;

  alunos[2].mat = 15;
  strcpy(alunos[2].senha, "1111\0");
  strcpy(alunos[2].nome, "Pedro\0");
  alunos[2].type = 2;

  alunos[3].mat = 16;
  strcpy(alunos[3].senha, "2222\0");
  strcpy(alunos[3].nome, "Victor\0");
  alunos[3].type = 2;

  alunos[4].mat = 17;
  strcpy(alunos[4].senha, "3333\0");
  strcpy(alunos[4].nome, "Nicolas\0");
  alunos[4].type = 2;

  alunos[5].mat = 18;
  strcpy(alunos[5].senha, "4444\0");
  strcpy(alunos[5].nome, "João Fini\0");
  alunos[5].type = 2;

  alunos[6].mat = 19;
  strcpy(alunos[6].senha, "5555\0");
  strcpy(alunos[6].nome, "Reverso\0");
  alunos[6].type = 2;

  alunos[7].mat = 20;
  strcpy(alunos[7].senha, "6666\0");
  strcpy(alunos[7].nome, "Heli\0");
  alunos[7].type = 2;

  alunos[8].mat = 21;
  strcpy(alunos[8].senha, "7777\0");
  strcpy(alunos[8].nome, "Fabi\0");
  alunos[8].type = 2;

  alunos[9].mat = 22;
  strcpy(alunos[9].senha, "88888\0");
  strcpy(alunos[9].nome, "Goiaba\0");
  alunos[9].type = 2;

  professores[0].mat = 7;
  strcpy(professores[0].senha, "99999\0");
  strcpy(professores[0].nome, "José Gustavo\0");
  professores[0].type = 3;

  professores[1].mat = 4;
  strcpy(professores[1].senha, "10000\0");
  strcpy(professores[1].nome, "Claudiney Tinoco\0");
  professores[1].type = 3;

  professores[2].mat = 12;
  strcpy(professores[2].senha, "10001\0");
  strcpy(professores[2].nome, "Jamil\0");
  professores[2].type = 3;

  professores[3].mat = 5;
  strcpy(professores[3].senha, "100002\0");
  strcpy(professores[3].nome, "Faina\0");
  professores[3].type = 3;

  professores[4].mat = 2;
  strcpy(professores[4].senha, "100003\0");
  strcpy(professores[4].nome, "Toninho\0");
  professores[4].type = 3;

  professores[5].mat = 9;
  strcpy(professores[5].senha, "100004\0");
  strcpy(professores[5].nome, "Ana Paula\0");
  professores[5].type = 3;

  professores[6].mat = 10;
  strcpy(professores[6].senha, "100005\0");
  strcpy(professores[6].nome, "Márcio F\0");
  professores[6].type = 3;

  professores[7].mat = 3;
  strcpy(professores[7].senha, "100006\0");
  strcpy(professores[7].nome, "Marcio Dantas\0");
  professores[7].type = 3;

  professores[8].mat = 1;
  strcpy(professores[8].senha, "100007\0");
  strcpy(professores[8].nome, "Marcia E\0");
  professores[8].type = 3;

  professores[9].mat = 6;
  strcpy(professores[9].senha, "100008\0");
  strcpy(professores[9].nome, "Marcia L\0");
  professores[9].type = 3;

  professores[10].mat = 8;
  strcpy(professores[10].senha, "100009\0");
  strcpy(professores[10].nome, "Renato\0");
  professores[10].type = 3;

  professores[11].mat = 11;
  strcpy(professores[11].senha, "100010\0");
  strcpy(professores[11].nome, "Renan\0");
  professores[11].type = 3;

  diretores[0].mat = 23;
  strcpy(diretores[0].senha, "100005\0");
  strcpy(diretores[0].nome, "Bianca\0");
  diretores[0].type = 1;

  diretores[1].mat = 24;
  strcpy(diretores[1].senha, "100006\0");
  strcpy(diretores[1].nome, "Lucila\0");
  diretores[1].type = 1;

  strcpy(recados[0].data, "11/04/2023\0");
  strcpy(recados[0].descricao,
         "Alunos, por favor estudem mais para aumentar o cra de vcs\0");
  push(p, recados[0]);

  strcpy(recados[1].data, "12/04/2023\0");
  strcpy(recados[1].descricao, "Se preparem para a vinda do hackatruck, uma "
                               "ótima oportunidade pra vcs\0");
  push(p, recados[1]);

  for (i = 0; i < 10; i++) {
    if (i < 6) {
      inserirFim(l, professores[i]);
    }
    if (i < 2) {
      inserirFim(l, diretores[i]);
    }
    inserirFim(l, alunos[i]);
  }

  solicit[0].tipo = 2;
  solicit[0].matAluno = 15;
  solicit[0].matMateria = 2;
  inserirFila(solicitacoes, solicit[0]);

  solicit[1].tipo = 2;
  solicit[1].matAluno = 19;
  solicit[1].matMateria = 9;
  inserirFila(solicitacoes, solicit[1]);

  solicit[2].tipo = 2;
  solicit[2].matAluno = 23;
  solicit[2].matMateria = 5;
  inserirFila(solicitacoes, solicit[2]);

  ocor[0].matAluno = 14;
  strcpy(ocor[0].data,"11/11/2023\0");
  strcpy(ocor[0].descricao,"Aluno estava correndo nos corredores da universidade\0");
  inserirInicioOcorrencia(ocorrencias, ocor[0]);

  ocor[1].matAluno = 17;
  strcpy(ocor[1].data,"17/06/2023\0");
  strcpy(ocor[1].descricao,"Aluno interrompeu a aula e desrespeitou o professor\0");
  inserirInicioOcorrencia(ocorrencias, ocor[1]);

  ocor[2].matAluno = 20;
  strcpy(ocor[2].data,"29/07/2023\0");
  strcpy(ocor[2].descricao,"Aluno estava vendendo doces nas mediações da universidade sem autorização\0");
  inserirInicioOcorrencia(ocorrencias, ocor[2]);

  for(int i = 13; i<23; i++){
    for(int j = 1; j<13; j++){
      adicionarAlunoMateriaAutomatico(materias, i, j);
      srand(time(0));
      int n1, n2, n3, n4;
      n1 = rand() % 31;
      n2 = rand() % 36;
      n3 = rand() % 36;
      n4 = 0;
      if(n1 + n2 + n3 < 60) n4 = rand() % 36;
      inserirNotasAutomatico(notas, materias, l, n1, n2, n3, n4, j, i);
    }
  } 
  return 0;
}

int senhacmp(char *l1,char *l2){
  int i;
  for(i=0;l1[i]!='\0'&&l2[i]!='\0';i++){
    if(l1[i]!=l2[i]){
      return 0;
    }
  }
  return 1;
}