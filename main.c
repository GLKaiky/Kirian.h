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

int main(){
    FILE* binfile;
    pessoa p;
    
    p.name = "eduardo";
    p.id = 2;
    unsigned char* byteArray = toByteArray(p);

    size_t dataSize = sizeof(byteArray);

    create("teste.db", byteArray, dataSize);

}