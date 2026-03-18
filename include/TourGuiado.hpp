#ifndef TOURGUIADO_HPP
#define TOURGUIADO_HPP

#include <set>
#include "Experiencia.hpp"

class TourGuiado : public Experiencia {
    private:
        string agencia;
        set<string> lugaresVisitados;
        int cantTuristas;
    public:
        TourGuiado(string, string, int, DTFecha, string,set<string>&,int);
        TourGuiado(TourGuiado&);
        ~TourGuiado() override;

        string getAgencia();
        //aca no estoy seguro si pasarlo por referencia
        set<string>& getLugaresVisitados();

        void setAgencia(string);
        //preguntar el &
        void setLugaresVisitados(const set<string>&);
        void setCantTuristas(int);
        float calcularCosto() override;
};

#endif
