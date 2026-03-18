#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscar_en_flujo(const char *termino, FILE *flujo) {
    char *linea = NULL;
    size_t longitud = 1024;
    linea = malloc(longitud);
    while (fgets(linea, longitud, flujo) != NULL) {
        if (strstr(linea, termino) != NULL) {
            printf("%s", linea);
        }
    }
    free(linea);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *termino = argv[1];

    if (argc == 2) {
        buscar_en_flujo(termino, stdin);
        return 0;
    }

    for (int i = 2; i < argc; i++) {
        FILE *archivo = fopen(argv[i], "r");
        if (archivo == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        buscar_en_flujo(termino, archivo);
        fclose(archivo);
    }

    return 0;
}