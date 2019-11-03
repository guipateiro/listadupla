#include<stdio.h>
#include<stdlib.h>


#define CHAVEMAX 2147483647

struct t_nodo {
    int chave;
    struct t_nodo *prox;
    struct t_nodo *prev;
};
typedef struct t_nodo t_nodo;

struct t_lista {
    t_nodo *ini;
    t_nodo *atual;
    t_nodo *fim;
    int tam;
};
typedef struct t_lista t_lista;

/*
  Cria uma lista vazia. Ela eh duplamente encadeada e tem sentinelas no
  inicio e no final. Tambem tem um apontador para um elemento qualquer.
*/
int inicializa_lista(t_lista *l){
  t_nodo *inicio,*fim;
  l = (t_lista *) malloc(sizeof(t_lista));
  inicio = (t_nodo *) malloc(sizeof(t_nodo));
  fim = (t_nodo *) malloc(sizeof(t_nodo));
  l->ini = inicio;
  l->fim = fim;
  inicio->prox = fim;
  fim->prev = inicio;
  fim->chave = CHAVEMAX;
  inicio->prev = NULL;
  fim->prox = NULL;
  l->tam = 0;
  l->atual = l->ini; 
  return 1;
}

/*
  Retorna 1 se a lista está vazia e zero caso contrário.
*/
int lista_vazia(t_lista *l){
  if (l->tam == 0) 
      return 1;
    return 0; 
}

/*
  Insere o elemento item no início da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int insere_inicio_lista(int item, t_lista *l){
  t_nodo *novo;
  t_nodo *aux;
  novo = (t_nodo *) malloc(sizeof(t_nodo));
  if (novo == NULL)
    return 0;  
  novo->chave = item;
  aux = l->ini->prox;
  l->ini->prox = novo;
  aux->prev = novo;
  novo->prox = aux;
  novo->prev = l->ini;
  l->tam ++;
  return 1; 
}   

/*
  Retorna o tamanho da lista em *tam.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int tamanho_lista(int *tam, t_lista *l){
  *tam = l->tam;
  if (l->tam < 0)
    return 0;
  return 1;
 } 
/*
  Insere o elemento item no final da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
/*int insere_fim_lista(int item, t_lista *l){
  if (lista_vazia(&l)){
    insere_inicio_lista(item,&l);
    return 1;
  }  
  else{
    t_nodo *novo;
    novo = (t_nodo *) malloc(sizeof(t_nodo));
    if (novo == NULL)
      return 0;
    novo->chave = item; 

    atual = l->fim->prev;
    atual->prox = novo;
    novo->prev = atual;
    novo->prox =fim; 
    fim->prev = novo;
    l->tam++;
    return 1; 
  } 
}*/
/*
  Insere o elemento item na lista de maneira que ela fique em ordem
  crescente, do início para o final dela.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
/*int insere_ordenado_lista(int item, t_lista *l){

  if (lista_vazia){
    insere_inicio_lista(item,&l);
    return 1; 
  }
 
  if (item == CHAVEMAX){
    insere_fim_lista(item,&l);
    return 1;
  }  
  if (item > CHAVEMAX || item < -(CHAVEMAX)){
    printf("numero grende/pequeno de mais para ser alocado")
    return 0;   
  }
  t_nodo *novo; 
  t_nodo *aux;
  t_nodo *aux2;
  novo = (t_nodo *) malloc(sizeof(t_nodo));
  novo->chave = item; 
  aux = l->ini->prox;
  while (aux->chave < novo->chave ) 
      aux->prox = aux;
  if (aux->prox == NULL){
    insere_fim_lista(item,&l);
    return 1; 
  }    
  aux2 = aux->prev; 
  aux2->prox = novo; 
  aux->prev = novo; 
  novo->prox = aux;
  novo->prev = aux2;
  return 1; 
}*/

/*
  Remove o primeiro elemento da lista e o retorna em *item.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
/*int remove_inicio_lista(int *item, t_lista *l){
  t_nodo *aux;
  t_nodo *aux2;
  if (l->ini->prox == l->fim )
    return 0; 
  else 
    aux = l->ini->prox; 
    aux2 = aux->prox;
    l->ini->prox = aux2;
    aux2->prev = l->ini;
    aux->prox = NULL;
    aux->prev = NULL;
    *item = aux->chave;
    l->tam--;
    free(aux);  

}*/

