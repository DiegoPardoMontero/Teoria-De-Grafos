//
// Created by diego on 30/10/2022.
//

#ifndef TEORIA_DE_GRAFOS_ARISTA_HXX
#define TEORIA_DE_GRAFOS_ARISTA_HXX
#include "Arista.h"

template<class A>
Arista<A>::Arista() = default;

template<class A>
Arista<A>::Arista(int indvDestino):indvDestino(indvDestino) {}

template<class A>
Arista<A>::Arista(A peso, int indvDestino):peso(peso), indvDestino(indvDestino) {}

template<class A>
A Arista<A>::getPeso() const {
    return peso;
}

template<class A>
void Arista<A>::setPeso(A peso) {
    Arista::peso = peso;
}

template<class A>
int Arista<A>::getIndvDestino() const {
    return indvDestino;
}

template<class A>
void Arista<A>::setIndvDestino(int indvDestino) {
    Arista::indvDestino = indvDestino;
}

template<class A>
std::ostream &operator<<(std::ostream &os, const Arista<A> &arista) {
    os << "Peso: " << arista.peso;
    return os;
}


#endif //TEORIA_DE_GRAFOS_ARISTA_HXX
