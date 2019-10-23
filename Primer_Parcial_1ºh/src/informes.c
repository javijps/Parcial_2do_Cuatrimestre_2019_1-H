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




/**
* \brief Calcula cual es el cliente que mas pedidos en estado pendiente tiene.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular el maximo devuelve [0] o si fallo [-1]
*/
int informes_clienteConMasPedidosPendientes(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMaximo=0;
	int i;
	int cantidadPedidos;
	int maximoPedidos=0;
	int idMaximoPedidos;
	int idMaximoPedidos2=0;


	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadPedidos = pedidoCliente_contarPedidosPendientePorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadPedidos==maximoPedidos)
			{
				idMaximoPedidos2 = acliente[i].idCliente;
			}
			if((flagMaximo ==0) || (cantidadPedidos>maximoPedidos))
			{
				flagMaximo = 1;
				maximoPedidos = cantidadPedidos;
				idMaximoPedidos = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0 && idMaximoPedidos2==0)
		{
			printf("Id cliente con mas cantidad de pedidos pendientes: %d\n",idMaximoPedidos);
		}
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de pedidos pendientes!!\n"
					"Id 1er cliente con mas cantidad de pedidos pendientes: %d\n"
					,idMaximoPedidos);
			printf("Id 2do cliente con mas cantidad de pedidos pendientes: %d\n",idMaximoPedidos2);
		}
	}
	return retorno;
}


/**
* \brief Cuenta la cantidad de pedidos completos que tiene el cliente correspondiente al ID ingresado.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param id ID del cliente a ser encontrado.
* \return Si tuvo exito al contar devuelve la cantidad de pedidos del cliente indicado o si fallo [-1]
*/
int informes_contarPedidosCompletosPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	int contadorPedidosCompletos=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id && aPedido[i].statusPedido == STATUS_COMPLETADO)
			{
				contadorPedidosCompletos++;
				retorno = contadorPedidosCompletos;
			}
		}
	}
	return retorno;
}

/**
* \brief Calcula cual es el cliente que mas pedidos en estado completo tiene.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular el maximo devuelve [0] o si fallo [-1]
*/
int informes_clienteConMasPedidosCompletos(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMaximo=0;
	int i;
	int cantidadPedidos;
	int maximoPedidos=0;
	int idMaximoPedidos;
	int idMaximoPedidos2=0;


	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadPedidos = informes_contarPedidosCompletosPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadPedidos==maximoPedidos)
			{
				idMaximoPedidos2 = acliente[i].idCliente;
			}
			if((flagMaximo ==0) || (cantidadPedidos>maximoPedidos))
			{
				flagMaximo = 1;
				maximoPedidos = cantidadPedidos;
				idMaximoPedidos = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0 && idMaximoPedidos2==0)
		{
			printf("Id cliente con mas cantidad de pedidos completos: %d\n",idMaximoPedidos);
		}
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de pedidos completos!!\n"
					"Id 1er cliente con mas cantidad de pedidos completos: %d\n"
					"Id 2do cliente con mas cantidad de pedidos completos: %d\n",
					idMaximoPedidos,idMaximoPedidos2);
		}
	}
	return retorno;
}

/**
* \brief Cuenta la cantidad de pedidos que tiene el cliente correspondiente al ID ingresado.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param id ID del cliente a ser encontrado.
* \return Si tuvo exito al contar devuelve la cantidad de pedidos del cliente indicado o si fallo [-1]
*/
int informes_contarPedidosTotalesPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	int contadorPedidosCompletos=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id &&
					(aPedido[i].statusPedido == STATUS_COMPLETADO
							||aPedido[i].statusPedido == STATUS_PENDIENTE))
			{
				contadorPedidosCompletos++;
				retorno = contadorPedidosCompletos;
			}
		}
	}
	return retorno;
}


