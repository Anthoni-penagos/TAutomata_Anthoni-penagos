#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void complementoParaLetras(char a[], int rango);
void interseccion(char a[], char b[]);
void diferencia(char z[], char x[]);
char* unionAlfabetos(char alfabeto1[], char alfabeto2[]);
char* newCadena(int longitud);
void funcionCorrecta(char alfabeto1[]);
int main() {
    int n=0,t,i;
    char s1[50], s2[50], *ptr;
    char alfabeto1[50] = "", alfabeto2[50] = "";
    
    printf("Por favor, ingrese el primer conjunto de caracteres separados por espacios:\n");
    scanf(" %[^\n]%*c", s1); 
    ptr = strtok(s1, " ");
    while (ptr != NULL) {
        if (!strchr(alfabeto1, *ptr)) { 
            strncat(alfabeto1, ptr, 1);  
        }
        ptr = strtok(NULL, " ");
    }
    printf("Ingrese el segundo conjunto de caracteres separados por espacios:\n");
    scanf(" %[^\n]%*c", s2);
    ptr = strtok(s2, " ");
    while (ptr != NULL) {
        if (!strchr(alfabeto2, *ptr)) { 
            strncat(alfabeto2, ptr, 1);  
        }
        ptr = strtok(NULL, " ");
    }
    do {
		printf("Primer Lenguaje= ");
		for(t=0;t<strlen(alfabeto1);t++){
			printf("|%c ",alfabeto1[t]);
		}
		printf("\n");
		printf("Segundo Lenguaje= ");
		for(i=0;i<strlen(alfabeto2);i++){
			printf("|%c ",alfabeto2[i]);
		}
        printf("\nElija la opcion de su preferencia:\n");
        printf("1.- Complemento\n2.- Diferencia\n3.- Interseccion\n4.- Union\n5.- Salir\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("El complemento del primer conjunto es: ");
                funcionCorrecta(alfabeto1);  
                break;
            case 2:
                printf("\nLa diferencia de los dos conjuntos es: ");
                diferencia(alfabeto1, alfabeto2);
                break;
            case 3:
                printf("\nLa interseccion de los dos conjuntos es: ");
                interseccion(alfabeto1, alfabeto2);
                break;
            case 4: {
                printf("\nLa union de los dos conjuntos es: ");
                char* unionRes = unionAlfabetos(alfabeto1, alfabeto2);
                printf("%s\n", unionRes);
                break;
            }
            case 5:
                printf("\nSaliendo\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (n != 5);

    return 0;
}
void complementoParaLetras(char a[], int rango) {
    int i, j, encontrado;
    for (j = 'a'; j < 'a' + rango; j++) {
        encontrado = 0;
        for (i = 0; i < strlen(a); i++) {
            if (j == a[i]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("%c ", j);
        }
    }
    printf("\n");
}
void complementoParaNum(char a[],int rango) {
	int size=strlen(a);
	int i,j;
	int array[100];
	for(j=0;j<100;j++){
		array[j]=j;
	}
	    for (j=1;j<rango;j++){
        int encontrado=0;
        for (i=0;i<size;i++){
            if (array[j]==(a[i]-'0')){ 
                encontrado=1;
            }
        }
        if (!encontrado) {
            printf("%d ", array[j]);
        }
    }
}
void interseccion(char a[], char b[]) {
    int i, j;
    for (i = 0; i < strlen(a); i++) {
        for (j = 0; j < strlen(b); j++) {
            if (a[i] == b[j]) {
                printf("%c ", a[i]);
                break;
            }
        }
    }
    printf("\n");
}
void diferencia(char z[], char x[]) {
    int i, j, encontrado;
    for (i = 0; i < strlen(z); i++) {
        encontrado = 0;
        for (j = 0; j < strlen(x); j++) {
            if (z[i] == x[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("%c ", z[i]);
        }
    }
    printf("\n");
}
char* unionAlfabetos(char alfabeto1[],char alfabeto2[]) {
    int longitud=strlen(alfabeto1)+strlen(alfabeto2)+1;
    char* nuevaCadena=newCadena(longitud);
    strcpy(nuevaCadena,alfabeto1);
    strcat(nuevaCadena,alfabeto2);
    return nuevaCadena;
}

char* newCadena(int longitud) {
    char* cadena = (char*)malloc(sizeof(char) * longitud);
    return cadena;
}
void funcionCorrecta(char alfabeto1[]) {
    int esLetra = isalpha(alfabeto1[0]); 
    if (!esLetra) {
        complementoParaNum(alfabeto1, 100); 
    } else {
		complementoParaLetras(alfabeto1,26);
	}
}




