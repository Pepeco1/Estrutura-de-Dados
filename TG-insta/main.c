#include "TG.h"

void main(void){

	TG *grafo = inicializa();
	int caso;

	TG *grafo1 = inicializa();
	grafo1 = ins_no(grafo1, 1, 10);
	grafo1 = ins_no(grafo1, 2, 15);
	grafo1 = ins_no(grafo1, 3, 17);
	grafo1 = ins_no(grafo1, 4, 19);
	ins_um_sentido(grafo1, 1, 2);
	ins_um_sentido(grafo1, 3, 4);
	ins_um_sentido(grafo1, 4, 2);
	//ins_um_sentido(grafo1, 4, 3);

	//int resp;
	//resp = seguidores(grafo1, 2, 1);
	//printf("RESPOSTA: %d\n", resp);

	TG *resp;
	resp = mais_popular(grafo1);

	if(resp)	printf("Mais popular: %d\n", resp->id_no);
	else	printf("erro\n");



	
}