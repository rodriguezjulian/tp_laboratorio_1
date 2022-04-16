/*
 * FuncionesParaTP1-LAB1.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Julian Rodriguez
 */


#include "FuncionesParaTP1-LAB1.h"
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
