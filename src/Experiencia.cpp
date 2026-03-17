#include <iostream>
#include <string>
#include "Experiencia.h"
#include "Turista.h" // PENSAR SI SE INCLUYE

#include "Experiencia.hpp"

Experiencia::Experiencia(std::string cod, std::string desc, int precio, DTFecha f) 
    : codigoReserva(cod), descripcion(desc), precioBase(precio), fecha(f) {}

Experiencia::~Experiencia() {}


std::string Experiencia::getCodigoReserva() {
    return this->codigoReserva;
}

std::string Experiencia::getDescripcion() {
    return this->descripcion
}

int Experiencia::getPrecioBase() const {
    return this->precioBase;
}

