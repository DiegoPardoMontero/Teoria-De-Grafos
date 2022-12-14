#include <iostream>
#include "Grafo.h"
#include "Vertice.h"
using namespace std;

Grafo<char, int> opcionCrearGrafo();

void opcionImprimirGrafo(Grafo<char, int>& grafo);

void opcionAgregarVertice(Grafo<char, int>& grafo);

void opcionAgregarArista(Grafo<char, int>& grafo);

void opcionEliminarVertice(Grafo<char, int>& grafo);

void opcionEliminarArista(Grafo<char, int>& grafo);

void opcionActualizarVertice(Grafo<char, int>& grafo);

void opcionActualizarArista(Grafo<char, int>& grafo);

void opcionImprimirVecinos(Grafo<char, int>& grafo);

void opcionAlgoritmoDijkstra(Grafo<char, int>& grafo);

void opcionRutaEntreDosVertices(Grafo<char, int>& grafo);

int main() {
    int opcion;
    bool seguir = true;
    Grafo<char, int> grafo;
    do{
        cout << endl;
        cout << "=================" << endl;
        cout << "|    TEORIA     |" << endl;
        cout << "|   DE GRAFOS   |" << endl;
        cout << "=================" << endl << endl;

        cout <<"Ingrese el numero de la operacion que desea ejecutar"<<endl;
        cout << "1. Crear grafito :D" << endl;
        cout << "2. Imprimir grafito" << endl;
        cout << "3. Agregar vertice" << endl;
        cout << "4. Agregar arista"  << endl;
        cout << "5. Eliminar vertice" << endl;
        cout << "6. Eliminar arista" << endl;
        cout << "7. Actualizar vertice" << endl;
        cout << "8. Actualizar arista" << endl;
        cout << "9. Imprimir todos los vecinos de un vertice" << endl;
        cout << "10. Algoritmo de Dijkstra" << endl;
        cout << "11. Ruta entre dos vertices" << endl;
        cout << "12. Salir" << endl;
        cin  >> opcion ;

        switch (opcion) {
            case 1:
                grafo = opcionCrearGrafo();
                break;
            case 2:{
                opcionImprimirGrafo(grafo);
                break;
            }
            case 3:{
                opcionAgregarVertice(grafo);
                break;
            }
            case 4:{
                opcionAgregarArista(grafo);
                break;
            }
            case 5:{
                opcionEliminarVertice(grafo);
                break;
            }
            case 6:{
                opcionEliminarArista(grafo);
                break;
            }
            case 7:{
                opcionActualizarVertice(grafo);
                break;
            }
            case 8:{
                opcionActualizarArista(grafo);
                break;
            }
            case 9:{
                opcionImprimirVecinos(grafo);
                break;
            }
            case 10:{
                opcionAlgoritmoDijkstra(grafo);
                break;
            }
            case 11:{
                opcionRutaEntreDosVertices(grafo);
                break;
            }
            default: {
                seguir = false;
                cout << "Gracias por utilizar Grafos VSP!" << endl;
                break;
            }
        }



    }while(seguir);

    return 0;
}

Grafo<char, int> opcionCrearGrafo(){
    char dirigido;
    char ponderado;
    cout<<"=========================CREAR GRAFO=========================="<<endl;

    cout << "Grafo dirigido? s o n" << endl;
    cin >> dirigido;
    cout << "Grafo ponderado? s o n" << endl;
    cin >> ponderado;
    Grafo<char, int> grafo(true, true);
    if (dirigido == 's'){
        if (ponderado == 's'){
            grafo.setDirigido(true);
            grafo.setPonderado(true);
        }else{
            grafo.setDirigido(true);
            grafo.setPonderado(false);
        }
    }else{
        if (ponderado == 's'){
            grafo.setDirigido(false);
            grafo.setPonderado(true);
        }else{
            grafo.setDirigido(false);
            grafo.setPonderado(false);
        }
    }
    return grafo;
}

void opcionImprimirGrafo(Grafo<char, int>& grafo){
    cout<<"=========================IMPRIMIR GRAFO=========================="<<endl;
    grafo.imprimirGrafo();
}

void opcionAgregarVertice(Grafo<char, int>& grafo){
    cout<<"========================= AGREGAR VERTICE=========================="<<endl;

    char verticeAgregar;
    cout << "Ingrese el valor del vertice a agregar: " << endl;
    cin >> verticeAgregar;
    grafo.agregarVertice(verticeAgregar);
}

