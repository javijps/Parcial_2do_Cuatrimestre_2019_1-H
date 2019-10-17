/*
 * informes.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include "informes.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_EMPTY -1
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1
#define STATUS_NOT_EMPTY 0

//en la funcion que llama a todas, el array de auxiliar de cliente puede manejarse internamente para no llamarlo en la definicion de la funcion.
//ORDENAR ARRAY LO TENGO EN CLASE CLASE MD CLASE 5
//EL MAXIMO ES DE KILAJE TOTAL ENTRE TODOS LOS PEDIDOS. SI SE PIDE MAXIMO DE A 1 PEDIDO, NO USAR EL ACUMULADOR, HACER DIRECTAMENTE CON KG TOTALES
//PROMEDIO DE KG POR PEDIDO.ESTA EL ACUMULADOR Y EL CONTADOR, HACER CUENTA
//ESTA LA FUNCION PARA IMPRIMIR INFO DE CLIENTE + INFO DE CLIENTE AUXILIAR. SI SE SUMA DE PEDIDO, USAR BUSCARPEDIDOPORID E INDEXAR.
//LISTAR LOS CLIENTES CON MAS DE 50KG TOTALES X PEDIDO  DE RESIDUOS A RECOGER
//   **RECORRO LOS PEDIDOS,SI UN PEDIDO SUPERA LOS 50KG,IMPRIMO ESE CLIENTE O LA INFO QUE SE PIDE
//LISTAR LOS CLIENTES POR LOCALIDAD.
//   **
//LISTAR LOS PEDIDOS CON MAS DE 10KG DEL 1ER RESIDUO, MAS DE 5KG DEL 2DO Y MAS DE 3KG DEL 3RO.
//   IDEM LISTAR CLIENTES CON MAS DE 50KG... PERO SUMO HAGO 3 IF, UNO X CADA CONDICION POR TIPO Y PESO Q PONE
//LISTAR EL CLIENTE CON EL PEDIDO DE MAS KG TOTALES.IMPRIMIR SU CUIT, NOMBRE DE LA EMPRESA Y DIRECCION.
//     ** ES UN MAXIMO Y LISTAR MIXTO DE ESTRUCTURAS.

/**
* \brief ITERA ENTRE ARRAY DE CLIENTES Y ARRAY DE PEDIDOS, MACHEA AMBOS POR EL ID,
*  CADA VEZ QUE MACHEA(ENCUENTRA UN PEDIDO CON EL ID DE CLIENTE INDICADO, EL CONTADOR DE LA ESTRUCTURA AUXILIAR AUMENTA
*
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param lenAcliente tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param lenApedido tamaño del array de pedidos.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la auxiliar cliente.
* \param lenaAuxCLiente tamaño del array de auxiliar cliente.
* \return Si tuvo exito al  xxxxxxxxxxxxxxxxx devuelve [0] o si fallo [-1]
*/
int informes_contarPedidosPorCLiente(sCliente *aCliente,
                            int lenAcliente,
							sPedidoCliente *aPedido,
							int lenApedido,
							sAuxiliarCliente *aAuxCLiente,
							int lenaAuxCLiente)
{
	int retorno = -1;
	int i;
	int j;

	if(aCliente!=NULL && aPedido!=NULL && aAuxCLiente!=NULL && lenAcliente>0 && lenApedido>0 && lenaAuxCLiente>0)
	{
		auxiliarCliente_initClienteAuxiliar(aAuxCLiente,lenaAuxCLiente);
		for(i=0;i<lenAcliente;i++)
		{
			aAuxCLiente[i].idCliente = aCliente[i].idCliente;
			for(j=0;j<lenApedido;j++)
			{
				if(aCliente[i].idCliente == aPedido[j].idCliente)
				{
					aAuxCLiente[i].status = STATUS_NOT_EMPTY;
					aAuxCLiente[i].contadorPedidos++;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/**
* \brief LO MISMO QUE LA ANTERIOR, PERO EN LUGAR DE CONTAR, ACUMULA
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param lenAcliente tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param lenApedido tamaño del array de pedidos.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la auxiliar cliente.
* \param lenaAuxCLiente tamaño del array de auxiliar cliente.
* \return Si tuvo exito al  xxxxxxxxxxxxxxxxx devuelve [0] o si fallo [-1]
*/
int informes_acumularKgTotalesPorCliente(sCliente *aCliente,
                                int lenAcliente,
								sPedidoCliente *aPedido,
								int lenApedido,
								sAuxiliarCliente *aAuxCLiente,
								int lenaAuxCLiente)
{
	int retorno = -1;
	int i;
	int j;

	if(aCliente!=NULL && aPedido!=NULL && aAuxCLiente!=NULL && lenAcliente>0 && lenApedido>0 && lenaAuxCLiente>0)
	{
		auxiliarCliente_initClienteAuxiliar(aAuxCLiente,lenaAuxCLiente);
		for(i=0;i<lenAcliente;i++)
		{
			aAuxCLiente[i].idCliente = aCliente[i].idCliente;
			for(j=0;j<lenApedido;j++)
			{
				if(aCliente[i].idCliente == aPedido[j].idCliente)
				{
					aAuxCLiente[i].status = STATUS_NOT_EMPTY;
					aAuxCLiente[i].acumuladorPedidos+=aPedido[j].kgTotalesArecolectar;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/**
* \brief LISTA INFO CRUZADA ENTRE 2 TIPOS DE ESTRUCTURA, SI PIDE 3ER ESTRCTURA, BUSCO POR ID Y AGREGO UN 3ER FOR, LUEGO PRINT
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param lenAcliente tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param lenApedido tamaño del array de pedidos.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la auxiliar cliente.
* \param lenaAuxCLiente tamaño del array de auxiliar cliente.
* \return Si tuvo exito al  xxxxxxxxxxxxxxxxx devuelve [0] o si fallo [-1]
*/
int informes_listarInfoClientesConInfoAuxPorId(sCliente *aCliente,
		                         int lenAcliente,
								 sPedidoCliente *aPedido,
								 int lenApedido,
								 sAuxiliarCliente *aAuxCLiente,
								 int lenaAuxCLiente,
								 int idCliente)
{
	int retorno = -1;
	int indexCliente;
	int indexClienteAuxiliar;


	if(aCliente!=NULL && aPedido!=NULL && aAuxCLiente!=NULL && lenAcliente>0 && lenApedido>0 && lenaAuxCLiente>0)
	{
		indexCliente = cliente_buscarClientePorId(aCliente,lenAcliente,idCliente);
		indexClienteAuxiliar = auxiliarCliente_buscarClienteAuxiliarPorId(aAuxCLiente,lenaAuxCLiente,idCliente);
		if(aCliente[indexCliente].idCliente == aAuxCLiente[indexClienteAuxiliar].idCliente)
		{
			printf("\n-Id Cliente: %d\n"
					"-Nombre de la empresa: %s\n"
			//		"-Cantidad de pedidos: %d\n"
					"-Kg Totales en pedidos: %.2f\n"
					"\n"
					"\n",
					aCliente[indexCliente].idCliente,
					aCliente[indexCliente].empresa,
					//aAuxCLiente[indexClienteAuxiliar].contadorPedidos,
					aAuxCLiente[indexClienteAuxiliar].acumuladorPedidos);
		}
	}
	return retorno;
}

/**
* \brief CALCULA LA ACUMULACION LLAMANDO A LA FUNCION ANTERIOR Y DESPUES BUSCA EL MAXIMO, NO TIENE EN CASO DE Q SEAN 2, PERO PUEDE DEFINIRSE
* UN ID CLIENTE MAXIMO 2/ MAXIMO 2.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param lenAcliente tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param lenApedido tamaño del array de pedidos.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la auxiliar cliente.
* \param lenaAuxCLiente tamaño del array de auxiliar cliente.
* \return Si tuvo exito al  xxxxxxxxxxxxxxxxx devuelve [0] o si fallo [-1]
*/
int informes_maximoKgTotalesPorCliente(sCliente *aCliente,
                              int lenAcliente,
							  sPedidoCliente *aPedido,
							  int lenApedido,
							  sAuxiliarCliente *aAuxCLiente,
							  int lenaAuxCLiente)
{
	int retorno = -1;
	int i;
	int flagMaximo;
	int maximoKilosArecolectar;
	int idMaximoKgArecolectar;

	if(aCliente!=NULL && aPedido!=NULL && aAuxCLiente!=NULL && lenAcliente>0 && lenApedido>0 && lenaAuxCLiente>0)
	{
		auxiliarCliente_initClienteAuxiliar(aAuxCLiente,lenaAuxCLiente);
		informes_acumularKgTotalesPorCliente(aCliente,lenAcliente,aPedido,lenApedido,aAuxCLiente,lenaAuxCLiente);
		for(i=0;i<lenApedido;i++)
		{
			if(flagMaximo==0||aAuxCLiente[i].acumuladorPedidos>maximoKilosArecolectar)
			{
				retorno = 0;
				maximoKilosArecolectar = aAuxCLiente[i].acumuladorPedidos;
				idMaximoKgArecolectar = aAuxCLiente[i].idCliente;
				flagMaximo=1;
			}
		}
		printf("ID de cliente con maxima cantidad de kg totales entre todos sus pedidos: %d\n",idMaximoKgArecolectar);
		informes_listarInfoClientesConInfoAuxPorId(aCliente,lenAcliente,aPedido,lenApedido,aAuxCLiente,lenaAuxCLiente,idMaximoKgArecolectar);
	}
	return retorno;
}

/**
* \brief Accede al Sub-Menu informes mediante el ingreso de opciones de menu.
* \return Si tuvo exito al acceder devuelve [0] o si fallo [-1]
*/
void informes_subMenu(void)
{
	char option;

	do
	{
		if(getChar(&option,"\n---SubMenu Informes---\n"
				"Ingrese:\n"
				"a-\n"
				"b-\n"
				"c-\n"
				"d-\n"
				"e-\n"
				"f-\n"
				"g-\n"
				"h-\n"
				"i-EXIT\n",
				"Error, opcion incorrecta!\n",'a','i',2)!=0)
			{
			printf("No fue posible acceder al Sub-Menu de opciones");
			break;
			}
		else
		{
			switch(option)
			{
			case 'a':
				printf("ok\n");
				break;
			case 'b':
				printf("ok b\n");
				break;
			}
		}
	}while(option!='i');
}
