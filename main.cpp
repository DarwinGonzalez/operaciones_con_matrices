/*********************************************************************/
/* Author   : DARWIN GONZÁLEZ SUÁREZ                                 */
/* Comments : Algoritmos y Estructuras de Datos                      */
/*            Escuela Técnica Superior de Ingeniería Informática     */
/*            Universidad de La Laguna                               */  
/* Archivo  : Programa principal/main                                */
/*********************************************************************/

#include "matriz_t.hpp"

int main(void)
{
	int opt;
	int i,j,aux;
	matrix_t A;
	matrix_t B;
	matrix_t C;

cout<<"\nMenú ALGORITMOS Y ESTRUCTURAS DE DATOS:"<<endl;
cout<<"----------------------------------------------------"<<endl;
cout<<"Opciones del programa: "<<endl;
cout<<"\n1)Introducir elementos de la matriz uno por uno, mostarla por pantalla y comprobar si es cuadrada."<<endl;
cout<<"\n2)Introducir dos matrices y concluir si son compatibles."<<endl;
cout<<"\n3)Introducir una matriz y modificar un elemento de la misma de forma individual."<<endl;
cout<<"\n4)Introducir matriz y mostrar un elemento de forma individual."<<endl;
cout<<"\n5)Posición K en un vector."<<endl;
cout<<"\n6)Producto de matrices."<<endl;
cout<<"\nSalir del programa(cualquier otro caracter)."<<endl;
cout<<"----------------------------------------------------"<<endl;
cout<<"Introduzca la opción:\n";
cout<<"SELECT--> ";
cin >> opt;


switch(opt)
{
case 1: cout << endl;
	
	A.read(cin);
	cout << "---  MATRIZ ORIGINAL  ---" << endl;
	A.mostrarMatriz();
	A.matrizcuad();
        
break;

case 2: A.read(cin);
        B.read(cin);
        A.matrizcompat(&A,&B);
        
break;

case 3: A.read(cin);
        cout<<"---  MATRIZ INTRODUCIDA  ---"<<endl;
        A.mostrarMatriz();
        cout<<endl;
        cout<<"--- ELEMENTO INDIVIDUAL A MODIFICAR  ---"<<endl;
        A.modindivi();
        cout<<endl;
        A.mostrarMatriz();
        
break;

case 4: A.read(cin);
        cout<<"---  MATRIZ INTRODUCIDA  ---"<<endl;
        A.mostrarMatriz();
        cout<<endl;
        cout<<"--- ELEMENTO INDIVIDUAL  ---"<<endl;
        A.acelematriz();
         
break;

case 5: A.read(cin);
        cout<<endl;
        cout<<"---  MATRIZ INTRODUCIDA  ---"<<endl;
        A.mostrarMatriz();
        cout<<endl;
        cout<<"--- POSICIÓN K EN EL VECTOR  ---"<<endl;
        A.poscicion();
        
break;

case 6: B.read(cin);
        C.read(cin);
        A.producto(B,C);
        A.mostrarMatriz();

break;

default: cout<<"\n<<<--- !FIN DEL PROGRAMA¡ --->>>"<<endl;

};
	
}
