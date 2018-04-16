/*********************************************************************/
/* Author   : DARWIN GONZÁLEZ SUÁREZ                                 */
/* Comments : Algoritmos y Estructuras de Datos                      */
/*            Escuela Técnica Superior de Ingeniería Informática     */
/*            Universidad de La Laguna                               */
/* Archivo : Declaración clase y de métodos/procedimientos          */  
/*********************************************************************/
#pragma once

#include <stdio.h>		// Cabecera que contendrá el procedimiento sprintf
#include <iostream>		// Cabecera que tendrá la E/S mediante flujo
#include <cmath>		// Cabecera que contendrá las funcioens matemáticas

using namespace std;


//========================================================================================
// Definición de tipos
//========================================================================================

/** Tipo de dato que almacenará cada elemento de la matriz. */
typedef double 		matrix_item_t;	
/** Tipo de dato para índices de la matriz.                 */
typedef unsigned short int 	matrix_inx_t;	
/** Tipo de dato para índices del vector  .                 */
typedef unsigned short int 	vector_inx_t;	


class matrix_t {

//========================================================================================
// Atributos privados.
//========================================================================================

private:

	matrix_item_t*	M_;	/**< Puntero que apunta al comienzo del vector conteniendo los elementos de la matriz. */

	matrix_inx_t  	m_;	/**< Número de filas.   */
	matrix_inx_t	n_;	/**< Número de columnas.*/



//========================================================================================
// Métodos públicos.
//========================================================================================

public:


	matrix_t(matrix_inx_t m,matrix_inx_t n); 

	matrix_t(void); 	

	~matrix_t(void);

	void  mostrarMatriz(void);

	matrix_item_t get_matrix_item(matrix_inx_t i,matrix_inx_t j);

	void set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it);

	matrix_inx_t get_m(void);

	matrix_inx_t get_n(void);

	istream& read(istream& is);

	ostream& write(ostream& os);

    bool matrizcuad(void);

    void producto(matrix_t& B,matrix_t& C);
  
    void modindivi(void);

    void acelematriz(void);

    bool matrizcompat(matrix_t* A,matrix_t* B);
    
    void poscicion(void);

//========================================================================================
// Métodos privados.
//========================================================================================

private:


   vector_inx_t pos(matrix_inx_t i,matrix_inx_t j);

   void crearMatriz(void); 
	
   void destruirMatriz(void);

   void redimensiona(matrix_inx_t m,matrix_inx_t n);


};


