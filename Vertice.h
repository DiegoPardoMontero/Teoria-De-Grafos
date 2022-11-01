#ifndef TEORIA_DE_GRAFOS_VERTICE_H
#define TEORIA_DE_GRAFOS_VERTICE_H
#include <vector>
#include <ostream>
#include "Arista.h"

template <class V, class A>
class Vertice{
private:
    V valor;
    std::vector<Arista<A>*> aristas;
public:
    //CONSTRUCTORES:
    Vertice();

    explicit Vertice(V valor);

    explicit Vertice(const std::vector<Arista<A> *> &aristas);

    Vertice(V valor, const std::vector<Arista<A> *> &aristas);

    ~Vertice();

    //GETTER Y SETTER
    V getValor() const;

    void setValor(V valor);

    std::vector<Arista<A> *> &getAristas();

    void setAristas(const std::vector<Arista<A> *> &aristas);

    //MÉTODOS REALES

    friend std::ostream &operator<<(std::ostream &os, const Vertice<V, A> &vertice);

    void agregarAristaEnVertice(int indAgregar);

    void agregarAristaEnVertice(int indAgregar, A peso);
};



#include "Vertice.hxx"

#endif //TEORIA_DE_GRAFOS_VERTICE_H