/**
* \brief Calcula cual es el cliente que mas pedidos tiene.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular el maximo devuelve [0] o si fallo [-1]
*/
int informes_clienteConMasCantidadDePedidosTotales(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMaximo=0;
	int i;
	int cantidadPedidos;
	int maximoPedidos=0;
	int idMaximoPedidos;
	int idmaximoPedidos2=0;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadPedidos = informes_contarPedidosTotalesPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadPedidos==maximoPedidos)
			{
				idmaximoPedidos2 = acliente[i].idCliente;
			}
			if((flagMaximo ==0) || (cantidadPedidos>maximoPedidos))
			{
				flagMaximo = 1;
				maximoPedidos = cantidadPedidos;
				idMaximoPedidos = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0 && idmaximoPedidos2==0)
		{
			printf("Id cliente con mas cantidad de pedidos totales: %d\n",idMaximoPedidos);
		}
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de pedidos totales!!\n"
					"Id 1er cliente con mas cantidad de pedidos totales: %d\n"
					"Id 2do cliente con mas cantidad de pedidos totales: %d\n",idMaximoPedidos,idmaximoPedidos2);
		}
	}
	return retorno;
}



/**
* \brief Cuenta la cantidad de kg reciclados que tiene el cliente correspondiente al ID ingresado.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param id ID del cliente a ser encontrado.
* \return Si tuvo exito al contar devuelve la cantidad de pedidos del cliente indicado o si fallo [-1]
*/
float informes_contarKgRecicladosPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	float contadorKg=0;
	int idClienteConkgPrevios;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id &&  aPedido[i].statusPedido == STATUS_COMPLETADO)
			{
				if(idClienteConkgPrevios == aPedido[i].idCliente)
				{
					contadorKg += aPedido[i].kgHDPE + aPedido[i].kgLDPE + aPedido[i].kgPP;
				}
				else
				{
					contadorKg = aPedido[i].kgHDPE + aPedido[i].kgLDPE + aPedido[i].kgPP;
					idClienteConkgPrevios = aPedido[i].idCliente;
				}
				retorno = contadorKg;
			}
		}
	}
	return retorno;
}

/**
* \brief Calcula cual es el cliente que mas kg reciclados tiene.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular el maximo devuelve [0] o si fallo [-1]
*/
int informes_clienteConMasCantidadKgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMaximo=0;
	int i;
	float cantidadKg;
	float maximoKg=0;
	int idMaximokg;
	int idmaximokg2=0;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadKg = informes_contarKgRecicladosPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadKg==maximoKg)
			{
				idmaximokg2 = acliente[i].idCliente;
			}
			if((flagMaximo ==0) || (cantidadKg>maximoKg))
			{
				flagMaximo = 1;
				maximoKg = cantidadKg;
				idMaximokg = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0 && idmaximokg2==0)
		{
			printf("Id cliente con mas cantidad de kg reciclados: %d\n",idMaximokg);
		}
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de kg reciclados!!\n"
					"Id 1er cliente con mas cantidad de kg reciclados: %d\n"
					"Id 2do cliente con mas cantidad de kg reciclados: %d\n",idMaximokg,idmaximokg2);
		}
	}
	return retorno;
}



/**
* \brief Calcula cual es el cliente que menos kg reciclados tiene.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular el minimo devuelve [0] o si fallo [-1]
*/
int informes_clienteConMenosCantidadKgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMinimo=0;
	int i;
	float cantidadKg;
	float minimokg=0;
	int idMinimokg;
	int idMinimokg2=0;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadKg = informes_contarKgRecicladosPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadKg!=-1 && cantidadKg==minimokg)
				idMinimokg2 = acliente[i].idCliente;
			if(cantidadKg!=-1 && ((flagMinimo ==0) || (cantidadKg<minimokg)))
			{
				flagMinimo = 1;
				minimokg = cantidadKg;
				idMinimokg = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0 && idMinimokg2==0)
			printf("Id cliente con menor cantidad de kg reciclados: %d\n",idMinimokg);
		else
			printf("Existen 2 clientes con la minima cantidad de kg reciclados!!\n"
					"Id 1er cliente con menor cantidad de kg reciclados: %d\n"
					"Id 2do cliente con menor cantidad de kg reciclados: %d\n",idMinimokg,idMinimokg2);
	}
