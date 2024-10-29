#include <stdio.h>
#include <string.h>
void q0(char nombre[]);
void q1(char nombre[]);
void q2(char nombre[]);
void q3(char nombre[]);
void q4(char nombre[]);
int main(){
	char nombre[6];
	q0(nombre);
	printf("%s",nombre);
	return 0;
}

void q0(char nombre[]){
	char letra='e';
	strncat(nombre,&letra,1);
	q1(nombre);	
}
void q1(char nombre[]){
	char letra='f';
	strncat(nombre,&letra,1);
	q2(nombre);
}
void q2(char nombre[]){
	char letra='r';
	strncat(nombre,&letra,1);
	q3(nombre);
}
void q3(char nombre[]){
	char letra='e';
	strncat(nombre,&letra,1);
	q4(nombre);
}
void q4(char nombre[]){
	char letra='n';
	strncat(nombre,&letra,1);
}