void opcionAgregarArista(Grafo<char, int>& grafo){
    cout<<"=========================AGREGAR ARISTA=========================="<<endl;
    char verticeOrigen, verticeDestino;
    int peso;
    cout<<"Ingrese el vertice de origen: "<<endl;
    cin>>verticeOrigen;

    cout<<"Ingrese el vertice de destino: "<<endl;
    cin>>verticeDestino;

    if(grafo.isPonderado()){
        cout<<"Ingrese el peso de la arista: "<<endl;
        cin>>peso;
        grafo.agregarArista(verticeOrigen,verticeDestino,peso);
        cout<<"La arista se ha creado exitosamente"<<endl;
    }else {
        grafo.agregarArista(verticeOrigen,verticeDestino);
        cout<<"La arista se ha creado exitosamente"<<endl;
    }
}

void opcionEliminarVertice(Grafo<char, int>& grafo){
    cout<<"========================= ELIMINAR VERTICE=========================="<<endl;
    char vertice;
    cout << "Ingrese el vertice que desea eliminar" << endl;
    cin >> vertice;
    grafo.eliminarVertice(vertice);
}

void opcionEliminarArista(Grafo<char, int>& grafo){
    cout<<"=========================ELIMINAR ARISTA=========================="<<endl;
    char verticeOrigen, verticeDestino;
    int peso;
    cout<<"Ingrese el vertice de origen a eliminar: "<<endl;
    cin>>verticeOrigen;

    cout<<"Ingrese el vertice de destino a eliminar: "<<endl;
    cin>>verticeDestino;

    grafo.eliminarArista(verticeOrigen, verticeDestino);
}

void opcionActualizarVertice(Grafo<char, int>& grafo){
    cout<<"=========================ACTUALIZAR VERTICE=========================="<<endl;
    char verticeOrigen, verticeDestino;
    cout<<"Ingrese el vertice a actualizar: "<<endl;
    cin>>verticeOrigen;

    cout<<"Ingrese el valor del nuevo vertice: "<<endl;
    cin>>verticeDestino;

    grafo.actualizarVertice(verticeOrigen, verticeDestino);
}

void opcionActualizarArista(Grafo<char, int>& grafo){
    cout<<"=========================ACTUALIZAR ARISTA=========================="<<endl;
    char verticeOrigen, verticeDestino;
    int pesoActualizar;
    cout<<"Ingrese el vertice origen de la arista: "<<endl;
    cin>>verticeOrigen;

    cout<<"Ingrese el vertice destino de la arista: "<<endl;
    cin>>verticeDestino;

    cout<<"Ingrese el valor del nuevo peso: " << endl;
    cin >> pesoActualizar;

    grafo.actualizarArista(verticeOrigen, verticeDestino, pesoActualizar);
}

void opcionImprimirVecinos(Grafo<char, int>& grafo){
    cout<<"=========================IMPRIMIR VECINOS DE UN VERTICE=========================="<<endl;
    char verticeImprimir;
    cout << "Ingrese el vertice del cual desea conocer sus vecinos:" << endl;
    cin >> verticeImprimir;
    grafo.imprimirVecinos(verticeImprimir);
}

void opcionAlgoritmoDijkstra(Grafo<char, int>& grafo) {
    cout << "=========================ALGORITMO DE DIJKSTRA==========================" << endl;
    grafo.DijkstraTodosLosCaminos('S');
    cout << "Finalizado!" << endl;
    cout << endl;
}

void opcionRutaEntreDosVertices(Grafo<char, int>& grafo){
    cout<<"=========================RUTA ENTRE DOS VERTICES=========================="<<endl << endl;
    char verticeInicial, verticeFinal;
    cout << "Ingrese el vertice inicial: " << endl;
    cin >> verticeInicial;
    cout << "Ingrese el vertice final: " << endl;
    cin >> verticeFinal;
    std::stack<Vertice<char, int>*> ruta = grafo.DijkstraCaminoEntreDosNodos(verticeInicial, verticeFinal);
    cout<<"=========================RUTA ENCONTRADA=========================="<<endl << endl;
    while(!ruta.empty()){
        if(ruta.top()->getValor() == verticeFinal){
            cout << ruta.top()->getValor();
        }
        else{
            cout << ruta.top()->getValor() << " -> ";
        }
        ruta.pop();
    }
}
