#include "kirian.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char* name;
    int id;
}pessoa;

unsigned char* toByteArray(pessoa p){
    unsigned char* byteArray = (unsigned char*) malloc(sizeof(pessoa));

    if(!byteArray){
        printf("ERRO DE ALOCAÇÃO!");
    }

    memcpy(byteArray, &p, sizeof(pessoa));

    return byteArray;
}

// Função principal
int main() {
    printf("aqui");
    // Aloca memória para o objeto pessoa
    pessoa* p = (pessoa*)malloc(sizeof(pessoa));
    if (p == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Atribuindo valores à struct corretamente
    strcpy(p->name, "eduardo"); // Usa strcpy para atribuir a string
    p->id = 2;
    
    FILE* binFile = fopen("teste.db", "ab"); // Abre o arquivo para escrita
    if (!binFile) {   
        printf("Erro ao abrir o arquivo!\n");
        free(p); // Libera a memória antes de retornar
        return 1;
    }

    fwrite(p, sizeof(pessoa), 1, binFile); // Escreve o objeto no arquivo

    fclose(binFile); // Fecha o arquivo
    free(p); // Libera a memória alocada

    return 0;
}
