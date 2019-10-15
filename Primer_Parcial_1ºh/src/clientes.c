/*
 * clientes.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include "clientes.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define STATUS_EMPTY  -1
#define STATUS_NOT_EMPTY 0
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1

/**
* \brief Imprime la informacion correspondiente a clientes activos..
* \param sCliente *aCliente puntero a una array de estructuras cliente.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int imprimirClientesActivos(sCliente *aCliente, int len){

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
void imprimirUnCliente(sCliente aCliente)
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
* \brief Imprime la informacion correspondiente a un cliente auxiliar.
* \param sAuxiliarCliente aAuxCliente auxiliar cliente
*/
void imprimirUnClienteAux(sAuxiliarCliente aAuxCliente)
{
	printf("\n - Id Cliente: %d\n"
			" - Cantidad pedidos: %d\n"
			" - Cantidad total de kg a recolectar: %d\n",
			aAuxCliente.idCliente,
			aAuxCliente.contadorPedidos,
			aAuxCliente.acumuladorPedidos);
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
* \param sCliente *acliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes a inicializar
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int initcliente(sCliente *aCliente, int cantidad)
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
* \brief Inicializa cliente auxiliar.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la estructura sAuxiliarCliente.
* \param len Tamaño del array
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int initClienteAuxiliar(sAuxiliarCliente *aAuxCLiente,int len)
{

	int i;
	int retorno = -1;

	if(aAuxCLiente != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			aAuxCLiente[i].status = STATUS_EMPTY;
			aAuxCLiente[i].contadorPedidos = 0;
			aAuxCLiente[i].acumuladorPedidos = 0;
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
int getDatoscliente(sCliente *aCliente,int cantidad){

	int retorno = -1;
	sCliente bcliente;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(getAlfanumerico(bcliente.empresa,"Ingrese nombre de la  Empresa\n","Nombre Incorrecto\n",50,3)!=0)
		{
			printf("Nombre Incorrecto\n");
			break;
		}
		if(getCuit(bcliente.cuit,50,3)!=0)
		{
			printf("Cuit Incorrecto\n");
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
		aCliente[i].idCliente = generarIdcliente();
		aCliente[i].statusCliente = STATUS_NOT_EMPTY;
		retorno = 0;
		imprimirUnCliente(aCliente[i]);
	}
	return retorno;
}

/**
* \brief Busca una cliente sin datos cargados.
* \param sCliente *aCliente puntero a una xxxxx de la estructura cliente.
* \param cantidad Cantidad de clientes.
* \return Si tuvo exito al encontrar una cliente vacia devuelve [0] o si fallo [-1]
*/
int buscarclienteLibre(sCliente *aCliente,int cantidad)
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
int altaCliente(sCliente *aCliente, int cantidad)
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
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array.
* \param id ID de cliente a ser encontrado.
* \return Si tuvo exito al encontrar el cliente indicado devuelve [0] o si fallo [-1]
*/
int buscarClientePorId(sCliente *aCliente,int len, int id)
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
	}
	return retorno;
}

/**
* \brief Busca un cliente auxiliar por medio de su ID.
* \param sAuxiliarCliente *aAuxCliente puntero a un array de estructura cliente auxiliar.
* \param len Tamaño del array.
* \param id ID de cliente a ser encontrado.
* \return Si tuvo exito al encontrar el cliente indicado devuelve [0] o si fallo [-1]
*/
int buscarClienteAuxiliarPorId(sAuxiliarCliente *aAuxCliente,int len, int idCliente)//modificar doc
{
	int retorno = -1;
	int i;

	if(aAuxCliente!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(aAuxCliente[i].idCliente == idCliente && aAuxCliente[i].status == STATUS_NOT_EMPTY)
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
int modificarClientePorId(sCliente *aCliente,int len, int id)
{
	int retorno = -1;
	sCliente bcliente;
	int index;
	int opcion;

	index = buscarClientePorId(aCliente,len,id);
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
		imprimirUnCliente(aCliente[index]);
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
int bajaClientePorId(sCliente *aCliente,int cantidad,int id)
{

	int retorno = -1;
	int index=0;
	char option;

	if(aCliente != NULL && cantidad>0)
	{
		index = buscarClientePorId(aCliente,cantidad,id);
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
			imprimirUnCliente(aCliente[index]);
		}
		}
	return retorno;
}

/**
* \brief Carga los datos definidos en un array de Estructura del tipo cliente.
* \param sCliente *aCliente puntero a un array de estructura cliente.
* \param len Tamaño del array
*/
void clienteForzado(sCliente *aCliente,int len)
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

/**
* \brief Imprime el campo contadorPedidos de la estructura sAuxiliarCLiente.
* \param sAuxiliarCLiente cliente Auxiliar.
*/
void imprimirContadorAuxCliente(sAuxiliarCliente aAuxCliente)
{
	printf("- Cantidad de pedidos: %d\n",aAuxCliente.contadorPedidos);
}

/**
* \brief Cuenta la cantidad de pedidos de cada cliente y muestra la informacion de cada cliente y dicho conteo.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param cantidad tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param cantidad tamaño del array de pedidos.
* \param sAuxiliarCliente *aAuxCLiente puntero a una array de la auxiliar cliente.
* \param cantidad tamaño del array de auxiliar cliente.
* \return Si tuvo exito al contar la cantidad de pedidos por cliente devuelve [0] o si fallo [-1]
*/
int contarYmostrarCantidadPedidosPorCliente(sCliente *aCliente,
		                                 int lenAcliente,
										 sPedidoCliente *aPedido,
										 int lenApedido,
										 sAuxiliarCliente *aAuxCLiente,
										 int lenAauxiliarCliente)
{
	int retorno = -1;
	int i;
	int j;

	if(aCliente!=NULL && aPedido!=NULL && aAuxCLiente!=NULL && lenAcliente>0 && lenApedido>0 && lenAauxiliarCliente>0)
	{
		initClienteAuxiliar(aAuxCLiente,lenAauxiliarCliente);
		for(i=0;i<lenAcliente;i++)
		{
			aAuxCLiente[i].idCliente = aCliente[i].idCliente;
			for(j=0;j<lenApedido;j++)
			{
				if((aCliente[i].idCliente == aPedido[j].idCliente) && (aPedido[j].statusPedido = STATUS_PENDIENTE))
				{
					aAuxCLiente[i].contadorPedidos++;
					retorno = 0;
				}
			}
			imprimirUnCliente(aCliente[i]);
			imprimirContadorAuxCliente(aAuxCLiente[i]);
		}
	}
	return retorno;
}

/**
* \brief Imprime informacion de los clientes correspondiente a pedidos con status pendiente con informacion especifica de dicho cliente.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param cantidad tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param cantidad tamaño del array de pedidos.
*/
void imprimirPedidosPendientesConInformacionDelCliente(sCliente *aCliente,int lenAcliente,sPedidoCliente *aPedido,int lenApedido)
{
	int i;
	int j;

	for(i=0;i<lenApedido;i++)
	{
		for(j=0;j<lenAcliente;j++)
		{
			if(aPedido[i].statusPedido == STATUS_PENDIENTE && aPedido[i].idCliente == aCliente[j].idCliente)
			{
				printf("\n-Id Pedido: %d\n"
						"-Status del pedido: %d\n"
						"-Cuit cliente %s\n"
						"-Direccion cliente %s\n"
						"-Cantidad de kg a recolectar: %d\n",
						aPedido[i].id_pedido,
						aPedido[i].statusPedido,
						aCliente[j].cuit,
						aCliente[j].direccion,
						aPedido[i].kgTotalesArecolectar);
			}
		}
	}
}
/**
* \brief Imprime informacion de los clientes correspondiente a pedidos con status procesado con informacion especifica de dicho cliente.
* \param sCliente *aCliente puntero a un array de la estructura cliente.
* \param cantidad tamaño del array de clientes.
* \param sPedidoCliente *aPedido puntero a un array de la estructura pedido cliente.
* \param cantidad tamaño del array de pedidos.
*/
void imprimirPedidosProcesadosConInformacionDelCliente(sCliente *aCliente,int lenAcliente,sPedidoCliente *aPedido,int lenApedido)
{
	int i;
	int j;

	for(i=0;i<lenApedido;i++)
	{
		for(j=0;j<lenAcliente;j++)
		{
			if(aPedido[i].statusPedido == STATUS_COMPLETADO && aPedido[i].idCliente == aCliente[j].idCliente)
			{
				printf("\n-Id Pedido: %d\n"
						"-Status del pedido: %d\n"
						"-Cuit cliente %s\n"
						"-Direccion cliente %s\n"
						"-Cantidad de kg HDPE procesados: %d\n"
						"-Cantidad de kg LDPE procesados: %d\n"
						"-Cantidad de kg PP procesados: %d\n",
						aPedido[i].id_pedido,
						aPedido[i].statusPedido,
						aCliente[j].cuit,
						aCliente[j].direccion,
						aPedido[i].kgHDPE,
						aPedido[i].kgLDPE,
						aPedido[i].kgPP);
			}
		}
	}
}
