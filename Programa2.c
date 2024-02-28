#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


void inicialize() {
    char variableLocal[14000]; // Variable local de 14.000 bytes
    printf("Dirección de variableLocal: %p\n", (void*)&variableLocal);
    printf("Tamaño de variableLocal: %ld bytes\n", sizeof(variableLocal));

    char cmd[25];
    printf("mapa de memoria de inicialize\n");
    sprintf(cmd, "cat /proc/%d/maps", getpid());
    system(cmd);
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
