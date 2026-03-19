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
        Experiencia();
        Experiencia(std::string codigo, std::string desc, int precio, DTFecha f);
        virtual ~Experiencia();
    
        std::string getCodigoReserva() const;
        std::string getDescripcion()const;
        int getPrecioBase() const; //el const es una buena practica, le dice al codigo que no vas a modificar (es un get) si modificaras algo desde aca te avisa al compilar
        DTFecha getFecha() const; 
        //entiendo que no es necesario el get de participantes, porque la letra define la participación como un pseudo-atributo que se gestiona mediante agregarParticipante y la información se expone únicamente a través del DTExpe  

        void setCodigoReserva(const std::string& codigo); 
        void setDescripcion(const std::string& desc);
        void setPrecioBase(int precio);
        void setFecha(const DTFecha& f);
        //no lleva set de participantes, por lo mismo que el get


        virtual DTExpe getDT() const;
        virtual float calcularCosto() = 0; //El = 0 obliga a que sea abstracto

        void agregarParticipante(Turista* t);//Para linkear Turistas a Experiencia
        void eliminarParticipante(Turista* t);
};

#endif
