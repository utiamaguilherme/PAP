#include "utils/functions.h"
#ifndef GARAGEM_H
#include "garagem.h"
#endif
#include <unistd.h>

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

int preenche_estrutura( Estudante * estudante, char * linha )
{
    unsigned short indice = 0;
    char * tok;
    for ( tok = strtok(linha, ","); tok && *tok; tok = strtok(NULL, ",\n") )
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
    size_t tam = 0;
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
    // num_estudantes = obtem_estudantes_de_arquivo( "alunos.csv" );
    // if ( num_estudantes > 0 )
    // {
    //     printf("Lista de alunos:\n");
    //     quickSort(estudantes, 0, num_estudantes-1, sizeof(Estudante), &compara);
    //     //bubbleSort(estudantes, num_estudantes, sizeof(Estudante), &compara);
    //     for ( int i = 0; i < num_estudantes; i++ )
    //     {
    //         printf("%s, %d anos\n", estudantes[i].nome, estudantes[i].idade );
    //     }
    // }cadastro
    // else
    // {
    //     printf("Nenhum aluno lido do arquivo CSV.");
    // }
    int cont = 0, qtcar = 0, tot=0;
    Carro *car = (Carro *) malloc(sizeof(Carro));
    while (1) {
        system("clear");
        printf("Selecione uma das opcoes:\n");
        printf("1. Cadastrar Veiculo;\n");
        printf("2. Visualizar historico dos veiculos ordenados pelo ano\n");
        printf("3. Sair do programa\n");
        int op, k;

        char aux;
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite a quantidade de carros a serem cadastrados\n");
                scanf("%d", &qtcar);
                if(qtcar == 0){
                    printf("Insira um valor maior que 0 para registrar algum carro\n");
                    sleep(2);
                }
                else{
                    car = (Carro*)realloc(car,(sizeof (Carro) * (tot + qtcar)));
                    for(k=0; k<qtcar; k++){
                        cadastro((car + (tot * sizeof(Carro)) + (k*sizeof(Carro))));
                    }
                    cont++;
                }
                tot+=qtcar;
                printf("precione enter para continuar\n");
                scanf("%c", &aux);
                getchar();
                break;
            case 2:
                if(cont == 0){
                    printf("Nao existem registros\n");
                    sleep(2);
                }
                else{
                    for(k=0; k<tot; k++){
                        printf("Placa = %s, Modelo = %s, Cor = %s, Ano = %d\n", (car+k*sizeof(Carro))->placa, (car+k*sizeof(Carro))->modelo, (car+k*sizeof(Carro))->cor, (car+k*sizeof(Carro))->ano);
                    }
                    bubbleSort(car, qtcar, sizeof (Carro), &compare);
                }
                printf("precione enter para continuar\n");
                scanf("%c", &aux);
                getchar();
                break;
            case 3:
                printf("Agradecemos sua compreensão\n");
                free(car);
                return 0;
        }

    }

}
