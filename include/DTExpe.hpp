#ifndef DTEXPE_HPP
#define DTEXPE_HPP

#include <string>
#include <set>
#include <iostream>
#include "DTFecha.hpp"

class DTExpe {
private:
    std::string codigoReserva;
    std::string descripcion;
    DTFecha fecha;
    std::set<std::string> turistas;

public:
    DTExpe(std::string codigo, std::string desc, DTFecha f, std::set<std::string> turistas);
    DTExpe();
    ~DTExpe();

    std::string getCodigoReserva() const;
    std::string getDescripcion() const;
    DTFecha getFecha() const;
    std::set<std::string> getTuristas() const;

};

std::ostream& operator<<(std::ostream& os, const DTExpe& dt);

#endif