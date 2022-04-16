/*
 ============================================================================
 Name        : Lisandro.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main(void)
{
	setbuf(stdout, NULL);

	int kilometros =0;
	int banderaKm = 0;

	float precioAero = 0;
	float precioLatam = 0;
	int	flagPrecioAero = 0;
	int flagPrecioLatam = 0;
	int banderaPrecio = 0 ;

	int banderaCosto = 0;
	float aeroTd;
	float aeroTc;
	float aeroBtc;
	float aeroPxKm;
	float latamTd;
	float latamTc;
	float latamBtc;
	float latamPxKm;
	float difPrecioAeroLatam;

	char salir = 'n';

	do
	{
		switch(menu(kilometros,precioAero,precioLatam))
		{
		case 1: // PEDIMOS KILOMETROS*************************************
			kilometros =calcularKilometros();
			printf("Km ingresados: %d \n",kilometros);
			banderaKm = 1; // BANDERA KM ACTIVADA
			break;

		case 2:  // PEDIMOS PRECIO LATAM Y AERO***************************
			if (banderaKm == 1)
			{
				if(submenuPrecio() == 1)
				{
					precioAero = cargarPrecio(1);
					flagPrecioAero = 1;
				}
				else
				{
					precioLatam = cargarPrecio(2);
					flagPrecioLatam = 1;
				}

				if (flagPrecioAero == 1)
				{
					precioLatam = cargarPrecio(2);
				}
				else
				{
					if (flagPrecioLatam == 1)
					{
						precioAero = cargarPrecio(1);
					}
				}
			}
			else
			{
				printf("Antes de cargar el precio, por favor ingresar Kilometros. \n");
			}
			banderaPrecio = 1; // BANDERA PRECIO ACTIVADA
			break;

		case 3: // CALCULAMOS COSTO LATAM Y AERO***************************
			if (banderaKm == 0 || banderaPrecio == 0)
			{
				printf("Antes de calcular el costo, por favor asegurese de cargar KM y Precio. \n");
			}
			else
			{
				aeroTd = calcularTd(precioAero);
				aeroTc = calcularTc(precioAero);
				aeroBtc = calcularBtc(precioAero);
				aeroPxKm = calcularPxKm(precioAero,kilometros);
				latamTd = calcularTd(precioLatam);
				latamTc = calcularTc(precioLatam);
				latamBtc = calcularBtc(precioLatam);
				latamPxKm = calcularPxKm(precioLatam,kilometros);
				difPrecioAeroLatam = calcularDifPrecio (precioAero,precioLatam);
				printf("Costos calculados correctamente. \n");

				banderaCosto = 1 ;  // BANDERA COSTO ACTIVADA
			}
			break;

		case 4:
			if (banderaKm == 0 || banderaPrecio == 0 || banderaCosto == 0)
			{
				printf("Antes de mostrar los costos, por favor asegurese de cargar KM, precios y calcularlos... \n");
			}
			else
			{
				mostrarCostos(kilometros,precioAero, aeroTd, aeroTc,aeroBtc,aeroPxKm,precioLatam,latamTd,latamTc,latamBtc,latamPxKm,difPrecioAeroLatam);
				banderaCosto = 1 ;  // BANDERA COSTO ACTIVADA
			}
			break;

		case 5:
			kilometros = 7090;
			precioAero = 162965;
			precioLatam = 159339;

			aeroTd = calcularTd(precioAero);
			aeroTc = calcularTc(precioAero);
			aeroBtc = calcularBtc(precioAero);
			aeroPxKm = calcularPxKm(precioAero,kilometros);
			latamTd = calcularTd(precioLatam);
			latamTc = calcularTc(precioLatam);
			latamBtc = calcularBtc(precioLatam);
			latamPxKm = calcularPxKm(precioLatam,kilometros);
			difPrecioAeroLatam = calcularDifPrecio (precioAero,precioLatam);

			mostrarCostos(kilometros,precioAero, aeroTd, aeroTc,aeroBtc,aeroPxKm,precioLatam,latamTd,latamTc,latamBtc,latamPxKm,difPrecioAeroLatam);
			break;

		case 6:
			salir  = 's';
			printf("Muchas gracias por utilizar nuestra aplicacion. Vuelva pronto... \n");
			break;

		default:
			printf("Opcion incorrecta, Seleccionar opcion: 1-6 \n");
		}
		system("pause");
	}
	while (salir != 's');

	return 0;
}











