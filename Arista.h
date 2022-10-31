#ifndef TEORIA_DE_GRAFOS_ARISTA_H
#define TEORIA_DE_GRAFOS_ARISTA_H

#include <ostream>
#include "Vertice.h"

template<class V, class A>
class Vertice;

template <class V, class A>
class Arista{
private:
    A peso;
    Vertice<V, A>* vDestino;
public:
    //CONSTRUCTORES:
    Arista();

    Arista(A peso);

    Arista(Vertice<V, A> *vDestino);

    Arista(A peso, Vertice<V, A> *vDestino);

    ~Arista();

    //GETTERS Y SETTERS:
    A getPeso() const;

    void setPeso(A peso);

    Vertice<V, A> *getVDestino() const;

    void setVDestino(Vertice<V, A> *vDestino);

    //MÉTODOS NORMALES:
    friend std::ostream &operator<<(std::ostream &os, const Arista<V, A> &arista);

};

#include "Arista.hxx"
#include "Vertice.hxx"


#endif //TEORIA_DE_GRAFOS_ARISTA_H
