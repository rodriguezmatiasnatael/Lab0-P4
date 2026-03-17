#ifndef EXPERIENCIA_HPP
#define EXPERIENCIA_HPP

#include <string>
#include "DTFecha.hpp"
#include "DTExpe.hpp"

class Experiencia {
    private:
        std::string codigoReserva;
        std::string descripcion;
        int precioBase;
        DTFecha fecha;

    public:
        Experiencia(std::string cod, std::string desc, int precio, DTFecha f);
        virtual ~Experiencia();


        std::string getCodigoReserva();
        std::string getDescripcion();
        int getPrecioBase() const;
        virtual DTExpe getDT() const;
        
        virtual float calcularCosto() = 0; 
};

#endif