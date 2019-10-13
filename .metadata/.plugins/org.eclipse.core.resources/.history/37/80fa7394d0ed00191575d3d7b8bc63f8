/*
 * utn.c
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOAT 1000
#define QTY_CARACTERES 50

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
			if((scanf("%d",&buffer)==1) && buffer >= minimo && buffer <= maximo)//reemplazar x get
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
			__fpurge(stdin);//gets
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
* \param reintentos cantidad de errores permitidos
* \return Si tuvo exito al obtener el nombre [0] o si fallo [-1]
*/
int getNombre(char pNombre[49],int reintentos)
{
	int retorno=-1;

	do
	{
		getString(pNombre,"Ingrese nombre\n","El nombre ingresado es incorrecto\n",1,49,3);
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














/**
* \brief Evalua si la cadena de caracteres es numerica.
* \param cadena Array de caracteres a ser validado
* \return Si la cadena de caracteres recibida es numerica [0] o si no lo es[-1]
*/

int esNumerica(char cadena[50])
{
	int retorno=-1;
	int i;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				printf("Error, los datos ingresados no corresponden a un numero!!\n");
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una cadena alfanumérico al usuario y lo devuelve
 * \param *input puntero a Array donde se cargará el texto ingresado
 * \param reintentos reintentos permitidos ante el error al usuario
 * \return 0 si el texto contiene solo números
 */
int getStringNumeros(char *input,int reintentos)
{
	int retorno = -1;

	do
	{
		if(getString(input,"\nIngrese numeros \n","Numeros incorrectos\n",0,100,reintentos)==0)
		{
			if(esNumerica(input)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("Los datos ingresados no corresponden a numeros!\n");
				reintentos--;
			}
		}
	}while(reintentos>0);
	return retorno;
}

/**
* \brief Evalua si la cadena de caracteres es alfanumerica.
* \param cadena Array de caracteres a ser validado
* \return Si la cadena de caracteres recibida es alfanumerica [0] o si no lo es[-1]
*/

int esAlfaNumerica(char cadena[50])
{
	int retorno=-1;
	int i;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || (cadena[i] >= 'a' && cadena[i] <= 'z') ||
					(cadena[i] >= 'A' && cadena[i] <= 'Z'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				retorno = -1;
					break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param input puntero a Array donde se cargará el texto ingresado
 * \param reintentos reintentos permitidos al usuario
 * \return 0 si el texto es correcto -1 si no lo es
 */

int getAlfanumerica(char *input,int reintentos)
{
	int retorno = -1;

	do
	{
		if(getString(input,"\nIngrese caracteres alfanumericos \n","caracteres incorrectos\n",0,100,reintentos)==0)
		{
			if(esAlfaNumerica(input)==0)
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("Los datos ingresados no corresponden a alfanumericsos!\n");
				reintentos--;
			}
		}
	}while(reintentos>0);
	return retorno;
}

/**
* \brief Evalua si la cadena de caracteres es alfanumerica.
* \param cadena Array de caracteres a ser validado
* \return Si la cadena de caracteres recibida es numerica [0] o si no lo es[-1]
*/

int esCuit(char cadena[50])
{
	int retorno=-1;
	int i;
	int contadorCaracteres=0;

	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i] >= '0' && cadena[i] <= '9')			{
				retorno = 0;
				contadorCaracteres++;
				i++;
			}
			else
			{
				retorno = -1;
				printf("Error, los datos ingresados no corresponden a caracteres alfannumericos!!\n");
				break;
			}
		}
		if(contadorCaracteres!=11)
		{
			retorno = -1;
			printf("Cantidad de caracteres ingresados (%d) incorrecto!\nEl cuit debe contener 11 caracteres\n",contadorCaracteres);
		}
	}
	return retorno;
}

/**
 * \brief Solicita un cuit al usuario y lo devuelve
 * \param input puntero a Array donde se cargará el cuit ingresado
 * \param reintentos reintentos permitidos al usuario
 * \return 0 si el cuit es correcto -1 si no lo es
 */

int getCuit(char *input,int reintentos)
{
	int retorno = -1;

	do
	{
		if(getString(input,"\nIngrese cuit sin / ni - \n","No corresponde a un Cuit\n",1,111,reintentos)==0)//es 10 u 11
		{
			if(esCuit(input)==0)
			{
				retorno = 0;
				break;
			}
			else
				reintentos--;
		}
	}while(reintentos>0);
	return retorno;
}
