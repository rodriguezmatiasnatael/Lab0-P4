#include "Turista.hpp"
#include "Experiencia.hpp"

//Turista::Turista(); No se si es necesario para algo, mientras tanto lo dejo comentado

Turista::Turista(const std::string& ci,const std::string& nombre,const std::string& email){
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}

Turista::~Turista() {
    for(std::set<Experiencia*>::iterator it = experiencias.begin(); it != experiencias.end(); ++it) {
        (*it)->eliminarParticipante(this); 
    }
    experiencias.clear();
}

std::string Turista::getCi() const{
    return ci;
}

std::string Turista::getNombre() const{
    return nombre;
}
std::string Turista::getEmail() const{
    return email;
}


void Turista::setCi(const std::string& ci){
    this->ci = ci;
}

void Turista::setNombre(const std::string& nombre){
    this->nombre = nombre;
    }

void Turista::setEmail(const std::string& email){
    this->email = email;
}

std::string Turista::toString() const{
    return ci+"->"+nombre+"/"+email;
}

std::set<std::string> Turista::listarExperiencias(const DTFecha& desde, float min, float max) const{
    std::set<std::string> res;
    for(std::set<Experiencia*>::const_iterator it = experiencias.begin(); it != experiencias.end(); ++it){
        Experiencia* e = *it;
        if(e->getFecha() >= desde){
            float costo = e->calcularCosto();
            if(costo >= min && costo <= max){
                res.insert(e->getCodigoReserva());
            }
        }
    }
    return res;
}

void Turista::agregarExperiencia(Experiencia* e){
    experiencias.insert(e);
}

void Turista::removerExperiencia(Experiencia* e) {
    experiencias.erase(e);
}

