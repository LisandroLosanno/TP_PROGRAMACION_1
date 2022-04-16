/*
 * Funciones.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Lisandro Losanno
 */


#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int menu (int km, float aero, float latam)
{
    int opcion;

    printf("*** MENU DE OPCIONES *** \n\n");
    printf("1-Ingresar Kilometros: (km = %d)  \n",km);
    printf("2-Ingresar Precio de Vuelos: (Aerolineas $%.2f , Latam $%.2f )\n", aero,latam);
    printf("3-Calcular todos los costos:\n");
    printf("4-Informar Resultados\n");
    printf("5-Carga forzada de datos\n");
    printf("6-Salir \n \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int calcularKilometros()
{
    int km;
    int aux;

    printf("Ingrese kilometros:\n ");
    aux = scanf("%d", &km);

		while(km <= 0 || aux == 0)
		{
			fflush(stdin);
			printf("ERROR, Ingrese kilometros validos: \n **(Debe ser mayor a 0KM)**\n ");
			aux = scanf("%d", &km);
		}
	return	km;
}


int submenuPrecio ()
{
    int	opcion;

    printf("1- Precio Aerolineas Argentinas\n");
    printf("2- Precio Latam\n");
    printf("Seleccione una opcion:");
    scanf("%d",&opcion);

    while(opcion != 1 && opcion != 2)
    {
       fflush(stdin);
       printf("ERROR, Ingresar opcion valida '1 o 2' :");
       scanf("%d",&opcion);
    }
    return opcion;
}


float cargarPrecio(int opcion)
{
    float precioVuelo = 0;

    if  (opcion == 1)
    {
        printf("Ingrese el precio de vuelo de Aerolineas Argentinas:\n");
        scanf("%f",&precioVuelo);


        while (precioVuelo < 1 )
        {
            fflush(stdin);
        	printf("ERROR, Ingrese el precio valido:\n");
            scanf("%f",&precioVuelo);
        }
    }
    else
    {
		printf("Ingrese el precio de vuelo de LATAM:\n");
		scanf("%f",&precioVuelo);


		while (precioVuelo < 1 )
		{
			fflush(stdin);
			printf("ERROR, Ingrese el precio valido:\n");
			scanf("%f",&precioVuelo);
		}
    }

    return precioVuelo;
}


float calcularTd(float costoTd)
{
	costoTd = costoTd * 0.9;
	return costoTd;
}


float calcularTc(float costoTc)
{
	costoTc = costoTc * 1.25;
	return costoTc;
}


float calcularBtc(float costoBtc)
{
	costoBtc = costoBtc /(40000*195);
	return costoBtc ;
}


float calcularPxKm(float precioViaje, int km)
{
	float precioxKm;

	precioxKm = (float)(precioViaje / km);
	return  precioxKm ;
}


float calcularDifPrecio(float precioAero,float precioLatam)
{
	float difXprecio;

	difXprecio = precioAero - precioLatam;
	return difXprecio;
}


void mostrarCostos (int km, float precioAero, float tdAero, float tcAero, float btcAero, float pxKmAero, float precioLatam, float tdLatam, float tcLatam, float btcLatam, float pxKmLatam, float diferenciaPrecio)
{
    printf("KMs Ingresados: %d km \n\n", km );
    printf("Precio Aerolineas: $%.2f \n", precioAero);
    printf("a) Precio con tarjeta de debito: $%.2f \n",tdAero);
    printf("b) Precio con tarjeta de credito $%.2f \n",tcAero);
    printf("c) Precio pagando con bitcoin: %.9f BTC \n",btcAero);
    printf("d) Mostrar precio unitario: $%.2f \n\n",pxKmAero);

    printf("Precio Latam: $%.2f \n", precioLatam);
    printf("a) Precio con tarjeta de debito: $%.2f \n",tdLatam);
    printf("b) Precio con tarjeta de credito $%.2f \n",tcLatam);
    printf("c) Precio pagando con bitcoin: %.9f BTC \n",btcLatam);
    printf("d) Mostrar precio unitario: $%.2f \n\n",pxKmLatam);

    printf("La diferencia de precio es: $%.2f \n",diferenciaPrecio);
}




