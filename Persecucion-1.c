#include <stdio.h>
#include <pthread.h>

//Estructura del movl, inicia en (50,50)
struct movil{
	int coordenadaX_origen, coordenadaY_origen;
	coordenadaX_origen = 50;
	coordenadaY_origen = 50;
};
//
void *hilo1();
//Declaración de la funcion del hilo secundario, recibe coordenadas X y Y destino 
void *hilo2(struct movil *destino);

int main(){
	
	//int coordenadaX_destino, coordenadaY_destino;
	int pasos = 0; //Pasos para llegar al destino

	//Creación Hilo principal
	pthread_t hilo_principal;
	pthread_create(&hilo_principal, NULL, &hilo1, NULL);
	//Creación Hilo secundario
	pthread_t hilo_secundario;
	phread_create(&hilo_secundario, NULL, &hilo2, NULL);

	

	//FInalización de los hilos
	pthread_join(hilo_principal, NULL);
	pthread_join(hilo_secundario, NULL); 

	return 0;

}

void *hilo1(){

}

void *hilo2(struct movil *destino){
	
}