#include <iostream>
#include "Grafo.h"

using namespace std;


int main(){
    //Letrero Inicial:

    cout << endl;
    cout << "=================" << endl;
    cout << "|    TEORIA     |"   << endl;
    cout << "|   DE GRAFOS   |" << endl;
    cout << "=================" << endl << endl;

    //Definición de Grafo No Dirigido Ponderado:
    Grafo<char, int> grafoNoDir(false, true);

    //Definición de Grafo Dirigido Ponderado:
    Grafo<char, int> grafoDir(true, true);

    //Insercion de valores Grafo No Dirigido:
    grafoNoDir.agregarVertice('A');
    grafoNoDir.agregarVertice('F');
    grafoNoDir.agregarVertice('B');
    grafoNoDir.agregarVertice('C');
    grafoNoDir.agregarVertice('C');
    grafoNoDir.agregarVertice('H');
    grafoNoDir.agregarVertice('G');

    //Impresion del grafo:
    grafoNoDir.imprimirGrafo();




    return 0;
}