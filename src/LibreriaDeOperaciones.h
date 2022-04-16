/*
 * LibreriaDeOperaciones.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Julian Rodriguez
 *
 *		ACA VAN SOLO LOS INCLUDES DE TODAS LAS BIBLIOTECAS QUE VAYA A USAR
 *		los INCLUDES se ponen entre los #infdef y #endif al igual que los PROTOTIPOS de funciones
 *
 *
 */

#ifndef LIBRERIADEOPERACIONES_H_

#define LIBRERIADEOPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS:
float sumar (float, float);//PROTOTIPO DE FUNCION
float restar (float, float);
float multiplicar (float, float);
float dividir (float, float);
int deseaContinuar (int);
int getInt (char mensaje [], int reintentos,int min, int max, char mensajeError[], int *pnumeroIngresado);
int getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado);
int CalcularPorcentaje(float precio,float porcentaje, float *pPrecioFinal);
int getFloatSinMax(char mensaje[], int reintentos, int min, char mensajeError[], float *pNumeroingresado);
int CalcularCostos(int kilometros, float valorBitcoin, float precioAerolineas,float precioLatam, float *precioAerolineasdDebito,float *precioLatamDebito,float *precioAerolineasdCredito, float *precioLatamCredito,float *precioAerolineasBitcoin,float *precioLatamBitcoin,float *precioPorKmAerolineas,float *precioPorKmLatam,float *diferenciaPrecios, int *bandera);
void Imprimir(char mensaje[]);
void InformarResultados(int kilometros, float precioAerolineas,float precioLatam, float precioAerolineasdDebito,float precioLatamDebito,float precioAerolineasdCredito, float precioLatamCredito,float precioAerolineasBitcoin,float precioLatamBitcoin,float precioPorKmAerolineas,float precioPorKmLatam,float diferenciaPrecios, int flag);


#endif /* LIBRERIADEOPERACIONES_H_ */


