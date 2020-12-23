#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;
int main() {
    // Write C++ code here
    const char  str[] = ".#.";
    double soma;
    int n = 3;
    for (int i = 0; i < n ; i = i + 1) {
        if (str[i] == '#'){
           soma =  soma + str[i]*pow( 2 , i);
            }
        printf("letra: %c numero:  %i \n",str[i],str[i]);

        }
    //sprintf(soma , str);
    
    std::cout << soma;

    return 0;
}
