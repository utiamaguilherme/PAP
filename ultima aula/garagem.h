typedef struct{
    char placa[7];
    char *modelo;
    char *cor;
    int ano;
}Carro;

void cadastro(Carro *carro);
int compare(void * a, void * b);
