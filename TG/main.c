#include "TG.h"

void main(void){

	TG *grafo = inicializa();
	int caso;

	TG *grafo1 = inicializa();
	grafo1 = ins_no(grafo1, 10);
	grafo1 = ins_no(grafo1, 11);
	grafo1 = ins_no(grafo1, 12);
	grafo1 = ins_no(grafo1, 13);
	ins_aresta(grafo1, 10, 11);
	ins_aresta(grafo1, 12, 13);

	TG *grafo2 = inicializa();
	grafo2 = ins_no(grafo2, 10);
	grafo2 = ins_no(grafo2, 11);
	grafo2 = ins_no(grafo2, 12);
	grafo2 = ins_no(grafo2, 13);
	ins_aresta(grafo2, 10, 11);
	ins_aresta(grafo2, 12, 13);


	while(1){
		printf("digite 0 para inserir, 1 para criar arestas e  9 para rodar meu código carai\n");
		scanf("%d", &caso);

		switch(caso){

			case 0:
			printf("digite um número para inserir no grafo \n");
			int info;
			scanf("%d", &info);
			grafo = ins_no(grafo, info);
			imprime(grafo);
			break;

			case 1:
			printf("digite dois nós para formar arestas\n");
			int info1, info2;
			scanf("%d %d", &info1, &info2);
			ins_aresta(grafo, info1, info2); 
			imprime(grafo);
			break;

			case 8:
			int resp;
			resp = ig(grafo1, grafo2);
			printf("\nRESPOSTA: %d\n", resp);

			case 9:
			printf("Digite um grau 'k'\n");
			int grau;
			scanf("%d", &grau);
			int resp;
			resp = testek(grafo, grau);
			printf("\nRESPOSTA: %d\n", resp);
			imprime(grafo);
			break;
		}

	}
}