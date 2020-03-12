#ifndef FUNCTIONS_H
#include "functions.h"
#endif

void quickSort(void * vetor, int ini, int end, int tam, int (*cmp)(void*, void*)){
  int i, j;
  i = ini, j = end;

  void *pivo = vetor + (end-ini)/2*tam;
  while(i <= j){
    void *now = vetor + i*tam;
    while(cmp(now, pivo) < 0) i++, now = vetor + i*tam;
    now = vetor + j*tam;
    while(cmp(now, pivo) > 0) j--, now = vetor + j*tam;
    if(i <= j){
      swap(vetor, vetor + i*tam, (size_t)tam);
      i++;j--;
    }
  }
  if(ini < j){
    quickSort(vetor, ini, j, tam, cmp);
  }
  if(i < end){
    quickSort(vetor, i, end, tam, cmp);
  }

}

void bubbleSort(void * vetor, int qtd, int tam, int (*cmp)(void* , void*)){
  int i=0, j=0;
  for(; i<qtd; i++){
    void * elem = vetor + i*tam;
    for(j=i+1; j<qtd; j++){
      void * prox = vetor + j*tam;
      if(cmp(elem, prox) == 1){
        swap(elem, prox, sizeof(elem));
      }
    }
  }
}

void swap(void * elem, void * prox, size_t tam){
    void * temp = malloc(tam);
    memcpy(temp, elem, tam);
    memcpy(elem, prox, tam);
    memcpy(prox, temp, tam);
    free(temp);
}
