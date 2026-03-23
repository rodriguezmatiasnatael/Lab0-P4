#include <iostream>
#include <list>
#include <map>

#include "include/Experiencia.hpp"
#include "include/Alojamiento.hpp"
#include "include/EventoCultural.hpp"
#include "include/DTFecha.hpp"
#include "include/DTExpe.hpp"
#include "include/Turista.hpp"
#include "include/TipoRegimen.hpp"
#include "include/TourGuiado.hpp"


std::list<Experiencia*> experiencias;
std::map<std::string, Experiencia*> map_experiencias;

std::list<Turista*> turistas;
std::map<std::string, Turista*> map_turistas;

void coleccion_guardarExperiencia(Experiencia* exp){
	experiencias.push_back(exp);
	std::pair<std::string, Experiencia*> entry(exp->getCodigoReserva(), exp);
    map_experiencias.insert(entry);
}
void coleccion_eliminarExperiencia(Experiencia* exp){
	experiencias.remove(exp);
	map_experiencias.erase(exp->getCodigoReserva());
}

void coleccion_guardarTurista(Turista* tur){
	turistas.push_back(tur);
	std::pair<std::string, Turista*> entry(tur->getCi(), tur);
    map_turistas.insert(entry);
}

Turista* coleccion_getTurista(std::string ci){
	return map_turistas[ci];
}

Experiencia* coleccion_getExperiencia(std::string codigoReserva){
	return map_experiencias[codigoReserva];
}

void parte_a(){
    DTFecha fecha1 = DTFecha(18, 5, 2020);
    Experiencia* alojamiento1 = new Alojamiento("ALX5489", "Hotel moderno", 30, fecha1, "Hotel Lindorf", AllInclusive, 5);
    coleccion_guardarExperiencia(alojamiento1);

    DTFecha fecha2 = DTFecha(10, 2, 2025);
    Experiencia* alojamiento2 = new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, fecha2, "Hotel SeaView", MediaPension, 15);
    coleccion_guardarExperiencia(alojamiento2);
}

void parte_b(){
    DTFecha fecha3 = DTFecha(29, 8, 2024);
    
    std::set<std::string> Lugares1;
    Lugares1.insert("Plaza Independencia");
    Lugares1.insert("Plaza Matriz");
    Experiencia* tour1 = new TourGuiado("TGO4657", "Plazas de Montevideo", 10, fecha3, "Paseos SA", Lugares1);
    coleccion_guardarExperiencia(tour1);

    std::set<std::string> Lugares2;
    Lugares2.insert("Puerta de la Ciudadela");
    Lugares2.insert("Mausoleo");
    Lugares2.insert("Cabildo");
    Lugares2.insert("Palacio Salvo");
    Experiencia* tour2 = new TourGuiado("TGR3257", "Puntos emblematicos", 5, fecha3, "Recorre", Lugares2);
    coleccion_guardarExperiencia(tour2);
}

void parte_c(){
    DTFecha fecha4 = DTFecha(29, 10, 2025);
    Experiencia* evento1 = new EventoCultural("ECP1346", "Danza en el Solis", 10, fecha4, "Teatro Solis", true);
    coleccion_guardarExperiencia(evento1);
}

void parte_d(){
	std::list<Experiencia*>::iterator it;
	for (it = experiencias.begin(); it != experiencias.end(); ++it) {
		if(*it != NULL){
    		std::cout << (*it)->getDT() << std::endl;
		}
	}
}

void parte_e() {
    Turista* t1 = new Turista("4.951.278-9", "Vanesa Castro", "vcastro.uy@servidor.net");
    coleccion_guardarTurista(t1);
    Turista* t2 = new Turista("1.535.442-0", "Karen Santos", "karen.s89@internet.uy");
    coleccion_guardarTurista(t2);
}

void parte_f() {
    std::list<Turista*>::iterator it;
    for (it = turistas.begin(); it != turistas.end(); ++it) {
        std::cout << (*it)->toString() << std::endl;
    }
    
}

void parte_g() {
    Turista* vanesa = coleccion_getTurista("4.951.278-9");
    Turista* karen = coleccion_getTurista("1.535.442-0");
    
    Experiencia* hotelModem = coleccion_getExperiencia("ALX5489");
    Experiencia* hotelSea = coleccion_getExperiencia("ALJ4789");
    Experiencia* tourPlazas = coleccion_getExperiencia("TGO4657");
    Experiencia* tourPuntos = coleccion_getExperiencia("TGR3257");
    Experiencia* eventoSolis = coleccion_getExperiencia("ECP1346");

    hotelModem->agregarParticipante(vanesa);

	vanesa->agregarExperiencia(hotelModem);

    hotelSea->agregarParticipante(vanesa);
    vanesa->agregarExperiencia(hotelSea);
	
	tourPuntos->agregarParticipante(vanesa);
	vanesa->agregarExperiencia(tourPuntos);

    eventoSolis->agregarParticipante(vanesa);
	vanesa->agregarExperiencia(eventoSolis);

    tourPlazas->agregarParticipante(karen);
	karen->agregarExperiencia(tourPlazas);

	tourPuntos->agregarParticipante(karen);
	karen->agregarExperiencia(tourPuntos);
}

void parte_h() {
    Turista* vanesa = coleccion_getTurista("4.951.278-9");
    if (vanesa != NULL) {
        DTFecha fechaFiltro = DTFecha(10, 12, 2023);
        std::set<std::string> resultados = vanesa->listarExperiencias(fechaFiltro, 0, 1000);
        std::set<std::string>::iterator it;
        for (it = resultados.begin(); it != resultados.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
}

void parte_i(){
	Experiencia* tourPuntos = coleccion_getExperiencia("TGR3257");
	coleccion_eliminarExperiencia(tourPuntos);
    delete tourPuntos;
    tourPuntos = NULL;
}

void parte_j(){
	Turista* karen = coleccion_getTurista("1.535.442-0");
    if (karen != NULL) {
        DTFecha fechaFiltro = DTFecha(10, 10, 2020);
        std::set<std::string> resultados = karen->listarExperiencias(fechaFiltro, 0, 1000);
        std::set<std::string>::iterator it;
        for (it = resultados.begin(); it != resultados.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
}

void parte_k(){
	std::list<Experiencia*>::iterator it;
	for (it = experiencias.begin(); it != experiencias.end(); ++it) {
    	std::cout << (*it)->getDT() << std::endl;
	}
}

void cleanUp(){
}

int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}
