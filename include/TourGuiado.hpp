#ifndef TOURGUIADO_HPP
#define TOURGUIADO_HPP

#include <set>
#include "Experiencia.hpp"

class TourGuiado : public Experiencia {
    private:
        string agencia;
        set<string> lugaresVisitados;
        int cantLugares;
        int cantTuristas;
    public:
        TourGuiado(string, string, int, DTFecha, string,set<string>&,int,int);
        TourGuiado(TourGuiado&);
        ~TourGuiado() override;

        string getAgencia();
        //aca no estoy seguro si pasarlo por referencia
        set<string>& getLugaresVisitados();
        int getCantLugares();
        int getCantTuristas();

        void setAgencia(string);
        //preguntar el &
        void setLugaresVisitados(const set<string>&);
        void setCantLugares(int);
        void setCantTuristas(int);

        float calcularCosto() override;
};

#endif
