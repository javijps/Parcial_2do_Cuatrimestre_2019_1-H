/*
 ============================================================================
 Name        : Primer_Parcial_1ºh.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos_de_recoleccion.h"

#define MAX_CLIENTES 100
#define MAX_PEDIDOS 1000

int main(void) {

	sCliente aCliente[MAX_CLIENTES];
	sCliente fCliente[5];
	clienteForzado(fCliente,5);
	sPedidoCliente aPedido[MAX_PEDIDOS];
	int option;
	int bId;

	//initcliente(aCliente,MAX_CLIENTES);
	initPedido(aPedido,MAX_CLIENTES);
	do
	{

		getInt(&option,"\n---------------------\n"
				"Ingrese:\n"
				"1-Alta de cliente\n"
				"2-Modificar datos cliente\n"
				"3-Baja de cliente\n"
				"4-Crear pedido de recoleccion\n"
				"5-Procesar residuos\n"
				"6-\n"
				"7-\n"
				"8-\n"
				"9-EXIT\n",
				"Error\n",1,12,2);
		switch(option)
		{
		case 1:
			if(altaCliente(aCliente,1)!=0)
				printf("Alta no realizada!\n");
			else
				printf("Alta exitosa!\n");
			break;
		case 2:
			imprimirClientesActivos(fCliente,5);
			if((getInt(&bId,"Ingrese ID de cliente\n","Error, id incorreto\n",1,100,2)==0) &&
					(modificarClientePorId(fCliente,5,bId)==0))//FORZADO!
					printf("Modificacion exitosa!\n");
			else
				printf("Modificacion no realizada!\n");
			break;
		case 3:
			imprimirClientesActivos(fCliente,5);
			if((getInt(&bId,"Ingrese ID de cliente","Error id",1,100,2)==0) && (bajaClientePorId(fCliente,5,bId)==0))
					printf("Baja Exitosa!!\n");
			else
				printf("Baja no realizada!!\n");
			break;
		case 4:
			imprimirClientesActivos(aCliente,5);
			if(altaPedido(aPedido,1)!=0)
				printf("Alta fallida\n");
		imprimirPedidosActivos(aPedido,5);
		break;
		case 5:
			imprimirPedidosActivos(aPedido,5);
			if(procesarResiduos(aPedido,MAX_PEDIDOS)!=0)
				printf("No fue posible procesar!");
			break;
		}
	}while(option!=9);
	return EXIT_SUCCESS;
}

