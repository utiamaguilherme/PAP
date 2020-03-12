#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void quickSort(void * vetor, int ini, int end, int tam, int (*cmp)(void*, void*));
void bubbleSort(void * vetor, int qtd, int tam, int (*cmp)(void* , void*));
void swap(void * a, void * b, size_t tam);
