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


float sumar (float  num1, float num2)
	{
		float rtn;
		rtn= num1 + num2;

		return rtn;
	}
float restar (float  num1, float num2)
	{
		float rtn;
		rtn= num1 - num2;

		return rtn;
	}
float multiplicar (float  num1, float num2)
	{
		float rtn;
		rtn= num1 * num2;

		return rtn;
	}
// NO SE PUEDE DIVIDIR POR CERO, EN ESE CASO RETORNAR CERO.
float dividir (float  num1, float num2)
	{
		float rtn;
		if(rtn!=0)
		{
			rtn= num1 / num2;
		}
		else
		{
			rtn=0;
		}

		return rtn;
	}
int deseaContinuar (int num1)
	{
		int rtn;
		printf("%d");
		scanf("%d",&rtn);

		return rtn;
	}
float SumaryPromediar  (float num1, float num2, float promedio)
{
		int rtn;
		rtn=(num1+num2)/promedio;
		printf("%f");
		return rtn;
}
int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroingresado)
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


int getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado)
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
int getFloatSinMax(char mensaje[], int reintentos, int min, char mensajeError[], float *pNumeroingresado)
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



float CalcularPorcentajes(float precio,float porcentaje,int cien, float *pPrecioFinal, int reintentos)
	{
	float precioAuxiliar;
	//float precioMas;
	int retorno;
	retorno=-1;
		do
		{
			reintentos--;

			if(precio>0 && cien==100 && reintentos>0)
			{
				precioAuxiliar=(porcentaje*precio/cien)+precio;
				retorno=0;
			}

		}while(reintentos>0);

		*pPrecioFinal=precioAuxiliar;
		return retorno;
	}
/*char mostrarFloat(char mensaje[],float num1)
	{
		return printf("%.2f", num1);

	}*/
//DECLARAR FUNCION
void imprimir(char mensaje [], float num1)
	{
		printf("%s",num1);
	}




