/*
  Remove o último elemento da lista e o retorna em *item.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
/*int remove_fim_lista(int *item, t_lista *l){
  t_nodo *aux;
  t_nodo *aux2;
  if (l->fim->prev == l->ini )
    return 0; 
  else 
    aux = l->fim->prev; 
    aux2 = aux->prev;
    l->fim->prev = aux2;
    aux2->prox = l->fim;
    aux->prox = NULL;
    aux->prev = NULL;
    *item = aux->chave;
    free(aux);  
} */   
/*
  Se o elemento chave existir na lista, o retorna em *item.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário
  (elemento não encontrado também retorna zero).
*/
/*int remove_item_lista(int chave, int *item, t_lista *l){
  t_nodo *aux;
  t_nodo *auxprev;
  t_nodo *auxprox;


}*/

/*
  Retorna 1 se o elemento contendo a chave chave existe na lista,
  caso contrário retorna zero.
*/
/*int pertence_lista(int chave, t_lista *l){
  t_nodo *aux;
  aux = l->ini->prox;
  while (aux->prox != NULL){
    if (aux->chave == chave)
      return 1; 
  }
  return 0; 
}*/

/* 
  Inicializa o ponteiro atual para o primeiro elemento da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
/*int inicializa_atual_inicio(t_lista *l){
   l->atual = l->ini;
}*/
  
/* 
  Inicializa o ponteiro atual para o ultimo elemento da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
/*int inicializa_atual_fim(t_lista *l){
    l->atual = l->fim; 
} */
/*
  Faz o ponteiro atual apontar para o próximo nodo da lista l e retorna 
  este ponteiro. Se atual estiver apontando para o último, isto é, não 
  tem próximo, retorna NULL.
*/
/*void incrementa_atual(t_lista *l){
    if (l->atual->prox != NULL)
      l->atual = l->atual->prox;
    else 
      l->atual = NULL;  
}   */ 
/*
  Faz o ponteiro atual apontar para o nodo anterior da lista l e retorna 
  este ponteiro. Se atual estiver apontando para o primeiro, isto é, não 
  tem anterior, retorna NULL.
*/
/*void decrementa_atual(t_lista *l){
  if (l->atual->prev != NULL)
    l-atual = l->atual->prev;
  else 
    l->atual = NULL;
}  */
/*
  Retorna em *item o valor contido na chave apontada pelo ponteiro atual. 
  Se atual não for válido a função retorna zero senão retorna 1.
*/
/*int consulta_item_atual(int *item, t_lista *atual){
  if (l->atual->prox == NULL || l->atual->prev == NULL)
    return 0;
  else   
    *item = atual->chave;
  return 1; 
}*/

/*
  Remove o elemento apontado por atual da lista l e o retorna em *item.
  Faz o atual apontar para o sucessor do nodo removido.
  Retorna 1 se houve sucesso e zero caso contrário.
*/
/*int remove_item_atual(int *item, t_lista *l){
  t_nodo *auxprox;
  t_nodo *auxprev;
  if (atual->prox == NULL || atual->prev == NULL)
    return 0;
  else 

}*/

/*
  Remove todos os elementos da lista e faz com que ela aponte para NULL.
*/
/*void destroi_lista(t_lista *l){
  int coisa; 

  l->atual = l->ini;
  while(atual->prox != NULL)
    remove_inicio_lista (&coisa, &l);
  l->ini->prox = NULL; 
  l->fim->prev = NULL;
  free(l->ini);
  free(l->fim);
  l->ini = NULL;
  l->fim = NULL; 
  free(l);

}*/


int main (){
	printf("iniciou \n");
	t_lista lista; 
	int tam; 
	printf("iniciar \n");
	inicializa_lista(&lista);
	
	if (lista_vazia(&lista)){
		tamanho_lista(&tam,&lista);
		printf(" tanaho da lista eh %i",tam);
	}
	/*for (i = 1; i<=tam; i++){
		remove_fim_lista(&j,&lista);
		printf("removido %i",j);
	}*/


return 1;
}