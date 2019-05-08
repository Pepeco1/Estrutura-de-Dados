#include <stdlib.h>
#include <stdio.h>

typedef struct viz {
	int id_viz;
	int idade_viz;
	struct viz *prox_viz;
}TVIZ;

typedef struct grafo{
	int id_no;
	int idade_no;
	TVIZ *prim_viz;
	struct grafo *prox_no;
}TG;


TG *inicializa();
void imprime(TG *g);
void libera(TG *g);
TG* busca_no(TG* g, int x);
TVIZ* busca_aresta(TG *g, int no1, int no2);
TG *ins_no(TG *g, int x, int idade);
void ins_aresta(TG *g, int no1, int no2);
void ins_um_sentido(TG *g, int no1, int no2);
void retira_aresta(TG *g ,int no1, int no2);
TG *retira_no(TG *g, int no);

int testek(TG *g, int k);
int ig(TG *g1, TG *g2);

int numero_seguidos(TG *g, int id);
int seguidores(TG *g, int id, int imprime);
TG *mais_popular(TG *g);