#ifndef EXPERIENCIA_HPP
#define EXPERIENCIA_HPP

#include <string>
#include "DTFecha.hpp"
#include "DTExpe.hpp"

class Experiencia {
    private:
        string codigoReserva,descripcion;
        int precioBase;
        DTFecha fecha;
        set<string> participantes;
    public:
        Experiencia(string,string, int, DTFecha);
        Experiencia(Experiencia&);
        virtual ~Experiencia();


        string getCodigoReserva();
        string getDescripcion();
        //para que es el const aca?
        int getPrecioBase() const;
        DTFecha getFecha();

        void setCodigoReserva(string);
        void setDescripcion(string);
        void setPrecioBase(int);
        void setFecha(DTFecha);

        virtual DTExpe getDT() const;
        virtual float calcularCosto() = 0; 
};

#endif
