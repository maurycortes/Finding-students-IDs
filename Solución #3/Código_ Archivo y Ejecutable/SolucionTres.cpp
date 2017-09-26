/*
Mauricio Iván Cortés García
A00816689
Análisis y Diseño de Algoritmos
Prof. Roman Martinez
Tarea 2
Solución 3
SolucionTres.cpp
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <list>
using namespace std;
const int Posiciones_Tabla_Hash=1000;

/*
Nombre: FuncionHash.
Entradas: Matrícula.
Salidas: Clave de 3 dígitos para introducir a tabla hash.
Función: Introduciendo una matrícula (int), se sacan los últimos 3 dígitos para obtener la clave para la tabla hash.
*/
int FuncionHash(int iDatos)
{
    return iDatos % 1000;
}

/*
Nombre: Encuentra_Matricula.
Entradas: Lista de hash <int>, iDatos(int) - Matricula que se desea buscar.
Salidas: Booleano diciendo si la matricula existe o no en la tabla de hash
Función: Se busca en la lista dentro de la posicion de la tabla de hash para identificar la matriula a buscar.
*/
bool Encuentra_Matricula(list<int> Lista_Hash[Posiciones_Tabla_Hash], int iDatos)
{
    list<int>::iterator Inicio=Lista_Hash[FuncionHash(iDatos)].begin();
    list<int>::iterator Final=Lista_Hash[FuncionHash(iDatos)].end();
    while(Inicio!=Final)
    {
        if(*Inicio==iDatos)
            return true;
        ++Inicio;
    }
    return false;
}

int main()
{
    int Busca_Mat, iDatos;
    list<int> Lista_Hash[Posiciones_Tabla_Hash];
    ifstream Archivo_Entrada;
	ofstream Archivo_Salida;

    //Pregunta al usuario por la matrícula a buscar en el tabla de hash de matrículas y lo almacena en Busca_Mat.
	cout << "Que matricula deseas buscar?" << endl;
	cin >> Busca_Mat;

	clock_t startTime = clock();
    Archivo_Entrada.open("Archivo_Matriculas.txt");//Abre el archivo de entrada.
	//Mientras que el archivo no se acabe, se obtienen los datos e introducen en la tabla de hash
    while(!Archivo_Entrada.eof())
    {
        Archivo_Entrada >> iDatos;
        Lista_Hash[FuncionHash(iDatos)].push_back(iDatos);
    }
	//Se despliega si la matricula buscada pertenece a la tabla(si es EXATEC o no).
    Encuentra_Matricula(Lista_Hash,Busca_Mat) ? cout << "Si es EXATEC." << endl : cout << "No es EXATEC." << endl;
    //Despliega en un archivo .txt el tiempo de ejecucion del programa.
    Archivo_Salida.open("Tiempo de ejecucion Solucion Tres.txt");
    Archivo_Salida << double(clock()-startTime)/(double)CLOCKS_PER_SEC << " segundos." << endl;
    Archivo_Salida.close();
	system("PAUSE");
	return 0;
}
