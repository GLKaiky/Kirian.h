#ifndef KIRIAN_H
#define KIRIAN_H
#include <stdlib.h>

void createHeader(const char* fileName, short header_size);

void create(const char* fileName,void * obj);

void read(const char * fileName, void * structPointer, size_t structSize);

void deleteEntity(const char * fileName, void* indentifier);

#endif