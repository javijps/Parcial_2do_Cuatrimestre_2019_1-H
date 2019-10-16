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
#define STATUS_EMPTY -1
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1



/**
* \brief Imprime la informacion correspondiente a pedidos
* \param sPedidoCliente *aPedidos puntero a una array de estructuras pedidos.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int pedidoCliente_imprimirPedidosActivos(sPedidoCliente *aPedido, int len)
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
					" - Kilos totales a recolectar: %.2f\n"
					" - kg HDPE: %.2f\n"
					" - kg LDPE: %.2f\n"
					" - kg PP: %.2f\n",
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
int pedidoCliente_imprimirPedidosPendientes(sPedidoCliente *aPedido, int len)
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
					" - Kilos totales a recolectar: %.2f\n"
					" - kg HDPE: %.2f\n"
					" - kg LDPE: %.2f\n"
					" - kg PP: %.2f\n",
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
void pedidoCliente_imprimirUnPedido(sPedidoCliente aPedido)
{
	printf("\nId Pedido: %d\n"
			"Id Cliente: %d\n"
			" - Status Pedido: %d\n"
			" - Kilos totales a recolectar: %.2f\n"
			" - kg HDPE: %.2f\n"
			" - kg LDPE: %.2f\n"
			" - kg PP: %.2f\n",
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
static int pedidoCliente_generarIdpedido(void){
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
int pedidoCliente_initPedido(sPedidoCliente *aPedido, int cantidad)
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
int pedidoCliente_getDatosPedido(sPedidoCliente *aPedido,int cantidad,int idCliente)
{

	int retorno = -1;
	sPedidoCliente bPedidoCliente;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(getFloat(&bPedidoCliente.kgTotalesArecolectar,
				"Ingrese la cantidada de kg totales a recolectar\n",
				"Id incorrecto!\n",
				1,
				1000
				,3)!=0)
				break;
		aPedido[i].idCliente = idCliente;
		aPedido[i].kgTotalesArecolectar = bPedidoCliente.kgTotalesArecolectar;
		aPedido[i].statusPedido = STATUS_PENDIENTE;
		aPedido[i].id_pedido = pedidoCliente_generarIdpedido();
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
int pedidoCliente_buscarPedidoLibre(sPedidoCliente *aPedido,int cantidad)
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
int pedidoCliente_altaPedido(sPedidoCliente *aPedido, int cantidad,int idCliente)
{

	int retorno = -1;
	int index=0;

	if(aPedido != NULL && cantidad>0)
	{
		index = pedidoCliente_buscarPedidoLibre(aPedido,cantidad);
		if(index!=-1)
		{
			if(pedidoCliente_getDatosPedido(aPedido,cantidad,idCliente)==0)
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
int pedidoCliente_buscarPedidoPorId(sPedidoCliente *aPedido,int cantidad, int id)
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
int pedidoCliente_buscarPedidoPendientePorIdCliente(sPedidoCliente *aPedido,int cantidad, int idCliente)//corregir doc
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
int pedidoCliente_procesarResiduos(sPedidoCliente *aPedido, int cantidad,int idPedido)
{
	int retorno = -1;
	sPedidoCliente bPedido;
	int index;
	int opcion;
	int sumaKilaje;

	if(aPedido!=NULL && cantidad>0)
	{
		index = pedidoCliente_buscarPedidoPorId(aPedido,cantidad,idPedido);

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
						if(getFloat(&bPedido.kgHDPE,"Ingresar kg  del residuo HDPE\n",
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
						if(getFloat(&bPedido.kgLDPE,"Ingresar kg  del residuo kgLDPE\n",
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
						if(getFloat(&bPedido.kgPP,"Ingresar kg  del residuo kgPP\n",
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
		pedidoCliente_imprimirUnPedido(aPedido[index]);
	}
	return retorno;
}


/**
* \brief Carga los datos definidos en un array de Estructura del tipo cliente.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array
*/
void pedidoCliente_pedidoDeClienteForzado(sPedidoCliente *aPedidoCLiente,int len)
{

	int aId_pedido[5] = {1,2,3,4,5};
	int aStatusPedido[5] = {0,0,1,1,1};
	int aIdCliente[5] = {1,1,2,2,5};
	float akgTotalesArecolectar[5] = {45,71,25,71,171};//todos tiene 10kg a recolectar demas q la suma de los 3 tipos de residuos
	float akgHDPE[5] = {20,32,10,15,65};
	float akgLDPE[5] = {10,22,2,5,55};
	float akgPP[5] = {5,17,7,3,41};

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
int pedidoCliente_buscarPedidoPorIdCLiente(sPedidoCliente *aPedido,int cantidad, int bIdCliente)//modificar doc
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


/**
* \brief Cuenta la cantidad de pedidos de cada cliente y muestra la informacion de cada cliente y dicho conteo.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param cantidad tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param cantidad tamaño del array de pedidos.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la auxiliar cliente.
* \param cantidad tamaño del array de auxiliar cliente.
* \return Si tuvo exito al contar la cantidad de pedidos por cliente devuelve [0] o si fallo [-1]
*/
int contarYmostrarCantidadPedidosPorCliente(sCliente *aCliente,
		                                 int lenAcliente,
										 sPedidoCliente *aPedido,
										 int lenApedido,
										 sAuxiliarCliente *aAuxCLiente,
										 int lenAauxiliarCliente)
{
	int retorno = -1;
	int i;
	int j;

	if(aCliente!=NULL && aPedido!=NULL && aAuxCLiente!=NULL && lenAcliente>0 && lenApedido>0 && lenAauxiliarCliente>0)
	{
		auxiliarCliente_initClienteAuxiliar(aAuxCLiente,lenAauxiliarCliente);
		for(i=0;i<lenAcliente;i++)
		{
			aAuxCLiente[i].idCliente = aCliente[i].idCliente;
			for(j=0;j<lenApedido;j++)
			{
				if((aCliente[i].idCliente == aPedido[j].idCliente) && (aPedido[j].statusPedido = STATUS_PENDIENTE))
				{
					aAuxCLiente[i].contadorPedidos++;
					retorno = 0;
				}
			}
			cliente_imprimirUnCliente(aCliente[i]);
			auxiliarCliente_imprimirContadorAuxCliente(aAuxCLiente[i]);
		}
	}
	return retorno;
}

/**
* \brief Imprime informacion de los clientes correspondiente a pedidos con status pendiente con informacion especifica de dicho cliente.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param cantidad tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param cantidad tamaño del array de pedidos.
*/
void imprimirPedidosPendientesConInformacionDelCliente(sCliente *aCliente,int lenAcliente,sPedidoCliente *aPedido,int lenApedido)
{
	int i;
	int j;

	for(i=0;i<lenApedido;i++)
	{
		for(j=0;j<lenAcliente;j++)
		{
			if(aPedido[i].statusPedido == STATUS_PENDIENTE && aPedido[i].idCliente == aCliente[j].idCliente)
			{
				printf("\n-Id Pedido: %d\n"
						"-Status del pedido: %d\n"
						"-Cuit cliente %s\n"
						"-Direccion cliente %s\n"
						"-Cantidad de kg a recolectar: %.2f\n",
						aPedido[i].id_pedido,
						aPedido[i].statusPedido,
						aCliente[j].cuit,
						aCliente[j].direccion,
						aPedido[i].kgTotalesArecolectar);
			}
		}
	}
}
/**
* \brief Imprime informacion de los clientes correspondiente a pedidos con status procesado con informacion especifica de dicho cliente.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param cantidad tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param cantidad tamaño del array de pedidos.
*/
void imprimirPedidosProcesadosConInformacionDelCliente(sCliente *aCliente,int lenAcliente,sPedidoCliente *aPedido,int lenApedido)
{
	int i;
	int j;

	for(i=0;i<lenApedido;i++)
	{
		for(j=0;j<lenAcliente;j++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO && aPedido[i].idCliente == aCliente[j].idCliente)
			{
				printf("\n-Id Pedido: %d\n"
						"-Status del pedido: %d\n"
						"-Cuit cliente %s\n"
						"-Direccion cliente %s\n"
						"-Cantidad de kg HDPE procesados: %.2f\n"
						"-Cantidad de kg LDPE procesados: %.2f\n"
						"-Cantidad de kg PP procesados: %.2f\n",
						aPedido[i].id_pedido,
						aPedido[i].statusPedido,
						aCliente[j].cuit,
						aCliente[j].direccion,
						aPedido[i].kgHDPE,
						aPedido[i].kgLDPE,
						aPedido[i].kgPP);
			}
		}
	}
}
