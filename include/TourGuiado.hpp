#ifndef TOURGUIADO_HPP
#define TOURGUIADO_HPP

#include <set>
#include "Experiencia.hpp"

class TourGuiado : public Experiencia {
    private:
        std::string agencia;
        std::set<std::string> lugaresVisitados;
    public:
        TourGuiado(std::string cod, std::string desc, int precio, DTFecha f, std::string ag, std::set<std::string> lugares);
        ~TourGuiado() override;

        std::string getAgencia();
        std::<std::string> getLugaresVisitados();

        float calcularCosto() override;
};

#endif
