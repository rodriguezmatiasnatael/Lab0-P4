#include <iostream>
#include <string>
#include "TourGuiado.h"
#include "Experiencia.h"

using namespace std;

TourGuiado::TourGuiado(std::string cod, std::string desc, int precio, DTFecha f, std::string ag, const std::set<std::string>& lugares) : 
    Experiencia(cod, desc, precio, f),
    agencia(ag),
    lugaresVisitados(lugares)
{}

TourGuiado::~TourGuiado() {}

std::string getAgencia() {
    return this->agencia
}

std::set<std::string> getLugaresVisitados() {
    return this->lugaresVisitados;
}

float TourGuiado :: calcularCosto(){
    return 0;
}
