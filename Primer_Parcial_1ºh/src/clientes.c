/*
 * clientes.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#define STATUS_EMPTY  -1
#define STATUS_NOT_EMPTY 0

/**
* \brief Imprime la informacion correspondiente a clientes activos..
* \param cliente *aCliente puntero a una array de estructuras cliente.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int imprimirClientesActivos(cliente *aCliente, int len){

	int i;
	int retorno = -1;
	if(aCliente != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(aCliente[i].statusCliente==STATUS_EMPTY)
				continue;
			printf("Id Cliente: %d\n"
					" - Status Cliente: %d\n"
					" - Empresa: %s\n"
					" - Cuit: %s\n"
					" - Direccion: %s\n"
					" - Localidad: %s\n",
					aCliente[i].idCliente,
					aCliente[i].statusCliente,
					aCliente[i].empresa,
					aCliente[i].cuit,
					aCliente[i].direccion,
					aCliente[i].localidad);
		}
	}
	return retorno;
}


/**
* \brief Genera el ID correspondiente a una cliente.
* \return Devuelve el ID correspondiente.
*/
static int generarIdcliente(void){
	static int id = 0;
	id++;
	return id;
}

/**
* \brief Inicializa las clientes con STATUS_EMPTY.
* \param cliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes a inicializar
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int initcliente(cliente *aCliente, int cantidad)
{

	int i;
	int retorno = -1;

	if(aCliente != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			aCliente[i].statusCliente = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
/**
* \brief Solicita los datos correspondientes a una cliente.
* \param cliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al completar todos los campos devuelve [0] o si fallo [-1]
*/
int getDatoscliente(cliente *aCliente,int cantidad){

	int retorno = -1;
	cliente bcliente;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(getNombre(bcliente.empresa,50,3)!=0)
		{
			printf("Nombre Incorrecto\n");
			break;
		}
		if(getString(bcliente.cuit,"Ingrese Cuit","Error cuit",1,50,2)!=0)
		{
			printf("Cuit Incorrecto\n");
			break;
		}
		if(getString(bcliente.direccion,"Inrgese direccion\n","Direccion Incorrecta!\n",1,50,3)!=0)//get direccion
		{
			printf("Direccion Incorrecto\n");
			break;
		}
		if(getString(bcliente.localidad,"Ingrese localidad\n","Direccion Incorrecta!\n",1,50,3)!=0)//get localidad
		{
			printf("Localidad Incorrecto\n");
			break;
		}
		strncpy(aCliente[i].empresa,bcliente.empresa,50);
		strncpy(aCliente[i].cuit,bcliente.cuit,50);
		strncpy(aCliente[i].direccion,bcliente.direccion,50);
		strncpy(aCliente[i].localidad,bcliente.localidad,50);
		aCliente[i].idCliente = generarIdcliente();
		aCliente[i].statusCliente = STATUS_NOT_EMPTY;

		retorno = 0;
	}
	return retorno;
}

/**
* \brief Busca una cliente sin datos cargados.
* \param cliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al encontrar una cliente vacia devuelve [0] o si fallo [-1]
*/
int buscarclienteLibre(cliente *acliente,int cantidad)
{
	int retorno = -1;
	int i;

	if(acliente != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(acliente[i].statusCliente==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}

/**
* \brief Realiza el alta de una nueva cliente.
* \param cliente *aCliente puntero a un array de estructuras cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int altaCliente(cliente *aCliente, int cantidad)
{

	int retorno = -1;
	int index=0;

	if(aCliente != NULL && cantidad>0)
	{
		index = buscarclienteLibre(aCliente,cantidad);

		if(index!=-1)
		{
			if(getDatoscliente(aCliente,cantidad)==0)
				retorno = 0;
		}
	}
	return retorno;
}


/**
* \brief Busca una cliente existente por medio de su ID.
* \param cliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \param id ID de cliente a ser encontrada.
* \return Si tuvo exito al encontrar la cliente indicada devuelve [0] o si fallo [-1]
*/
int buscarClientePorId(cliente *acliente,int cantidad, int id)
{
	int retorno = -1;
	int i;

	if(acliente!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(acliente[i].idCliente == id && acliente[i].statusCliente == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



int modificarClientePorId(cliente *acliente, int cantidad,int id)
{
	int retorno = -1;
	cliente bcliente;
	int index;
	int opcion;


	index = buscarClientePorId(acliente,cantidad,id);
	if(index!=-1)
	{
		do
		{
			if(getInt(&opcion,"\nIngrese: \n1-Modificar Direccion. \n"
					"2-Modificar Localidad\n"
					"3-Salir \n",
					"Error, opcion incorrecta\n",
					1,3,2)==0)
			{
				switch(opcion)
				{
				case 1:
					if(getString(bcliente.direccion,"Ingrese la direccion del cliente\n",
							"direccion incorrecto\n",
							1,49,2)==0)
					{
						strncpy(acliente[index].direccion,bcliente.direccion,50);
						retorno = 0;
					}
					else
						printf("Error!");
					break;
				case 2:
					if(getString(bcliente.localidad,"Ingrese la localidad del cliente\n",
							"localidad incorrecta\n",
							1,49,2)==0)
					{
						strncpy(acliente[index].localidad,bcliente.localidad,50);
						retorno = 0;
					}
					else
						printf("Error!");
					break;
					break;
}
			}
		}while(opcion!= 3);
	}
	else
		printf("cliente no encontrado!!\n");
	return retorno;
}

/**
* \brief Da de baja una cliente existente por medio de su ID.
* \param cliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \param id ID de cliente a ser dada de baja.
* \return Si tuvo exito al realizar la baja de la cliente indicada devuelve [0] o si fallo [-1]
*/
int bajaClientePorId(cliente *acliente,int cantidad,int id)
{

	int retorno = -1;
	int index=0;

	if(acliente != NULL && cantidad>0)
	{
		index = buscarClientePorId(acliente,cantidad,id);

		if(index!=-1)
		{
			acliente[index].statusCliente = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

