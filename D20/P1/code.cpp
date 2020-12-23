#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#include <sys/mman.h>

using namespace std;

int lerTiles(std::string ficheiro, int h , int l , int tile[][9]) {

    std::ifstream data (ficheiro.c_str());
    std::string str;
    std::vector<std::string> linhas;
    // int tile[nTotalTiles][4];
    int nLinha = 0 ;
    int nTile = 0;
    tile[0][1] = 0;
    tile[0][2] = 0;
    tile[0][3] = 0;
    tile[0][4] = 0;
    tile[0][5] = 0;
    tile[0][6] = 0;
    tile[0][7] = 0;
    tile[0][8] = 0;
    while(std::getline(data , str)) {
        // nome 
        if (nLinha == 0 && str.size() > 0) {
        tile[nTile][0] = stoi(str.substr(5,5));
        } 
        
        // parte de cima [1]
        if (nLinha == 1 ) {
            int soma = 0;
            int somaflip = 0;
            for (int i = 0; i < l ; i = i + 1) {
                if (str[i] == '#') {
                    soma =  soma + pow( 2 , i);
                    somaflip = somaflip + pow(2,((l-1)-i));
                    // cout << "nTile = "<< nTile << " 2^" << ((l-1) - i) << " = " << somaflip << "\n";
                    }
            }
        tile[nTile][1] = soma;
        tile[nTile][5] = somaflip;
        }
        // lado esquerdo [4] e direito [2] 
        if (nLinha < 11 && nLinha > 0 ) {
            //esq
            if (str[0] == '#'){
                tile[nTile][4] = tile[nTile][4] + pow( 2 , nLinha - 1);
                tile[nTile][8] = tile[nTile][8] + pow( 2 , 9 - (nLinha - 1));
            } 
            //dir
            
            if (str[l-1] == '#'){
                tile[nTile][2] = tile[nTile][2] + pow( 2 , nLinha - 1);
                tile[nTile][6] = tile[nTile][6] + pow( 2 , 9 - (nLinha - 1));
            } 
    
  
            // cout << "nTile = "<< nTile << " 2^" << (9 - (nLinha - 1) ) << " = " << tile[nTile][6] << "\n";
            
           } 
        // parte de baixo [3]
        if (nLinha == 10){
            int soma = 0;
            int somaFlip = 0; 
            for (int i = 0; i < l ; i = i + 1) {
                if (str[i] == '#') {
                    soma =  soma + pow( 2 , i);
                    somaFlip = somaFlip + pow(2,((l-1)-i));
                }
            }
            tile[nTile][3] = soma;
            tile[nTile][7] = somaFlip;

            }
        
       nLinha++;
       if (nLinha == 12) {
            // cout << "tiles befor = " << tile[nTile][4] << "\n";
           nLinha = 0;
           nTile = nTile + 1;
           tile[nTile][1] = 0;
           tile[nTile][2] = 0;
           tile[nTile][3] = 0;
           tile[nTile][4] = 0;
           tile[nTile][5] = 0;
           tile[nTile][6] = 0;
           tile[nTile][7] = 0;
           tile[nTile][8] = 0;
       }
    }
    data.close();
    return 0;
}

