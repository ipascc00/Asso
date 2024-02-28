#include <stdio.h>
#include <stdlib.h>

void inicialize() {

    char* variableReservada = (char*)malloc(14000); // Variable local de 14.000 bytes
    if (variableReservada == NULL) {
        perror("Error en malloc");
        exit(EXIT_FAILURE);
    }

    printf("Dirección de variableReservada después de malloc: %p\n", (void*)variableReservada);
    printf("Tamaño de variableReservada después de malloc: %ld bytes\n", sizeof(variableReservada));
    printf("contenido de variableReservada después de malloc: %s\n", variableReservada);
    char cmd[25];
    printf("mapa de memoria de inicialize\n");
    sprintf(cmd, "cat /proc/%d/maps", getpid());
    system(cmd);

    free(variableReservada); // Liberar la memoria reservada
}

int main() {
    char cmd[25];
    printf("mapa de memoria de main\n");
    sprintf(cmd, "cat /proc/%d/maps", getpid());
    system(cmd);

    inicialize();

    // Imprimir mapa de memoria despues 
    printf("Mapa de memoria después de inicialize()\n");
    sprintf(cmd, "cat /proc/%d/maps", getpid());
    system(cmd);

    return 0;
}