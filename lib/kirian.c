#include <stdlib.h>
#include "lib/kirian.h" 
#include <stdio.h>

#define KIRIAN_H

void createHeader(const char* fileName, short header_size){
    FILE* binFile = fopen(fileName, "ab");

    if(!binFile){   
        printf("Error opening the file!");
    }

    short* header = (short *) malloc (header_size * sizeof(short));
    
    if(!header){
        fclose(binFile);
        printf("Memory allocation falied");
        return;
    }

    for(short i = 0; i<header_size; i++){
        header[i] = 0;
    }

    short write = fwrite(header, sizeof(short), header_size, binFile);

    if(write != header_size){
        printf("Error of writing to the file!\n");
    }

    free(header);
    fclose(binFile);    
}

void create(const char* fileName, void* obj, size_t objSize){
    FILE* binFile = fopen(fileName, "ab");
    if(!binFile){   
        printf("Error opening the file!");
    }
    
    fwrite(obj, objSize, 1, binFile);

    fclose(binFile);
}

void read(const char *fileName, void *structPointer, size_t structSize) {
    FILE *binFile = fopen(fileName, "rb");
    if (!binFile) {
        perror("Error opening the file"); // Exibe um erro caso não consiga abrir o arquivo
        return; // Retorna se não puder abrir o arquivo
    }
    
    size_t itemsRead = fread(structPointer, structSize, 1, binFile);
    if (itemsRead != 1) { // Verifica se a leitura foi bem-sucedida
        perror("Error reading from the file");
    } else {
        printf("Successfully read %zu item(s) from the file.\n", itemsRead);
    }

    fclose(binFile); // Fecha o arquivo após a leitura
}
