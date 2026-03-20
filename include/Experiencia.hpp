#ifndef EXPERIENCIA_HPP
#define EXPERIENCIA_HPP

#include <string>
#include <set>
#include "DTFecha.hpp"
#include "DTExpe.hpp"

class Turista; //Le dice al codigo que clase Turista existe, es el forward declarations (hay que hacer lo mismo en Turista)

class Experiencia{
    private:
        std::string codigoReserva;
        std::string descripcion;
        int precioBase;
        DTFecha fecha;
        std::set<Turista*> participantes; //este es el link a Turistas desde Experiencia
    public:
    
        Experiencia(std::string codigo, std::string desc, int precio, DTFecha f);
        virtual ~Experiencia();
    
        int getPrecioBase() const;
        std::string getCodigoReserva() const;
        std::set<Turista*> getParticipantes();
        const DTFecha& getFecha() const;
        DTExpe getDT() const;

        bool eliminarParticipante(Turista* t);
        bool agregarParticipante(Turista* t);

        virtual float calcularCosto() = 0; //El = 0 obliga a que sea abstracto

};

#endif
