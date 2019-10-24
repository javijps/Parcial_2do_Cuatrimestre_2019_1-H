/*
 * clientes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define MAX_CUIT 15
#include "utn.h"

typedef struct{

	int idCliente;
	int statusCliente;
	char empresa[50];
	char cuit[MAX_CUIT];
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
int cliente_buscarClientePorCuit(sCliente *aCliente,int len, char cuit[MAX_CUIT]);
int cliente_buscarClientePorEmpresa(sCliente *aCliente,int len, char empresa[50]);
int cliente_modificarClientePorId(sCliente *aCliente,int len, int id);
int cliente_bajaClientePorId(sCliente *aCliente,int cantidad,int id);
void cliente_clienteForzado(sCliente *aCliente,int len);
int cliente_imprimirCuitClientesActivos(sCliente *aCliente, int len);

<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/master
int cliente_buscarLocalidadExistente(sCliente *aCliente,int len, char *localidad);
int cliente_imprimirLocalidades(sCliente *aCliente, int len);
int cliente_guardarYmostarLocalidades(sCliente *aCliente,int len);
int cliente_initclienteAux(sCliente *aCliente, int cantidad);


<<<<<<< HEAD
=======
//INFORMES
>>>>>>> refs/remotes/origin/master
#endif /* CLIENTE_H_ */
