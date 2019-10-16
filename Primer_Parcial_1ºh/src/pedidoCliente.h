/*
 * pedidos_de_recoleccion.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOCLIENTE_H_
#define PEDIDOCLIENTE_H_

#include "utn.h"
#include "auxiliarCliente.h"
#include "cliente.h"

typedef struct {

	int id_pedido;
	int statusPedido;
	int idCliente;
	float kgTotalesArecolectar;
	float kgHDPE;
	float kgLDPE;
	float kgPP;

} sPedidoCliente;

int pedidoCliente_imprimirPedidosActivos(sPedidoCliente *aPedido, int len);
int pedidoCliente_imprimirPedidosPendientes(sPedidoCliente *aPedido, int len);
void pedidoCliente_imprimirUnPedido(sPedidoCliente aPedido);
int pedidoCliente_getDatosPedido(sPedidoCliente *aPedido,int cantidad,int idCliente);
int pedidoCliente_buscarPedidoLibre(sPedidoCliente *aPedido,int cantidad);
int pedidoCliente_altaPedido(sPedidoCliente *aPedido, int cantidad,int idCliente);
int pedidoCliente_initPedido(sPedidoCliente *aPedido, int cantidad);
int pedidoCliente_buscarPedidoPorId(sPedidoCliente *aPedido,int cantidad, int id);
int pedidoCliente_procesarResiduos(sPedidoCliente *aPedido, int cantidad,int idPedido);
void pedidoCliente_pedidoDeClienteForzado(sPedidoCliente *aPedidoCLiente,int len);
int pedidoCliente_buscarPedidoPendientePorIdCliente(sPedidoCliente *aPedido,int cantidad, int idCliente);//corregir doc
int contarYmostrarCantidadPedidosPorCliente(sCliente *aCliente,
		                                    int lenAcliente,
											sPedidoCliente *aPedido,
											int lenApedido,
											sAuxiliarCliente *aAuxCLiente,
											int lenAauxiliarCliente);
void imprimirPedidosPendientesConInformacionDelCliente(sCliente *aCliente,
		                                              int lenAcliente,
													  sPedidoCliente *aPedido,
													  int lenApedido);
void imprimirPedidosProcesadosConInformacionDelCliente(sCliente *aCliente,
		                                              int lenAcliente,
													  sPedidoCliente *aPedido,
													  int lenApedido);


#endif /* PEDIDOCLIENTE_H_ */
