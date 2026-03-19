#include <iostream>
#include <string>
#include "Experiencia.hpp"
#include "Turista.hpp" // PENSAR SI SE INCLUYE

#include "Experiencia.hpp"

Experiencia::Experiencia(std::string cod, std::string desc, int precio, DTFecha f) {
    codigoReserva = cod;
    descripcion = desc;
    precioBase = precioBase;
    fecha = DTFecha(f);
}
/*
Experiencia::Experiencia(Experiencia& exp){
    codigoReserva = exp.codigoReserva;
    descripcion = exp.descripcion;
    precioBase = exp.precioBase;
    fecha = DTFecha(exp.fecha);
    participantes = exp.participantes;
}*/

Experiencia::~Experiencia() {}


std::string Experiencia::getCodigoReserva() const{
    return codigoReserva;
}

std::string Experiencia::getDescripcion() const{
    return descripcion;
}

int Experiencia::getPrecioBase() const {
    return precioBase;
}

DTFecha Experiencia :: getFecha() const{
    return fecha;
}

/*set<string>& Experiencia::getParticipantes(){
    return participantes;
} 
Puse en el hpp por que creo que no va aca*/

void Experiencia::setCodigoReserva(const std::string& codigo){
    codigoReserva = codigo;
}

void Experiencia :: setDescripcion(const std::string& desc){
    descripcion = desc;
}

void Experiencia :: setPrecioBase(int pbase){
    precioBase = pbase;
}

void Experiencia :: setFecha(const DTFecha& f){
    fecha = DTFecha(f);//se puede hacer esto?
}

/*void Experiencia::setParticipantes(set<string>& p){
    participantes = p;
}
En el hpp puse por que creo que no iria    
*/
