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
const std::vector<Arista<V, A>> &Vertice<V, A>::getAristas() const {
    return aristas;
}

template<class V, class A>
void Vertice<V, A>::setAristas(const std::vector<Arista<V, A>> &aristas) {
    Vertice::aristas = aristas;
}


#endif //TEORIA_DE_GRAFOS_VERTICE_HXX
