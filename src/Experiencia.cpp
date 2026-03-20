#include <iostream>
#include <string>
#include "Experiencia.hpp"
#include "Turista.hpp" // PENSAR SI SE INCLUYE
#include "DTExpe.hpp"
#include "Experiencia.hpp"

Experiencia::Experiencia(std::string codigo, std::string desc, int precio, DTFecha f, std::set<std::string> p) 
    : codigoReserva(codigo), 
      descripcion(desc), 
      precioBase(precio), 
      fecha(f),
      participantes(p)
{}

Experiencia::~Experiencia() {}

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

bool eliminarParticipante(Turista * t) {
    if (t == nullptr) {
        return false
    } else {
        return participantes.erase(t) > 0;
    }
}

bool agregarParticipante(Turista * t) {
    if (t == nullptr) {
        return false
    } else {
        return turistas.insert(t).second;
    }
}

/*void Experiencia::setParticipantes(set<string>& p){
    participantes = p;
}
En el hpp puse por que creo que no iria    
*/
