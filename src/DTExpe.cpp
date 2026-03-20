#include <iostream>
#include <string>
#include "../include/DTExpe.hpp"
#include "../include/DTFecha.hpp"

DTExpe::DTExpe(std::string codigo, std::string desc, DTFecha f, std::set<std::string> turistas) :  
    codigoReserva(codigo),
    descripcion(desc),
    fecha(f),
    turistas(turistas)
{}

DTExpe::~DTExpe() {}

