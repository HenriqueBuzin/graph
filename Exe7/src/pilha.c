#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *dados;
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
	pilha_t * pilha = malloc(sizeof(pilha_t));

	pilha->dados = criar_lista_enc();

	return pilha;
}

//adiciona elemento
void push(void* dado, pilha_t *pilha)
{
	no_t *no = criar_no(dado);
	add_cabeca(pilha->dados, no);
}

//retira elemento do topo
void *pop(pilha_t *pilha)
{
	no_t * cabeca = obter_cabeca(pilha->dados);
	void * dado = obter_dado(cabeca);
	remover_cabeca(pilha->dados);
	return dado;
}


void libera_pilha(pilha_t* pilha)
{
	libera_lista(pilha->dados);
	free(pilha);
}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->dados);
}
