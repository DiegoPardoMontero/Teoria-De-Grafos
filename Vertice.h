#ifndef TEORIA_DE_GRAFOS_VERTICE_H
#define TEORIA_DE_GRAFOS_VERTICE_H
#include <vector>
#include <ostream>
#include "Arista.h"

template <class V, class A>
class Vertice{
private:
    V valor;
    A distancia;
    Vertice<V, A>* predecesor;
    bool visitado;
    std::vector<Arista<A, V>*> aristas;
public:

    //CONSTRUCTORES:
    Vertice();

    explicit Vertice(V valor);

    explicit Vertice(const std::vector<Arista<A, V> *> &aristas);

    Vertice(V valor, const std::vector<Arista<A, V> *> &aristas);

    ~Vertice();

    //GETTER Y SETTER
    V getValor() const;

    void setValor(V valor);

    std::vector<Arista<A, V> *> &getAristas();

    void setAristas(const std::vector<Arista<A, V> *> &aristas);

    A getDistancia() const;

    void setDistancia(A distancia);

    Vertice<V, A> *getPredecesor() const;

    void setPredecesor(Vertice<V, A> *predecesor);

    bool isVisitado() const;

    void setVisitado(bool visitado);


    //MÉTODOS REALES

    friend std::ostream &operator<<(std::ostream &os, const Vertice<V, A> &vertice);

    void agregarAristaEnVertice(V valor);

    void agregarAristaEnVertice(V valor, A peso);
};



#include "Vertice.hxx"

#endif //TEORIA_DE_GRAFOS_VERTICE_H