return retorno;
}

/**
* \brief Informa cuantos clientes reciclaron mas de 1000 kg.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al contar devuelve [0] o si fallo [-1]
*/
int informes_clienteConMasDe1000KgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int i;
	float cantidadKg;
	int contadorMasDe1000=0;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadKg = informes_contarKgRecicladosPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadKg>1000)
			{
				retorno = 0;
				contadorMasDe1000++;
			}
		}
	}
	if(retorno==-1)
		printf("No se encontraron clientes que hayan reciclado mas de 1000kg!!\n");
	else
		printf("Cantidad clientes que reciclaron mas de 1000kg: %d\n",contadorMasDe1000);
	return retorno;
}

/**
* \brief Informa cuantos clientes reciclaron menos de 100 kg.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al contar devuelve [0] o si fallo [-1]
*/
int informes_clienteConMenosDe100KgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int i;
	float cantidadKg;
	int contadorMenosDe100=0;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadKg = informes_contarKgRecicladosPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if(cantidadKg>0 && cantidadKg<100)
			{
				retorno = 0;
				contadorMenosDe100++;
			}
		}
	}
	if(retorno==-1)
	printf("No se encontraron clientes que hayan reciclado menos de 100kg!!\n");
	else
		printf("Cantidad clientes que reciclaron menos de 100kg: %d\n",contadorMenosDe100);
	return retorno;
}


/**
* \brief Calcula el porcentaje de plastico reciclado sobre el total recolectado por pedido.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular devuelve el porcentaje de plastico recilado sobre el total recolectado o si fallo [-1]
*/
float informes_calcularPorcentajeDePlasticoReciclado(sPedidoCliente *aPedido,int lenApedido,int idPedido)
{
	float retorno = -1;
	int i;
	float kgReciclados;
	float porcentajekgReciclados;


	if(aPedido!=NULL && lenApedido>0)
	{
		for(i=0;i<lenApedido;i++)
		{
			if(aPedido[i].id_pedido == idPedido && aPedido[i].statusPedido==STATUS_COMPLETADO)
			{
				kgReciclados =  aPedido[i].kgHDPE + aPedido[i].kgLDPE + aPedido[i].kgPP;
				porcentajekgReciclados = (kgReciclados * 100) /aPedido[i].kgTotalesArecolectar;
				retorno = porcentajekgReciclados;
			}
		}
	}
	return retorno;
}

/**
* \brief Imprime los pedidos completados indicando: ID de pedido, cuit cliente y porcentaje de plastico reciclado.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al contar devuelve [0] o si fallo [-1]
*/

