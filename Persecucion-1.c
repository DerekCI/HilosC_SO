#include <stdio.h>
#include <pthread.h>

//Estructura del movl, inicia en (50,50)
struct movil{
	int coordenadaX_origen, coordenadaY_origen;
	coordenadaX_origen = 50;
	coordenadaY_origen = 50;
};
struct destino{
	int coordenadaX_destino, coordenadaY_destino;
}

//Declaración de la funcion del hilo secundario, recibe coordenadas X y Y destino 
void *hilo2(struct movil *destino);

int main(){
	
	int cx, cy;

	//Se pide al usuario las coordenadas del destino (x,y)
	printf("Coordenada X destino: \n");
	scanf("%d", &cx );
	printf("Coordenada Y destino: \n");
	scanf("%d", &cy);
	//Creación de la estructura destino
	struct destino = {cx,cy};

	//Creación Hilo secundario
	pthread_t hilo_secundario;
	phread_create(&hilo_secundario, NULL, (void*)hilo2, NULL);

	

	//FInalización de hilo
	pthread_join(hilo_secundario, NULL); 

	return 0;

}

void *hilo1(){

}

void *hilo2(struct movil *destino){
	int pasos = 0; 
	struct movil = {50,50}
	
	//Bucle para buscar coordenadas
	while((destino.coordenadaX_destino == movil.coordenadaX_origen) && (destino.coordenadaY_destino != destino.coordenadaY_destino)){
		//Condicion de coordenada X
		if (destino.coordenadaX_destino < 50){
			movil.coordenadaX_origen -= 1;
			pasos ++;
		}else{
			movil.coordenadaX_origen += 1;
			pasos ++;
		}
		//Condicion de coordenada Y
		if(destino.coordenadaY_destino < 50){
			movil.coordenadaY_origen -= 1;
			pasos++;
		}else{
			movil.coordenadaY_origen += 1;
			pasos++;
		}		
	}

}