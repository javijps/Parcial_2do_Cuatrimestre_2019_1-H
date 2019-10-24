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
#include "cliente.h"
#include "informes.h"
#include "pedidoCliente.h"

#define MAX_CLIENTES 100
#define MAX_PEDIDOS 1000


int main(void) {

	sCliente aCliente[MAX_CLIENTES];
	sCliente fCliente[6];
	cliente_clienteForzado(fCliente,6);
	sPedidoCliente aPedido[MAX_PEDIDOS];
	sPedidoCliente fPedido[9];
	pedidoCliente_pedidoDeClienteForzado(fPedido,9);
	int option;
	int bIdCliente;
	int bIdPedido;
	char optionChar;
	char bcuit[15];
	int subOption;

	cliente_initcliente(aCliente,MAX_CLIENTES);
	pedidoCliente_initPedido(aPedido,MAX_CLIENTES);
	do
	{

		getInt(&option,"\n---------------------\n"
				"Ingrese:\n"
				"1-Alta de cliente\n"
				"2-Modificar datos cliente\n"
				"3-Baja de cliente\n"
				"4-Crear pedido de recoleccion\n"
				"5-Procesar residuos\n"
				"6-Imprimir clientes con cantidad de pedidos pendientes\n"
				"7-Imprimir pedidos pendientes\n"
				"8-Imprimir pedidos procesados\n"
				"9-SUBMENU INFORMES\n"
				"10-EXIT\n",
				"Error\n",1,12,2);
		switch(option)
		{
		case 1:
			if(cliente_altaCliente(aCliente,5)!=0)
				printf("Alta no realizada!\n");
			else
				printf("Alta exitosa!\n");
			break;
		case 2:
			cliente_imprimirClientesActivos(fCliente,6);
			if((getInt(&bIdCliente,"Ingrese ID de cliente\n","Error, id incorreto\n",1,MAX_CLIENTES,2)==0) &&
					(cliente_modificarClientePorId(fCliente,6,bIdCliente)==0))
				printf("Modificacion exitosa!\n");
			else
				printf("Modificacion no realizada!\n");
			break;
		case 3:
			cliente_imprimirClientesActivos(fCliente,6);
			if((getInt(&bIdCliente,"Ingrese ID de cliente","Error id",1,MAX_CLIENTES,2)==0) &&
					(cliente_bajaClientePorId(fCliente,6,bIdCliente)==0))
				printf("Baja Exitosa!!\n");
			else
				printf("Baja no realizada!!\n");
			break;
		case 4:
			cliente_imprimirClientesActivos(fCliente,6);
			if((getInt(&bIdCliente,"\nIngrese ID de cliente\n","Error id\n",1,MAX_CLIENTES,2)==0) &&
					(cliente_buscarClientePorId(fCliente,6,bIdCliente)!=-1) &&
					(pedidoCliente_altaPedido(fPedido,9,bIdCliente)==0))
			{
				printf("Alta exitosa!!\n");
				pedidoCliente_imprimirPedidosPendientes(aPedido,5);
			}
			else
				printf("No fue posible realizar el alta!!\n");
			break;
		case 5:
			pedidoCliente_imprimirPedidosActivos(fPedido,9);
			if(getInt(&bIdPedido,"Ingrese id del pedido\n","Id incorrecto!\n",1,MAX_PEDIDOS,2)==0 &&
					pedidoCliente_procesarResiduos(fPedido,9,bIdPedido)==0)
				printf("Pedido procesado!!\n!");
			break;
		case 6:
			if(imprimirClientesConCantidadDePedidosPendientes(fCliente,6,fPedido,9)!=0)
				printf("No fue posible imprimir la informacion!\n");
			break;
		case 7:
			pedidoCliente_imprimirPedidosPendientesConInformacionDelCliente(fCliente,6,fPedido,9);
			break;
		case 8:
			if(pedidoCliente_imprimirPedidosProcesadosConInformacionDelCliente(fCliente,6,fPedido,9)!=0)
				printf("No se encontraron pedidos en estado procesado!!\n");
			break;
		case 9:
			do
			{
				if(getChar(&optionChar,"\n---SubMenu Informes---\n"
						"Ingrese:\n"
						"a-Cliente con mas pedidos pendientes\n"
						"b-Cliente con mas pedidos completados\n"
						"c-Cliente con mas pedidos\n"
						"d-Cliente que reciclo mas kilos\n"
						"e-Cliente que reciclo menos kilos\n"
						"f-Cantidad de clientes que reciclaron mas de 1000kg\n"//CORREGIR, NO ACUMULA
						"g-Cantidad de clientes que reciclaron menos de 100kg\n"
						"h-Imprimir los pedidos completados(ID pedido, Cuit, % de plastico reciclado.\n"
						"i-Pedidos pendientes por localidad\n"
						"j-Promedio de polipropileno reciclado por cliente\n"
						"k-Informar cantidad de kilos totales reciclada por tipo de residuo(por cuit cliente)\n"
						"l-EXIT\n",
						"Error, opcion incorrecta!\n",'a','l',2)!=0)
				{
					printf("No fue posible acceder al Sub-Menu de opciones");
					break;
				}
				else
				{
					switch(optionChar)
					{
					case 'a':
						if(informes_clienteConMasPedidosPendientes(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'b':
						if(informes_clienteConMasPedidosCompletos(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'c':
						if(informes_clienteConMasCantidadDePedidosTotales(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'd':
						if(informes_clienteConMasCantidadKgReciclados(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'e':
						if(informes_clienteConMenosCantidadKgReciclados(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'f':
						if(informes_clienteConMasDe1000KgReciclados(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'g':
						if(informes_clienteConMenosDe100KgReciclados(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'h':
						if(informes_imprimirPedidoCompletadoConInfoDeCliente(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'i':
						cliente_guardarYmostarLocalidades(fCliente,6);//ver xq al reingresar muestra solo CABA
						informes_contarPedidosPendientesPorLocalidad(fCliente,6,fPedido,9);
						break;
					case 'j':
						if(informes_promedioKgPPrecicladoPorCliente(fCliente,6,fPedido,9)!=0)
							printf("\nNo fue posible imprimir el informe!\n");
						break;
					case 'k':
						cliente_imprimirCuitClientesActivos(fCliente,6);
						if(getCuit(bcuit,50,3)==0)
						{
							do{
								{
									if(getInt(&subOption,"\nIngrese: \n1-Informar kg totales de HDPE del cliente.\n"
											"2-Informar kg totales de LDPE del cliente.\n"
											"3-Informar kg totales de PP del cliente.\n"
											"4-EXIT\n",
											"Error, opcion incorrecta\n",
											1,4,2)==0)
										informes_kgTotalesRecicladosPorCuitClienteYtipoResiduo(fCliente,6,fPedido,9,bcuit,subOption);
									else
										printf("\nNo fue posible imprimir el informe!\n");
								}
							}while(subOption!=4);
						}
						break;
					}
				}
			}while(optionChar!='l');
		}
	}while(option!=10);
	return EXIT_SUCCESS;
}
