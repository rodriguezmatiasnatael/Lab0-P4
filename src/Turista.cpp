#include <iostream>
#include <string>
#include <set>
#include "../include/Turista.hpp"

Turista :: Turista (std::string ci, std::string nombre, std::string email) : 
  ci(ci),
  nombre(nombre),
  email(email)
{}

std::string Turista :: getCI () const {
  return ci;
}

std::string Turista :: toString(){
  std::string sCi = ci;
  std::string sflecha = "->";
  std::string sNom = nombre;  
  std::string sBarra = "/";
  std::string sEmail = email;
  std::string total = sCi + sflecha + sNom + sBarra + sEmail;
                                        //VER SI VA EL . AL FINAL DE LA CADENA
  return total;
}
