#ifndef TEORIA_DE_GRAFOS_VERTICE_H
#define TEORIA_DE_GRAFOS_VERTICE_H
#include <vector>
#include "Arista.h"

template <class V, class A>
class Vertice{
private:
    V valor;
    std::vector<Arista<V, A>> aristas;
public:
    Vertice();
    ~Vertice();

    V getValor() const;

    void setValor(V valor);

    const std::vector<Arista<V, A>> &getAristas() const;

    void setAristas(const std::vector<Arista<V, A>> &aristas);
};



#endif //TEORIA_DE_GRAFOS_VERTICE_H
