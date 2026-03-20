#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *archivo = fopen(argv[i], "rb");
        if (archivo == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        int contador;
        char caracter;

        while (fread(&contador, sizeof(int), 1, archivo) == 1) {
            fread(&caracter, sizeof(char), 1, archivo);
            for (int j = 0; j < contador; j++) {
                printf("%c", caracter);
            }
        }

        fclose(archivo);
    }

    return 0;
}