#ifndef TEORIA_DE_GRAFOS_VERTICE_H
#define TEORIA_DE_GRAFOS_VERTICE_H
#include <vector>
#include <ostream>
#include "Arista.h"

template <class V, class A>
class Vertice{
private:
    V valor;
    std::vector<Arista<V, A>*> aristas;
public:
    //CONSTRUCTORES:
    Vertice();

    Vertice(V valor);

    Vertice(const std::vector<Arista<V, A> *> &aristas);

    Vertice(V valor, const std::vector<Arista<V, A> *> &aristas);

    ~Vertice();

    //GETTER Y SETTER
    V getValor() const;

    void setValor(V valor);

    const std::vector<Arista<V, A> *> &getAristas() const;

    void setAristas(const std::vector<Arista<V, A> *> &aristas);

    //MÉTODOS REALES

    friend std::ostream &operator<<(std::ostream &os, const Vertice &vertice);
};

#include "Vertice.hxx"

#endif //TEORIA_DE_GRAFOS_VERTICE_H
