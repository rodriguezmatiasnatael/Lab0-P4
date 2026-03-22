
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

void parte_a(){
	DTFecha fecha1 = DTFecha(18, 5, 2020);
	Alojamiento alojamiento1 = Alojamiento("ALX5489", "Hotel moderno", 30, fecha1, "Hotel Lindorf", TipoRegimen::AllInclusive, 5);

	DTFecha fecha2 = DTFecha(10, 02, 2025);
	Alojamiento alojamiento2 = Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, fecha2, "Hotel SeaView", TipoRegimen::MediaPension, 15);
}

void parte_b(){
	DTFecha fecha3 = DTFecha(29, 8, 2024);
	std::set<std::string> Lugares1;
    Lugares1.insert("Plaza Independencia");
    Lugares1.insert("Plaza Matriz");
	TourGuiado TourGuiado1 = TourGuiado("TGO4657", "Plazas de Montevideo", 10, fecha3, "Paseos SA", Lugares1);

	std::set<std::string> Lugares2;
    Lugares2.insert("Puerta de la Ciudadela");
    Lugares2.insert("Mausoleo");
	Lugares2.insert("Cabildo");
    Lugares2.insert("Palacio Salvo");
	TourGuiado TourGuiado2 = TourGuiado("TGR3257", "Puntos emblematicos", 5, fecha3, "Recorre", Lugares2);
}

void parte_c(){
	DTFecha fecha4 = DTFecha(29, 10, 2025);
	EventoCultural EventoCultural1 = EventoCultural("ECP1346", "Danza en el Solis", 10, fecha4, "Teatro Solis", true);
}

void parte_d(){
	std::list<Experiencia*>::iterator it;
	for (it = listaExp.begin(); it != listaExp.end(); ++it) {
    	std::cout << (*it)->getDT() << std::endl;
	}
}

void parte_e(){
}

void parte_f(){
}

void parte_g(){
}

void parte_h(){
}

void parte_i(){
}

void parte_j(){
}

void parte_k(){
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
