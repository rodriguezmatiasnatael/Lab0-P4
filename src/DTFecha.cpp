#include "DTFecha.hpp"

DTFecha::DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

DTFecha::DTFecha(const DTFecha& f) : dia(f.dia), mes(f.mes), anio(f.anio) {}

DTFecha::~DTFecha() {}

DTFecha& DTFecha::operator=(const DTFecha& f) {
    if (this != &f) { 
        dia = f.dia;
        mes = f.mes;
        anio = f.anio;
    }
    return *this;
}

bool DTFecha::operator>=(const DTFecha& otra) const {
    if (anio > otra.anio) {
        return true;
    } else if (anio == otra.anio) {
        if (mes > otra.mes) {
            return true;
        } else if (mes == otra.mes) {
            return dia >= otra.dia;
        }
    }
    return false;
}
