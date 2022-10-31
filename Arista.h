#ifndef TEORIA_DE_GRAFOS_ARISTA_H
#define TEORIA_DE_GRAFOS_ARISTA_H
#include "Vertice.h"

template <class V, class A>
class Arista{
private:
    A peso;
    Vertice<V, A>* vDestino;
public:
    Arista();
    ~Arista();

    A getPeso() const;

    void setPeso(A peso);

    Vertice<V, A> *getVDestino() const;

    void setVDestino(Vertice<V, A> *vDestino);
};




#endif //TEORIA_DE_GRAFOS_ARISTA_H
