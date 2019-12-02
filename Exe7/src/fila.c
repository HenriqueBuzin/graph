#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *dados;
};

//cria uma fila generica
fila_t * cria_fila (void)
{
	fila_t * fila = malloc(sizeof(fila_t));

	fila->dados = criar_lista_enc();

	return fila;
}

//adiciona elemento
void enqueue(void* dado, fila_t *fila)
{
	no_t *no = criar_no(dado);
	add_cauda(fila->dados, no);
}

//retira elemento do topo
void *dequeue(fila_t *fila)
{
	no_t * cabeca = obter_cabeca(fila->dados);
	void * dado = obter_dado(cabeca);
	remover_cabeca(fila->dados);
	return dado;
}


void libera_fila(fila_t* fila)
{
	libera_lista(fila->dados);
	free(fila);
}

int fila_vazia(fila_t *fila)
{
	return lista_vazia(fila->dados);
}
