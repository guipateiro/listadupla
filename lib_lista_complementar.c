/*
  Feito por Marcos Castiho para a disciplina CI1001 - Programacao I
  Em 18/10/2019.
  Biblioteca auxiliar que manipula o TAD lista. 
*/

#include <stdio.h>
#include "lista.h"

#define MAX 5

/*
  Funcao que imprime todos os elementos da lista, do inicio ao fim.
  Caso a lista seja vazia nao imprime nada, nem um \n
*/
void imprime_lista(t_lista *l){
  if (lista_vazia(l))
    return 0;

  int tam, item , i;
  tamanho_lista(&tam , l ); 
  inicializa_atual_inicio(l);
  incrementa_atual(l);
  for (i = 1; i <= tam; i++){
    consulta_item_atual(&item ,l);
    printf("item %i : %i",i ,item);
    incrementa_atual(l);
  } 
  return 0; 

}

/*
  Funcao que copia todos os elementos da lista l na lista c.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int copia_lista(t_lista *l, t_lista *c){
  if(lista_vazia(l))
    return 0; 

  int tam, item , i; 
  tamanho_lista(&tam , l );
  inicializa_atual_inicio(l);
  for (i = 1; i <= tam; i++){
  }


}

/*
  Concatena os elementos da lista c (na mesma ordem) ao final
  da lista l e destroi a lista c.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int concatena_listas(t_lista *l, t_lista *c){
  if (lista_vazia(c))
    return 0; 

  int tam,item,i; 
  tamanho_lista(&tam , c);
  inicializa_atual_inicio(c);
  incrementa_atual(c);
  for (i = 1; i <= tam; i++){
    consulta_item_atual(&item , c);
    insere_fim_lista(item , l);
    incrementa_atual(c);
  }

  destroi_lista(c);
  return 1; 
}


/*
  Ordena a lista l em ordem crescente.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int ordena_lista(t_lista *l){
  if (lista_vazia(l))
    return 0;

  t_lista aux;
  int tam , i , elemento; 
  tamanho_lista(&tam , l);
  inicializa_lista(&aux);
  inicializa_atual_inicio(l);
  incrementa_atual(l);
  for (i = 1; i <= tam; i++){
    consulta_item_atual(&item , l);
    insere_ordenado_lista(item , &aux);
    incrementa_atual(l)
  }
  destroi_lista(l);
  inicializa_lista(l);
  copia_lista(&aux , l);
  return 1; 
}

/*
  Funcao que cria uma nova lista i pela intercalacao dos elementos
  das listas l e c. As listas l e c devem estar ordenadas.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int intercala_listas(t_lista *l, t_lista *m, t_lista *i);
