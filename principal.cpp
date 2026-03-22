
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


// std::list<Experiencia*> experiencias;
// std::map<std::string, Experiencia*> map_experiencias;

// std::list<Turista*> turistas;
// std::map<std::string, Turista*> map_turistas;

// void coleccion_guardarExperiencia(Experiencia* exp){
// 	experiencias.push_back(exp);
// 	std::pair<std::string, Experiencia*> entry(exp->getCodigoReserva(), exp);
//     map_experiencias.insert(entry);
// }
// void coleccion_eliminarExperiencia(Experiencia* exp){
// 	experiencias.remove(exp);
// 	map_experiencias.erase(exp->getCodigoReserva());
// }

// void coleccion_guardarTurista(Turista* tur){
// 	turistas.push_back(tur);
// 	std::pair<std::string, Turista*> entry(tur->getCi(), tur);
//     map_turistas.insert(entry);
// }

// Turista* coleccion_getTurista(std::string ci){
// 	return map_turistas[ci];
// }

// Experiencia* coleccion_getExperiencia(std::string codigoReserva){
// 	return map_experiencias[codigoReserva];
// }

std::list<Experiencia*> listaExp; ///esta lista contiene las distintas experiencias que se crean en a, b y c para mostrarlas en d
std::list<Turista*> listaTur; // esta Lista contiene los turistas

Turista* buscarTur(std::string ci) {  ///Esta funcion busca al turista en la lista
    std:: list<Turista*>::iterator it;
    for (it = listaTur.begin(); it != listaTur.end(); ++it) {
        if ((*it)->getCi() == ci) return *it;
    }
    return NULL;
}

Experiencia* buscarExp(std::string cod) { // Esta funcion busca la experiencia en la lista
    std::list<Experiencia*>::iterator it;
    for (it = listaExp.begin(); it != listaExp.end(); ++it) {
        if ((*it)->getCodigoReserva() == cod) return *it;
    }
    return NULL;
}

void parte_a(){
    DTFecha fecha1 = DTFecha(18, 5, 2020);
    Experiencia* alojamiento1 = new Alojamiento("ALX5489", "Hotel moderno", 30, fecha1, "Hotel Lindorf", TipoRegimen::AllInclusive, 5);
    listaExp.push_back(alojamiento1);

    DTFecha fecha2 = DTFecha(10, 2, 2025);
    Experiencia* alojamiento2 = new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, fecha2, "Hotel SeaView", TipoRegimen::MediaPension, 15);
    listaExp.push_back(alojamiento2);
}

void parte_b(){
    DTFecha fecha3 = DTFecha(29, 8, 2024);
    
    std::set<std::string> Lugares1;
    Lugares1.insert("Plaza Independencia");
    Lugares1.insert("Plaza Matriz");
    Experiencia* tour1 = new TourGuiado("TGO4657", "Plazas de Montevideo", 10, fecha3, "Paseos SA", Lugares1);
    listaExp.push_back(tour1);

    std::set<std::string> Lugares2;
    Lugares2.insert("Puerta de la Ciudadela");
    Lugares2.insert("Mausoleo");
    Lugares2.insert("Cabildo");
    Lugares2.insert("Palacio Salvo");
    Experiencia* tour2 = new TourGuiado("TGR3257", "Puntos emblematicos", 5, fecha3, "Recorre", Lugares2);
    listaExp.push_back(tour2);
}

void parte_c(){
    DTFecha fecha4 = DTFecha(29, 10, 2025);
    Experiencia* evento1 = new EventoCultural("ECP1346", "Danza en el Solis", 10, fecha4, "Teatro Solis", true);
    listaExp.push_back(evento1);
}

void parte_d(){
	std::list<Experiencia*>::iterator it;
	for (it = listaExp.begin(); it != listaExp.end(); ++it) {
    	std::cout << (*it)->getDT() << std::endl;
	}
}

void parte_e() {
    Turista* t1 = new Turista("4.951.278-9", "Vanesa Castro", "vcastro.uy@servidor.net");
    listaTur.push_back(t1);
    Turista* t2 = new Turista("1.535.442-0", "Karen Santos", "karen.s89@internet.uy");
    listaTur.push_back(t2);
}

void parte_f() {
    std::list<Turista*>::iterator it;
    for (it = listaTur.begin(); it != listaTur.end(); ++it) {
        std::cout << (*it)->toString() << std::endl;
    }
}

void parte_g() {
    Turista* vanesa = buscarTur("4.951.278-9");
    Turista* karen = buscarTur("1.535.442-0");
    
    Experiencia* hotelModem = buscarExp("ALX5489");
    Experiencia* hotelSea = buscarExp("ALJ4789");
    Experiencia* tourPlazas = buscarExp("TGO4657");
    Experiencia* tourPuntos = buscarExp("TGR3257");
    Experiencia* eventoSolis = buscarExp("ECP1346");

    hotelModem->agregarParticipante(vanesa);
    hotelSea->agregarParticipante(vanesa);
    tourPuntos->agregarParticipante(vanesa);
    eventoSolis->agregarParticipante(vanesa);
    tourPlazas->agregarParticipante(karen);
    tourPuntos->agregarParticipante(karen);
}

void parte_h() {
    Turista* vanesa = buscarTur("4.951.278-9");
    if (vanesa != NULL) {
        DTFecha fechaFiltro(10, 12, 2023);
        std::set<std::string> resultados = vanesa->listarExperiencias(fechaFiltro, 0, 1000);
        std::set<std::string>::iterator it;
        for (it = resultados.begin(); it != resultados.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
}

void parte_i(){
    Experiencia* borrar = buscarExp("TGR3257");
    
    //al hacer delete llamamos al destructor por despacho y luego se libera memoria
    //en el destructor de experiencia se borra todas las relaciones de esa experiencia
    //con sus turistas participantes
    if(borrar != NULL){
        listaExp.remove(borrar);
        delete borrar;
    }
}

void parte_j(){
    Turista* karen = buscarTur("1.535.442-0");
    if (karen != NULL) {
        DTFecha fechaFiltro(10, 10, 2020);
        std::set<std::string> resultados = karen->listarExperiencias(fechaFiltro, 0, 1000);
        std::set<std::string>::iterator it;
        for (it = resultados.begin(); it != resultados.end(); ++it){
            std::cout << *it << std::endl;
        }
    }
}

void parte_k(){
    std::list<Experiencia*>::iterator it;
	for (it = listaExp.begin(); it != listaExp.end(); ++it){
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
