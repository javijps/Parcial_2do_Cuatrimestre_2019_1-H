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
		      char *mensaje,
			  char *mensajeError,
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
int esNombre(char pNombre[QTY_CARACTERES]);//
int getNombreEmpresa(char pNombre[QTY_CARACTERES],int limite,int reintentos);
int getStringToInt(int *pNumero,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos);
int esEntero(char cadena[QTY_CARACTERES]);
int esCuit(char cadena[QTY_CARACTERES]);
int getCuit(char cuit[QTY_CARACTERES],int limite,int reintentos);
int esAlfanumerico(char aAlfanumerica[QTY_CARACTERES]);
int getAlfanumerico(char alfanumerica[QTY_CARACTERES],char *mensaje,char *mensajeError,int limite,int reintentos);

int getStringToFloat(float *pNumero,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos);
int esFloat(char cadena[QTY_CARACTERES]);

int getLetraMinuscula(char *pLetra,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos);
int esLetraMinuscula(char *pLetra,char *mensajeError);

void stringAmayuscula(char *input,int len);


#endif /* UTN_H_ */
