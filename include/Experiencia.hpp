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
        std::set<std::string> participantes; //este es el link a Turistas desde Experiencia
    public:
        
    
        Experiencia(std::string codigo, std::string desc, int precio, DTFecha f);
        Experiencia();
        virtual ~Experiencia();
    
        std::string getCodigoReserva() const;
        std::string getDescripcion()const;
        int getPrecioBase() const;
        std::set<Turista*> getParticipantes();
        DTFecha getFecha() const; 
        DTExpe getDT() const;

        void setCodigoReserva(const std::string& codigo); 
        void setDescripcion(const std::string& desc);
        void setPrecioBase(int precio);
        void setFecha(const DTFecha& f);

        virtual float calcularCosto() = 0; //El = 0 obliga a que sea abstracto
};

#endif
