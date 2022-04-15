/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Julian Manuel Rodriguez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LibreriaDeOperaciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int respuesta=1;
	int kilometros;
	//int retornoOpciones;
	float precioAerolineas;
	float precioLatam;
	//float precioAerolineasDebito;

		do{
				printf("aca 1");
				//retornoOpciones=
			getInt("MARQUE 1, para ingresar kilometros \n"
						"MARQUE 2, para ingresar precio de los vuelos \n"
						"MARQUE 3, para calcular los costos con los distintos medios de pago\n"
						"MARQUE 4 para informar resultados\n"
						"MARQUE 5, para realizar una carga forzada de datos\n"
						"MARQUE 6, para salir \n"
						,3,1,6,"ERROR, ingrese un numero valido \n", &opcion);

				printf("\n\t\t\t Opcion ingresada: %d\n",opcion);

				/*if(retornoOpciones==0){printf("\t\t\tSALIO MAL: %d\n",retornoOpciones);}
				else{printf("SALIO TODO BIEN");}*/
			//printf("aca2");

			switch(opcion)
			{
			 case 1:
		// int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroingresado)
				 	getInt("Ingrese kilometros a recorrer \n",3,1,15000,"ERROR, Ingrese un numero valido\n", &kilometros);
			 break;
			 case 2:
		//			 int getFloatSinMax(char mensaje[], int reintentos, int minimo, char mensajeError[], float *pNumeroingresado)
				 getFloatSinMax("Ingrese precio del vuelo vijando con Aerolineas \n",3,1,"ERROR, Ingrese un precio valido\n",&precioAerolineas);
				 getFloatSinMax("Ingrese precio del vuelo vijando con LATAM \n",3,1,"ERROR, Ingrese un precio valido\n",&precioLatam);
			 break;
			 case 3:

			 break;
			 case 4:
			 break;
			 case 5:
			 break;
			 case 6:
			 break;
			}

			printf("Para continuar operando presione el numero 8\n ");
			scanf("%d \n ", &respuesta);

		}while(respuesta==8);

	//printf("Ingrese kilometros");
	//scanf("%d", &kilometros);
	return EXIT_SUCCESS;
}






