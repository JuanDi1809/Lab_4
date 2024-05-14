#include "red.h"
#include "router.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Red::Red(){
}

Red::~Red(){
    for (Router* router : routers) {
        delete router;
    }
    routers.clear();
}

int Red::getCantRouters() const{
    return routers.size();
}

Router* Red::getObjetoRouter(int pos) const{
    return routers[pos -1];
}

string Red::verificarRouter(){
    string nameRouter;

    while(true){
        try{
            cout << "Ingresa el nombre del router: ";
            cin >> nameRouter;

            for(Router* router: routers){
                if(router->getNombre() == nameRouter) throw "el enrutador ya existe, ingrese un nuevo nombre.";
            }

            break;
        }
        catch(const char* msg){
            cerr << "Error: " << msg << endl;
        }
    }
    return nameRouter;
}

void Red::agregarRouter(Router* router){
    routers.push_back(router);
}

void Red::eliminarEnrutador(int pos){
    routers.erase(routers.begin() + pos - 1);
}

void Red::eliminarVecinos(int pos){

    Router* routerEliminar = routers[pos -1];

    vector<pair<Router*, int>> vecinosTemp;

    // Iteramos sobre los vecinos del vecino actual
    for (const auto& neighbor : routerEliminar->vecinos) {

        Router* routerVecino = neighbor.first;

        for(const auto& par : routerVecino->vecinos){
            if (par.first->getNombre() != routerEliminar->getNombre()) {
                // Si no es el router que queremos eliminar, lo agregamos al vector temporal
                vecinosTemp.push_back(par);
            }
        }
        // Reemplazamos el vector de vecinos con el temporal
        routerVecino->vecinos = vecinosTemp;
    }

    //Elimino el router de la red
    routers.erase(routers.begin() + pos - 1);
}

void Red::listarRouters(string routerAgregado){
    int pos = 1;

    for(Router* router: routers){
        if(router->getNombre() != routerAgregado){
            cout << pos << ". " << router->getNombre() << endl;
            pos++;
        }
    }
}

void Red::crearTablaEnrutamiento(int pos){
    Router* router = routers[pos - 1];

    dijkstra(router);

    for(Router* routerRed : routers){
        router->datoTablaEnrutamiento(routerRed->getNombre(), routerRed->distancia);
    }

    for(Router* routerRed : routers){
        routerRed->reinicio();
    }


}

//METODOS PARA CREAR RED DESDE ARCHIVO

string Red::verificarArchivo(){
    string nombre;

    while(true){
        try{
            cout << "Ingrese el nombre del archivo (formato .txt): ";
            cin >> nombre;

            if(nombre.substr(nombre.size() - 4, 4 ) != ".txt"){
                throw "formato no valido";
            }

            ifstream archivo(nombre); //Intenta abrir el archivo en modo lectura

            if(!archivo.good()){
                throw runtime_error("el archivo no existe");
            }

            break;
        }
        catch(const exception &ex){
            cerr << "Error: " << ex.what() << endl;
        }
        catch(const char *msg){
            cerr << "Error: " << msg << endl;
        }
    }

    return nombre;
}

Router* Red::getObjetoRouter2(string nombreRouter){
    for(Router* router : routers){
        if(nombreRouter == router->getNombre()){
            return router;
        }

    }

}


