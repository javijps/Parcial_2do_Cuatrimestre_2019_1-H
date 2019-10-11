/*
 * clientes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct{

	int idCliente;
	int statusCliente;
	char empresa[50];
	char cuit[50];
	char direccion[50];
	char localidad[50];

} cliente;

int imprimirClientesActivos(cliente *acliente, int len);
int initcliente(cliente *aCliente, int cantidad);
int getDatoscliente(cliente *aCliente,int cantidad);
int buscarclienteLibre(cliente *acliente,int cantidad);
int altaCliente(cliente *aCliente, int cantidad);
int buscarClientePorId(cliente *acliente,int cantidad, int id);
int modificarClientePorId(cliente *acliente, int cantidad,int id);
int bajaClientePorId(cliente *acliente,int cantidad,int id);


#endif /* CLIENTES_H_ */
