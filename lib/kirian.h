#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef KIRIAN_H
#define KIRIAN_H

void createHeader(const char* fileName, short header_size);

bool create(const char* fileName, void* obj, size_t objSize);

void read(const char *fileName, void *structPointer, size_t structSize, void * primaryKey);


#endif