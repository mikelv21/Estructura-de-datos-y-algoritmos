// =================================================================
//
// File: main.cpp
// Author: José Miguel Luna Vega A01706424
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include "search.h"
#include "merge.h"
#include "registro.h"

using namespace std;

int main(int argc, char* argv[]) {

 //Indicaciones iniciales (declaracion de variables, funciones, archivos, vectores)
  void menu();
  int mesI, mesF, limiteInferior, limiteSuperior;
  float fechaI, fechaF, diaI, diaF;
  vector<Registro> registros;
  vector<float> fechas;
	ifstream input;
	ofstream output;
  string nameIn = "bitacora.txt";
  string nameOut = "output.txt";
	string line;

  //Lectura de datos de un archivo .txt
	input.open(nameIn);
	if (input.is_open()) {
		while (getline(input, line)) {
			registros.push_back(Registro(line));   // emplace_back
		}
	}

  //Ordenamiento de todos los registros por fecha (mes/dia)
	for(int j=0; j<registros.size();j++){
		registros[j].separarDatos();
	}
  mergeSort(registros);

  //Escritura en un archivo de todos los registros ordenados
  output.open(nameOut);
  if (output.is_open()) {
    for (int j = 0; j < registros.size(); j++) {
      output << registros[j].get_info() << "\n";
      fechas.push_back(registros[j].get_fecha());
      }
    }

  //Busqueda para el usuario de registros delimitados por fechas
  menu();
  cout << "\nDia inicial: ";
  cin >> diaI;
  cout << "Mes inicial: ";
  cin >> mesI;
  cout << "Dia final: ";
  cin >> diaF;
  cout << "Mes final: ";
  cin >> mesF;

  fechaI = mesI + diaI/100;
  fechaF = mesF + diaF/100;

  limiteInferior = sequentialSearch(fechas,fechaI);
  limiteSuperior = sequentialSearchReverse(fechas,fechaF);

  if(limiteInferior != -1 && limiteSuperior !=-1){
      cout<<"\nLos registros encontrados son: \n\n";
      for(int j = limiteInferior; j<= limiteSuperior; j++){
      cout<<registros[j].get_info()<<endl;
      }
  }
  else {
    cout<<"\nERROR: Alguna fecha introducida no tiene un registro correspondiente";
    cout<<"\n       Intente de nuevo \n";
  }

  return 0;
}

void menu(){
  cout<<"\n    ================   Bienvenido a la bitacora   ===============\n\n";
  cout<<" Para buscar los registros entre un rango de fechas desde el 1 de Junio \n";
  cout<<"             al 30 de Octubre, ingresa los siguientes datos: \n\n";
  cout<<"  NOTA: Para el día ingrese un número entero del 1 a 31 y para el mes \n";
  cout<<"  el número entero correspondiente a este. Por ejemplo, para el 10 de \n";
  cout<<"           Sepriembre, la entrada debe ser dia '10' y mes '9'\n";
}
