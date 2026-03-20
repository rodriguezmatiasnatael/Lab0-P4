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
        Alojamiento(std::string, std::string, int, DTFecha, std::string, TipoRegimen, int);
        ~Alojamiento() override;
        
        //no seria virtual??
        float virtual calcularCosto() override;
};

#endif
