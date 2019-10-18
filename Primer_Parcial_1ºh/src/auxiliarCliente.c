/*
 * auxiliarCliente.c
 *
 *  Created on: 16 oct. 2019
 *      Author: javijps
 */

#include "auxiliarCliente.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define STATUS_EMPTY  -1
#define STATUS_NOT_EMPTY 0
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1


/**
* \brief Imprime el campo contadorPedidos de la estructura sAuxiliarCLiente.
* \param sAuxiliarCLiente cliente Auxiliar.
*/
void auxiliarCliente_imprimirContadorAuxCliente(sAuxiliarCliente aAuxCliente)
{
	printf("- Cantidad de pedidos pendientes: %d\n",aAuxCliente.contadorPedidos);
}

/**
* \brief Imprime la informacion correspondiente a un cliente auxiliar.
* \param sAuxiliarCliente aAuxCliente auxiliar cliente
*/
void auxiliarCliente_imprimirUnClienteAux(sAuxiliarCliente aAuxCliente)
{
	printf("\n - Id Cliente: %d\n"
			" - Cantidad pedidos: %d\n"
			" - Cantidad total de kg a recolectar: %.2f\n",
			aAuxCliente.idCliente,
			aAuxCliente.contadorPedidos,
			aAuxCliente.acumuladorPedidos);
}

/**
* \brief Inicializa cliente auxiliar.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la estructura sAuxiliarCliente.
* \param len Tamaño del array
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int auxiliarCliente_initClienteAuxiliar(sAuxiliarCliente *aAuxCLiente,int len)
{

	int i;
	int retorno = -1;

	if(aAuxCLiente != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			aAuxCLiente[i].status = STATUS_EMPTY;
			aAuxCLiente[i].contadorPedidos = 0;
			aAuxCLiente[i].acumuladorPedidos = 0;
		}
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Busca un cliente auxiliar por medio de su ID.
* \param sAuxiliarCliente *aAuxCliente puntero a un array de estructura cliente auxiliar.
* \param len Tamaño del array.
* \param id ID de cliente a ser encontrado.
* \return Si tuvo exito al encontrar el cliente indicado devuelve [0] o si fallo [-1]
*/
int auxiliarCliente_buscarClienteAuxiliarPorId(sAuxiliarCliente *aAuxCliente,int len, int idCliente)//modificar doc
{
	int retorno = -1;
	int i;

	if(aAuxCliente!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aAuxCliente[i].idCliente == idCliente && aAuxCliente[i].status == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

