#ifndef TEORIA_DE_GRAFOS_ARISTA_H
#define TEORIA_DE_GRAFOS_ARISTA_H
#include <ostream>

template <class A>
class Arista{
private:
    A peso;
    int indvDestino;
public:
    //CONSTRUCTORES:
    Arista();

    explicit Arista(int indvDestino);

    Arista(A peso, int indvDestino);

    //GETTERS Y SETTERS:

    A getPeso() const;

    void setPeso(A peso);

    int getIndvDestino() const;

    void setIndvDestino(int indvDestino);

    //MÉTODOS REALES:
    friend std::ostream &operator<<(std::ostream &os, const Arista &arista);

};


#include "Arista.hxx"


#endif //TEORIA_DE_GRAFOS_ARISTA_H
