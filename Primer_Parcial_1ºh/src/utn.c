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
#include <ctype.h>
<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/master

#define MAX_FLOAT 1000
#define QTY_CARACTERES 50


<<<<<<< HEAD
=======
//EMPROLIJAR UTN
//HACER esFloat
//CAMBIAR TODOS LOS GET FLOAT POR LA FUNCION DE GETSTRINGTOFLOAT.
//CAMBIAR isNUmber de juli por esNumerica mia.

//PROBAR MUCHAS VECES TODO EL PARCIAL PARA CHEQUEAR QUE ANDE BIEN CON LAS NUEVAS FUNCIONES.



void stringAmayuscula(char *input,int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		input[i] = toupper(input[i]);
	}
}


















>>>>>>> refs/remotes/origin/master
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
int esNombre(char pNombre[QTY_CARACTERES])
{
	int retorno = -1;
	int i;

	if(pNombre!=NULL)

		for(i=0;pNombre[i]!='\0';i++)
		{
			if((pNombre[i] >= 'a' && pNombre[i] <= 'z') ||
					(pNombre[i] >= 'A' && pNombre[i] <= 'Z') ||
					(pNombre[i] >= '0' && pNombre[i] <= '9') ||
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
int getNombreEmpresa(char pNombre[QTY_CARACTERES],int limite,int reintentos)
{
	int retorno=-1;

	if(pNombre!=NULL && limite >0)
	{
		do
		{
			getString(pNombre,"Ingrese nombre de la empresa\n","El nombre ingresado es incorrecto\n",1,49,3);
			if(esNombre(pNombre)==0)
			{
				retorno = 0;
				break;
			}
			else
				reintentos--;
		}while(reintentos>0);
	}
	return retorno;
}

/**
* \Valida si el nombre esta compuesto por letras
* \param pNombre Nombre recibido
* \return Si valida el nombre [0] o si es invalido [-1]
*/
int esLetraMinuscula(char *pLetra,char *mensajeError)
{
	int retorno = -1;
	int i;

	if(pLetra!=NULL)

		for(i=0;pLetra[i]!='\0';i++)
		{
			if((pLetra[i] >= 'a' && pLetra[i] <= 'z'))
			{
				retorno = 0;
				i++;
			}
			else
			{
				printf(mensajeError);
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
int getLetraMinuscula(char *pLetra,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno=-1;

	if(pLetra!=NULL && maximo>minimo)
	{
		do
		{
			getString(pLetra,mensaje,mensajeError,1,50,3);
			if(esLetraMinuscula(pLetra,mensajeError)==0)
			{
				retorno = 0;
				break;
			}
			else
				reintentos--;
		}while(reintentos>0);
	}
	return retorno;
}

int esEntero(char *resultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno =-1;
	int i=0;
	char buffer[4096];
	int cantidad;
	int contador=0;

	strncpy(buffer,resultado,maximo+1);
	cantidad=strlen(buffer);

	while(buffer[0]!='\0' && (buffer[i] >= '0' && buffer[i] <= '9'))
	{
		contador++;
		i++;
	}
	if(cantidad==contador)
	{
		strncpy(resultado,buffer,maximo+1);
		retorno = 0;
	}
	else
		printf("%s",mensajeError);

	return retorno;
}


/**
 * \brief Solicita una cadena alfanumérico al usuario y lo devuelve
 * \param *input puntero a Array donde se cargará el texto ingresado
 * \param reintentos reintentos permitidos ante el error al usuario
 * \return 0 si el texto contiene solo números
 */
int getStringToInt(int *pNumero,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	char buffer[100];

	do
	{
		if(getString(buffer,mensaje,mensajeError,1,100,reintentos)==0)
		{
			if(esEntero(buffer,mensaje,mensajeError,minimo,maximo,reintentos)==0)
			{
				*pNumero = atoi(buffer);
				retorno = 0;
				break;
			}
			else
			{
				printf(mensajeError);
				reintentos--;
			}
		}
	}while(reintentos>0);
	return retorno;
}

<<<<<<< HEAD

void stringAmayuscula(char *input,int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		input[i] = toupper(input[i]);
	}
}

=======
>>>>>>> refs/remotes/origin/master
/**
* \Valida si la cadena es alfanumerica, permitiendo espacios.
* \param pAlfanumerica Cadena recibida
* \return Si la cadena es valida [0] o si es invalido [-1]
*/
int esAlfanumerico(char aAlfanumerica[QTY_CARACTERES])
{
	int retorno = -1;
	int i;

	if(aAlfanumerica!=NULL)

		for(i=0;aAlfanumerica[i]!='\0';i++)
		{
			if((aAlfanumerica[i] >= 'a' && aAlfanumerica[i] <= 'z') ||
					(aAlfanumerica[i] >= 'A' && aAlfanumerica[i] <= 'Z') ||
					(aAlfanumerica[i] >= '0' && aAlfanumerica[i] <= '9') ||
					(aAlfanumerica[i]== ' '))
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
* \brief Solicita input alfanumerico al usuario.
* \param alfanumerica Se carga el alfanumerico ingresado.
* \param reintentos cantidad de errores permitidos
* \return Si tuvo exito al obtener el alfanumerico [0] o si fallo [-1]
*/
int getAlfanumerico(char alfanumerica[QTY_CARACTERES],char *mensaje,char *mensajeError,int limite,int reintentos)
{
	int retorno=-1;


	if(alfanumerica!=NULL && limite >0)
	{
		do
		{
			getString(alfanumerica,mensaje,mensajeError,1,49,3);
			stringAmayuscula(alfanumerica,QTY_CARACTERES);
			if(esAlfanumerico(alfanumerica)==0)
			{
				retorno = 0;
				break;
			}
			else
				reintentos--;
		}while(reintentos>0);
	}
	return retorno;
}


/**
* \brief Evalua si la cadena de caracteres es un cuit,aceptando solo numeros y 11 caracteres.
* \param cuit Array de caracteres a ser validado
* \return Si la cadena de caracteres recibida es un cuit [0] o si no lo es[-1]
*/

int esCuit(char cuit[QTY_CARACTERES])
{
	int retorno=-1;
	int i=0;
	int contadorCaracteres=0;

	if(cuit!=NULL)
	{
		while(cuit[i]!='\0')
		{
			if((cuit[i] >= '0' && cuit[i] <= '9')||cuit[i] == '-' )
			{
				retorno = 0;
				contadorCaracteres++;
				i++;
			}
			else
			{
				retorno = -1;
				printf("Error, los datos ingresados son incorrectos!!\n");
				break;
			}
		}
		if(contadorCaracteres!=13)
		{
			retorno = -1;
			printf("Cantidad de caracteres ingresados (%d) incorrecto!\nEl cuit debe contener 13 caracteres\n",contadorCaracteres);
		}
	}
	return retorno;
}

/**
 * \brief Solicita un cuit al usuario y lo devuelve
 * \param cuit Array donde se cargará el cuit ingresado
 * \param limite limite del array donde se cargará el cuit ingresado
 * \param reintentos reintentos permitidos al usuario
 * \return 0 si el cuit es correcto -1 si no lo es
 */

int getCuit(char cuit[QTY_CARACTERES],int limite,int reintentos)
{
	int retorno=-1;

	if(cuit!=NULL && limite >0)
	{
		do
		{
			getString(cuit,"Ingrese Cuit, formato xx-xxxxxxxx-x\n","Cuit Incorrecto!\n",1,49,3);
			if(esCuit(cuit)==0)
			{
				retorno = 0;
				break;
			}
			else
				reintentos--;
		}while(reintentos>0);
	}
	return retorno;
}


