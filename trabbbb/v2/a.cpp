#include <bits/stdc++.h>
// #include <curl/curl.h>
#define QUANT 10

using namespace std;

class Pessoa {
    string matricula;
    string nome;
    string cpf;
public:
    Pessoas(string id, string nome, string cpf){
        this -> id = id;
        this -> nome = nome;
        this -> cpf = cpf;
    }
    string getCpf(){
        return cpf;
    }

    string getId(){
        return id;
    }

    string getNome(){
        return nome;
    }
    void show(){
      string ret = "id: "+getId()+" nome: "+getNome()+" cpf: "+getCpf();
      cout << ret << endl;
    }

};


int main(void){
  vector<Pessoa> negado;
  vector<Pessoa> correto;
  // CURL *curl;
  // CURLcode res;
  //
  // curl = curl_easy_init();
  // if(curl) {
  //   curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:5000");
  //
  //   /* Perform the request, res will get the return code */
  //   res = curl_easy_perform(curl);
  //   /* Check for errors */
  //   if(res != CURLE_OK)
  //     fprintf(stderr, "curl_easy_perform() failed: %s\n",
  //             curl_easy_strerror(res));
  //
  //   /* always cleanup */
  //   curl_easy_cleanup(curl);
  // }

  int k = QUANT;
  while(k--){
        string id, nome, cpf;
        cout << "Digite seu id\n";
        cin >> id;
        cout << "Digite seu CPF\n";
        cin >> cpf;
        getchar();
        cout << "Digite seu nome completo\n";
        getline(cin, nome);
        int catraca;
        cout << "Digite 1. Para acessar a catraca dos Alunos\n";
        cout << "Digite 2. Para acessar a catraca dos Servidores\n";
        cout << "Digite 3. Para acessar a catraca dos Professores\n";
        cin >> catraca;
        Pessoas user(id, nome, cpf);
        if(catraca == listaRequisito)   correto.push_back(user);
        else                            negado.push_back(user);
    }
}
