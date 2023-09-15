/*
    Programa para escrever registros de dados em arquivoss
    Autor: Gustavo Rondinelli de Oliveira
    Data: 15/09/2023
*/

#include <stdio.h>
#include <stdlib.h>

#define N_REG 2

typedef char Disc[5];

struct reg{
    int RA;
    char nome[256];
    Disc matriculas[6]; //Cria uma matriz para armazenar dados
    float CR, CP;
};

typedef struct reg Reg_alunos;

Reg_alunos dados[N_REG] = {
    {12436, "Maria", {"MC102", "MA141", "F 128", "F 129"}, 0.0, 0.0},  //O terceiro item sao as matriculas que serao armazenadas na matriz Matriculas
    {12232, "Joao", {"MC202", "MA211", "F 228", "F 229"}, 0.8, 0.15}
};

void escreve_dados(void);

int main(void){
    escreve_dados();
    return(0);
}

void escreve_dados(void){
    FILE *fw;

    fw = fopen("dados_aluno.bin", "w");  //o W faz com que abra o arquivo no modo leitura

    if (fw == NULL){
        perror("dados_aluno.bin");
        exit(-1);
        }

    fwrite(dados, sizeof(Reg_alunos), N_REG, fw);
    fclose(fw);
    return;

}
