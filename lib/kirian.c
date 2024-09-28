#include <stdlib.h>
#include "kirian.h" 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define KIRIAN_H

static int headerSize;

void createHeader(const char* fileName, short header_size){

    if(headerSize > 0){
        return;
    }

    FILE* binFile = fopen(fileName, "ab");

    if(!binFile){   
        printf("Error opening the file!");
    }

    headerSize = header_size;

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

bool create(const char* fileName, void* obj, size_t objSize){

    if(headerSize <= 0){
        printf("Error when initializing the file, please check if the header was created. Use the createHeader function\n");
    }

    FILE* binFile = fopen(fileName, "r+b");
    short num;
    bool lapid = false;


    if(!binFile){   
        printf("Error opening the file!\n");
        return false;
    }

    fseek(binFile, 0, SEEK_SET);
    
    if(fread(&num, sizeof(short), 1, binFile) != 1){
        perror("Error reading the file\n");
        fclose(binFile);
        return false;
    }

    num+=1;

    fseek(binFile, 0, SEEK_SET);

    if(fwrite(&num, sizeof(short), 1, binFile) != 1){
        perror("Error writing the file\n");
        fclose(binFile);
        return false;
    }
    
    fseek(binFile, 0, SEEK_END);

    if(fwrite(&lapid, sizeof(bool), 1, binFile) != 1){
        perror("Error writing the file\n");
        fclose(binFile);
        return false;
    }

    if(fwrite(&objSize, sizeof(size_t), 1, binFile) != 1){
        perror("Error writing the file\n");
        fclose(binFile);
        return false;
    }

    if(fwrite(obj, objSize, 1, binFile) != 1){
        perror("Error writing the object in the file\n  ");
        fclose(binFile);
        return false;
    }

    fclose(binFile);
    return true;
}   

    void read(const char *fileName, void *structPointer, size_t structSize, void * primaryKey) {
        FILE *binFile = fopen(fileName, "rb");
        if (!binFile) {
            perror("Error opening the file");   
            return; 
        }

        short objects_registred;
        
        if(fread(&objects_registred, sizeof(short), 1, binFile) != 1){
            perror("Error writing the file");
            fclose(binFile);
            return;
        }


        if(headerSize > 1){
            fseek(binFile, (headerSize - 1) * sizeof(short),SEEK_CUR);
        }

        for(short i = 0; i<objects_registred; i++){
            bool lapid;

            fread(&lapid, sizeof(bool), 1, binFile);

            if(lapid == 1){
                size_t objSize;

                fread(&objSize, sizeof(size_t), 1, binFile);

                fseek(binFile, objSize, SEEK_CUR); 
            }else{
                
                size_t objSize;

                char* objKey = malloc(sizeof(char*));   

                fread(&objSize, sizeof(size_t), 1, binFile);
                
                long address = ftell(binFile);

                fread(objKey, sizeof(primaryKey), 1, binFile);

                if(strcmp(primaryKey, objKey) == 0){
                    fseek(binFile, address, SEEK_SET);
                    fread(structPointer, structSize, 1, binFile);     
                    break;          
                }else{
                    fseek(binFile, address, SEEK_SET);  

                    fseek(binFile, objSize, SEEK_CUR);
                }
            }
        }

        fclose(binFile); 
    }
