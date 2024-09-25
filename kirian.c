#include "kirian.h"
#include <stdlib.h>
#include <stdio.h>

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

void create(const char* fileName, void * obj){
    FILE* binFile = fopen(fileName, "ab");
        if(!binFile){   
            printf("Error opening the file!");
        }
    fwrite(obj, sizeof(obj), 1, binFile);

    fclose(binFile);
}