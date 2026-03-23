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

std::ostream& operator<<(std::ostream& os, const DTExpe& dt){
    std::string strTuristas = "";
    if(!dt.getTuristas().empty()){

        const std::set<std::string>& turistas = dt.getTuristas();
        //aca estaba el problema, estaba haciendo muchas llamadas a getTuristas, en cada llamada hacia un getTuristas lo que 
        //hacia todo un set nuevo y daba errores de memoria por reservar mucha memoria
        
        for (std::set<std::string>::const_iterator it = turistas.begin(); it != turistas.end(); ++it){
            strTuristas = strTuristas + (*it) + ",";
        };
        strTuristas.erase(strTuristas.size()-1);
    }
    os <<  dt.getCodigoReserva() + "->" + dt.getDescripcion() + "(" + dt.getFecha().toString() + ")/" + strTuristas;
    return os;
}
