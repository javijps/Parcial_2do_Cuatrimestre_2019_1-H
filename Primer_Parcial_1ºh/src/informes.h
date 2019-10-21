/*
 * informes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "utn.h"
#include "auxiliarCliente.h"
#include "cliente.h"
#include "pedidoCliente.h"
#include "informes.h"

int informes_contarPedidosPendientePorIDcliente(sPedidoCliente *aPedido,int len, int id);
int informes_clienteConMasCantidadDePedidosPendientes(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

int informes_contarPedidosCompletosPorIDcliente(sPedidoCliente *aPedido,int len, int id);
int informes_clienteConMasCantidadDePedidosCompletos(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

int informes_contarPedidosTotalesPorIDcliente(sPedidoCliente *aPedido,int len, int id);
int informes_clienteConMasCantidadDePedidosTotales(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

float informes_contarKgRecicladosPorIDcliente(sPedidoCliente *aPedido,int len, int id);
int informes_clienteConMasCantidadKgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

int informes_clienteConMenosCantidadKgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

int informes_clienteConMasDe1000KgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

int informes_clienteConMenosDe100KgReciclados(sCliente *acliente,int lenCLientes,sPedidoCliente *aPedidos,int lenPedidos);

float informes_calcularPorcentajeDePlasticoReciclado(sPedidoCliente *aPedido,int lenApedido,int idPedido);
float informes_imprimirPedidoCompletadoConInfoDeCliente(sCliente *aCliente,
		                                                   int lenAcliente,
														   sPedidoCliente *aPedido,
														   int lenApedido);

int informes_buscarClientePorLocalidad(sCliente *aCliente,int lenAcliente,char *localidad);
int informes_contarPedidosPendientesPorLocalidad(sCliente *aCliente,int lenAcliente, sPedidoCliente *aPedido,int lenApedido,char *localidad);

float informes_contarKgPpReciclados(sPedidoCliente *aPedido,int len);
int informes_contarClientes(sCliente *aCliente,int len);//LO HACE CON CLIENTES ACTIVOS
int informes_promedioKgPPrecicladoPorCliente(sCliente *aCliente,int lenAcliente, sPedidoCliente *aPedido,int lenApedido);

float informes_contarKgPPrecicladosPorCliente(sPedidoCliente *aPedido,int len,int idCliente);
float informes_contarKgHDPErecicladosPorCliente(sPedidoCliente *aPedido,int len,int idCliente);
float informes_contarKgLDPErecicladosPorCliente(sPedidoCliente *aPedido,int len,int idCliente);
int informes_kgTotalesRecicladosPorCuitClienteYtipoResiduo(sCliente *aCliente,int lenAcliente, sPedidoCliente *aPedido,int lenApedido,char *cuit,int residuo);































#endif /* INFORMES_H_ */

