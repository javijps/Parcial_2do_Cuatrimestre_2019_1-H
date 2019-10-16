/*
 * clientes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "utn.h"

typedef struct{

	int idCliente;
	int statusCliente;
	char empresa[50];
	char cuit[50];
	char direccion[50];
	char localidad[50];

} sCliente;

int cliente_imprimirClientesActivos(sCliente *acliente, int len);
void cliente_imprimirUnCliente(sCliente aCliente);
int cliente_initcliente(sCliente *aCliente, int cantidad);
int cliente_getDatoscliente(sCliente *aCliente,int cantidad);
int cliente_buscarclienteLibre(sCliente *aCliente,int cantidad);
int cliente_altaCliente(sCliente *aCliente, int cantidad);
int cliente_buscarClientePorId(sCliente *aCliente,int len, int id);
int cliente_modificarClientePorId(sCliente *aCliente,int len, int id);
int cliente_bajaClientePorId(sCliente *aCliente,int cantidad,int id);
void cliente_clienteForzado(sCliente *aCliente,int len);


//INFORMES
#endif /* CLIENTE_H_ */
