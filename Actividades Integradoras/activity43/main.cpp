// =========================================================
// File:   main.cpp
// Author: José Miguel Luna Vega
// Date:   24/11/2020
// =========================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include "ugraph.h"

using namespace std;

int main(int argc, char* argv[]) {

  int n, from, to, nFiles = 4;
  ifstream input;
  ofstream output;
  UListGraph<int> *graph[nFiles];
  stringstream file;
  output.open("output.txt");

/*Complejidad del algoritmo completo: O(n^2) ya que depende de cuantos
archivos se lean o grafos se creen y cuantos vertices tiene cada uno de ellos*/

  for(int i = 0; i<nFiles; i++){  //  O(n), siendo n el numero de archivos

    //Se prepara el archivo de entrada a leer
    file << "input";
    file << i+1;
    file << ".txt";
    cout << "Leyendo el archivo: " << file.str() << endl;

    //Se abre el archivo de entrada y se puede crear el grafo
    input.open(file.str());
    input >> n;
    graph[i] = new UListGraph<int>(n);

    //Se leen y agregan las conexiones
    while (true) {
      input >> from >> to;
      if (!from && !to) {
      break;
      }
      graph[i]->addEdge(from, to);
    }

    //Se escribe en el archivo de salida los daros sobre el numero de conexiones
    output << "File: input" << i+1 << ".txt" << endl;
    output << graph[i]->getConnections();      //O(V)
    output << graph[i]->getMaxConnections();   //O(V)
    cout << "..." << endl;

    //Se cierra el archivo de entrada y se borra su nombre para la sig. busqueda
    input.close();
    file.str("");
  }

  cout << "\n¡Listo!, resultados en output.txt " << endl;
  return 0;
}
