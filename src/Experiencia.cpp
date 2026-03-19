#include <iostream>
#include <string>
#include "Experiencia.hpp"
#include "Turista.hpp" // PENSAR SI SE INCLUYE

#include "Experiencia.hpp"

Experiencia::Experiencia(std::string codigo, std::string desc, int precio, DTFecha f, std::set<std::string> p) 
    : codigoReserva(codigo), 
      descripcion(desc), 
      precioBase(precio), 
      fecha(f),
      participantes(p)
{}

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

set<Turista*>& Experiencia::getParticipantes(){
    return participantes;
}

DTExpe Experiencia::getDT() {
    return DTExpe(codigoReserva, descripcion, precioBase, fecha, participantes);
}

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
