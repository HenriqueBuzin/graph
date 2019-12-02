#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void) {
	int i,j;
	grafo_t *g;

    /* Cria grafo com 03 vértices */
	g = cria_grafo(4);


	// Adicionar arestas
	cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 0, 2);
	cria_adjacencia(g, 1, 3);
	cria_adjacencia(g, 2, 3);


	bfs(g, 0);

	dfs(g, 0);

	desenha(g);

	/* Imprime matriz */

	for (i=0; i < 4; i++){
		for (j=0; j < 4; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

//	libera_grafo(g);

	return EXIT_SUCCESS;

}
