/*********************************************************************/
/* Author   : DARWIN GONZÁLEZ SUÁREZ                                 */
/* Comments : Algoritmos y Estructuras de Datos                      */
/*            Escuela Técnica Superior de Ingeniería Informática     */
/*            Universidad de La Laguna                               */  
/* Archivo  : Implementación de métodos                              */
/*********************************************************************/
#include "matriz_t.hpp"

#define MAX_MATRIX_ITEM 100



//========================================================================================
// Métodos privados.
//========================================================================================


/************************************************************************/
/** Procedimiento que devuelve la posición K del elemento en el vector **/
/************************************************************************/
vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		std::cerr << "Error accediendo a matriz"<< std::endl;
		return 0;
        }

	return (i-1)*n_+j-1;   //Formula que saca la posición K del elemento en el vector
    
}

/***********************************************************************/
/** Procedimiento que reserva memoria para un vector de m*n elementos **/
/***********************************************************************/
void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		            // Si ha fallado la reserva de memoria. 
		std::cerr << "Error creando matriz." << std::endl;
}		


/******************************************************************/
/** Procedimiento que libera la memoria reservada para la matriz **/
/******************************************************************/
void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;	// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}

/******************************************************/
/** Procedimiento que redimensiona  la matriz        **/
/******************************************************/
void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}

//========================================================================================
// Métodos públicos.
//========================================================================================

/*************************************************************************/
/** Procedimiento que crea la matriz, constructor pasando parametros    **/
/*************************************************************************/
matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n)
{
	crearMatriz();
}	

/******************************************************/
/** Procedimiento que crea una matriz desde cero     **/
/******************************************************/
matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0)
{}		


/******************************************************/
/** Procedimiento que destruye la matriz             **/
/******************************************************/
matrix_t::~matrix_t(void)
{
	destruirMatriz();
}


/******************************************************/
/** Procedimiento que muestra la matriz por pantalla **/
/******************************************************/
void  matrix_t::mostrarMatriz(void)
{

	char aux[80];

	for(int i=1;i<=m_;i++){
	
		std::cout << "|";	
		for(int j=1;j<=n_;j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			cout << aux;
		}
		std::cout << " |";
		cout << endl;
	}

	cout << endl;	
}


/*********************************************************/
/** Procedimiento que devuelve un elemento de la matriz **/
/*********************************************************/
matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j)
{
	return M_[pos(i,j)];
}

/**********************************************************************/
/** Procedimiento que pone el contenido de una posicion de la matriz **/
/**********************************************************************/
void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}


/*******************************************************/
/** Procedimiento que coge el elemento m de la matriz **/
/*******************************************************/
matrix_inx_t matrix_t::get_m(void)
{
	return m_;
}



/*******************************************************/
/** Procedimiento que coge el elemento n de la matriz **/
/*******************************************************/
matrix_inx_t matrix_t::get_n(void)
{
	return n_;
}


/***********************************************************************************/
/** Procedimiento que rellena la matriz con los datos introducidos por el usuario **/
/***********************************************************************************/
istream& matrix_t::read(istream& is)
{
	int m,n;
	cout<<"Introduzca el numero de filas: "<<endl;
	is >> m;
	cout <<"Introduza el numero de columnas: "<<endl;
	is >>n;

	redimensiona(m,n);

	const int sz=m*n;
     	int aux=0;
     	while(aux<sz){
         for(int i=1;i<=m;i++){
		   for(int j=1;j<=n;j++){        
		    cout <<"Introduzca el elemento de la posicion ->( " <<i<<","<<j<<" )<- de la matriz: "<<endl;
		    is >> M_[aux];
		    aux++;
	       }
	     }
	  
       }
 
	
}


/******************************************************/
/** Procedimiento que                                **/
/******************************************************/
ostream& matrix_t::write(ostream& os)
{
	char aux[80];

	sprintf(aux, " %10d  %10d ",m_,n_);
	os << aux<<endl;

	for(int i=1;i<=m_;i++){
		for(int j=1;j<=n_;j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			os << aux;
		}
		os << endl;
	}

}

