#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

int variable1 = 50, variable2, variable3, variable4;

int main() {
 printf("Creando lista");
 ListEntry *list = NULL;
 assert(list_append(&list, &variable1) != NULL);
 assert(list_append(&list, &variable2) != NULL);
 assert(list_append(&list, &variable3) != NULL);
 assert(list_append(&list, &variable4) != NULL);
 printf("Lista creada");
 return 0;
}

