#ifndef EVENTOCULTURAL_HPP
#define EVENTOCULTURAL_HPP

#include "Experiencia.hpp"

class EventoCultural : public Experiencia {
    private:
        std::string ubicacion;
        bool usoCupon;
    public:
        EventoCultural(std::string cod, std::string desc, int precio, DTFecha f, std::string ubi, bool cupon);
        ~EventoCultural() override;

        std::string getUbicacion();
        bool getUsoCupon();
        
        float calcularCosto() override;
};

#endif