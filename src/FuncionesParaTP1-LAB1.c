/*
 * FuncionesParaTP1-LAB1.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Julian Rodriguez
 */


#include "FuncionesParaTP1-LAB1.h"

/// @fn int CalcularCostos(int, float, float, float, float*, float*, float*, float*, float*, float*, float*, float*, float*, int*)
/// @brief
///TOMANDO PARAMETROS OBTENIDOS CON ANTERIORIDAD (kilometros, valor BTC, precio Aerolinea y Latam), REALIZA LOS CALCULOS NECESARIOS Y LOS ESCRIBE EN LA
/// VARIABLES A TRAVEZ DEL USO DE PUNTEROS.
/// @pre
/// @post
/// @param kilometros
/// @param valorBitcoin
/// @param precioAerolineas
/// @param precioLatam
/// @param precioAerolineasdDebito
/// @param precioLatamDebito
/// @param precioAerolineasdCredito
/// @param precioLatamCredito
/// @param precioAerolineasBitcoin
/// @param precioLatamBitcoin
/// @param precioPorKmAerolineas
/// @param precioPorKmLatam
/// @param diferenciaPrecios
/// @param bandera
/// @return (SALIO BIEN=1 /SINO 0)
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

		//printf("Costos calculados correctamente \n"); NO PORQUE CUANDO REALICE LA CARGA FORZADA ME APARECERIAN ESTOS MSJS
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
/// @fn void InformarResultados(int, float, float, float, float, float, float, float, float, float, float, float, int)
/// @brief
///SE MUESTRAN RESULTADOS SIEMPRE Y CUANDO EL FLAG ESTE EN 1, COSA QUE SUCEDE UNA VEZ QUE SE EJECUTA CORRECTAMENTE LA FUNCION CalcularCostos, DE LO CONTRARIO
/// NO SE INFORMARA NADA YA QUE PRIMERO SE DEBE OPERAR ESA OPCION
/// @pre
/// @post
/// @param kilometros
/// @param precioAerolineas
/// @param precioLatam
/// @param precioAerolineasdDebito
/// @param precioLatamDebito
/// @param precioAerolineasdCredito
/// @param precioLatamCredito
/// @param precioAerolineasBitcoin
/// @param precioLatamBitcoin
/// @param precioPorKmAerolineas
/// @param precioPorKmLatam
/// @param diferenciaPrecios
/// @param flag
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
