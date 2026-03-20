#include <iostream>
#include <string>
#include "Experiencia.hpp"
#include "Turista.hpp" // PENSAR SI SE INCLUYE
#include "DTExpe.hpp"
#include "Experiencia.hpp"

Experiencia::Experiencia(std::string codigo, std::string desc, int precio, DTFecha f) :
    codigoReserva(codigo), 
    descripcion(desc), 
    precioBase(precio), 
    fecha(f)
{}

Experiencia::~Experiencia() {}

int Experiencia::getPrecioBase() const {
    return precioBase;
}

const DTFecha& Experiencia::getFecha() const {
    return fecha;
}

std::set<Turista*> Experiencia::getParticipantes(){
    return participantes;
}

DTExpe Experiencia::getDT() const {
    std::set<std::string> turistas;
    for (Turista* t : participantes) {
        turistas.insert(t->getCI());
    };
    return DTExpe(codigoReserva, descripcion, fecha, turistas);
}

bool Experiencia::eliminarParticipante(Turista * t) {
    if (t == nullptr) {
        return false;
    } else {
        return participantes.erase(t) > 0;
    }
}

bool Experiencia::agregarParticipante(Turista * t) {
    if (t == nullptr) {
        return false;
    } else {
        return participantes.insert(t).second;
    }
}

/*void Experiencia::setParticipantes(set<string>& p){
    participantes = p;
}
En el hpp puse por que creo que no iria    
*/
