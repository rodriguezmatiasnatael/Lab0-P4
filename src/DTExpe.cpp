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