#ifndef ALOJAMIENTO_HPP
#define ALOJAMIENTO_HPP

#include "Experiencia.hpp"
#include "TipoRegimen.hpp"

class Alojamiento : public Experiencia {
    private:
        std::string hotel;
        TipoRegimen regimen;
        int cantNoches;
    public:
        Alojamiento(std::string cod, std::string desc, int precio, DTFecha f, std::string h, TipoRegimen reg, int cant);
        ~Alojamiento() override;
        
        std::string getHotel();
        TipoRegimen getRegimen();
        int getCantNoches();
        
        float calcularCosto() override;
};

#endif