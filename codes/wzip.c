#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int contador = 0;
    int caracter_actual;
    int caracter_anterior = -1; 

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((caracter_actual = fgetc(fp)) != EOF) {
            if (caracter_anterior == -1) {
                caracter_anterior = caracter_actual;
                contador = 1;
            } else if (caracter_actual == caracter_anterior) {
                contador++;
            } else {
               
                fwrite(&contador, sizeof(int), 1, stdout);
                fwrite(&caracter_anterior, sizeof(char), 1, stdout);
                
                caracter_anterior = caracter_actual;
                contador = 1;
            }
        }
        fclose(fp);
    }

   
    if (caracter_anterior != -1) {
        fwrite(&contador, sizeof(int), 1, stdout);
        fwrite(&caracter_anterior, sizeof(char), 1, stdout);
    }

    return 0;
}