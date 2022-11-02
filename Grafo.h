#ifndef TEORIA_DE_GRAFOS_GRAFO_H
#define TEORIA_DE_GRAFOS_GRAFO_H
#include "Vertice.h"
#include <vector>
#include <stack>

template <class V, class A>
class Grafo{
private:
    std::vector<Vertice<V, A>*> vertices;
    bool dirigido;
    bool ponderado;
public:
    //CONSTRUCTORES:
    Grafo();

    explicit Grafo(const std::vector<Vertice<V, A> *> &vertices);

    Grafo(bool dirigido);

    Grafo(const std::vector<Vertice<V, A> *> &vertices, bool dirigido, bool ponderado);

    Grafo(bool dirigido, bool ponderado);

    Grafo(const std::vector<Vertice<V, A> *> &vertices, bool dirigido);

    ~Grafo();

    //GETTER Y SETTERS:

    const std::vector<Vertice<V, A> *> &getVertices() const;

    void setVertices(const std::vector<Vertice<V, A> *> &vertices);

    bool isDirigido() const;

    void setDirigido(bool dirigido);

    bool isPonderado() const;

    void setPonderado(bool ponderado);

    //MÉTODOS REALES:

    bool verificarExistencia(V valor);

    bool agregarVertice(V valor);

    bool esVacio();

    void imprimirGrafo();

    std::vector<Vertice<V, A>> DijkstraCaminoUnico(V valorInicial, V valorDestino);

    std::vector<std::stack<Vertice<V, A> > > DijkstraTodosLosCaminos(V valorInicial);
};

#include "Grafo.hxx"
#endif //TEORIA_DE_GRAFOS_GRAFO_H