float informes_imprimirPedidoCompletadoConInfoDeCliente(sCliente *aCliente,
		                                                   int lenAcliente,
														   sPedidoCliente *aPedido,
														   int lenApedido)
{
	int retorno = -1;
	int indexCliente;
	float porcentajePlasticoReciclado;
	int i;

	if(aCliente!=NULL && aPedido!=NULL && lenAcliente>0 && lenApedido>0)
	{

		for(i=0;i<lenApedido;i++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO)
			{
				indexCliente = cliente_buscarClientePorId(aCliente,lenAcliente,aPedido[i].idCliente);
				porcentajePlasticoReciclado = informes_calcularPorcentajeDePlasticoReciclado(aPedido,
						                                                                     lenApedido,
						                                                                     aPedido[i].id_pedido);
				if(aCliente[indexCliente].idCliente == aPedido[i].idCliente)
				{
					printf("\nID Pedido:%d\n"
							"Cuit Cliente:%s\n"
							"Porcentaje de plastico reciclado : %.2f\n",
							aPedido[i].id_pedido,
							aCliente[indexCliente].cuit,
							porcentajePlasticoReciclado);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/**
* \brief Busca un cliente correspondiente a la localidad ingresada.
* \param sCliente *aCliente puntero a un array de la estructura sCliente.
* \param len Longitud del array de clientes.
* \param localidad localidad del cliente a ser encontrado.
* \return Si tuvo exito al contar devuelve la cantidad de pedidos del cliente indicado o si fallo [-1]
*/
int informes_buscarClientePorLocalidad(sCliente *aCliente,int lenAcliente,char *localidad)
{
	int retorno = -1;
	int i;

	if(aCliente!=NULL && lenAcliente>0)
	{
		for(i=0;i<lenAcliente;i++)
		{
			if(aCliente[i].statusCliente == STATUS_NOT_EMPTY && (strncmp(aCliente[i].localidad,localidad,50)==0))
			{
				printf("ID CLIENTE %d\n",aCliente[i].idCliente);
				printf("LOCALIDAD CLIENTE %s\n",aCliente[i].localidad);
				printf("LOCALIDAD INGRESADA %s\n",localidad);
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief Cuenta la cantidad de pedidos pendientes por localidad ingresada.
* \param sCliente *aCliente puntero a un array de la estructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param id ID del cliente a ser encontrado.
* \return Si tuvo exito al contar devuelve la cantidad de pedidos pendientes por la localidad indicada o si fallo [-1]
*/
int informes_contarPedidosPendientesPorLocalidad(sCliente *aCliente,
		                                         int lenAcliente,
												 sPedidoCliente *aPedido,
												 int lenApedido)
{
	int retorno = -1;
	int cantdidadDePedidos=0;
	int i;
	int j;
	char bLocalidad[51];

	if(aPedido!=NULL && lenApedido>0 && aCliente!=NULL && lenAcliente>0)
	{
		if(getAlfanumerico(bLocalidad,"\nIngrese Localidad:\n","Localidad Incorrecta\n",50,3)==0)
		{
			for(i=0;i<lenAcliente;i++)
			{
				if(strncmp(aCliente[i].localidad,bLocalidad,50)==0)
				{
					retorno=0;
					for(j=0;j<lenApedido;j++)
					{
						if(aPedido[j].idCliente==aCliente[i].idCliente && aPedido[j].statusPedido == STATUS_PENDIENTE)
						{
							cantdidadDePedidos++;
						}
					}
				}
			}
			printf("Cantidad de pedidos pendientes de la localidad ingresada: %d",cantdidadDePedidos);
		}
	}
	if(retorno!=0)
		printf("No fue posible imprimir el informe!\n");
	return retorno;
}

/**
* \brief Cuenta la cantidad de kg de PP reciclados en todos los pedidos
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al contar devuelve la cantidad de kg de PP reciclados en todos los pedidos o si fallo [-1]
*/
float informes_contarKgPpReciclados(sPedidoCliente *aPedido,int len)
{
	int retorno = -1;
	int i;
	float acumuladorKgPP=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO)
			{
				acumuladorKgPP += aPedido[i].kgPP;
			}
		}
		retorno = acumuladorKgPP;
	}
	return retorno;
}

/**
* \brief Cuenta la cantidad de clientes activos.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \return Si tuvo exito al contar devuelve la cantidad de clientes activos o si fallo [-1]
*/
int informes_contarClientes(sCliente *aCliente,int len)
{
	int retorno = -1;
	int i;
	int contadorClientes=0;

	if(aCliente!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aCliente[i].statusCliente == STATUS_NOT_EMPTY)
			{
				contadorClientes++;
			}
		}
			retorno = contadorClientes;
	}
	return retorno;
}

/**
* \brief Calcula e informa el promedio de kg de pp reciclados por cliente activo.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \return Si tuvo exito al calcular el promedio devuelve [0] o si fallo [-1]
*/
int informes_promedioKgPPrecicladoPorCliente(sCliente *aCliente,int lenAcliente, sPedidoCliente *aPedido,int lenApedido)
{
	int retorno =-1;
	float cantidadKgPPreciclados;
	int cantidadClientesActivos;
	float promedioPorCliente;

	if(aPedido!=NULL && lenApedido>0 && aCliente!=NULL && lenAcliente>0)
	{
		cantidadKgPPreciclados = informes_contarKgPpReciclados(aPedido,lenApedido);
		cantidadClientesActivos = informes_contarClientes(aCliente,lenAcliente);
		promedioPorCliente = cantidadKgPPreciclados / cantidadClientesActivos;
		printf("Promedio de Kg reciclados de Polipropileno por cliente: %.2f",promedioPorCliente);
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Cuenta e informa la cantidad de kg de pp reciclados por cliente
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param idCliente id del cliente a contar los kg de pp
* \return Si tuvo exito al contar devuelve la cantidad de kg de pp reciclados por cliente o si fallo [-1]
*/
float informes_contarKgPPrecicladosPorCliente(sPedidoCliente *aPedido,int len,int idCliente)
{
	int retorno = -1;
	int i;
	float acumuladorKgPP=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO && aPedido[i].idCliente == idCliente)
			{
				acumuladorKgPP += aPedido[i].kgPP;
			}
		}
		retorno = acumuladorKgPP;
	}
	return retorno;
}

/**
* \brief Cuenta e informa la cantidad de kg de HDPE reciclados por cliente
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param idCliente id del cliente a contar los kg de HDPE
* \return Si tuvo exito al contar devuelve la cantidad de kg de HDPE reciclados por cliente o si fallo [-1]
*/
float informes_contarKgHDPErecicladosPorCliente(sPedidoCliente *aPedido,int len,int idCliente)
{
	int retorno = -1;
	int i;
	float acumuladorKgHDPE=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO && aPedido[i].idCliente == idCliente)
			{
				acumuladorKgHDPE += aPedido[i].kgHDPE;
			}
		}
		retorno = acumuladorKgHDPE;
	}
	return retorno;
}

