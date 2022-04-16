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
		printf("%f",promedio);
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

void Imprimir(char mensaje[])
	{
		printf("%s", mensaje);
	}

































