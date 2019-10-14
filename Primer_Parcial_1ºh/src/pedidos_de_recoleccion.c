/*
 * pedidos_de_recoleccion.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include "pedidos_de_recoleccion.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define STATUS_EMPTY -1
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1



/**
* \brief Imprime la informacion correspondiente a pedidos
* \param sPedidoCliente *aPedidos puntero a una array de estructuras pedidos.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int imprimirPedidosActivos(sPedidoCliente *aPedido, int len)
{
	int i;
	int retorno = -1;
	if(aPedido != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido==STATUS_EMPTY)
				continue;
			printf("\nId Pedido: %d\n"
					"Id Cliente: %d\n"
					" - Status Pedido: %d\n"
					" - Kilos totales a recolectar: %d\n"
					" - kg HDPE: %d\n"
					" - kg LDPE: %d\n"
					" - kg PP: %d\n",
					aPedido[i].id_pedido,
					aPedido[i].idCliente,
					aPedido[i].statusPedido,
					aPedido[i].kgTotalesArecolectar,
					aPedido[i].kgHDPE,
					aPedido[i].kgLDPE,
					aPedido[i].kgPP);

		}
	}
	return retorno;
}

/**
* \brief Imprime la informacion correspondiente a pedidos con status pendiente
* \param sPedidoCliente *aPedidos puntero a una array de estructuras pedidos.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int imprimirPedidosPendientes(sPedidoCliente *aPedido, int len)
{
	int i;
	int retorno = -1;
	if(aPedido != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido!=STATUS_PENDIENTE)
				continue;
			printf("Id Pedido: %d\n"
					"Id Cliente: %d\n"
					" - Status Pedido: %d\n"
					" - Kilos totales a recolectar: %d\n"
					" - kg HDPE: %d\n"
					" - kg LDPE: %d\n"
					" - kg PP: %d\n",
					aPedido[i].id_pedido,
					aPedido[i].idCliente,
					aPedido[i].statusPedido,
					aPedido[i].kgTotalesArecolectar,
					aPedido[i].kgHDPE,
					aPedido[i].kgLDPE,
					aPedido[i].kgPP);
		}
	}
	return retorno;
}

/**
* \brief Imprime la informacion correspondiente a un cliente.
* \param sCliente aCliente ?? de estructuras cliente.
*/
void imprimirUnPedido(sPedidoCliente aPedido)
{
	printf("\nId Pedido: %d\n"
			"Id Cliente: %d\n"
			" - Status Pedido: %d\n"
			" - Kilos totales a recolectar: %d\n"
			" - kg HDPE: %d\n"
			" - kg LDPE: %d\n"
			" - kg PP: %d\n",
			aPedido.id_pedido,
			aPedido.idCliente,
			aPedido.statusPedido,
			aPedido.kgTotalesArecolectar,
			aPedido.kgHDPE,
			aPedido.kgLDPE,
			aPedido.kgPP);

}

/**
* \brief Genera el ID correspondiente a una pedido.
* \return Devuelve el ID correspondiente.
*/
static int generarIdpedido(void){
	static int id = 0;
	id++;
	return id;
}

