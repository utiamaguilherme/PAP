#ifndef FUNCTIONS_H
#include "utils/functions.h"
#endif
#ifndef GARAGEM_H
#include "garagem.h"
#endif

void cadastro(Carro *carro){
    carro->modelo = (char*) malloc(sizeof(char) * 30);
    carro->cor = (char*) malloc(sizeof(char) * 30);
    scanf("%s %s %s %d", (carro->placa), (carro->modelo), (carro->cor), &(carro->ano));
    int a = strlen(carro->modelo);
    carro->modelo = (char*) realloc(carro->modelo, sizeof(char)*a + 1);
    a = strlen(carro->cor);
    carro->cor = (char*) realloc(carro->cor, sizeof(char)*a + 1);
}

int compare(void * a, void * b){
    Carro *aa = (Carro*) a;
    Carro *bb = (Carro*) b;
    return (aa->ano) - (bb->ano);
}
