#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

std::vector<int> lerNumeros(std::string ficheiro ) {

    std::ifstream data (ficheiro.c_str());
    std::string str;
    std::vector<int> numeros;

    while(std::getline(data , str)) {

       if(str.size() > 0 ) {
            numeros.push_back(std::stoi(str));
       }
    }
    data.close();
    return numeros;
}

int main() {

    std::vector<int> numeros = lerNumeros("./data");

    for (int x : numeros) {
        for (int y : numeros){
            if (x+y == 2020) {
                cout << "Done: " << x*y << "\n";
                return x*y;
            }
        }
    }    
    
    return 0;
}

