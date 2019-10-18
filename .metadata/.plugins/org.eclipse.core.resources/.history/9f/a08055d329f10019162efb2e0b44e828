/*
 * clientes.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include "cliente.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define STATUS_EMPTY  -1
#define STATUS_NOT_EMPTY 0
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1
#define MAX_CUIT 15

/**
* \brief Imprime la informacion correspondiente a clientes activos..
* \param sCliente *aCliente puntero a una array de estructuras cliente.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int cliente_imprimirClientesActivos(sCliente *aCliente, int len){

	int i;
	int retorno = -1;
	if(aCliente != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(aCliente[i].statusCliente==STATUS_EMPTY)
				continue;
			printf("\nId Cliente: %d\n"
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
* \brief Imprime la informacion correspondiente a un cliente.
* \param sCliente aCliente cliente.
*/
void cliente_imprimirUnCliente(sCliente aCliente)
{
	printf("\n - Id Cliente: %d\n"
			" - Status Cliente: %d\n"
			" - Empresa: %s\n"
			" - Cuit: %s\n"
			" - Direccion: %s\n"
			" - Localidad: %s\n",
			aCliente.idCliente,
			aCliente.statusCliente,
			aCliente.empresa,
			aCliente.cuit,
			aCliente.direccion,
			aCliente.localidad);
}

/**
* \brief Genera el ID correspondiente a una cliente.
* \return Devuelve el ID correspondiente.
*/
static int cliente_generarIdcliente(void){
	static int id = 0;
	id++;
	return id;
}

/**
* \brief Inicializa las clientes con STATUS_EMPTY.
* \param sCliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes a inicializar
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int cliente_initcliente(sCliente *aCliente, int cantidad)
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
* \param sCliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al completar todos los campos devuelve [0] o si fallo [-1]
*/
int cliente_getDatoscliente(sCliente *aCliente,int cantidad){

	int retorno = -1;
	sCliente bcliente;
	int i;
	char option='s';

	if(aCliente!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			while(option=='s')
			{
				if(getAlfanumerico(bcliente.empresa,"Ingrese nombre de la  Empresa\n","Nombre Incorrecto\n",50,3)!=0)
				{
					printf("Nombre Incorrecto\n");
					break;
				}
				else
					if(cliente_buscarClientePorEmpresa(aCliente,cantidad,bcliente.empresa)!=-1)
					{
						printf("Empresa existente!\n");
						retorno=-1;
						break;
					}
				if(getCuit(bcliente.cuit,50,3)!=0)
				{
					printf("Cuit Incorrecto\n");
					break;
				}
				else
					if(cliente_buscarClientePorCuit(aCliente,cantidad,bcliente.cuit)!=-1)
					{
						printf("Cuit existente!\n");
						retorno=-1;
						break;
					}
				if(getAlfanumerico(bcliente.direccion,"Ingrese direccion\n","Direccion Incorrecta\n",50,3)!=0)
				{
					printf("Direccion Incorrecta\n");
					break;
				}
				if(getAlfanumerico(bcliente.localidad,"Ingrese Localidad\n","Localidad Incorrecta\n",50,3)!=0)
				{
					printf("Localidad Incorrecta\n");
					break;
				}
				strncpy(aCliente[i].empresa,bcliente.empresa,50);
				strncpy(aCliente[i].cuit,bcliente.cuit,50);
				strncpy(aCliente[i].direccion,bcliente.direccion,50);
				strncpy(aCliente[i].localidad,bcliente.localidad,50);
				aCliente[i].idCliente = cliente_generarIdcliente();
				aCliente[i].statusCliente = STATUS_NOT_EMPTY;
				retorno = 0;
				cliente_imprimirUnCliente(aCliente[i]);
				getChar(&option,
						"Desea dar de alta otro cliente?\nIngrese 's'\nDe lo contrario presione 'n'\n",
						"Opcion incorrecta!\n",
						'a',
						's'
						,2);
			}
		}
	}
	return retorno;
}

/**
* \brief Busca una cliente sin datos cargados.
* \param sCliente *aCliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al encontrar una cliente vacia devuelve [0] o si fallo [-1]
*/
int cliente_buscarclienteLibre(sCliente *aCliente,int cantidad)
{
	int retorno = -1;
	int i;

	if(aCliente != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aCliente[i].statusCliente==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}

/**
* \brief Realiza el alta de una nueva cliente.
* \param sCliente *aCliente puntero a un array de estructuras cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int cliente_altaCliente(sCliente *aCliente, int cantidad)
{

	int retorno = -1;
	int index=0;

	if(aCliente != NULL && cantidad>0)
	{
		index = cliente_buscarclienteLibre(aCliente,cantidad);

		if(index!=-1)
		{
			if(cliente_getDatoscliente(aCliente,cantidad)==0)
				retorno = 0;
		}
	}
	return retorno;
}


/**
* \brief Busca una cliente existente por medio de su ID.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array.
* \param id ID de cliente a ser encontrado.
* \return Si tuvo exito al encontrar el cliente indicado devuelve [0] o si fallo [-1]
*/
int cliente_buscarClientePorId(sCliente *aCliente,int len, int id)
{
	int retorno = -1;
	int i;

	if(aCliente!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aCliente[i].idCliente == id && aCliente[i].statusCliente == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
		}
		if(retorno==-1)
		{
			printf("Id no encontrado!\n");
		}
	}
	return retorno;
}

