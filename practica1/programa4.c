#include <stdio.h>
#include <math.h>

int main() {
    double x = 1.0;
    double resultado = cos(x);
    printf("Dirección de memoria de la función cos: %p\n", cos);
    printf("Dirección de memoria de la variable resultado: %p\n", &resultado);
    return 0;
}