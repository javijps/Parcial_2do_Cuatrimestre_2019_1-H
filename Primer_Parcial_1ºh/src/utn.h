/*
 * utn.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

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
int getLetter(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int reintentos);
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);

int getNombre(char pNombre[50],int limite,int reintentos);
int esNombre(char pNombre[50]);
int esNumerico(char str[]);
int esCuit(char str[]);
int getCuit(char input);

#endif /* UTN_H_ */
