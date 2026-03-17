#ifndef DTEXPE_HPP
#define DTEXPE_HPP

#include <string>
#include <set>
#include "DTFecha.hpp"

struct DTExpe {
    std::string codigoReserva;
    std::string descripcion;
    DTFecha fecha;
    std::set<std::string> turistas;
};

#endif