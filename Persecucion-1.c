#include <stdio.h>
#include <pthread.h>

//Estructura del movl, inicia en (50,50)
struct movil{
	int coordenadaX_origen, coordenadaY_origen;
};
//Esctructura destino, las coordenadas se piden en el main
struct destino{
	int coordenadaX_destino, coordenadaY_destino;
};

//Declaración de la funcion del hilo secundario, recibe coordenadas X y Y destino 
void *hilo2(struct movil *destino);

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
	pthread_create(&hilo_secundario, NULL, (void*)hilo2, NULL);

	

	//Finalización de hilo
	pthread_join(hilo_secundario, NULL); 

	return 0;

}


void *hilo2(struct movil *destino){
	int pasos = 0; 
	struct movil m = {50,50}
	
	//Bucle para buscar coordenadas
	while((destino.coordenadaX_destino != m.coordenadaX_origen) && (destino.coordenadaY_destino != m.coordenadaY_origen)){
		//Condicion de coordenada X
		if (destino->coordenadaX_destino < 50){
			m.coordenadaX_origen -= 1;
			pasos ++;
		}else{
			m.coordenadaX_origen += 1;
			pasos ++;
		}
		//Condicion de coordenada Y
		if(destino->coordenadaY_destino < 50){
			m.coordenadaY_origen -= 1;
			pasos++;
		}else{
			m.coordenadaY_origen += 1;
			pasos++;
		}		
	}
	printf("\n Pasos que se requirieron: %d", pasos);

}