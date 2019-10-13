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

} sCliente;

int imprimirClientesActivos(sCliente *acliente, int len);
void imprimirUnCliente(sCliente aCliente);
int initcliente(sCliente *aCliente, int cantidad);
int getDatoscliente(sCliente *aCliente,int cantidad);
int buscarclienteLibre(sCliente *aCliente,int cantidad);
int altaCliente(sCliente *aCliente, int cantidad);
int buscarClientePorId(sCliente *aCliente,int len, int id);
int modificarClientePorId(sCliente *aCliente,int len, int id);
int bajaClientePorId(sCliente *aCliente,int cantidad,int id);
void clienteForzado(sCliente *aCliente,int len);

#endif /* CLIENTES_H_ */
