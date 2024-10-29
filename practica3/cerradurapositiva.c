#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cerraduraPositiva(char* conjunto, int longitudMax, char* combinaciones);
char* newCadena(int longitud);

int main(){
    char conjunto[] = "ab";
    int longitudMax;
    printf("Introduce la longitud  para la Cerradura Positiva: ");
    scanf("%d", &longitudMax);
    char* combinaciones=newCadena(longitudMax);
    cerraduraPositiva(conjunto, longitudMax, combinaciones);
    return 0;
}
void cerraduraPositiva(char* conjunto, int longitudMax, char* combinaciones) {
    int tamConjunto=strlen(conjunto);
    int i, num, longitud;
    for (longitud = 1; longitud <= longitudMax; longitud++) {
        int totalCombinaciones = 1;
       // Calcular el total de combinaciones para la longitud actual 
        for (i = 0; i < longitud; i++) {
            totalCombinaciones *= tamConjunto;
        }
        // Generar cada combinación
        for (num = 0; num < totalCombinaciones; num++) {
            int temp = num;
            int longitudDCadena; 
            // Construir la combinación correspondiente
            for (i = 0; i < longitud; i++) {
                combinaciones[i] = conjunto[temp % tamConjunto];
                temp /= tamConjunto;
            }
            combinaciones[longitud] = '\0'; 
            printf("'%s'\n", combinaciones);
            longitudDCadena=strlen(combinaciones);
            printf("la longitud de cadena es:%i",longitudDCadena);
        }
    }
}

char* newCadena(int longitud) {
    char* cadena = (char*)malloc(sizeof(char) * (longitud + 1));
    return cadena;
}

