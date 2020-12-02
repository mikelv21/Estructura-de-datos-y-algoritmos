// =================================================================
//
// File: registro.h
// Author: José Miguel Luna Vega A01706424
//
// =================================================================
#ifndef REGISTRO_H
#define REGISTRO_H
#include<iostream>
#include<vector>
#include<stdlib.h>
#include"utility.h"
using namespace std;

class Registro{

  private:

    string info;
    string dia;
    string mes;
    string hora;
    string mensaje;
    float fecha;
    int get_mes();

  public:

      int numAccesos;
      string ip;
      //Constructor por default
      Registro():info(""),fecha(0.0),dia(""),mes(""),hora(""),ip(""),mensaje(""),
      numAccesos(0){};

      //Constructor parametrizado
      Registro(string informacion): info(informacion), mensaje(""){};

      //Funciones
      void separarDatos();
      string get_info();
      string get_ip();
      float get_fecha();
};

void Registro::separarDatos(){

  vector<string> aux;
  aux = split(info,' ');
  mes = aux[0];
  dia = aux[1];
  hora = aux[2];
  ip = aux[3];

  for(int i=4; i<aux.size();i++){
    mensaje = mensaje + aux[i]+ " ";
  }

}

int Registro::get_mes(){
  if(mes=="Jan"){
    return 1;
  }
  else if(mes=="Feb"){
    return 2;
  }
  else if(mes=="Mar"){
    return 3;
  }
  else if(mes=="Apr"){
    return 4;
  }
  else if(mes=="May"){
    return 5;
  }
  else if(mes=="Jun"){
    return 6;
  }
  else if(mes=="Jul"){
    return 7;
  }
  else if(mes=="Aug"){
    return 8;
  }
  else if(mes=="Sep"){
    return 9;
  }
  else if(mes=="Oct"){
    return 10;
  }
  else if(mes=="Nov"){
    return 11;
  }
  else if(mes=="Dec"){
    return 12;
  }
  else{
    return -1;
  }
}

string Registro::get_info(){
  return info;
}

string Registro::get_ip(){
  return ip;
}

float Registro::get_fecha(){
  return get_mes() + stof(dia)/100;
}

#endif /*REGISTRO_H*/
