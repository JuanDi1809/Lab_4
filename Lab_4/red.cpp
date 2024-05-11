#include "red.h"
#include "router.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

Red::Red(){
}

Red::~Red(){
    for (Router* ptrRouter : routers) {
        delete ptrRouter; // Libera la memoria del enrutador
    }
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

            for(Router* ptrRouter: routers){
                if(ptrRouter->getNombre() == nameRouter) throw "el enrutador ya existe, ingrese un nuveo nombre.";
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

void Red::listarRouters(){
    int pos = 1;

    for(Router* ptrRouter: routers){
        cout << pos << ". " << ptrRouter->getNombre() << endl;
        pos++;
    }
}
