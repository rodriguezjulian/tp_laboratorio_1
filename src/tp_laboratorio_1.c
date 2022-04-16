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
#include "FuncionesParaTP1-LAB1.h"


int main(void)
{

	setbuf(stdout,NULL);
	int opcion;
	int respuesta;
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	float precioAerolineasdDebito;
	float precioLatamDebito;
	float precioAerolineasdCredito;
	float precioLatamCredito;
	float precioAerolineasBitcoin;
	float precioLatamBitcoin;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	float diferenciaPrecios;
	float valorBitcoin;
	int flag;
	int calcularCostosAuxiliar;//PARA AVISAR SI SALIO BIEN O MAL, ES DECIR SI SE CALCULO O NO

	//-----------------------------------------------------------------------

	valorBitcoin= 4606954.55;
	//DEFINO VALORES PARA LUEGO VALIDAR LA ENTRADA A LA OPCION 3
	kilometros=0;
	precioAerolineas=0;
	precioLatam=0;
	flag=0;
	//------------------------------------------------------------------------


	//float precioAerolineasDebito;

		do{

			respuesta=0;//POR SI OPERO UNA OPCION ANTES DE SALIR, QUE NO VUELVA A ITERAR AL ELEGIR LA OPCION 6

			GetInt("MARQUE 1, para ingresar kilometros \n"
						"MARQUE 2, para ingresar precio de los vuelos \n"
						"MARQUE 3, para calcular los costos con los distintos medios de pago\n"
						"MARQUE 4 para informar resultados\n"
						"MARQUE 5, para realizar una carga forzada de datos\n"
						"MARQUE 6, para salir \n"
						,3,1,6,"ERROR, ingrese un numero valido \n", &opcion);

			switch(opcion)
			{
			 case 1:

				 GetFloat("Ingrese kilometros a recorrer \n",3,1,15000,"ERROR, Ingrese un numero valido\n", &kilometros);
				 	flag=0;//SI EL USUARIO QUISIESE REINGRESAR
			 break;
			 case 2:
				 GetFloatSinMax("Ingrese precio del vuelo vijando con Aerolineas \n",3,1,"ERROR, Ingrese un precio valido\n",&precioAerolineas);
				 GetFloatSinMax("Ingrese precio del vuelo vijando con LATAM \n",3,1,"ERROR, Ingrese un precio valido\n",&precioLatam);
				 flag=0;
			 break;
			 case 3:
				 // PARA REDUCIR EL CODIGO DEL MAIN, ME AYUDE DE LA FUNCION CalcularPorcentaje.
				 calcularCostosAuxiliar= CalcularCostos(kilometros,valorBitcoin, precioAerolineas, precioLatam, &precioAerolineasdDebito,&precioLatamDebito, &precioAerolineasdCredito, &precioLatamCredito,&precioAerolineasBitcoin,&precioLatamBitcoin,&precioPorKmAerolineas, &precioPorKmLatam, &diferenciaPrecios, &flag);
				 if(calcularCostosAuxiliar==1)
				 {
					 	Imprimir("Costos calculados correctamente \n");
				 }
				 else
				 {
					 Imprimir("Error, operar opcion 1 y 2 previamente \n");
				 }
			 break;
			 case 4:
				  InformarResultados(kilometros,  precioAerolineas, precioLatam, precioAerolineasdDebito, precioLatamDebito, precioAerolineasdCredito,  precioLatamCredito, precioAerolineasBitcoin, precioLatamBitcoin, precioPorKmAerolineas, precioPorKmLatam, diferenciaPrecios, flag);

			 break;
			 case 5:
				 kilometros=7090;
				 precioAerolineas=162965;
				 precioLatam=159339;
				 CalcularCostos(kilometros,valorBitcoin, precioAerolineas, precioLatam, &precioAerolineasdDebito,&precioLatamDebito, &precioAerolineasdCredito, &precioLatamCredito,&precioAerolineasBitcoin,&precioLatamBitcoin,&precioPorKmAerolineas, &precioPorKmLatam, &diferenciaPrecios, &flag);
				 InformarResultados(kilometros,  precioAerolineas, precioLatam, precioAerolineasdDebito, precioLatamDebito, precioAerolineasdCredito,  precioLatamCredito, precioAerolineasBitcoin, precioLatamBitcoin, precioPorKmAerolineas, precioPorKmLatam, diferenciaPrecios, flag);
				 flag=0;
			 break;
			}
			if(opcion!=6)
				{

					Imprimir("Para continuar operando presione el numero 8 \n ");
					scanf("%d",&respuesta);
				}


		}while(respuesta==8);

		Imprimir("Fin del programa");

	return EXIT_SUCCESS;
}






