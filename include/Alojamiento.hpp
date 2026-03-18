#ifndef ALOJAMIENTO_HPP
#define ALOJAMIENTO_HPP

#include "Experiencia.hpp"
#include "TipoRegimen.hpp"

class Alojamiento : public Experiencia {
    private:
        string hotel;
        TipoRegimen regimen;
        int cantNoches;
    public:
        Alojamiento(string, string, int, DTFecha,string, TipoRegimen, int);
        Alojamiento(Alojamiento&);
        ~Alojamiento() override;
        
        string getHotel();
        TipoRegimen getRegimen();
        int getCantNoches();

        void setHotel(string);
        void setRegimen(TipoRegimen);
        void setCantNoches(int);

        //no seria virtual??
        float virtual calcularCosto() override;
};

#endif
