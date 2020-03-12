#include <bits/stdc++.h>
#include "curlpp-0.8.1/include/curlpp/cURLpp.hpp"
#include "Easy.hpp"
#include "Options.hpp"

using namespace std;

class Alunos{

};

class Professores{

};

class Servidores{

};

int main(void){

curlpp::Cleanup inicio;

// standard request object.
curlpp::Easy myRequest;

// Set the URL.
myRequest.setOpt(new curlpp::options::Url(std::string("http://www.wikipedia.com")));

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
          std::cout << curlpp::options::Url("http://example.com");

          // You don't need to use just the standard outputs. You
          // can use any stream:
          std::ostringstream os;
          os << curlpp::options::Url("http://example.com");
        }
}
