//
// Created by diego on 30/10/2022.
//

#ifndef TEORIA_DE_GRAFOS_GRAFO_HXX
#define TEORIA_DE_GRAFOS_GRAFO_HXX
#include "Grafo.h"
#include "Vertice.hxx"
#include <iostream>

//CONSTRUCTORES:
template<class V, class A>
Grafo<V, A>::Grafo() {

}

template<class V, class A>
Grafo<V, A>::~Grafo() = default;

template<class V, class A>
Grafo<V, A>::Grafo(bool dirigido):dirigido(dirigido) {}

template<class V, class A>
Grafo<V, A>::Grafo(const std::vector<Vertice<V, A> *> &vertices, bool dirigido):vertices(vertices),
                                                                                dirigido(dirigido) {}
    //}

//GETTER Y SETTERS:

template<class V, class A>
const std::vector<Vertice<V, A> *> &Grafo<V, A>::getVertices() const {
    return vertices;
}

template<class V, class A>
void Grafo<V, A>::setVertices(const std::vector<Vertice<V, A> *> &vertices) {
    Grafo::vertices = vertices;
}

template<class V, class A>
Grafo<V, A>::Grafo(const std::vector<Vertice<V, A> *> &vertices):vertices(vertices) {}

template<class V, class A>
bool Grafo<V, A>::isDirigido() const {
    return dirigido;
}

template<class V, class A>
void Grafo<V, A>::setDirigido(bool dirigido) {
    Grafo::dirigido = dirigido;
}

template<class V, class A>
Grafo<V, A>::Grafo(const std::vector<Vertice<V, A> *> &vertices, bool dirigido, bool ponderado):vertices(vertices),
                                                                                                dirigido(dirigido),
                                                                                                ponderado(ponderado) {}

template<class V, class A>
Grafo<V, A>::Grafo(bool dirigido, bool ponderado):dirigido(dirigido), ponderado(ponderado) {}

template<class V, class A>
bool Grafo<V, A>::isPonderado() const {
    return ponderado;
}

template<class V, class A>
void Grafo<V, A>::setPonderado(bool ponderado) {
    Grafo::ponderado = ponderado;
}

//MÉTODOS REALES:

template<class V, class A>
bool Grafo<V, A>::verificarExistencia(V valor){
    for (int i = 0; i < this->vertices.size(); i++){
        if(this->vertices[i]->getValor() == valor){
            return true;
        }
    }
    return false;
}

template<class V, class A>
bool Grafo<V, A>::agregarVertice(V valor){
    bool existe = verificarExistencia(valor);
    if(!existe){
        auto* nuevoVertice = new Vertice<V, A>(valor);
        this->vertices.push_back(nuevoVertice);
        std::cout << "El vertice se ha agregado exitosamente!" << std::endl;
        return true;
    }
    else{
        std::cout << "El vertice ya se encuentra en el grafo!" << std::endl;
        return false;
    }
}

template<class V, class A>
bool Grafo<V, A>::esVacio(){
    if(vertices.empty()) {
        return true;
    }
    return false;
}

