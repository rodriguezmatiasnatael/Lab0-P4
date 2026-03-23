#include <iostream>
#include <string>
#include "DTExpe.hpp"
#include "DTFecha.hpp"

DTExpe::DTExpe(std::string codigo, std::string desc, DTFecha f, std::set<std::string> turistas) :  
    codigoReserva(codigo),
    descripcion(desc),
    fecha(f),
    turistas(turistas)
{}

DTExpe::~DTExpe() {}

std::string DTExpe::getCodigoReserva() const {
    return this->codigoReserva;
}

std::string DTExpe::getDescripcion() const {
    return this->descripcion;
}

DTFecha DTExpe::getFecha() const {
    return this->fecha;
}

std::set<std::string> DTExpe::getTuristas() const {
    return this->turistas;
}

std::ostream& operator<<(std::ostream& os, const DTExpe& dt) {
    std::string strImprimir = dt.getCodigoReserva() + 
                            "->" + dt.getDescripcion() + 
                            "(" + dt.getFecha().toString() + ")/";
    
    std::string strTuristas = "";
    for (std::set<std::string>::const_iterator it = dt.getTuristas().begin(); it != dt.getTuristas().end(); ++it) {
        strTuristas = strTuristas + *it + ",";
    };
    if (strTuristas != "") {
        strTuristas.erase(strTuristas.size() - 1);
    };

    os << strImprimir + strTuristas;
    return os;
}