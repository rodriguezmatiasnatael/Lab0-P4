#ifndef DTFECHA_HPP
#define DTFECHA_HPP

class DTFecha {
private:
    int dia, mes, anio;
public:
    DTFecha(int d, int m, int a);
    DTFecha();
    ~DTFecha();
    
    int getD() const;
    int getM() const;
    int getA() const;

    bool operator>(const DTFecha& otra) const;
};

#endif