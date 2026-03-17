#include <iostream>
#include <string>
#include "Alojamiento.hpp"
#include "TipoRegimen.hpp"

Alojamiento::Alojamiento(std::string cod, std::string desc, int precio, DTFecha f, std::string h, TipoRegimen reg, int cant) :
    Experiencia(cod, desc, precio, f), 
    hotel(h),
    regimen(reg),
    cantNoches(cant)
{}

Alojamiento::~Alojamiento() {}

std::string getHotel() {
    return this->hotel;
}

TipoRegimen getRegimen() {
    return this->hotel
}

int getCantNoches() {
    return this->hotel;
}

float Alojamiento::calcularCosto() {
    if (this->regimen == TipoRegimen::AllInclusive) {
        return ((getPrecioBase() + 10) * this->cantNoches);
    } else {
        return (getPrecioBase() * this->cantNoches);
    }
}