/**
* \brief Busca una cliente existente por medio de su nombre de empresa.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array.
* \param id ID de cliente a ser encontrado.
* \return Si tuvo exito al encontrar el cliente indicado devuelve [0] o si fallo [-1]
*/
int cliente_buscarClientePorEmpresa(sCliente *aCliente,int len, char empresa[50])
{
	int retorno = -1;
	int i;

	if(aCliente!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if((aCliente[i].statusCliente == STATUS_NOT_EMPTY) && (strncmp(aCliente[i].empresa,empresa,50)==0))
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief Busca una cliente existente por medio de su cuit.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array.
* \param cuit cuit de cliente a ser encontrado.
* \return Si tuvo exito al encontrar el cliente indicado devuelve [0] o si fallo [-1]
*/
int cliente_buscarClientePorCuit(sCliente *aCliente,int len, char cuit[MAX_CUIT])
{
	int retorno = -1;
	int i;

	if(aCliente!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if((aCliente[i].statusCliente == STATUS_NOT_EMPTY) && (strncmp(aCliente[i].cuit,cuit,MAX_CUIT)==0))
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**
* \brief Modifica direccion y locaclidad del cliente indicado por id.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array.
* \param id ID de cliente a ser encontrada.
* \return Si tuvo exito al modificar cliente indicado devuelve [0] o si fallo [-1]
*/
int cliente_modificarClientePorId(sCliente *aCliente,int len, int id)
{
	int retorno = -1;
	sCliente bcliente;
	int index;
	int opcion;

	index = cliente_buscarClientePorId(aCliente,len,id);
	if(aCliente!=NULL && len>0 && index!=-1)
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
					if(getAlfanumerico(bcliente.direccion,"Ingrese direccion\n","Direccion Incorrecta\n",50,3)==0)
					{
						strncpy(aCliente[index].direccion,bcliente.direccion,50);
						retorno = 0;
					}
					else
						printf("Error!");
					break;
				case 2:
					if(getAlfanumerico(bcliente.localidad,"Ingrese Localidad\n","Localidad Incorrecta\n",50,3)==0)
					{
						strncpy(aCliente[index].localidad,bcliente.localidad,50);
						retorno = 0;
					}
					else
						printf("Error!");
					break;
				}
			}
		}while(opcion!= 3);
		cliente_imprimirUnCliente(aCliente[index]);
	}
	else
		printf("cliente no encontrado!!\n");
	return retorno;
}

/**
* \brief Da de baja una cliente existente por medio de su ID.
* \param sCliente *aCliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \param id ID de cliente a ser dada de baja.
* \return Si tuvo exito al realizar la baja de la cliente indicada devuelve [0] o si fallo [-1]
*/
int cliente_bajaClientePorId(sCliente *aCliente,int cantidad,int id)
{

	int retorno = -1;
	int index=0;
	char option;

	if(aCliente != NULL && cantidad>0)
	{
		index = cliente_buscarClientePorId(aCliente,cantidad,id);
		if((index!=-1) &&
				(getChar(&option,
						"Desea confirmar la baja?\nIngrese 's' para confirmar\n","Opcion incorrecta\n",
						'a',
						's',
						2)==0) &&
						(option=='s'))
		{
			aCliente[index].statusCliente = STATUS_EMPTY;
			retorno = 0;
			cliente_imprimirUnCliente(aCliente[index]);
		}
		}
	return retorno;
}

/**
* \brief Carga los datos definidos en un array de Estructura del tipo cliente.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array
*/
void cliente_clienteForzado(sCliente *aCliente,int len)
{
	int aIdCliente[5] = {1,2,3,4,5};
	int aStatusCliente[5] = {0,0,0,0,0};
	char aEmpresa[][50] = {"Transaporte San Miguel SA","Green Eat SA","Nucha","Patagonia Brewery","Guten Bier"};
	char aCuit[][50] = {"20322670355","20350876589","30382549014","20289549514","30231943712"};
	char aDireccion[][50] = {"Cabildo 5000","Santa Fe 4600","Callao 750","Suipacha 324", "Calle 435"};
	char aLocalidad[][50] = {"Belgrano","Palermo","Recoleta","Microcentro","Barrio Parque"};
	int i;

	for(i=0;i<len;i++)
	{
		strncpy(aCliente[i].empresa,aEmpresa[i],50);
		strncpy(aCliente[i].cuit,aCuit[i],50);
		strncpy(aCliente[i].direccion,aDireccion[i],50);
		strncpy(aCliente[i].localidad,aLocalidad[i],50);
		aCliente[i].idCliente = aIdCliente[i];
		aCliente[i].statusCliente = aStatusCliente[i];
	}
}














