/*
  Feito por Marcos Castiho para a disciplina CI1001 - Programacao I
  Em 18/10/2019.
  Define a estrutura de dados para o Tipo Abstrato de Dados Lista
  como sendo uma lista duplamente encadeada com sentinelas no inicio
  e no final. A cabeca da lista tem ponteiros para o inicio, fim e
  para um elemento qualquer da lista, alem do tamanho da lista.
  Contem os prototipos publicos das funcoes que manipulam o TAD.
*/
#define CHAVEMAX 2147483647;
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
    int tamanho;
};
typedef struct t_lista t_lista;

/*
  Cria uma lista vazia. Ela eh duplamente encadeada e tem sentinelas no
  inicio e no final. Tambem tem um apontador para um elemento qualquer.
*/
int inicializa_lista(t_lista *l){
  t_nodo *incio,*fim;
  inicio = (t_nodo *) malloc(sizeof(t_nodo));
  fim = (t_nodo *) malloc(sizeof(t_nodo));
  inicio = l->ini;
  fim = l->fim;
  inicio->prox = fim;
  fim->prev = inicio;
  fim->chave = CHAVEMAX;
  inicio->prev = NULL;
  fim->prox = NULL;
  l->tam = 0;
  l->atual = ini; 
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
  Remove todos os elementos da lista e faz com que ela aponte para NULL.
*/
void destroi_lista(t_lista *l);

/*
  Insere o elemento item no início da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int insere_inicio_lista(int item, t_lista *l){
  t_nodo *novo;
  novo = (t_nodo *) malloc(sizeof(t_nodo));
  if (novo == NULL)
    return 0;  
  novo->chave = x;
  atual = l->ini->prox;
  atual->prev = novo;
  l->ini->prox = novo;
  novo->prox = atual;
  novo->prev = ini;
  l->tam ++;
  return 1; 
}   

/*
  Retorna o tamanho da lista em *tam.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int tamanho_lista(int *tam, t_lista *l){
  tam = l->tam;
  if (l->tam < 0)
    return 0;
  return 1;
 } 
/*
  Insere o elemento item no final da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int insere_fim_lista(int item, t_lista *l);
  if (lista_vazia){
    insere_inicio_lista(item,&l);
    return 1;
  }  
  else{
    t_nodo *novo;
    novo = (t_nodo *) malloc(sizeof(t_nodo));
    if (novo == NULL)
      return 0;
    novo->chave = x; 

    atual = l->fim->prev;
    atual->prox = novo;
    novo->prev = atual;
    novo->prox =fim; 
    fim->prev = novo;
    return 1; 
  } 

/*
  Insere o elemento item na lista de maneira que ela fique em ordem
  crescente, do início para o final dela.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int insere_ordenado_lista(int item, t_lista *l){
  if (lista_vazia){
    insere_inicio_lista(item,&l);
    return 1; 
  }
 
  if (item == CHAVEMAX){
    insere_fim_lista(item,&l)
    return 1;
  }  
  if (item >> CHAVEMAX || item << -(CHAVEMAX){
    printf("numero grende/pequeno de mais para ser alocado")
    return 0;   
  }
  t_nodo *novo; 
  t_nodo *aux;
  novo = (t_nodo *) malloc(sizeof(t_nodo));
  novo->chave = item; 
  atual = ini->prox;
  while (atual->chave << novo->chave ) 
    atual->prox = atual;
  if (atual->prox == NULL){
    insere_fim_lista(item,&l);
    return 1; 
  }
  aux = atual->prev; 
  aux->prox = novo; 
  atual->prev = novo; 
  novo->prox = atual;
  novo->prev = aux;
}

/*
  Remove o primeiro elemento da lista e o retorna em *item.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int remove_inicio_lista(int *item, t_lista *l);

/*
  Remove o último elemento da lista e o retorna em *item.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int remove_fim_lista(int *item, t_lista *l);

/*
  Se o elemento chave existir na lista, o retorna em *item.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário
  (elemento não encontrado também retorna zero).
*/
int remove_item_lista(int chave, int *item, t_lista *l);

/*
  Retorna 1 se o elemento contendo a chave chave existe na lista,
  caso contrário retorna zero.
*/
int pertence_lista(int chave, t_lista *l);

/* 
  Inicializa o ponteiro atual para o primeiro elemento da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int inicializa_atual_inicio(t_lista *l);

/* 
  Inicializa o ponteiro atual para o ultimo elemento da lista.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int inicializa_atual_fim(t_lista *l);

/*
  Faz o ponteiro atual apontar para o próximo nodo da lista l e retorna 
  este ponteiro. Se atual estiver apontando para o último, isto é, não 
  tem próximo, retorna NULL.
*/
void incrementa_atual(t_lista *l);

/*
  Faz o ponteiro atual apontar para o nodo anterior da lista l e retorna 
  este ponteiro. Se atual estiver apontando para o primeiro, isto é, não 
  tem anterior, retorna NULL.
*/
void decrementa_atual(t_lista *l);

/*
  Retorna em *item o valor contido na chave apontada pelo ponteiro atual. 
  Se atual não for válido a função retorna zero senão retorna 1.
*/
int consulta_item_atual(int *item, t_lista *atual);

/*
  Remove o elemento apontado por atual da lista l e o retorna em *item.
  Faz o atual apontar para o sucessor do nodo removido.
  Retorna 1 se houve sucesso e zero caso contrário.
*/
int remove_item_atual(int *item, t_lista *l);
