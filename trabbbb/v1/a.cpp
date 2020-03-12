#include <bits/stdc++.h>
#include "curlpp-0.8.1/include/curlpp/cURLpp.hpp"
#include "Easy.hpp"
#include "Options.hpp"

using namespace std;

class Pessoas{
    string id;
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

};

class Alunos : public Pessoas{
    string id;
    string nome;
    string cpf;
};

class Professores : public Pessoas{
    string id;
    string nome;
    string cpf;
};

class Servidores : public Pessoas{
    string id;
    string nome;
    string cpf;
};

int main(void){

curlpp::Cleanup inicio;

// standard request object.
curlpp::Easy myRequest;

// Set the URL.
myRequest.setOpt(new curlpp::options::Url(string("http://127.0.0.1:5000/")));

// Send request and get a result.
// By default the result goes to standard output.
// Here I use a shortcut to get it in a string stream ...
ostringstream os;
os << myRequest.perform();

string asAskedInQuestion = os.str();



/////// v2///
curlpp::Cleanup myCleanup;

        // First easy example.
        {
          // The first easiest example is to retreive the content of
          // a web page and put it in a stream.
          cout << curlpp::options::Url("http://127.0.0.1:5000/");

          // You don't need to use just the standard outputs. You
          // can use any stream:
          ostringstream os;
          os << curlpp::options::Url("http://127.0.0.1:5000/");
        }
}
