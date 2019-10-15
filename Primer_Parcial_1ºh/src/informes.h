/*
 * informes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "utn.h"
#include "pedidos_de_recoleccion.h"
#include "clientes.h"

int contarPedidosPorCLiente(sCliente *aCliente,
                            int lenAcliente,
							sPedidoCliente *aPedido,
							int lenApedido,
							sAuxiliarCliente *aAuxCLiente,
							int lenaAuxCLiente);
int acumularKgTotalesPorCliente(sCliente *aCliente,
                                int lenAcliente,
								sPedidoCliente *aPedido,
								int lenApedido,
								sAuxiliarCliente *aAuxCLiente,
								int lenaAuxCLiente);
int maximoKgTotalesPorCliente(sCliente *aCliente,
                              int lenAcliente,
							  sPedidoCliente *aPedido,
							  int lenApedido,
							  sAuxiliarCliente *aAuxCLiente,
							  int lenaAuxCLiente);
int listarInfoClientesConInfoAuxPorId(sCliente *aCliente,
		                         int lenAcliente,
								 sPedidoCliente *aPedido,
								 int lenApedido,
								 sAuxiliarCliente *aAuxCLiente,
								 int lenaAuxCLiente,
								 int idCliente);
#endif /* INFORMES_H_ */