/**
* \brief Cuenta e informa la cantidad de kg de LDPE reciclados por cliente
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param idCliente id del cliente a contar los kg de LDPE
* \return Si tuvo exito al contar devuelve la cantidad de kg de LDPE reciclados por cliente o si fallo [-1]
*/
float informes_contarKgLDPErecicladosPorCliente(sPedidoCliente *aPedido,int len,int idCliente)
{
	int retorno = -1;
	int i;
	float acumuladorKgLDPE=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO && aPedido[i].idCliente == idCliente)
			{
				acumuladorKgLDPE += aPedido[i].kgLDPE;
			}
		}
		retorno = acumuladorKgLDPE;
	}
	return retorno;
}

/**
* \brief Informa los kg reciclados por tipo y por cliente.
* \param sCliente *acliente puntero a un array de la esctructura sCliente.
* \param len Longitud del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param len Longitud del array de pedidos.
* \param cuit cuit correspondiente al cliente.
* \param residuo Tipo de residuo  del que se informara la cantidad reciclada.
* \return Si tuvo exito al informar devuelve [0] o si fallo [-1]
*/
int informes_kgTotalesRecicladosPorCuitClienteYtipoResiduo(sCliente *aCliente,
		                                                   int lenAcliente,
														   sPedidoCliente *aPedido,
														   int lenApedido,
														   char *cuit,
														   int residuo)
{
	int retorno = -1;
	int indexCliente;
	float kgHDPE;
	float kgLDPE;
	float kgPP;

	indexCliente = cliente_buscarClientePorCuit(aCliente,lenAcliente,cuit);

	switch(residuo)
	{
	case 1:
	{
		kgHDPE = informes_contarKgHDPErecicladosPorCliente(aPedido,lenApedido,aCliente[indexCliente].idCliente);
		printf("Total de Kg de HDPE recilados por el cliente: %.2f\n",kgHDPE);
		retorno = 0;
		break;
	}
	case 2:
	{
		kgLDPE = informes_contarKgLDPErecicladosPorCliente(aPedido,lenApedido,aCliente[indexCliente].idCliente);
		printf("Total de Kg de LDPE recilados por el cliente: %.2f\n",kgLDPE);
		retorno = 0;
		break;
	}
	case 3:
	{
		kgPP = informes_contarKgPPrecicladosPorCliente(aPedido,lenApedido,aCliente[indexCliente].idCliente);
		printf("Total de Kg de PP recilados por el cliente: %.2f\n",kgPP);
		retorno = 0;
		break;
	}
	}
	return retorno;
}
