/*
Mauricio Iván Cortés García
A00816689
Análisis y Diseño de Algoritmos
Prof. Roman Martinez
Tarea 2
Solución 2
SolucionDos.cpp
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

/*
Nombre: BusquedaBinaria.
Entradas: Vector_Mats(vector<int>), Busca_Mats(int).
Salidas: Booleano.
Función: Aplicar la busqueda binaria a un vector con las matrículas y regresar true si la encuentra y false si no la encuentra.
*/
bool BusquedaBinaria(vector<int> Vector_Mats, int Busca_Mats)
{
    int Central, Bajo, Valor_Central, Largo, Alto;
    Bajo=0;
    Largo=Vector_Mats.size();
    Alto=Largo-1;
    while(Bajo<=Alto)
    {
        Central=(Bajo+Alto)/2;
        Valor_Central = Vector_Mats[Central];
        if(Busca_Mats==Valor_Central)
            return true;
        else if(Busca_Mats<Valor_Central)
            Alto=Central-1;
        else
            Bajo=Central+1;
    }
    return false;
}

int main()
{
    int Matriculas, Busca_Mat;
    vector <int> Vector_Mats;
    ifstream Archivo_Entrada;
    ofstream Archivo_Salida;

    //Pregunta al usuario por la matrícula a buscar en el vector de matrículas y lo almacena en Busca_Mat.
	cout << "Que matricula deseas buscar?" << endl;
	cin >> Busca_Mat;

    clock_t startTime = clock();
	Archivo_Entrada.open("Archivo_Matriculas.txt");//Abre el archivo.
	while(!Archivo_Entrada.eof())//Recorre el archivo hasta que se acaben los datos.
	{
	    //Leer los datos del archivo y almacenarlos en el vector Vector_Mats.
		Archivo_Entrada >> Matriculas;
		Vector_Mats.push_back(Matriculas);
	}
	sort(Vector_Mats.begin(), Vector_Mats.end());//Se aplica el sort de STL al Vector para ordenar las matrículas de menor a mayor.

    //Si la función BusquedaBinaria regresa true, la matrícula si es de un EXATEC, de lo contrario no lo es.
    BusquedaBinaria(Vector_Mats, Busca_Mat) ? cout << "Si es EXATEC." << endl : cout << "No es EXATEC." << endl;
    Archivo_Entrada.close();//Se cierra el archivo de matriculas.
    //Despliega en un archivo .txt el tiempo de ejecucion del programa.
    Archivo_Salida.open("Tiempo de ejecucion Solucion Dos.txt");
    Archivo_Salida << double(clock()-startTime)/(double)CLOCKS_PER_SEC << " segundos." << endl;
    Archivo_Salida.close();
    system("PAUSE");
    return 0;
}
