#include <iostream>
#include <string>
#include "Alojamiento.hpp"
#include "TipoRegimen.hpp"

Alojamiento::Alojamiento(string cod,string desc, int precio, DTFecha f, string h, TipoRegimen reg, int cant) : Experiencia(cod, desc, precio, f){
    hotel = h;
    regimen = reg;
    cantNoches = cant;
}

Alojamiento::~Alojamiento() {}

float Alojamiento::calcularCosto() {
    if (regimen == TipoRegimen::AllInclusive) {
        return getPrecioBase()*cantNoches + 10*cantNoches;
    }
    else{
        return getPrecioBase() * cantNoches;
    }
}
