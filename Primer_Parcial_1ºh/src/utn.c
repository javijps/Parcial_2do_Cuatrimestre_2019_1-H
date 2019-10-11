/*
 * utn.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita numero entero al usuario y lo valida.
* \param pNumero Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/

int getInt(   int *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	int buffer;

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if((scanf("%d",&buffer)==1) && buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pNumero = buffer;
				break;

			}
			printf("%s",mensajeError);
			//__fpurge(stdin)
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}


/**
* \brief Solicita numero float al usuario y lo valida.
* \param pNumero Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/
int getFloat(   float *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	float buffer;

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if((scanf("%f",&buffer)==1) && buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pNumero = buffer;
				break;

			}
			printf("%s",mensajeError);
			//__fpurge(stdin)
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \brief Solicita caracter al usuario y lo valida.
* \param pChar Se carga el caracter ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el caracter [0] o si fallo [-1]
*/
int getChar(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer;

	if(     pChar != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)

	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%c",&buffer)==1 &&  buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pChar = buffer;
				break;

			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \brief Solicita letra al usuario y valida que la misma sea entre 'a' y 'z',tanto mayuscula como minuscula.
* \param pChar Se carga la letra ingresada.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener la letra [0] o si fallo [-1]
*/
int getLetter(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int reintentos)
{
	int retorno = -1;
	char buffer;
	char minimoLower='a';
	char maximoLower='z';
	char minimoUpper='A';
	char maximoUpper='Z';

	if(     pChar != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos>=0)

	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%c",&buffer)==1 &&//reemplazar scanf
					((buffer >= minimoLower && buffer <= maximoLower) ||
					(buffer >= minimoUpper && buffer <= maximoUpper)))
			{
				retorno = 0;
				*pChar = buffer;
				break;

			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}
/**
* \brief Solicita  cadena de caracteres al usuario y lo valida.
* \param pResultado Se carga la cadena ingresada.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener la cadena [0] o si fallo [-1]
*/
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer[4098];

	if(pResultado != NULL &&
	   pMensaje != NULL &&
	   pMensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >=0)
	{
		do
		{
			printf("%s",pMensaje);
			__fpurge(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos>=0);
	}

	return retorno;
}

/**
* \Valida si el nombre esta compuesto por letras
* \param pNombre Nombre recibido
* \return Si valida el nombre [0] o si es invalido [-1]
*/
int esNombre(char pNombre[50])
{
	int retorno = -1;
	int i;

	if(pNombre!=NULL)

		for(i=0;pNombre[i]!='\0';i++)
		{
			if((pNombre[i] >= 'a' && pNombre[i] <= 'z') ||
					(pNombre[i] >= 'A' && pNombre[i] <= 'Z') ||
					(pNombre[i]== ' '))
			{
				retorno = 0;
				i++;
			}
			else
			{
				printf("Error, los datos ingresados no corresponden a un nombre!!\n");
				break;
			}
		}
	return retorno;
}

/**
* \brief Solicita nombre al usuario.
* \param pNombre Se carga el nombre ingresado.
* \param limite. tamaño del array
* \param reintentos cantidad de errores permitidos
* \return Si tuvo exito al obtener el nombre [0] o si fallo [-1]
*/
int getNombre(char pNombre[49],int limite,int reintentos)
{
	int retorno=-1;

	do
	{
		getString(pNombre,"Ingrese nombre de la Empresa\n","El nombre ingresado es incorrecto\n",1,49,3);
		if(esNombre(pNombre)==0)
		{
			retorno = 0;
			break;
		}
		else
			reintentos--;

	}while(reintentos>0);

	return retorno;
}

int esNumerico(char str[])
{
	int retorno = -1;
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			retorno = 0;
		i++;
	}
	return retorno;
}

int esCuit(char str[])
{
	int retorno = -1;
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			retorno = 0;
		i++;
	}
	if(i<8||i>12)
			{
				retorno = -1;
				printf("\nNumero de cuit incorrecto!\n");
			}
	return retorno;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char *input)
{
	int retorno = -1;
    char aux[256];
    getString(aux,"\nIngrese cuit sin / ni -\n","Cuit incorrecto",0,12,3);
    if(esNumerico(aux))
    {
        strncpy(input,aux,50);
        return 0;
    }
    return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getCuit(char input)
{
	int retorno = -1;
    char aux[256];
    getString(aux,"\nIngrese cuit sin / ni -\n","Cuit incorrecto",0,50,3);
    if(esCuit(aux))
    {
        strncpy(input,aux,50);
        return 0;
    }
    return retorno;
}
