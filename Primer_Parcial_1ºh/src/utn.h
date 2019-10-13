/*
 * utn.h
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */

#ifndef UTN_H_
#define UTN_H_

#define QTY_CARACTERES 50

int getInt(   int *pNumero,
		      char mensaje[],
			  char mensajeError[],
			  int minimo,
			  int maximo,
			  int reintentos);
int getFloat(   float *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getChar(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int esNombre(char pNombre[50]);//
int getNombreEmpresa(char pNombre[50],int limite,int reintentos);
int getStringNumeros(char *input,int reintentos);
int esNumerica(char cadena[50]);
int esCuit(char cadena[50]);
int getCuit(char cuit[49],int limite,int reintentos);
int esAlfanumerico(char aAlfanumerica[50]);
int getAlfanumerico(char alfanumerica[49],char *mensaje,char *mensajeError,int limite,int reintentos);




#endif /* UTN_H_ */
