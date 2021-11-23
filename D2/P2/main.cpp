#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int main() {

    freopen("input.txt","r",stdin);
    string line;
    int valPwd,from,to,charCount;

    size_t pos = 0;
    string tok1 = "-";
    string tok2 = " ";
    string tok3 = ": ";
    string fullpwd;
    valPwd = 0;
    char letra;

    while (getline(cin,line)) { 
        charCount = 0;

        pos =  line.find(tok1);
        from = stoi(line.substr(0,pos));

        line.erase(0,pos + tok1.length());
        pos =  line.find(tok2);
        to = stoi(line.substr(0,pos));

        line.erase(0,pos + tok2.length());
        pos = line.find(tok3);
        letra = line.substr(0,pos).at(0);

        line.erase(0,pos + tok3.length());
        fullpwd = line;

      

        if ( (line.at(from -1 ) == letra && line.at(to -1 ) != letra) ||
            (line.at(to -1 ) == letra && line.at(from -1 ) != letra)
        ) {
            valPwd++;
            // cout << fullpwd << "\n";
        }

        }
        cout << valPwd <<"\n";
    return 0;
}
