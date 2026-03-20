#include <iostream>
#include <string>
#include "EventoCultural.hpp"
#include "Turista.hpp"
#include "Experiencia.hpp"

EventoCultural::EventoCultural(std::string cod, std::string desc, int precio, DTFecha f, std::string ubi, bool cupon) :
    Experiencia(cod, desc, precio, f),
    ubicacion(ubi),
    usoCupon(cupon)
{}

EventoCultural::~EventoCultural() {}

float EventoCultural::calcularCosto() {
    if (usoCupon){
        //preciobase*cantidadturistas - 5*cantidadturistas;
        return getPrecioBase()*getParticipantes().size() - 5*getParticipantes().size();
    } 
    else {
        return getPrecioBase()*getParticipantes().size();
    }
}
