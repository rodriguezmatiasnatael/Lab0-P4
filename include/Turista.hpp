#ifndef TURISTA_HPP
#define TURISTA_HPP

#include <string>
#include <set>
#include <vector>
#include "DTFecha.hpp"

class Experiencia; // Forward declaration para evitar inclusión circular

class Turista {
    private:
        std::string ci;
        std::string nombre;
        std::string email;
        std::vector<Experiencia*> experiencias; // Relación 1..* a *

    public:
        Turista(std::string ci, std::string nombre, std::string email);

        std::string getCI() const; //agregué esto porque lo necesito en Experiencia.cpp

        std::string toString();
        std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
};

#endif
