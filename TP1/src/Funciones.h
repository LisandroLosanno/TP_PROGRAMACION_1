/*
 * Funciones.h
 *
 *  Created on: 16 abr. 2022
 *  Author: Lisandro Losanno
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */

/** \brief Muestra el menu.
 *
 * \param int km - Kilometros ingresados para mostrar en el menu.
 * \param int aero - Precio de Aerolineas Arg ingresados para mostrar en el menu.
 * \return int - Retorna la opcion seleccionada por el usuario.
 *
 */
int menu (int km, float aero, float latam);


/** \brief Se solicita al usuario ingresar KM y se valida que sea un monto correcto.
 *
 * \return int - Retorna los KM ingresados correctamente.
 *
 */
int calcularKilometros();


/** \brief Despliega Submenu para cargar precio de Aerolineas y Latam.
 *
 * \return int - Retorna la opcion elegida por el usuario
 *
 */
int submenuPrecio ();


/** \brief Según la opcion elegida, carga un precio y valida que sea correcto.
 *
 * \param  int opcion - toma un numero que el usuario cargo.
 * \return float - Devuelve el precio cargado.
 *
 */
float cargarPrecio(int opcion);


/** \brief Calcula el costo al pagar con tarjeta de debito
 *
 * \param float costoTd - Precio total a calcular el descuento/aumento
 * \return float - Devuelve el resultado aplicado el descuento/aumento
 *
 */
float calcularTd(float costoTd);


/** \brief Calcula el costo al pagar con tarjeta de credito
 *
 * \param float costoTc  - Precio total a calcular el descuento/aumento
 * \return float - Devuelve el resultado aplicado el descuento/aumento
 *
 */
float calcularTc(float costoTc);


/** \brief Calcula el costo al pagar con BTC.
 *
 * \param float costoBtc  - Precio total a calcular el descuento/aumento
 * \return float - Devuelve el resultado aplicado el descuento/aumento
 *
 */
float calcularBtc(float costoBtc);


/** \brief Calcula el costo total sobre los kilometros ingresados
 *
 * \param float precioViaje  - Precio que ingresa el usuario
 * \param km int - Kilometros que ingresa el usuario
 * \return float - Division de precio sobre kilometros.
 *
 */
float calcularPxKm(float precioViaje, int km);


/** \brief Resta primer precio ingresado contra segundo precio ingresado.
 *
 * \param float precioAero  - Primer precio ingresado
 * \param precioLatam float - Segundo precio ingresado
 * \return float
 *
 */
float	calcularDifPrecio(float precioAero,float precioLatam);


/** \brief Muestra resultados de las variables cargadas.
 *
 * \param int km
 * \param float precioAero
 * \param float tdAero
 * \param float tcAero
 * \param float btcAero
 * \param float pxKmAero
 * \param float precioLatam
 * \param float tdLatam
 * \param float tcLatam
 * \param float btcLatam
 * \param float pxKmLatam
 *
 */
void mostrarCostos (int km, float precioAero, float tdAero, float tcAero, float btcAero, float pxKmAero, float precioLatam, float tdLatam, float tcLatam, float btcLatam, float pxKmLatam, float diferenciaPrecio);
