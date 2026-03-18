#include <iostream>
#include <string>
#include "Experiencia.h"
#include "Turista.h" // PENSAR SI SE INCLUYE

#include "Experiencia.hpp"

Experiencia::Experiencia(string cod,string desc, int precio, DTFecha f,set<string> p) {
    codigoReserva = cod;
    descripcion = desc;
    precioBase = pbase;
    fecha = DTFecha(f);
    participantes = p;
}
Experiencia::Experiencia(Experiencia& exp){
    codigoReserva = exp.codigoReserva;
    descripcion = exp.descripcion;
    precioBase = exp.precioBase;
    fecha = DTFecha(exp.fecha);
    participantes = exp.participantes;
}
Experiencia::~Experiencia() {}


string Experiencia::getCodigoReserva() {
    return codigoReserva;
}

string Experiencia::getDescripcion() {
    return descripcion;
}

int Experiencia::getPrecioBase() const {
    return precioBase;
}

DTFecha Experiencia :: getFecha(){
    return fecha;
}

set<string>& Experiencia::getParticipantes(){
    return participantes;
}

void Experiencia :: setCodigoReserva(string cod){
    codigoReserva = cod;
}

void Experiencia :: setDescripcion(string desc){
    descripcion = desc;
}

void Experiencia :: setPrecioBase(int pbase){
    precioBase = pbase;
}

void Experiencia :: setFecha(DTFecha f){
    fecha = DTFecha(f);//se puede hacer esto?
}

void Experiencia::setParticipantes(set<string>& p){
    participantes = p;
}
