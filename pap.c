#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DE_ESTUDANTES 100

/* Notas:
 * https://linux.die.net/man/3/getline
 * http://man7.org/linux/man-pages/man3/perror.3.html
 */

typedef struct
{
    char * nome;
    char genero;
    char matricula[8];
    short idade;
} Estudante;

Estudante * estudantes;
int num_estudantes;

int compara(void *a, void *b){
  Estudante *aa = (Estudante*)a;
  Estudante *bb = (Estudante*)b;
  //printf("A: %d\nB: %d\n", aa->idade, bb->idade);
  if(aa->idade > bb->idade){
    return 1;
  }else if(aa->idade < bb->idade){
    return -1;
  }
  return 0;
}

void printa(void *estudantes){
  Estudante * eestudantes = (Estudante*)estudantes;
  printf("%s, %d anos\n", eestudantes->nome, eestudantes->idade );
}

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
      printf("trocando\n");
      void * temp = malloc(tam);
      memcpy(temp, vetor + i*tam, tam);
      memcpy(vetor + i*tam, vetor + j*tam, tam);
      memcpy(vetor + j*tam, temp, tam);
      i++;j--;
      free(temp);
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
        void * temp = malloc(tam);
        memcpy(temp, elem, tam);
        memcpy(elem, prox, tam);
        memcpy(prox, temp, tam);
        free(temp);
      }
    }
  }
}

int preenche_estrutura( Estudante * estudante, char * linha )
{
    unsigned short indice = 0;
    char * tok;
    for ( tok = strtok(linha, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n") )
    {
#ifdef DEBUG
        printf( "%d, %s\n", indice, tok );
#endif
        switch( indice )
        {
            case 0:
                estudante->nome = strdup( tok );
                break;
            case 1:
                estudante->genero = tok[0];
                break;
            case 2:
                strncpy( estudante->matricula, tok, 7 );
                estudante->matricula[7] = '\0';
                break;
            case 3:
                estudante->idade = atoi( tok );
                break;
            default:
                perror( "Erro ao processar arquivo CSV: formato fora do esperado." );
                return -1;
        }
        indice++;
    }
}

int obtem_estudantes_de_arquivo( const char * arquivo )
{
    FILE * fd = NULL;
    char * linha = NULL;
    int tam = 0;
    int lido = 0;
    unsigned short contador = 0;
    char * conteudo[ MAXIMO_DE_ESTUDANTES ];

    fd = fopen( arquivo, "r" );
    if ( fd == NULL )
    {
        perror( "Erro ao abrir arquivo" );
        return -1;
    }

    memset( conteudo, 0, MAXIMO_DE_ESTUDANTES );

    // Ler arquivo linha a linha e guardar em um array de C st+rings
    // Define também o númerotam de alunos, limitado ao máximo de
    // MAXIMO_DE_ESTUDANTES
    while ( ( lido = getline( &linha, &tam, fd ) ) != -1 )
    {
#ifdef DEBUG
        printf( "%s", linha );
#endif
        conteudo[ contador ] = strdup( linha );
        contador++;
    }

    estudantes = (Estudante*)malloc( contador * sizeof (Estudante) );
    for ( int i = 0; i < contador; i++ )
    {
        if ( conteudo[i] != NULL )
        {
            preenche_estrutura( &estudantes[i], conteudo[i] );
        }
    }

    // Liberar tudo que foi alocado
    for ( int i = 0; i < contador; i++ )
    {
        free( conteudo[i] );
    }
    free(linha);
    fclose( fd );
    return contador;
}

int main()
{
    num_estudantes = obtem_estudantes_de_arquivo( "alunos.csv" );
    if ( num_estudantes > 0 )
    {
        printf("Lista de alunos:\n");
        quickSort(estudantes, 0, num_estudantes-1, sizeof(Estudante), &compara);
        //bubbleSort(estudantes, num_estudantes, sizeof(Estudante), &compara);
        for ( int i = 0; i < num_estudantes; i++ )
        {
            printf("%s, %d anos\n", estudantes[i].nome, estudantes[i].idade );
        }
    }
    else
    {
        printf("Nenhum aluno lido do arquivo CSV.");
    }
    return 0;
}
