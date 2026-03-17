#include <iostream>
#include <string>
#include "EventoCultural.h"
#include "Turista.h"
#include "Experiencia.h"

EventoCultural::EventoCultural(std::string cod, std::string desc, int precio, DTFecha f, std::string ubi, bool cupon) :
    Experiencia(cod, desc, precio, f),
    ubicacion(ubi),
    usoCupon(cupon)
{}

EventoCultural::~EventoCultural() {}

std::string getUbicacion() {
    return this->ubicacion
}

bool getUsoCupon() {
    return this->usoCupon;
}

float EventoCultural::calcularCosto() {
    return 0;
}