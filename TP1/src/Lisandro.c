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
float	calcularPxKm(float);
float	calcularDifPrecio(float,float);



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
	    float aeroDc;
		float aeroTc;
		float aeroBtc;
		float aeroPxKm;
		float latamDc;
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
	            kilometros=calcularKilometros();
	            banderaKm = 1; // BANDERA KM ACTIVADA
	            break;


	        case 2:  // PEDIMOS PRECIO LATAM Y AERO***************************
	            if (banderaKm == 1)
	            {
	            	if(submenuPrecio(precioAero,precioLatam) == 1)
	            	{
	            		precioAero = cargarPrecio(1);
	            		flagPrecioAero = 1;
	            	}

	            	else
	            	{
	            		if(submenuPrecio(precioAero,precioLatam) == 2)
						{
	            			precioLatam = cargarPrecio(2);
	            			flagPrecioLatam = 1;
						}
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
	        	    aeroDc = calcularTd(precioAero);
	        		aeroTc = calcularTc(precioAero);
	        		aeroBtc = calcularBtc(precioAero);
	        		aeroPxKm = calcularPxKm(precioAero);
	        		latamDc = calcularTd(precioLatam);
	        		latamTc = calcularTc(precioLatam);
	        		aeroBtc = calcularBtc(precioLatam);
	        		aeroPxKm = calcularPxKm(precioLatam);
	        		difPrecioAeroLatam = calcularDifPrecio (precioAero,precioLatam);


	                banderaCosto = 1 ;  // BANDERA COSTO ACTIVADA
	            }
	            break;

	        case 4:
	            if (banderaKm == 0 || banderaPrecio == 0 || banderaCosto == 0)
	            {

	            }
	            else
	            {
	                banderaCosto = 1 ;  // BANDERA COSTO ACTIVADA
	            }
	            break;

	        case 5:

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


	return EXIT_SUCCESS;

}

int menu (int km, float aero, float latam)
{
    int opcion;
    int validarMenu;

    system("cls");
    printf("*** MENU DE OPCIONES *** \n\n");
    printf("1-Ingresar Kilometros: (km = %d)  \n",km);
    printf("2-Ingresar Precio de Vuelos: (Aerolineas $%.2f , Latam $%.2f )\n", aero,latam);
    printf("3-Calcular todos los costos:\n");
    printf("4-Informar Resultados\n");
    printf("5-Carga forzada de datos\n");
    printf("6-Salir \n \n");
    fflush(stdin);

    validarMenu =  scanf("%d", &opcion);
        if(validarMenu == 0)
        {
        opcion = 7;
        }
        return opcion;
}

int calcularKilometros()
{
    int km;
    int aux;

    printf("Ingrese kilometros:\n ");
    aux = scanf("%d", &km);

    while(km < 100 || aux == 0) // No existen vuelos comerciales menores a 100KM en ARGENTINA.
    {
        printf("Ingrese kilometros validos: \n **(Debe ser mayor a 100KM)**\n ");
        fflush(stdin);
        scanf("%d", &km);
    }

    return km;
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
	int	flagPrecioAero = 0;
	int	flagPrecioLatam = 0;

    if  (opcion == 1)
    {
        printf("Ingrese el precio de vuelo de Aerolineas Argentinas:\n");
        scanf("%f",&precioVuelo);
        flagPrecioAero = 1;

        while (precioVuelo < 1 )
        {
            fflush(stdin);
        	printf("ERROR, Ingrese el precio valido:\n");
            scanf("%f",&precioVuelo);
        }

    }
    else
    {
        if (opcion == 2)
        {
            printf("Ingrese el precio de vuelo de LATAM:\n");
            scanf("%f",&precioVuelo);
            flagPrecioLatam = 1;

            while (precioVuelo < 1 )
            {
                fflush(stdin);
            	printf("ERROR, Ingrese el precio valido:\n");
            	scanf("%f",&precioVuelo);
            }
        }
    }

    return precioVuelo;
}

float	calcularTd(float);
{

	return ;
}

float	calcularTc(float);
{

	return ;
}
float	calcularBtc(float);
{

	return ;
}
float	calcularPxKm(float);
{

	return ;
}
float	calcularDifPrecio(float,float);
{

	return ;
}





int mostrarCostos (float precioAero,float precioLatam, int km)
{


    printf("KMs Ingresados: %d km \n\n", km );
    printf("Precio Aerolineas: $%.2f \n", precioAero);
    printf("a) Precio con tarjeta de debito: $%.2f \n",debitoAero);
    printf("b) Precio con tarjeta de credito $%.2f \n",creditoAero);
    printf("c) Precio pagando con bitcoin: %.9f BTC \n",btcAero);
    printf("d) Mostrar precio unitario: $%.2f \n\n",precioxKmAero);

    printf("Precio Latam: $%.2f \n", precioLatam);
    printf("a) Precio con tarjeta de debito: $%.2f \n",debitoLtm);
    printf("b) Precio con tarjeta de credito $%.2f \n",creditoLtm);
    printf("c) Precio pagando con bitcoin: %.9f BTC \n",btcLtm);
    printf("d) Mostrar precio unitario: $%.2f \n\n",precioxKmLtm);

    printf("La diferencia de precio es: $%.2f \n",diferenciaPrecio);



    return aclaracion;
}



