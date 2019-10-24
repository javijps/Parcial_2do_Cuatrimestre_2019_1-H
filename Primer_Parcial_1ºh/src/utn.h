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
int esNombre(char *pNombre);//
int getNombreEmpresa(char *pNombre,int limite,int reintentos);
int getStringNumeros(char *input,int reintentos);
int esNumerica(char *cadena);
int esCuit(char *cadena);
int getCuit(char *cuit,int limite,int reintentos);
int esAlfanumerico(char *aAlfanumerica);
int getAlfanumerico(char *alfanumerica,char *mensaje,char *mensajeError,int limite,int reintentos);
void stringAmayuscula(char *input,int len);



#endif /* UTN_H_ */
