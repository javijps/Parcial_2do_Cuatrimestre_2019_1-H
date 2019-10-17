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

int informes_contarPedidosPorCLiente(sCliente *aCliente,
                                     int lenAcliente,
									 sPedidoCliente *aPedido,
									 int lenApedido,
									 sAuxiliarCliente *aAuxCLiente,
									 int lenaAuxCLiente);
int informes_acumularKgTotalesPorCliente(sCliente *aCliente,
                                     int lenAcliente,
									 sPedidoCliente *aPedido,
									 int lenApedido,
									 sAuxiliarCliente *aAuxCLiente,
									 int lenaAuxCLiente);
int informes_maximoKgTotalesPorCliente(sCliente *aCliente,
                                       int lenAcliente,
									   sPedidoCliente *aPedido,
									   int lenApedido,
									   sAuxiliarCliente *aAuxCLiente,
									   int lenaAuxCLiente);
int informes_listarInfoClientesConInfoAuxPorId(sCliente *aCliente,
		                                       int lenAcliente,
									           sPedidoCliente *aPedido,
									           int lenApedido,
									           sAuxiliarCliente *aAuxCLiente,
									           int lenaAuxCLiente,
									           int idCliente);
void informes_subMenu(void);

#endif /* INFORMES_H_ */

