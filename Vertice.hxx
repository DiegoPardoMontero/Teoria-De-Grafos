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
const std::vector<Arista<V, A> *> &Vertice<V, A>::getAristas() const {
    return aristas;
}

template<class V, class A>
void Vertice<V, A>::setAristas(const std::vector<Arista<V, A> *> &aristas) {
    Vertice::aristas = aristas;
}

template<class V, class A>
Vertice<V, A>::Vertice(V valor):valor(valor) {}

template<class V, class A>
Vertice<V, A>::Vertice(const std::vector<Arista<V, A> *> &aristas):aristas(aristas) {}

template<class V, class A>
Vertice<V, A>::Vertice(V valor, const std::vector<Arista<V, A> *> &aristas):valor(valor), aristas(aristas) {}

template<class V, class A>
std::ostream &operator<<(std::ostream &os, const Vertice<V, A> &vertice) {
    os << "Vertice: " << vertice.valor << std::endl;
    if (vertice.getAristas().empty()){
        os << "\tEste vertice no tiene aristas" << std::endl;
    }else{
        os << "\tAristas: " << std::endl;
        for(int i = 0; i < vertice.getAristas().size(); i++){
            os << vertice.getAristas()[i] << std::endl;
        }
    }
    return os;
}

#endif //TEORIA_DE_GRAFOS_VERTICE_HXX
