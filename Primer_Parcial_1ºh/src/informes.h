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



































#endif /* INFORMES_H_ */