/****************************************************************/
/** Procedimiento que determina si una matriz es o no cuadrada **/
/****************************************************************/
bool matrix_t::matrizcuad(void)
{

    if(get_m()==get_n()){
    	cout<<"-----------------------------------------------------"<<endl;
    	cout<<"LA MATRIZ ES CUADRADA."<<endl;
        cout<<"-----------------------------------------------------\n"<<endl;
    	return 1;
    }
    else{
    	cout<<"-----------------------------------------------------"<<endl;
    	cout<<"LA MATRIZ NO ES CUADRADA."<<endl;
    	cout<<"-----------------------------------------------------\n"<<endl;
    	return 0;
    }
}

/**********************************************************************/
/** Procedimiento que determina si una matriz es compatible con otra **/
/**********************************************************************/
bool matrix_t::matrizcompat(matrix_t* A,matrix_t* B)
{
    if(A->get_n()==B->get_m()){
        cout<<endl;
    	cout<<"Las matrices son compatibles."<<endl;
        return true;
    	
    }
    else{
        cout<<endl;
    	cout<<"Las matrices no son compatibles."<<endl;
        return false;

    }
 
}

/***********************************************************************************************/
/** Procedimiento que realiza el producto de dos matrices y guarda el resultado en la primera **/
/***********************************************************************************************/
void matrix_t::producto(matrix_t& B,matrix_t& C)
{	
  bool mult=matrizcompat(&B,&C);
 if(mult==true){
 	redimensiona(B.get_m(),C.get_n());
 	
 	for (int i=1;i<=B.get_m();i++){
    	for (int j=1;j<=C.get_n();j++){ 
         double aux=0.0;
         for (int k=1;k<=B.get_n();k++) 
          {
          	aux+=B.get_matrix_item(i,k)*C.get_matrix_item(k,j);
          	set_matrix_item(i,j,aux);
          }
       }    
    }
 cout<<"Son multiplicables entre si."<<endl;
 }
 else{
 	cout<<"Las matrices son incompatibles y no se pueden multiplicar."<<endl;
 }

} 

/***************************************************************************/
/** Procedimiento que modifica un elemento de la matriz de foma individual**/
/***************************************************************************/
void matrix_t::modindivi(void)
{
  
  int i,j;
  cout<<"Introduza la posición i y j del elemento a modificar: "<<endl;
  cout<<"Introduzca i :"<<endl;
  cin >> i;
  cout<<"Introduzca j :"<<endl;
  cin >>j;
  cout<<endl;
  cout <<"Introduzca el elemento de la posicion ->( " <<i<<","<<j<<" )<- de la matriz: "<<endl;
  cin>>M_[pos(i,j)];
  cout<<endl;
 
 }

/******************************************************************/
/** Procedimiento que accede y lee un único elemento de la matriz**/
/******************************************************************/
void matrix_t::acelematriz(void)
{
  int i,j;
  cout<<"Introduza la posición i y j del elemento a mostrar: "<<endl;
  cout<<"Introduzca i :"<<endl;
  cin >> i;
  cout<<"Introduzca j :"<<endl;
  cin >>j;
  cout<<endl;
  cout <<"El elemento de la posicion ->( " <<i<<","<<j<<" )<- que ha introducido es: "<<M_[pos(i,j)]<<endl;
  cout<<endl;

}
/******************************************************************************************/
/** Procedimiento que devuelva la posición K en el vector del elemento (i,j) de la matriz**/
/******************************************************************************************/
void matrix_t::poscicion(){
    
    int i,j;
    cout<<"Introduzca i: "<<endl;
    cin >>i;
    cout<<"Introduzca j: "<<endl;
    cin >>j;
    cout<<endl;
    cout<<"La posición K en el vector es: "<<pos(i,j)<<"º posición"<<endl;
    cout<<endl;

}








