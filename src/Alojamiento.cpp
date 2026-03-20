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

float Alojamiento::calcularCosto() {
    if (regimen == TipoRegimen::AllInclusive) {
        return getPrecioBase()*cantNoches + 10*cantNoches;
    }
    else{
        return getPrecioBase() * cantNoches;
    }
}
