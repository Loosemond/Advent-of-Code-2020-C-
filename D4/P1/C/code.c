// gcc ./code.c -o out
// 1:40
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *fptr;     
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int validUsers = 0;
    int traits = 0;


    if ((fptr = fopen("data","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }

     while ((read = getline(&line, &len, fptr)) != -1) {
            if (read == 1) {
                if (traits == 7) {validUsers = 1 + validUsers;}
                traits = 0; 
            }

            if ( strstr(line,"byr:") != NULL) {traits = traits +1;}
            if ( strstr(line,"iyr:") != NULL) {traits = traits +1;}
            if ( strstr(line,"eyr:") != NULL) {traits = traits +1;}
            if ( strstr(line,"hgt:") != NULL) {traits = traits +1;}
            if ( strstr(line,"hcl:") != NULL) {traits = traits +1;}
            if ( strstr(line,"ecl:") != NULL) {traits = traits +1;}
            if ( strstr(line,"pid:") != NULL) {traits = traits +1;}           

    }

    if (read == -1) {
        if (traits == 7) {validUsers = 1 + validUsers;}
    }

    fclose(fptr);
    printf("Number of valid users : %d\n",validUsers);
    return 0;
}

