#include <stdio.h>
void Ejecutar();
void q0();
void q1();
int main(){
	Ejecutar();
	return 0;
}
void q0(){
	printf("apagado\n");
}
void q1(){
	printf("encendido\n");
}
void Ejecutar(){
	int j=1;
	int i=0;
	while(j!=0){
    	if(i==0){
			q1();
			i=1;
		}else{
			q0();
			i=0;
	    }
	}	
}
