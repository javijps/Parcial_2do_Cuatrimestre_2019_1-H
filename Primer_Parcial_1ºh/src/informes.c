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

// PUNTO A
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
			retorno = contadorPedidosPendientes;
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
	int idMaximoPedidos2=0;


	if(aPedidos!=NULL && lenPedidos>0 && acliente!=NULL && lenCLientes>0)
	{
		for(i=0;i<lenCLientes;i++)
		{
			cantidadPedidos = informes_contarPedidosPendientePorIDcliente(aPedidos,lenPedidos,acliente[i].idCliente);
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
			printf("Existen 2 clientes con la maxima cantidad de pedidos pendientes!!\nId 1er cliente con mas cantidad de pedidos pendientes: %d\n"
					,idMaximoPedidos);
			printf("Id 2do cliente con mas cantidad de pedidos pendientes: %d\n",idMaximoPedidos2);
		}
	}
	return retorno;
}



// PUNTO B

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

int informes_clienteConMasCantidadDePedidosCompletos(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos)
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


// PUNTO C
int informes_contarPedidosTotalesPorIDcliente(sPedidoCliente *aPedido,int len, int id)
{
	int retorno = -1;
	int i;
	int contadorPedidosCompletos=0;

	if(aPedido!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aPedido[i].idCliente == id && (aPedido[i].statusPedido == STATUS_COMPLETADO ||aPedido[i].statusPedido == STATUS_PENDIENTE))
			{
				contadorPedidosCompletos++;
				retorno = contadorPedidosCompletos;
			}
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



// PUNTO D

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



// PUNTO E
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
			printf("Id cliente con mas cantidad de kg reciclados: %d\n",idMinimokg);
		else
		{
			printf("Existen 2 clientes con la maxima cantidad de kg reciclados!!\n"
					"Id 1er cliente con mas cantidad de kg reciclados: %d\n"
					"Id 2do cliente con mas cantidad de kg reciclados: %d\n",idMinimokg,idMinimokg2);
		}
	}
return retorno;
}

//PUNTO F CANTIDAD DE CLIENTE QUE RECICLARON MAS DE 1000KG

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

//PUNTO G //PUNTO F CANTIDAD DE CLIENTE QUE RECICLARON MENOS DE 100KG

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
			printf("id %d\ncantidad de kg:%.2f\n",acliente[i].idCliente,cantidadKg);
			if(cantidadKg>0 && cantidadKg<100)
			{
				retorno = 0;
				contadorMenosDe100++;
				printf("contador %d\n",contadorMenosDe100);
			}
		}
	}
	if(retorno==-1)
	printf("No se encontraron clientes que hayan reciclado menos de 100kg!!\n");
	else
		printf("Cantidad clientes que reciclaron menos de 100kg: %d\n",contadorMenosDe100);
	return retorno;
}


//PUNTO H IMPRIMIR PEDIDOS COMPLETADOS CON ID PEDIDO,CUIT,%DE PLASTICO RECICLADO




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
				}
			}
		}
	}
	return retorno;
}

/*PUNTO I. INGRESAR UNA LOCALIDAD E INDICAR LA CANTIDAD DE PEDIDOS PENDIENTES PARA DICHA LOCALIDAD.
1RO HAGO FUNCION BUSCARPEDIDOSPENDIENTESPORLOCALIDAD.DEVUELVE LA CANTIDAD DE PEDIDOS PENDIENTES PARA ESA LOCALIDAD.
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




int informes_contarPedidosPendientesPorLocalidad(sCliente *aCliente,int lenAcliente, sPedidoCliente *aPedido,int lenApedido,char *localidad)
{
	int retorno = -1;
//	int indexCliente;
	int cantdidadDePedidos=0;
	int i;
	int j;

	if(aPedido!=NULL && lenApedido>0 && aCliente!=NULL && lenAcliente>0)
	{
		for(i=0;i<lenAcliente;i++)//HACER TODO CON EL MISMO FOR DE i
		{
		//buscaclientePOrlocalidad
			if(strncmp(aCliente[i].localidad,localidad,50)==0)
			{
			//if(buscarclientePorlocalidad!=-1)
			// &&
			//for(i=0;i<lenapedido;i++)
			//if(buscarpedidopendienteporid(aPedido[indexCliente].idcliente!=-1)
			//contadorPEdidos++;
				for(j=0;j<lenApedido;j++)
				{//buscapedidopendiente por id cliente
					if(aPedido[j].idCliente==aCliente[i].idCliente && aPedido[j].statusPedido == STATUS_PENDIENTE)
					{
					//si hay match entre un pedido con el id cliente correspondiente a un cliente de la localidad ingresada por localidad
						cantdidadDePedidos++;
						retorno=0;
					}
				}
			}
		}
		printf("Cantidad de pedidos pendientes de la localidad ingresada: %d",cantdidadDePedidos);
	}
			return retorno;
}




//PUNTO J

//1-ACUMULADOR DE PP RECICLADO

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
		printf("Cantidad de kg PP reciclados: %.2f",acumuladorKgPP);
	}
	return retorno;
}

int informes_contarClientes(sCliente *aCliente,int len)//LO HACE CON CLIENTES ACTIVOS
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
			printf("cantidad de clientes activos %d\n",contadorClientes);
	}
	return retorno;
}

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
		printf(" ID: %d - \nCantidad de kg PP reciclados: %.2f\n",idCliente,acumuladorKgPP);
	}
	return retorno;
}

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
		printf(" ID: %d - \nCantidad de kg kgHDPE reciclados: %.2f\n",idCliente,acumuladorKgHDPE);
	}
	return retorno;
}

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
		printf(" ID: %d - \nCantidad de kg LDPE reciclados: %.2f\n",idCliente,acumuladorKgLDPE);
	}
	return retorno;
}






int informes_kgTotalesRecicladosPorCuitClienteYtipoResiduo(sCliente *aCliente,int lenAcliente, sPedidoCliente *aPedido,int lenApedido,char *cuit,int residuo)
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
		printf("Total de Kg de HDPE recilados por el cliente: %.2f",kgHDPE);
		break;
	}
	case 2:
	{
		kgLDPE = informes_contarKgLDPErecicladosPorCliente(aPedido,lenApedido,aCliente[indexCliente].idCliente);
		printf("Total de Kg de LDPE recilados por el cliente: %.2f",kgLDPE);
		break;
	}
	case 3:
	{
		kgPP = informes_contarKgPPrecicladosPorCliente(aPedido,lenApedido,aCliente[indexCliente].idCliente);
		printf("Total de Kg de PP recilados por el cliente: %.2f",kgPP);
		break;
	}
	retorno = 0;
	}
	return retorno;
}