int main() {
    int tiles[149][9];
    
    lerTiles("./data",10,10,tiles);
    std::vector<int> resposta;
    int j = 0;
    for(int i = 0; i < 145; i = i + 1) {
        int nCombinacoes = 0;
    
        j = 0; 
        
        while( j < 145) {
            // cout << "nCombinacoes = " << nCombinacoes << "\n";
            if (tiles[i][1] == tiles[j][1] || tiles[i][1] == tiles[j][2] || tiles[i][1] == tiles[j][3] || tiles[i][1] == tiles[j][4] ||
                tiles[i][2] == tiles[j][1] || tiles[i][2] == tiles[j][2] || tiles[i][2] == tiles[j][3] || tiles[i][2] == tiles[j][4] ||
                tiles[i][3] == tiles[j][1] || tiles[i][3] == tiles[j][2] || tiles[i][3] == tiles[j][3] || tiles[i][3] == tiles[j][4] ||
                tiles[i][4] == tiles[j][1] || tiles[i][4] == tiles[j][2] || tiles[i][4] == tiles[j][3] || tiles[i][4] == tiles[j][4] ||
                tiles[i][5] == tiles[j][1] || tiles[i][5] == tiles[j][2] || tiles[i][5] == tiles[j][3] || tiles[i][5] == tiles[j][4] ||
                tiles[i][6] == tiles[j][1] || tiles[i][6] == tiles[j][2] || tiles[i][6] == tiles[j][3] || tiles[i][6] == tiles[j][4] ||
                tiles[i][7] == tiles[j][1] || tiles[i][7] == tiles[j][2] || tiles[i][7] == tiles[j][3] || tiles[i][7] == tiles[j][4] ||
                tiles[i][8] == tiles[j][1] || tiles[i][8] == tiles[j][2] || tiles[i][8] == tiles[j][3] || tiles[i][8] == tiles[j][4]
            ) {
                nCombinacoes = nCombinacoes + 1;
                // cout << tiles[i][1] << "   " << tiles[j][1] << "\n";
                // cout << tiles[i][2] << "   " << tiles[j][2] << "\n";
                // cout << tiles[i][3] << "   " << tiles[j][3] << "\n";
                // cout << tiles[i][4] << "   " << tiles[j][4] << "\n\n"; 

                // cout << tiles[i][5] << "   " << tiles[j][1] << "\n";
                // cout << tiles[i][6] << "   " << tiles[j][2] << "\n";
                // cout << tiles[i][7] << "   " << tiles[j][3] << "\n";
                // cout << tiles[i][8] << "   " << tiles[j][4] << "\n\n"; 
 
            }
            
            j = j + 1;
            
        }
        if (nCombinacoes == 3) {
            // int flag = 0;          
            // for (int k = 0; k < resposta.size(); k = k + 1 ){
            //     // cout << resposta[k]  << " == " << tiles[i][0] << " i = " << i << "\n";
            //     if (resposta[k] == tiles[i][0]){
            //         cout << "flag!!!";
            //         flag = 1;
            //         break;
            //     }
            // }
            // if (flag == 0) resposta.push_back(tiles[i][0]);
            resposta.push_back(tiles[i][0]);

        
        }
        nCombinacoes = 0;
    }

    // cout << "respostas\n";
    // for (int x : resposta){
    //     cout << x << "\n";
    // }
    cout << resposta[0] << "\n" << resposta[1] << "\n" << resposta[2] << "\n" << resposta[3] << "\n";
    double respostaFinal = (double) resposta.at(0) * resposta.at(1) * resposta.at(2) * resposta.at(3) ;

    // cout << resposta[0];
    // for (int i = 0; i < 144 ; i = i + 1 ) {
    //     cout << (int) tiles[i][0] << "  " << ((tiles[i][1] * 0x0202020202ULL & 0x010884422010ULL) % 0b1111111111) << "   " <<  (tiles[i][2]^0b1111111111) << "   " << (tiles[i][3]^0b1111111111) << "   " << (tiles[i][4]^0b1111111111) << "\n";
    // }
    int i = 2;
    // cout << "non flip" << "\n";
    // cout << (int) tiles[i][0] << "  " << tiles[i][1]  << "   " <<  tiles[i][2] << "   " << tiles[i][3] << "   " << tiles[i][4] << "\n";
    // cout << "flip" << "\n";
    // cout << (int) tiles[i][0] << "  " << tiles[i][5] << "   " <<  (tiles[i][2]^0b1111111111) << "   " << (tiles[i][3]^0b1111111111) << "   " << (tiles[i][4]^0b1111111111) << "\n";

    // resposta 
    cout.precision(17);
    cout <<"\nResposta: " << respostaFinal << "\n";

    return 0 ;
}
