#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);

void dfs(grafo_t *grafo, int inicial);
void bfs(grafo_t *grafo, int inicial);

int grafo_vazio(grafo_t *grafo);

void desenha(grafo_t *grafo);

#endif /* GRAFO_H_ */
