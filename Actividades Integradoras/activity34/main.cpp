// =================================================================
//
// File: main.cpp
// Author: José Miguel Luna Vega A01706424
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "splay.h"
#include "registro.h"

using namespace std;

int main(int argc, char* argv[]) {

  //Variables
  vector<Registro> registros;
  SplayTree splay;
	ifstream input;
	ofstream output;
  string nameInput = "bitacora.txt";
	string line;

  //Lectura de datos de un archivo .txt
	input.open(nameInput);
	if (input.is_open()) {
		while (getline(input, line)) {
			registros.push_back(Registro(line));
		}
	}

  //Se agregan a un SplayTree cada uno de los registros
	for(int j=0; j<registros.size();j++){
		registros[j].separarDatos();
    splay.add(registros[j]);
	}

  cout<<"Los 5 accesos mas recientes son: \n";
  cout<< splay.byLevel();
  cout<< "\n";

  return 0;
}
