#include <iostream>
#include "Grafo.h"

using namespace std;


int main() {
    //Letrero Inicial:

    cout << endl;
    cout << "=================" << endl;
    cout << "|    TEORIA     |" << endl;
    cout << "|   DE GRAFOS   |" << endl;
    cout << "=================" << endl << endl;

    //Definición de Grafo No Dirigido Ponderado:
    Grafo<char, int> grafoNoDir(false, true);

    //Definición de Grafo Dirigido Ponderado:
    Grafo<char, int> grafoDir(true, true);

    //Insercion de valores Grafo No Dirigido:
    grafoNoDir.agregarVertice('A');
    grafoNoDir.agregarVertice('B');
    grafoNoDir.agregarVertice('C');
    grafoNoDir.agregarVertice('D');
    grafoNoDir.agregarVertice('E');
    std::cout << std::endl;

    //Insercion de valores Grafo Dirigido:
    grafoDir.agregarVertice('A');
    grafoDir.agregarVertice('B');
    grafoDir.agregarVertice('C');
    grafoDir.agregarVertice('D');
    grafoDir.agregarVertice('E');
    std::cout << std::endl;

    //Insercion de aristas grafo no dirigido:
    grafoNoDir.agregarArista('A', 'C', 2);
    grafoNoDir.agregarArista('A', 'B', 3);
    grafoNoDir.agregarArista('B', 'D', 2);
    grafoNoDir.agregarArista('C', 'D', 1);
    grafoNoDir.agregarArista('C', 'E', 4);
    grafoNoDir.agregarArista('D', 'E', 2);
    grafoNoDir.agregarArista('D', 'E', 2);

    //Insercion de aristas grafo dirigido:
    grafoDir.agregarArista('A', 'D', 60);
    grafoDir.agregarArista('A', 'C', 12);
    grafoDir.agregarArista('B', 'A', 10);
    grafoDir.agregarArista('C', 'B', 20);
    grafoDir.agregarArista('C', 'D', 32);
    grafoDir.agregarArista('E', 'A', 7);
    grafoDir.agregarArista('E', 'A', 7);


    //Impresion del grafo no dirigido:
    cout << endl;
    cout << "=================" << endl;
    cout << "|     GRAFO     |" << endl;
    cout << "|   NO DIRIGIDO |" << endl;
    cout << "=================" << endl << endl;
    grafoNoDir.imprimirGrafo();


    //Impresion del grafo dirigido:
    cout << endl;
    cout << "=================" << endl;
    cout << "|     GRAFO     |"   << endl;
    cout << "|    DIRIGIDO   |" << endl;
    cout << "=================" << endl << endl;
    grafoDir.imprimirGrafo();

    return 0;
}