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
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos_de_recoleccion.h"
#include "informes.h"

#define MAX_CLIENTES 100
#define MAX_PEDIDOS 1000

int main(void) {

	sCliente aCliente[MAX_CLIENTES];
	sCliente fCliente[5];
	clienteForzado(fCliente,5);
	sPedidoCliente aPedido[MAX_PEDIDOS];
	sPedidoCliente fPedido[5];
	pedidoDeClienteForzado(fPedido,5);
	sAuxiliarCliente bAuxiliarCLiente[MAX_CLIENTES];
	int option;
	int bIdCliente;
	int bIdPedido;

	initcliente(aCliente,MAX_CLIENTES);
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
				"6-Imprimir clientes\n"
				"7-Imprimir pedidos pendientes\n"
				"8-Imprimir pedidos procesados\n"
				"9-EXIT\n"
				"10-PRUEBA INFORMES\n",
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
			if((getInt(&bIdCliente,"Ingrese ID de cliente\n","Error, id incorreto\n",1,100,2)==0) &&
					(modificarClientePorId(fCliente,5,bIdCliente)==0))//FORZADO!
					printf("Modificacion exitosa!\n");
			else
				printf("Modificacion no realizada!\n");
			break;
		case 3:
			imprimirClientesActivos(fCliente,5);
			if((getInt(&bIdCliente,"Ingrese ID de cliente","Error id",1,100,2)==0) &&
					(bajaClientePorId(fCliente,5,bIdCliente)==0))
					printf("Baja Exitosa!!\n");
			else
				printf("Baja no realizada!!\n");
			break;
		case 4://ver si se puede modificar para q muestre mensaje de id es inexistente
			imprimirClientesActivos(fCliente,5);
			if((getInt(&bIdCliente,"\nIngrese ID de cliente\n","Error id\n",1,100,2)==0) &&
					(buscarClientePorId(fCliente,5,bIdCliente)!=-1) &&
					(altaPedido(aPedido,1,bIdCliente)==0))
				printf("Alta exitosa!!\n");
			else
				printf("No fue posible realizar el alta!!\n");
			imprimirPedidosPendientes(fPedido,5);
			break;
		case 5://
			imprimirPedidosActivos(fPedido,5);
			if(getInt(&bIdPedido,"Ingrese id del pedido\n","Id incorrecto!\n",1,100,2)==0 &&
					procesarResiduos(fPedido,5,bIdPedido)==0)
				printf("Pedido procesado!!\n!");
			else
				printf("No fue posible procesar el pedido!!\n");
			break;
		case 6:
			if(contarYmostrarCantidadPedidosPorCliente(fCliente,5,fPedido,5,bAuxiliarCLiente,MAX_CLIENTES)!=0)
				printf("No fue posible imprimir la informacion!\n");
			break;
		case 7:
			imprimirPedidosPendientesConInformacionDelCliente(fCliente,5,fPedido,5);
			break;
		case 8:
			imprimirPedidosProcesadosConInformacionDelCliente(fCliente,5,fPedido,5);
			break;
		case 10:
			if(maximoKgTotalesPorCliente(fCliente,5,fPedido,5,bAuxiliarCLiente,MAX_CLIENTES)!=0)
				printf("No es posible mostrar el listado!\n");
			break;
		}
	}while(option!=9);
	return EXIT_SUCCESS;
}

