//
// Created by diego on 30/10/2022.
//

#ifndef TEORIA_DE_GRAFOS_VERTICE_HXX
#define TEORIA_DE_GRAFOS_VERTICE_HXX
#include "Vertice.h"

template<class V, class A>
Vertice<V, A>::Vertice() {

}

template<class V, class A>
Vertice<V, A>::~Vertice() {

}

template<class V, class A>
V Vertice<V, A>::getValor() const {
    return valor;
}

template<class V, class A>
void Vertice<V, A>::setValor(V valor) {
    Vertice::valor = valor;
}

template<class V, class A>
Vertice<V, A>::Vertice(V valor):valor(valor) {}


template<class V, class A>
std::ostream &operator<<(std::ostream &os, const Vertice<V, A> &vertice) {
    os << "Vertice: " << vertice.valor << std::endl;
    return os;
}

template<class V, class A>
Vertice<V, A>::Vertice(const std::vector<Arista<A> *> &aristas):aristas(aristas) {}

template<class V, class A>
Vertice<V, A>::Vertice(V valor, const std::vector<Arista<A> *> &aristas):valor(valor), aristas(aristas) {}

template<class V, class A>
const std::vector<Arista<A> *> &Vertice<V, A>::getAristas() const {
    return aristas;
}

template<class V, class A>
void Vertice<V, A>::setAristas(const std::vector<Arista<A> *> &aristas) {
    Vertice::aristas = aristas;
}

template<class V, class A>
void Vertice<V, A>::agregarAristaEnVertice(int indAgregar) {
    auto* aristaAgregar = new Arista<A>(indAgregar);
    this->aristas.push_back(aristaAgregar);
}

template<class V, class A>
void Vertice<V, A>::agregarAristaEnVertice(int indAgregar, A peso) {
    auto* aristaAgregar = new Arista<A>(peso, indAgregar);
    this->aristas.push_back(aristaAgregar);
}

#endif //TEORIA_DE_GRAFOS_VERTICE_HXX
