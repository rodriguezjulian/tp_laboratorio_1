/*
 * FuncionesParaTP1-LAB1.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Julian Rodriguez
 */

#ifndef FUNCIONESPARATP1_LAB1_H_
#define FUNCIONESPARATP1_LAB1_H_
#include <stdio.h>
#include <stdlib.h>
#include "LibreriaDeOperaciones.h"

//ESPECIFICAS DEL TP1
int CalcularCostos(int kilometros, float valorBitcoin, float precioAerolineas,float precioLatam, float *precioAerolineasdDebito,float *precioLatamDebito,float *precioAerolineasdCredito, float *precioLatamCredito,float *precioAerolineasBitcoin,float *precioLatamBitcoin,float *precioPorKmAerolineas,float *precioPorKmLatam,float *diferenciaPrecios, int *bandera);
void InformarResultados(int kilometros, float precioAerolineas,float precioLatam, float precioAerolineasdDebito,float precioLatamDebito,float precioAerolineasdCredito, float precioLatamCredito,float precioAerolineasBitcoin,float precioLatamBitcoin,float precioPorKmAerolineas,float precioPorKmLatam,float diferenciaPrecios, int flag);


#endif /* FUNCIONESPARATP1_LAB1_H_ */
