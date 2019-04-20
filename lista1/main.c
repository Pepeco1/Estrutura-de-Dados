#include "1.h"

void main(){


    TAB* a = inicializa(),
        *b = cria(5, NULL, NULL),
        *c = cria(25, NULL, NULL);

    a = cria(10, b, c);

    TAB* d = inicializa(),
        *e = cria(10, NULL, NULL),
        *f = cria(20, NULL, NULL);

    d = cria(5, e, f);
    
    TAB* g = inicializa();

    g = cria(1, a, d);
    
    imp_pos(g);

    retira_pares(g);
    printf("\n");

    imp_pos(g);



}
