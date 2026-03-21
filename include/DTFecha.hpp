#include <string>

#ifndef DTFECHA_HPP
#define DTFECHA_HPP

class DTFecha {
private:
    int dia, mes, anio;

public:
    DTFecha(int d, int m, int a);
    
    DTFecha(const DTFecha& f);
    
    ~DTFecha();
	
    std::string toString() const;

    DTFecha& operator=(const DTFecha& f);   // Se quita 'const' del final en la asignación para permitir modificar el objeto. 
    bool operator>=(const DTFecha& otra) const;
};

#endif
