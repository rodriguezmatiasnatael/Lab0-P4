#ifndef TOURGUIADO_HPP
#define TOURGUIADO_HPP

#include <set>
#include "Experiencia.hpp"

class TourGuiado : public Experiencia {
    private:
        std::string agencia;
        std::set<std::string> lugaresVisitados;
    public:
        TourGuiado(std::string, std::string, int, DTFecha, std::string, std::set<std::string>);
        ~TourGuiado();
        
        float calcularCosto();
};

#endif
