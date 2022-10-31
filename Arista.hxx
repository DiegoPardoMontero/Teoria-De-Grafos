//
// Created by diego on 30/10/2022.
//

#ifndef TEORIA_DE_GRAFOS_ARISTA_HXX
#define TEORIA_DE_GRAFOS_ARISTA_HXX
#include "Arista.h"

template<class V, class A>
Arista<V, A>::Arista() {

}

template<class V, class A>
Arista<V, A>::~Arista() {

}

template<class V, class A>
A Arista<V, A>::getPeso() const {
    return peso;
}

template<class V, class A>
void Arista<V, A>::setPeso(A peso) {
    Arista::peso = peso;
}

template<class V, class A>
Vertice<V, A> *Arista<V, A>::getVDestino() const {
    return vDestino;
}

template<class V, class A>
void Arista<V, A>::setVDestino(Vertice<V, A> *vDestino) {
    Arista::vDestino = vDestino;
}


#endif //TEORIA_DE_GRAFOS_ARISTA_HXX
