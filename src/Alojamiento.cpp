#include <iostream>
#include <string>
#include "Alojamiento.hpp"
#include "TipoRegimen.hpp"

Alojamiento::Alojamiento(string cod,string desc, int precio, DTFecha f, string h, TipoRegimen reg, int cant) : Experiencia(cod, desc, precio, f){
    hotel = h;
    regimen = reg;
    cantNoches = cant;
}
Alojamiento :: Alojamiento(Alojamiento& a): Experiencia(a.getCodigoReserva(),a.getDescripcion(),a.getPrecioBase(),a.getFecha()){
    hotel = a.hotel;
    regimen = a.regimen;
    cantNoches = a.cantNoches;
}

Alojamiento::~Alojamiento() {}

string Alojamiento::getHotel() {
    return hotel;
}

TipoRegimen Alojamiento::getRegimen() {
    return regimen;
}

int Alojamiento::getCantNoches() {
    return cantNoches;
}

void Alojamiento::setHotel(string h){
    hotel = h;
}

void Alojamiento::setRegimen(TipoRegimen r){
    regimen = r;
}

void Alojamiento::setCantNoches(int cant){
    cantNoches = cant;
}


float Alojamiento::calcularCosto() {
    if (regimen == TipoRegimen::AllInclusive) {
        return getPrecioBase()*cantNoches + 10*cantNoches;
    }
    else{
        return getPrecioBase() * cantNoches;
    }
}
