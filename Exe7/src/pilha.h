#ifndef PILHA_H_INCLUDED

#define PILHA_H_INCLUDED

typedef struct pilhas pilha_t;

#include "lista_enc.h"

pilha_t * cria_pilha (void);

//adiciona elemento
void push(void *dado, pilha_t *pilha);

//retira elemento do topo
void *pop(pilha_t *pilha);

void libera_pilha(pilha_t *pilha);

int pilha_vazia(pilha_t *pilha);

#endif // PILHA_H_INCLUDED