template<class V, class A>
void Grafo<V, A>::imprimirGrafo(){
    if(esVacio()){
        std::cout << "El grafo esta vacio!" << std::endl;
        return;
    } else{
        for (int i = 0; i < this->vertices.size(); i++){
            std::cout << "Vertice " << vertices[i]->getValor() << ":" << std::endl << std::endl;
            if (vertices[i]->getAristas().empty()){
                std::cout << "\tEste vertice no tiene aristas" << std::endl << std::endl;
            }else{
                std::cout << "\tAristas: " << std::endl;
                for(int j = 0; j < vertices[i]->getAristas().size(); j++){
                    std::cout << "\t - "
                              << vertices[i]->getValor()
                              << " -> "
                              << vertices[i]->getAristas()[j]->getValorVerticeDestino()
                              << " Peso: "
                              << vertices[i]->getAristas()[j]->getPeso() << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
}

template<class V, class A>
bool Grafo<V, A>::agregarArista(V valorOrigen, V valorDestino) {
    bool existenciaOrigen;
    bool existenciaDestino;
    existenciaOrigen = verificarExistencia(valorOrigen);
    existenciaDestino = verificarExistencia(valorDestino);
    if (existenciaOrigen && existenciaDestino) {
        for(int i = 0; i < this->vertices.size(); i++){
            if(valorOrigen == vertices[i]->getValor()){
                vertices[i]->agregarAristaEnVertice(valorDestino);
            }
            if(valorDestino == vertices[i]->getValor() && !dirigido){
                vertices[i]->agregarAristaEnVertice(valorOrigen);
            }
        }

    } else {
        std::cout << "Vertices invalidos!" << std::endl;
    }
}

template<class V, class A>
bool Grafo<V, A>::agregarArista(V valorOrigen, V valorDestino, A peso) {
    bool existenciaOrigen;
    bool existenciaDestino;
    existenciaOrigen = verificarExistencia(valorOrigen);
    existenciaDestino = verificarExistencia(valorDestino);
    if (existenciaOrigen && existenciaDestino) {
        for(int i = 0; i < this->vertices.size(); i++){
            if(valorOrigen == vertices[i]->getValor()){
                vertices[i]->agregarAristaEnVertice(valorDestino, peso);
            }
            if(valorDestino == vertices[i]->getValor() && !dirigido){
                vertices[i]->agregarAristaEnVertice(valorOrigen, peso);
            }
        }

    } else {
        std::cout << "Vertices invalidos!" << std::endl;
    }
}

template<class V, class A>
bool Grafo<V, A>::eliminarArista(V valorOrigen, V valorDestino){
    bool existenciaOrigen;
    bool existenciaDestino;
    existenciaOrigen = verificarExistencia(valorOrigen);
    existenciaDestino = verificarExistencia(valorDestino);
    if(existenciaOrigen && existenciaDestino){
        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i]->getValor() == valorOrigen){
                for (auto itA = this->vertices[i]->getAristas().begin(); itA != this->vertices[i]->getAristas().end(); itA++){
                    if((*itA)->getValorVerticeDestino() == valorDestino){
                        vertices[i]->getAristas().erase(itA);
                        break;
                    }
                }
            }
            if(vertices[i]->getValor() == valorDestino){
                if(!dirigido){
                    for (auto itA = this->vertices[i]->getAristas().begin(); itA != this->vertices[i]->getAristas().end(); itA++){
                        if((*itA)->getValorVerticeDestino() == valorOrigen){
                            vertices[i]->getAristas().erase(itA);
                            break;
                        }
                    }
                }
            }
        }
        std::cout << "La arista se ha eliminado exitosamente!" << std::endl;
    }else{
        std::cout << "Vertices invalidos!" << std::endl;
    }
}

template<class V, class A>
bool Grafo<V, A>::actualizarVertice(V elViejo, V elNuevo) {
    bool existe = verificarExistencia(elViejo);
    int i=0;
    if(existe) {
        for(int i = 0; i < vertices.size(); i++){
            for (auto itA = this->vertices[i]->getAristas().begin(); itA != this->vertices[i]->getAristas().end(); itA++){
                if((*itA)->getValorVerticeDestino() == elViejo){
                    (*itA)->setValorVerticeDestino(elNuevo);
                    break;
                }
            }
        }

        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i]->getValor() == elViejo){
                vertices[i]->setValor(elNuevo);
            }
        }

        std::cout << "El vertice se ha actualizado exitosamente!" << std::endl;
        return true;
    }
    else{
        std::cout << "El vertice no existe!" << std::endl;
        return false;
    }
}

template<class V, class A>
bool Grafo<V, A>::actualizarArista(V valorOrigen, V valorDestino, A peso) {
    bool existenciaOrigen;
    bool existenciaDestino;
    existenciaOrigen = verificarExistencia(valorOrigen);
    existenciaDestino = verificarExistencia(valorDestino);
    if(existenciaOrigen && existenciaDestino){
        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i]->getValor() == valorOrigen){
                for (auto itA = this->vertices[i]->getAristas().begin(); itA != this->vertices[i]->getAristas().end(); itA++){
                    if((*itA)->getValorVerticeDestino() == valorDestino){
                        (*itA)->setPeso(peso);
                        break;
                    }
                }
            }
            if(vertices[i]->getValor() == valorDestino){
                if(!dirigido){
                    for (auto itA = this->vertices[i]->getAristas().begin(); itA != this->vertices[i]->getAristas().end(); itA++){
                        if((*itA)->getValorVerticeDestino() == valorOrigen){
                            (*itA)->setPeso(peso);
                            break;
                        }
                    }
                }
            }
        }
        std::cout << "La arista se ha actualizado exitosamente!" << std::endl;
    }else{
        std::cout << "Vertices invalidos!" << std::endl;
    }
}

template<class V, class A>
void Grafo<V, A>::imprimirVecinos(V verticeImprimir) {
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->getValor() == verticeImprimir){
            std::cout << "Vecinos encontrados: " << std::endl;
            for(int j = 0; j < vertices[i]->getAristas().size(); j++){
                std::cout << "- " << vertices[i]->getAristas()[j]->getValorVerticeDestino() << std::endl;
            }
        }
    }
}

#endif //TEORIA_DE_GRAFOS_GRAFO_HXX
