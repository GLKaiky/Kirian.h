#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/kirian.h"         

typedef struct {
    int id;       // ID  pessoa
    char name[50]; // Nome da pessoa
    bool casado;
} pessoa;

int main() {
    pessoa p, s, i;
    
    strcpy(i.name, "Samuel");
    i.id = 12;
    i.casado = false;

    strcpy(p.name, "Eduardo"); // Atribui o nome
    p.id = 52; 
    p.casado = true;

    int ptr = 52;  

    create("./data/pessoas.db", &i, sizeof(pessoa));

    printf("%s e %d e %d", s.name, s.id, s.casado);

}
