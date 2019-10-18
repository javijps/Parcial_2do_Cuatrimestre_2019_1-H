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

int informes_contarPedidosPendientePorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	int contadorPedidosPendientes=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id && aPedido[i].statusPedido == STATUS_PENDIENTE)
			{
				contadorPedidosPendientes++;
			}
		}
		if(retorno==-1)
		{
			retorno = contadorPedidosPendientes;
		}
	}
	return retorno;
}

int informes_clienteConMasCantidadDePedidosPendientes(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMaximo=0;
	int i;
	int cantidadPedidos;
	int maximoPedidos=0;
	int idMaximoPedidos;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadPedidos = informes_contarPedidosPendientePorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if((flagMaximo ==0) || (cantidadPedidos>maximoPedidos))
			{
				flagMaximo = 1;
				maximoPedidos = cantidadPedidos;
				idMaximoPedidos = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0)
		{
			printf("Id cliente con mas cantidad de pedidos pendientes: %d\n",idMaximoPedidos);
		}
	}
	return retorno;
}





int informes_contarPedidosCompletosPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	int contadorPedidosPendientes=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id && aPedido[i].statusPedido == STATUS_COMPLETADO)
			{
				contadorPedidosPendientes++;
			}
		}
		if(retorno==-1)
		{
			retorno = contadorPedidosPendientes;
		}
	}
	return retorno;
}

int informes_clienteConMasCantidadDePedidosCompletos(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
{
	int retorno = -1;
	int flagMaximo=0;
	int i;
	int cantidadPedidos;
	int maximoPedidos=0;
	int idMaximoPedidos;

	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadPedidos = informes_contarPedidosCompletosPorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
			if((flagMaximo ==0) || (cantidadPedidos>maximoPedidos))
			{
				flagMaximo = 1;
				maximoPedidos = cantidadPedidos;
				idMaximoPedidos = acliente[i].idCliente;
				retorno = 0;
			}
		}
		if(retorno==0)
		{
			printf("Id cliente con mas cantidad de pedidos completos: %d\n",idMaximoPedidos);
		}
	}
	return retorno;
}

int informes_contarPedidosTotalesPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	int contadorPedidosPendientes=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id && (aPedido[i].statusPedido == STATUS_COMPLETADO || aPedido[i].statusPedido == STATUS_PENDIENTE ))
			{
				contadorPedidosPendientes++;
			}
		}
		if(retorno==-1)
		{
			retorno = contadorPedidosPendientes;
		}
	}
	return retorno;
}

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
			if((flagMaximo ==0) || (cantidadPedidos>maximoPedidos))
			{
				flagMaximo = 1;
				maximoPedidos = cantidadPedidos;
				idMaximoPedidos = acliente[i].idCliente;
				retorno = 0;
			}
			if(cantidadPedidos==maximoPedidos)
			{
				idmaximoPedidos2 = acliente[i].idCliente;
			}
		}
		if(retorno==0 && idmaximoPedidos2==0)
		{
			printf("Id cliente con mas cantidad de pedidos totales: %d\n",idMaximoPedidos);
		}
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de pedidos totales!!\nId cliente 1 con mas cantidad de pedidos totales: %d\n",idMaximoPedidos);
			printf("Id cliente 2 con mas cantidad de pedidos totales: %d\n",idmaximoPedidos2);
		}

	}
	return retorno;
}

float informes_contarKgRecicladosPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	float contadorKg=0;
	int idClienteConkgPrevios=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id &&  aPedido[i].statusPedido == STATUS_COMPLETADO)
			{
				if(idClienteConkgPrevios == aPedido[i].idCliente)
				{
					contadorKg += aPedido[i].kgHDPE + aPedido[i].kgHDPE + aPedido[i].kgHDPE;
				}
				else
				{
				contadorKg = aPedido[i].kgHDPE + aPedido[i].kgHDPE + aPedido[i].kgHDPE;
				idClienteConkgPrevios = aPedido[i].idCliente;
				}
			}
		}
		if(retorno==-1)
		{
			retorno = contadorKg;
		}
	}
	return retorno;
}

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
			if((flagMaximo ==0) || (cantidadKg>maximoKg))
			{
				flagMaximo = 1;
				maximoKg = cantidadKg;
				idMaximokg = acliente[i].idCliente;
				retorno = 0;
			}
			if(cantidadKg==idMaximokg)
			{
				idmaximokg2 = acliente[i].idCliente;
			}
		}
		if(retorno==0 && idmaximokg2==0)
		{
			printf("Id cliente con mas kg reciclados: %d\n",idMaximokg);
		}
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de kg reciclados!!\n"
					"Id cliente 1 con mas cantidad de kg reciclados: %d\n",idMaximokg);
			printf("Id cliente 2 con mas cantidad de kg reciclados: %df\n",idmaximokg2);
		}

	}
	return retorno;
}

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
			if((flagMinimo ==0) || (cantidadKg<minimokg && cantidadKg!=0))
			{
				flagMinimo = 1;
				minimokg = cantidadKg;
				idMinimokg = acliente[i].idCliente;
				retorno = 0;
			}
			if(cantidadKg==idMinimokg)
			{
				idMinimokg2 = acliente[i].idCliente;
			}
		}
		if(retorno==0 && idMinimokg2==0)
		{
			printf("Id cliente con menos kg reciclados: %d\n",idMinimokg);
		}
		else
		{
			printf("Existen 2 clientes con la minima cantidad de kg reciclados!!\n"
					"Id cliente 1 con menos cantidad de kg reciclados: %d\n",idMinimokg);
			printf("Id cliente 2 con menos cantidad de kg reciclados: %df\n",idMinimokg2);
		}
	}
	return retorno;
}
