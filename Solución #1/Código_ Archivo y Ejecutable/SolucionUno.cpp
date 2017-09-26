/*
Mauricio Iv�n Cort�s Garc�a
A00816689
An�lisis y Dise�o de Algoritmos
Prof. Roman Martinez
Tarea 2
Soluci�n 1
SolucionUno.cpp
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <windows.h>
using namespace std;
const int Datos=200000;

/*
Nombre: EncontrarMatricula.
Entrada: Busca_Mat(int), arr_Mats[](int), Cont_Mat(int).
Salida: Booleano.
Funci�n: Encontrar la matr�cula introducida en el arreglo de matr�culas.
*/
bool EncontrarMatricula(int Busca_Mat, int arr_Mats[], int Cont_Mat)
{
    for(int i=0; i<Cont_Mat; i++)
		if(arr_Mats[i]==Busca_Mat)
			return true;
	return false;
}

int main()
{
	int Cont_Mat=0, Matriculas, arr_Mats[Datos], Busca_Mat;
	ifstream Archivo_Entrada;
	ofstream Archivo_Salida;

    //Pregunta al usuario por la matr�cula a buscar en el arreglo de matr�culas y lo almacena en Busca_Mat.
	cout << "Que matricula deseas buscar?" << endl;
	cin >> Busca_Mat;

    clock_t startTime = clock();
	Archivo_Entrada.open("Archivo_Matriculas.txt");//Abre el archivo.
	while(!Archivo_Entrada.eof())//Recorre el archivo hasta que se acaben los datos.
	{
	    //Leer los datos del archivo y almacenarlos en el arreglo arr_Mats.
		Archivo_Entrada >> Matriculas;
		arr_Mats[Cont_Mat]=Matriculas;
		Cont_Mat++;
	}

    //Si la funci�n EncontrarMatricula regresa true, la matr�cula si es de un EXATEC, de lo contrario no lo es.
	if(EncontrarMatricula(Busca_Mat, arr_Mats, Cont_Mat))
        cout << "Si es EXATEC." << endl;
    else
        cout << "No es EXATEC." << endl;
    Archivo_Entrada.close();//Se cierra el archivo de matr�culas.
    //Despliega en un archivo .txt el tiempo de ejecucion del programa.
    Archivo_Salida.open("Tiempo de ejecucion Solucion Uno.txt");
    Archivo_Salida << double(clock()-startTime)/(double)CLOCKS_PER_SEC << " segundos." << endl;
    Archivo_Salida.close();
    system("PAUSE");
	return 0;
}
