#include "1.h"

void main(){

    TABB* a = inicializa(),
        *b = cria(7, NULL, NULL),
        *c = cria(9, NULL, NULL);

    a = cria(8, b, c);

    TABB* d = inicializa(),
        *e = cria(11, NULL, NULL),
        *f = cria(13, NULL, NULL);

    d = cria(12, e, f);
    
    TABB* g = inicializa();

    g = cria(10, a, d);
    

    printf("\n");
    TABB* serase = retira_impares(g);
    imp_pre(serase);


    //g = retira_impares(g);
   
    //int* resp = mN(g, 10);
    //int len = sizeof(resp)/sizeof(int);
    //int i;
    //for(i = 0; i < len; i++) printf("%d", resp[i]);

    printf("\n");
    
    //imp_pre(g);



}
