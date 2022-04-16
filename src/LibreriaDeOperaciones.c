/*
 * LibreriaDeOperaciones.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Julian Rodriguez
 *
 *		ACA VAN SOLAMENTE LOS DESARROLLOS DE LAS FUNCIONES QUE ESTAN COMO PROTOTIPO EN EL PUNTO H
 *		Y LA LLAMADA AL INCLUDE A LA BIBLIOTECA .H
 *
 *
 */

#include "LibreriaDeOperaciones.h"


float Sumar (float  num1, float num2)
	{
		float rtn;
		rtn= num1 + num2;

		return rtn;
	}
float Restar (float  num1, float num2)
	{
		float rtn;
		rtn= num1 - num2;

		return rtn;
	}
float Multiplicar (float  num1, float num2)
	{
		float rtn;
		rtn= num1 * num2;

		return rtn;
	}
// NO SE PUEDE DIVIDIR POR CERO, EN ESE CASO RETORNAR CERO.
float Dividir (float  num1, float num2)
	{
		float rtn;
		if(num2!=0)
		{
			rtn= num1 / num2;
		}
		else
		{
			rtn=0;
		}

		return rtn;
	}

float SumaryPromediar  (float num1, float num2, float promedio)
{
		int rtn;
		rtn=(num1+num2)/promedio;
		printf("%f");
		return rtn;
}
int GetInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroingresado)
{
	int rtn = 0;
	int auxiliarInt; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroingresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%d", &auxiliarInt);//si el retorno esta bien da 1
		do
		{
			//printf("Te quedan %d reintentos \n", reintentos);
			if (retornoScanf !=1 || auxiliarInt > maximo || auxiliarInt < minimo)
			{
				printf("\n%s", mensajeError);
				retornoScanf = scanf("%d", &auxiliarInt);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroingresado = auxiliarInt;
				rtn = 1;
			}

		}
		while(reintentos>0);
	}
	return rtn;
}


int GetFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado)
{
	int rtn = 0;
	float auxiliarFloat; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroingresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);
		do
		{
			if (retornoScanf !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				printf("\n%s", mensajeError);
				retornoScanf = scanf("%f", &auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroingresado = auxiliarFloat;
				rtn = 1;
			}
		}
		while(reintentos>0);
	}
	return rtn;
}
int GetFloatSinMax(char mensaje[], int reintentos, int min, char mensajeError[], float *pNumeroingresado)
{
	int rtn = 0;
	float auxiliarFloat; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL &&  min>0 && mensajeError != NULL && pNumeroingresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);
		do
		{
			if (retornoScanf !=1 || auxiliarFloat < min)
			{
				printf("\n %s", mensajeError);
				retornoScanf = scanf("%f", &auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroingresado = auxiliarFloat;
				rtn = 1;
			}
		}
		while(reintentos>0);
	}
	return rtn;
}



int CalcularPorcentaje(float precio,float porcentaje, float *pPrecioFinal)
	{
	float precioAuxiliar;
	//float precioMas;
	int retorno;
	retorno=-1;

			if(precio>0)
			{
				precioAuxiliar=(porcentaje*precio/100)+precio;
				retorno=0;
			}

		*pPrecioFinal=precioAuxiliar;
		return retorno;
	}


int CalcularCostos(int kilometros, float valorBitcoin, float precioAerolineas,float precioLatam, float *precioAerolineasdDebito,float *precioLatamDebito,float *precioAerolineasdCredito, float *precioLatamCredito,float *precioAerolineasBitcoin,float *precioLatamBitcoin,float *precioPorKmAerolineas,float *precioPorKmLatam,float *diferenciaPrecios, int *bandera)
	{
		int rtn;
		rtn=0;

		if(kilometros!=0 && valorBitcoin!=0 && precioAerolineas!=0 && precioLatam!=0)
		{
		CalcularPorcentaje(precioAerolineas,-10,precioAerolineasdDebito);
		CalcularPorcentaje(precioLatam,-10,precioLatamDebito);

		CalcularPorcentaje(precioAerolineas,25,precioAerolineasdCredito);
		CalcularPorcentaje(precioLatam,25,precioLatamCredito);

		*precioAerolineasBitcoin=Dividir(precioAerolineas,valorBitcoin);
		*precioLatamBitcoin=Dividir(precioLatam,valorBitcoin);

		*precioPorKmAerolineas=precioAerolineas/ kilometros;
		*precioPorKmLatam=precioLatam/ kilometros;

		*diferenciaPrecios=precioAerolineas-precioLatam;

		//printf("Costos calculados correctamente \n");
		*bandera=1;
		rtn=1;
		}
		else
		{
			//printf("ERROR, operar opcion 1 y 2 previamente \n");
			*bandera=0;
			rtn=0;
		}
		return rtn;
	}

void InformarResultados(int kilometros, float precioAerolineas,float precioLatam, float precioAerolineasdDebito,float precioLatamDebito,float precioAerolineasdCredito, float precioLatamCredito,float precioAerolineasBitcoin,float precioLatamBitcoin,float precioPorKmAerolineas,float precioPorKmLatam,float diferenciaPrecios, int flag)
	{
		if(flag==1)
		{
			printf("KMs Ingresados: %d km \n\n", kilometros);

			printf("Precio Aerolineas: $%.2f \n", precioAerolineas);
			printf("a)Precio con tarjeta de debito: $ %.2f \n",precioAerolineasdDebito);
			printf("b)Precio con tarjeta de credito: $ %.2f \n",precioAerolineasdCredito);
			printf("c)Precio pagando con bitcoin: %.2f BTC\n",precioAerolineasBitcoin);
			printf("d)Mostrar precio unitario: $ %.2f \n\n",precioPorKmAerolineas );

			printf("Precio Aerolineas: $%.2f \n", precioLatam);
			printf("a)Precio con tarjeta de debito: $ %.2f \n",precioLatamDebito);
			printf("b)Precio con tarjeta de credito: $ %.2f \n",precioLatamCredito);
			printf("c)Precio pagando con bitcoin: %.2f BTC\n",precioLatamBitcoin);
			printf("d)Mostrar precio unitario: $ %.2f \n\n",precioPorKmLatam );

			printf("La diferencia de precio es: %.2f \n",diferenciaPrecios);

		}
		else
		{
			Imprimir("ERROR, operar opcion 3 previamente \n");
		}
	}


void Imprimir(char mensaje[])
	{
		printf("%s", mensaje);
	}

































