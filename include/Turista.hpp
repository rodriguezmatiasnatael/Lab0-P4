#ifndef TURISTA_HPP
#define TURISTA_HPP

#include <string>
#include <set>
#include "DTFecha.hpp"

class Experiencia; //forward declaration

class Turista {
private:
    std::string ci;
    std::string nombre;
    std::string email;

    std::set<Experiencia*> experiencias; //link a experiencias en las que participa

public:
    //Turista(); No se si es necesario, mientras tanto lo dejo comentado
    Turista(const std::string& ci,const std::string& nombre,const std::string& email);
    ~Turista();

    std::string getCi() const;
    std::string getNombre() const;
    std::string getEmail() const;
    
    void setCi(const std::string& ci);
    void setNombre(const std::string& nombre);
    void setEmail(const std::string& email);

    std::string toString() const;     // Tiene que devolver un string en formato ci->nombre/email

    std::set<std::string> listarExperiencias(const DTFecha& desde, float min, float max) const;

    void agregarExperiencia(Experiencia* e);
    void removerExperiencia(Experiencia* e);
};

#endif