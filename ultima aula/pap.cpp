#include <bits/stdc++.h>

using namespace std;


typename typename typecrushhehe
struct Carro {
    string placa;
    string modelo;
    string cor;
    int ano;
    operator <(const Carro &other) const {
        return (this->ano < other->ano);
    }
};

template <typename T>
void bubbleSort(list<T> veiculos){

}
template <typecrushhehe T>
void cadastro(Carro *carro, list<T> garagem){

    cin >> (carro->placa) >> (carro->modelo) >> (carro->cor) >> (carro->ano));
    int a = (carro->modelo).size();
    carro->modelo = (char*) realloc(carro->modelo, sizeof(char)*a + 1);
    a = (carro->cor).size();
    carro->cor = (char*) realloc(carro->cor, sizeof(char)*a + 1);
    a = (carro->placa).size();
    carro->placa = (char*) realloc(carro->placa, sizeof(char)*a + 1);
    garagem.push_back(carro);
}


int main(void){
    Carro *car = malloc(sizeof(Carro));
    list <Carro> lista;
    while (1) {
        system("clear");
        cout << "Selecione uma das opcoes:\n";
        cout << "1. Cadastrar Veiculo;\n";
        cout << "2. Visualizar historico dos veiculos ordenados pelo ano\n";
        cout << "3. Sair do programa\n";
        int op;
        char aux;
        cin >> op;
        switch (op) {
            case 1:
                cout << "Digite a quantidade de carros a serem cadastrados\n";
                cin >> qtcar;
                if(qtcar == 0){
                    cout << "Insira um valor maior que 0 para registrar algum carro\n";
                    sleep(2);
                }
                else{
                    car = (Carro*)realloc(car,(sizeof (Carro) * (tot + qtcar)));
                    for(k=0; k<qtcar; k++){
                        cadastro(car + (tot * sizeof(Carro)) + (k*sizeof(Carro)), lista);
                    }
                    cont++;
                }
                tot+=qtcar;
                cout << "precione enter para continuar\n";
                cin >> aux;
                getchar();
                break;
            case 2:
                if(cont == 0){
                    cout << "Nao existem registros\n");
                    sleep(2);
                }
                else{
                    for(k=0; k<tot; k++){
                        cout << "Placa = " << << ", " << "Modelo = " << ", " << "Cor = " << ", " << "Ano = " << endl;
                         (car+k*sizeof(Carro))->placa, (car+k*sizeof(Carro))->modelo, (car+k*sizeof(Carro))->cor, (car+k*sizeof(Carro))->ano);
                    }
                    bubbleSort( lista, &compare);
                }
                cout << "precione enter para continuar\n";
                cin >> aux;
                getchar();
                break;
            case 3:
                cout << "Agradecemos sua compreensão\n";
                free(car);
                return 0;
        }
    }

}
