#include <iostream>
#include <string>
#include "Turista.h"

using namespace std;

Turista :: Turista(string ci,string nombre,string email,Experiencia* experiencias){
  this->ci = ci;
  this->nombre = nombre;
  this->email = email;
  this->experiencias = experiencias;

}

string Turista :: getCi(){
  return ci;
}

string Turista :: getNombre(){
  return nombre;
}

string Turista :: getEmail(){
  return email;
}

void Turista :: setCi(string ci){
  this->ci = ci;
}

void Turista :: setNombre(string nombre){
  this->nombre = nombre;
}

void Turista :: setEmail(string email){
  this->email = email;
}

string Turista :: toString(){
  string sCi = getCi();
  string sflecha = "->";
  string sNom = getNombre();  
  string sBarra = "/";
  string sEmail = getEmail();
  string total = sCi + sflecha + sNom + sBarra + sEmail;
                                        //VER SI VA EL . AL FINAL DE LA CADENA
  return total;
}
