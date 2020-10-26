/*
NOMBRE : CORTEZ IBARRA DEREK
MATERIA: SISTEMAS OPERATIVOS
FECHA: 25 DE OCTUBRE DEL 2020

PROPOSITO DEL PROGRAMA: 
Hacer un programa (a) con un hilo secundario (b) que reciba dos parámetros,
coordenada X y Coordenada Y destino y luego, va a (c) mover progresivamente un "movil" que parte de la coordenada 50,50 
(de un "tablero" de 100x100) con pasos de +-1 en X así como Y por paso. (d) El hilo principal en el inter, 
presenta el progreso de la distancia entre el movil y el destino en la consola solo hasta 
que termine el hilo secundario del movil. (e) Para terminar el programa imprime el número de pasos que se requirieron.
*/
//Librerias a utilizar
#include <stdio.h> //Libreria para E/S
#include <pthread.h> //Libreria de hilos posix

//Estructura del movl, inicia en (50,50)
struct movil{
	int coordenadaX_origen, coordenadaY_origen;
};
//Esctructura destino, las coordenadas se piden en el main
struct destino{
	int coordenadaX_destino, coordenadaY_destino;
};

//Declaración de la funcion del hilo secundario, recibe coordenadas X y Y destino 
void *hilo2(struct destino *d);

int main(){
	//Variables que se utilizarán para crear la coordenada destino
	int cx, cy;

	//Se pide al usuario las coordenadas del destino (x,y)
	printf("Coordenada X destino: \n");
	scanf("%d", &cx );
	printf("Coordenada Y destino: \n");
	scanf("%d", &cy);
	//Creación de la estructura destino
	struct destino d = {cx,cy};

	//Creación Hilo secundario
	pthread_t hilo_secundario;
	pthread_create(&hilo_secundario, NULL, (void*)hilo2, &d);

	

	//Finalización de hilo
	pthread_join(hilo_secundario, NULL); 

	return 0;

}


void *hilo2(struct destino *d){
	int pasos = 0; 
	struct movil m = {50,50};
	
	//Bucle para buscar coordenadas
	while((d->coordenadaX_destino != m.coordenadaX_origen) && (d->coordenadaY_destino != m.coordenadaY_origen)){
		//Condicion de coordenada X
		if(d->coordenadaX_destino < 50){
			m.coordenadaX_origen -= 1;
			pasos ++;
		}else if(d->coordenadaX_destino > 50){
			m.coordenadaX_origen += 1;
			pasos ++;
		}
		//Condicion de coordenada Y
		if(d->coordenadaY_destino < 50){
			m.coordenadaY_origen -= 1;
			pasos ++;
		}else if(d->coordenadaY_destino > 50){
			m.coordenadaY_origen += 1;
			pasos ++;
		}		
	}



	printf("\n Pasos que se requirieron: %d", pasos);

}