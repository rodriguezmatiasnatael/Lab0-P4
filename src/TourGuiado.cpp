#include <iostream>
#include <string>
#include "TourGuiado.hpp"
#include "Experiencia.hpp"

using namespace std;

TourGuiado::TourGuiado(std::string cod,std::string desc, int precio, DTFecha f, std::string ag,std::set<std::string> lugares,int cantL,int cantT) : Experiencia(cod, desc, precio, f){
    agencia = ag;
    lugaresVisitados = lugares;
}


TourGuiado::~TourGuiado() {}


float TourGuiado :: calcularCosto(){
    //preciobase + 2.cantlugares.cantturistas
    return (getPrecioBase() + (2*lugaresVisitados.size()*getParticipantes().size()));
}