/**
* \brief Inicializa los pedidos con STATUS_EMPTY.
* \param sPedidoCliente *apedidos puntero a una xxxxx de la estructura pedidos.
* \param cantidad Cantidad de pedidos a inicializar
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int initPedido(sPedidoCliente *aPedido, int cantidad)
{

	int i;
	int retorno = -1;

	if(aPedido != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			aPedido[i].statusPedido = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Solicita los datos correspondientes a una pedido.
* \param sPedidoCliente *apedido puntero a una xxxxx de la estructura pedido.
* \param cantidad Cantidad de pedido.
* \return Si tuvo exito al completar todos los campos devuelve [0] o si fallo [-1]
*/
int getDatosPedido(sPedidoCliente *aPedido,int cantidad,int idCliente)
{

	int retorno = -1;
	sPedidoCliente bPedidoCliente;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(getInt(&bPedidoCliente.kgTotalesArecolectar,
				"Ingrese la cantidada de kg totales a recolectar\n",
				"Id incorrecto!\n",
				1,
				1000
				,3)!=0)
				break;
		aPedido[i].idCliente = idCliente;
		aPedido[i].kgTotalesArecolectar = bPedidoCliente.kgTotalesArecolectar;
		aPedido[i].statusPedido = STATUS_PENDIENTE;
		aPedido[i].id_pedido = generarIdpedido();
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Busca una pedido sin datos cargados.
* \param sPedidoCliente *acliente puntero a una xxxxx de la estructura pedido.
* \param cantidad Cantidad de pedido.
* \return Si tuvo exito al encontrar un pedido vacio devuelve [0] o si fallo [-1]
*/
int buscarPedidoLibre(sPedidoCliente *aPedido,int cantidad)
{
	int retorno = -1;
	int i;

	if(aPedido != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPedido[i].statusPedido==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}

/**
* \brief Realiza el alta de una nueva pedido.
* \param sPedidoCliente *aPedido puntero a un array de estructuras pedido.
* \param cantidad Cantidad de altas a realizar.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int altaPedido(sPedidoCliente *aPedido, int cantidad,int idCliente)
{

	int retorno = -1;
	int index=0;

	if(aPedido != NULL && cantidad>0)
	{
		index = buscarPedidoLibre(aPedido,cantidad);
		if(index!=-1)
		{
			if(getDatosPedido(aPedido,cantidad,idCliente)==0)
				retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Busca una pedido en estado pendiente existente por medio de su ID.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param cantidad Cantidad de pedidos.
* \param id ID de pedido a ser encontrado.
* \return Si tuvo exito al encontrar el pedido indicada devuelve [0] o si fallo [-1]
*/
int buscarPedidoPorId(sPedidoCliente *aPedido,int cantidad, int id)
{
	int retorno = -1;
	int i;

	if(aPedido!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPedido[i].id_pedido == id && aPedido[i].statusPedido == STATUS_PENDIENTE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief Busca una pedido en estado pendiente existente por medio de su ID.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param cantidad Cantidad de pedidos.
* \param id ID de pedido a ser encontrado.
* \return Si tuvo exito al encontrar el pedido indicada devuelve [0] o si fallo [-1]
*/
int buscarPedidoPendientePorIdCliente(sPedidoCliente *aPedido,int cantidad, int idCliente)//corregir doc
{
	int retorno = -1;
	int i;

	if(aPedido!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPedido[i].idCliente == idCliente && aPedido[i].statusPedido == STATUS_PENDIENTE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief procesa el pedido de recolleccion de residuos para pasar de pendiente a completado
* \param sPedidoCliente *aPedido puntero a un array de estructuras pedido.
* \param cantidad Cantidad de altas a realizar.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int procesarResiduos(sPedidoCliente *aPedido, int cantidad,int idPedido)
{
	int retorno = -1;
	sPedidoCliente bPedido;
	int index;
	int opcion;
	int sumaKilaje;

	if(aPedido!=NULL && cantidad>0)
	{
		index = buscarPedidoPorId(aPedido,cantidad,idPedido);

		if(index!=-1)
		{
			do
			{
				if(getInt(&opcion,"\nIngrese: \n1-Cargar kg  del residuo HDPE.\n"
						"2-Cargar kg  del residuo LDPE.\n"
						"3-Cargar kg  del residuo kgPP.\n \n"
						"4-EXIT\n",
						"Error, opcion incorrecta\n",
						1,4,2)==0)
				{
					switch(opcion)
					{
					case 1:
						if(getInt(&bPedido.kgHDPE,"Ingresar kg  del residuo HDPE\n",
								"kilaje incorrecto, maximo 1000kg\n",
								1,1000,2)==0)
						{
							sumaKilaje = bPedido.kgHDPE;
							if(sumaKilaje>aPedido[index].kgTotalesArecolectar)
							{
								printf("El total de los kg a procesar supera el total de kg del pedido!\n");
								retorno = -1;
								opcion=4;

							}
							else
							{
								aPedido[index].kgHDPE = bPedido.kgHDPE;
								retorno = 0;
							}
						}
						break;
					case 2:
						if(getInt(&bPedido.kgLDPE,"Ingresar kg  del residuo kgLDPE\n",
								"kilaje incorrecto, maximo 1000kg\n",
								1,1000,2)==0)
						{
							sumaKilaje = aPedido[index].kgHDPE + bPedido.kgLDPE;
							if(sumaKilaje>aPedido[index].kgTotalesArecolectar)
							{
								printf("El total de los kg a procesar supera el total de kg del pedido!\n");
								retorno = -1;
								opcion=4;
							}
							else
							{
								aPedido[index].kgLDPE = bPedido.kgLDPE;
								retorno = 0;
							}
						}
						break;
					case 3:
						if(getInt(&bPedido.kgPP,"Ingresar kg  del residuo kgPP\n",
								"kilaje incorrecto, maximo 1000kg\n",
								1,1000,2)==0)
						{
							sumaKilaje = aPedido[index].kgHDPE + aPedido[index].kgLDPE + bPedido.kgPP;
							if(sumaKilaje>aPedido[index].kgTotalesArecolectar)
							{
								printf("El total de los kg a procesar supera el total de kg del pedido!\n");
								retorno = -1;
								//opcion=4;
							}
							else
							{
								aPedido[index].kgPP = bPedido.kgPP;
								retorno = 0;
							}
						}
						break;
					}
				}
			}while(opcion!= 4);
		}
		imprimirUnPedido(aPedido[index]);
	}
	return retorno;
}


/**
* \brief Carga los datos definidos en un array de Estructura del tipo cliente.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array
*/
void pedidoDeClienteForzado(sPedidoCliente *aPedidoCLiente,int len)
{

	int aId_pedido[5] = {1,2,3,4,5};
	int aStatusPedido[5] = {0,0,1,1,1};
	int aIdCliente[5] = {1,1,2,2,5};
	int akgTotalesArecolectar[5] = {45,71,25,71,171};//todos tiene 10kg a recolectar demas q la suma de los 3 tipos de residuos
	int akgHDPE[5] = {20,32,10,15,65};
	int akgLDPE[5] = {10,22,2,5,55};
	int akgPP[5] = {5,17,7,3,41};

	int i;

	for(i=0;i<len;i++)
	{
		aPedidoCLiente[i].id_pedido = aId_pedido[i];
		aPedidoCLiente[i].statusPedido = aStatusPedido[i];
		aPedidoCLiente[i].idCliente = aIdCliente[i];
		aPedidoCLiente[i].kgTotalesArecolectar = akgTotalesArecolectar[i];
		aPedidoCLiente[i].kgHDPE = akgHDPE[i];
		aPedidoCLiente[i].kgLDPE = akgLDPE[i];
		aPedidoCLiente[i].kgPP = akgPP[i];
	}
}


/**
* \brief Busca una pedido en estado pendiente existente por medio de su ID.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param cantidad Cantidad de pedidos.
* \param id ID de pedido a ser encontrado.
* \return Si tuvo exito al encontrar el pedido indicada devuelve [0] o si fallo [-1]
*/
int buscarPedidoPorIdCLiente(sPedidoCliente *aPedido,int cantidad, int bIdCliente)//modificar doc
{
	int retorno = -1;
	int i;

	if(aPedido!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPedido[i].idCliente == bIdCliente && aPedido[i].statusPedido == STATUS_PENDIENTE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
