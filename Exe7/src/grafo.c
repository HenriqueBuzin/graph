#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila.h"
#include "pilha.h"

struct vertices {
	int id;
	int pai;
	int visitado;
	int distancia;
};

struct arestas {
	int adj;
	int peso;
	int exported;
};

struct grafos{
	int n_vertices;
	vertice_t *vertices;
	aresta_t **matriz_adj;
};

void bfs(grafo_t *grafo, int inicial){
    // Busca em largura

	fila_t * Q = cria_fila();
	int i;

	for(i = 0; i < grafo->n_vertices; i++){
		// -1 na distância significa infinito
		grafo->vertices[i].distancia = -1;
		// -1 no pai significa NULL
		grafo->vertices[i].pai = -1;
	}

    /* Renan:
        Surigo utilizar o endereço do vértice na fila:
        enqueue(&grafo->vertices[inicial],Q)
    */
	grafo->vertices[inicial].distancia = 0;
	enqueue((void*)(long)inicial, Q);

	while (!fila_vazia(Q)){
		int u = (int) (long) dequeue(Q);
		for(i = 0; i < grafo->n_vertices; i++){
			if(adjacente(grafo, u, i)){
				if(grafo->vertices[i].distancia == -1){
					grafo->vertices[i].distancia = (grafo->vertices[u].distancia + 1);
					grafo->vertices[i].pai = u;
					enqueue((void*)(long)i, Q);
				}
			}
		}
	}
	libera_fila(Q);
}

void dfs(grafo_t *grafo, int inicial){
    // Busca em profundidade

	pilha_t * S = cria_pilha();
	int i;

	for(i = 0; i < grafo->n_vertices; i++){
		// -1 no visitado a significa falso
		grafo->vertices[i].visitado = -1;
	}

    
    /* Renan:
        Surigo utilizar o endereço do vértice na pilha:
        push(&grafo->vertices[inicial],S)
    */

	push((void*)(long)inicial, S);

	while(!pilha_vazia(S)){
		int u = (int) (long) pop(S);
		if(grafo->vertices[u].visitado == -1){
			grafo->vertices[u].visitado = 1;
			for(i = 0; i < grafo->n_vertices; i++){
				if(adjacente(grafo, u, i)){
					push((void*)(long)i, S);
				}
			}
		}
	}
	libera_pilha(S);
}

void desenha(grafo_t *grafo){
    int i, j;
	puts("graph {");
	for(i = 0; i < grafo->n_vertices; i++){
		//for(int j = i+1; j < grafo->n_vertices; j++){
		for(j = 0; j < grafo->n_vertices; j++){
			if(adjacente(grafo, i, j)){
				printf("    %d -- %d [label=\"Pai: %d\\nDistância: %d\\nVisitado: %d\"];\n", i, j, grafo->vertices[j].pai, grafo->vertices[j].distancia, grafo->vertices[j].visitado);
			}
		}
	}
	puts("}");
}

int grafo_vazio(grafo_t *grafo){

	if(grafo->n_vertices > 0){
		return 0;
	} return 1;

}

grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;

	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda nÃºmero total de vÃ©rtices */
	g->n_vertices = vertices;

	/* Aloca vÃ©rtices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de vÃ©rtices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

    /* Aloca 1a dimensÃ£o da matriz de adjacÃªncia */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimensÃ£o da matriz de adjacÃªncia */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;
	// Extra
	//g->matriz_adj[v][u].adj = TRUE;

	return TRUE;
}

int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	// Extra
	//g->matriz_adj[v][u].adj = FALSE;

	return TRUE;
}

int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}
