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

//liberamos la referencia de experiencia en todos los turistas que la contengan
Experiencia::~Experiencia() {
    std::set<Turista*>::iterator it;
    for(it = participantes.begin(); it != participantes.end(); ++it){
        (*it)->removerExperiencia(this);
    }
}

int Experiencia::getPrecioBase() const {
    return precioBase;
}

std::string Experiencia::getCodigoReserva() const{
    return codigoReserva;
}

const DTFecha& Experiencia :: getFecha() const{
    return fecha;
}

std::set<Turista*> Experiencia::getParticipantes(){
    return participantes;
}

DTExpe Experiencia::getDT() const {
    std::set<std::string> nombresTuristas;
    for (std::set<Turista*>::const_iterator it = participantes.begin(); it != participantes.end(); ++it) {
        if (*it != NULL) { // <--- Verificación de seguridad
            nombresTuristas.insert((*it)->getNombre());
        }
    }
    return DTExpe(this->codigoReserva, this->descripcion, this->fecha, nombresTuristas);
}

void Experiencia::eliminarParticipante(Turista* t) {
    this->participantes.erase(t);
}

void Experiencia::agregarParticipante(Turista * t) {
    participantes.insert(t);
}
