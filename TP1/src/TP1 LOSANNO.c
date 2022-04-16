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

int menu (int,float,float);


int calcularKilometros(); // PUNTO 1


int	submenuPrecio(); // PUNTO 2
float cargarPrecio(int); // PUNTO 2


float	calcularTd(float);
float	calcularTc(float);
float	calcularBtc(float);
float	calcularPxKm(float,int);
float	calcularDifPrecio(float,float);

void mostrarCostos (int, float, float, float, float, float, float, float, float, float, float, float);

int main(void)
{
		setbuf(stdout, NULL);

	   	int kilometros =0;
	   	int banderaKm = 0; // 0= FALSE, NO ACTIVADA.

	    float precioAero = 0;
	    float precioLatam = 0;
	    int	flagPrecioAero = 0;
	    int flagPrecioLatam = 0;
	    int banderaPrecio = 0 ; // 0= FALSE, NO ACTIVADA.

	    int banderaCosto = 0; // 0= FALSE, NO ACTIVADA.
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
float	calcularDifPrecio(float precioAero,float precioLatam)
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




