#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_REG 32

typedef char Disc[5];

struct reg {
    int RA;
    char nome[256];
    Disc matriculas[6];
    float CR, CP;
};

typedef struct reg Reg_alunos;

void leitura( char *nome, Reg_alunos *dados, int *numAlunos);
void escreve_dados( char *nome, Reg_alunos *dados, int numAlunos);
void listar_alunos( char *nome);

int main(void) {
    Reg_alunos dados[N_REG];
    int numAlunos = 0;
    char nomeArquivo[] = "dados_alunos.bin";

    printf("Menu:\n");
    printf("1. Inserir aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Sair\n");

    int opcao;
    do {
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                leitura(nomeArquivo, dados, &numAlunos);
                break;
            case 2:
                listar_alunos(nomeArquivo);
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

void leitura( char *nome, Reg_alunos *dados, int *numAlunos) {
    if (*numAlunos == N_REG) {
        printf("Limite de registros alcancado. Nao eh possivel adicionar mais alunos.\n");
        return;

    }

    printf("Nome do aluno: ");
    scanf("%s", dados[*numAlunos].nome);
    printf("RA: ");
    scanf("%d", &dados[*numAlunos].RA);
    printf("Matriculas:");
    scanf("%s", &dados[*numAlunos].matriculas);
    printf("CR:");
    scanf("%f", &dados[*numAlunos].CR);
    printf("CP:");
    scanf("%f", &dados[*numAlunos].CP);

    (*numAlunos)++;
    escreve_dados(nome, dados, *numAlunos);
}

void escreve_dados( char *nome,  Reg_alunos *dados, int numAlunos) {
    FILE *fw = fopen(nome, "w");

    if (fw == NULL) {
        perror(nome);
        exit(-1);
    }

    fwrite(dados, sizeof(Reg_alunos), numAlunos, fw);
    fclose(fw);
}

void listar_alunos( char *nome) {
    FILE *fr = fopen(nome, "rb");

    if (fr == NULL) {
        perror(nome);
        return;
    }

    Reg_alunos aluno;

    printf("\nLista de Alunos:\n");

    while (fread(&aluno, sizeof(Reg_alunos), 1, fr) == 1) {
        printf("Nome: %s\n", aluno.nome);
        printf("RA: %d\n", aluno.RA);
        printf("Matriculas: %c\n", aluno.matriculas);
        printf("CR: %0.2f\n", aluno.CR);
        printf("CP: %0.2f\n", aluno.CP);
        printf("\n");
    }

    fclose(fr);
}
