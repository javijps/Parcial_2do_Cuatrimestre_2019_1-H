/*
 * pedidos_de_recoleccion.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_DE_RECOLECCION_H_
#define PEDIDOS_DE_RECOLECCION_H_

typedef struct {

	int id_pedido;
	int statusPedido;
	int idCliente;
	int kgTotalesArecolectar;
	int kgHDPE;
	int kgLDPE;
	int kgPP;


} sPedidoCliente;

int imprimirPedidosActivos(sPedidoCliente *aPedido, int len);
int getDatosPedido(sPedidoCliente *aPedido,int cantidad);
int buscarPedidoLibre(sPedidoCliente *aPedido,int cantidad);
int altaPedido(sPedidoCliente *aPedido, int cantidad);
int initPedido(sPedidoCliente *aPedido, int cantidad);
int buscarPedidoPorId(sPedidoCliente *aPedido,int cantidad, int id);
int procesarResiduos(sPedidoCliente *aPedido, int cantidad);

#endif /* PEDIDOS_DE_RECOLECCION_H_ */
