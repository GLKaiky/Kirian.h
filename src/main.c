#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/kirian.h"         

typedef struct {
    char name[50]; // Nome da pessoa
    int id;       // ID  pessoa
} pessoa;

int main() {
    pessoa p, s;

    strcpy(p.name, "Eduardo"); // Atribui o nome
    p.id = 52; 

    createHeader("pessoasdois.db", 2);

    create("pessoasdois.db", &p, sizeof(pessoa));

    read("pessoasdois.db", &s, sizeof(pessoa));

    printf("%s e %d", s. name, s.id);
           
}
