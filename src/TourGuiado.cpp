#include <iostream>
#include <string>
#include "TourGuiado.h"
#include "Experiencia.h"

using namespace std;

TourGuiado::TourGuiado(string cod, string desc, int precio, DTFecha f, string ag, const set<string>& lugares,int cantL,int cantT) : Experiencia(cod, desc, precio, f){
    agencia = ag;
    lugaresVisitados = lugares;
    cantLugares = cantL;
    cantTuristas = cantT;
}

TourGuiado::~TourGuiado() {}

string TourGuiado::getAgencia() {
    return agencia;
}

set<string>& TourGuiado::getLugaresVisitados() {
    return lugaresVisitados;
}

int TourGuiado::getCantLugares(){
    return cantLugares;
}

int TourGuiado::getCantTuristas(){
    return cantTuristas;
}

void TourGuiado::setAgencia(string a){
    agencia = a;
}
void TourGuiado::setLugaresVisitados(const set<string>& lugares){
    lugaresVisitados = lugares;
}

void TourGuiado::setCantLugares(int cant){
    cantLugares = cant;
}
void TourGuiado::setCantTuristas(int cant){
    cantTuristas = cant;
}

float TourGuiado :: calcularCosto(){
    return ((getPrecioBase()+2)*cantLugares*cantTuristas*;
}
