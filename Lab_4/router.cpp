#include "router.h"
#include "red.h"

#include <iostream>
#include <queue>
#include <climits>
#include <map>

//Constructor de la clase. El router se debe crear con su ID, y por defecto pone los miembros de la clase en esos valores
Router::Router(string _nameEnrutador) : nombreEnrutador(_nameEnrutador), distancia(INT_MAX), visitado(false){}

void Router::nuevoVecino(Router* vecino, int costo) {
    vecinos.emplace_back(vecino, costo); // en vez de push_back, porque construyo el elemento que es un par
}

void Router::confDistancia(int dist) {
    distancia = dist;
}

void Router::reinicio() {
    distancia = INT_MAX;
    visitado = false;
}

string Router::getNombre() const{
    return nombreEnrutador;
}

int Router::getCantVecions() const{
    return vecinos.size();
}

Router* Router::getVecino(int pos){
    return vecinos[pos].first;
}

void Router::datoTablaEnrutamiento(string name, int costoMinimo){
    tablaEnrutamiento.insert(make_pair(name, costoMinimo));
}

void Router::mostrarTablaEnrutamiento(){
    for (const auto& par : tablaEnrutamiento) {
        cout << "Desde " << nombreEnrutador << " hasta " << par.first << " cuesta " << par.second << std::endl;
    }
}

int Router::menorCosto(string routerDestino){
    for(const auto& par : tablaEnrutamiento){
        if(par.first == routerDestino){
            return par.second;
        }
    }
}

bool Router::esCrucialParaConectividad() {
    if (vecinos.size() >= 2) {
        return true;
    }
    return false;
}

void dijkstra(Router* fuente) {
    fuente->confDistancia(0); //(*fuente).confDistancia(0); es equivalente con dereferenciación

    std::priority_queue<std::pair<int, Router*>> pq; //es una cola que tiene un valor adicional(prioridad), el elemento con mayor prio se guarda al inicio
    pq.push({0, fuente});

    while (!pq.empty()) {
        Router* actual = pq.top().second; //Tomo el valor del router del primer elemento de la cola
        pq.pop();

        if (actual->visitado) continue;

        actual->visitado = true;

        for (auto& vec : actual->vecinos) { //leo los vecinos del router actual
            Router* sigRouter = vec.first; //vecinos es un vector de pares, el primero es un router
            int costoBorde = vec.second; //lo que cuesta el borde a ese primer vecino

            int nuevaDistancia = actual->distancia + costoBorde; //La distancia es un valor de la fuente al router
            if (nuevaDistancia < sigRouter->distancia) {
                sigRouter->confDistancia(nuevaDistancia);
                pq.push({-nuevaDistancia, sigRouter}); // lo guardo con una prioridad que garantice su lugar en la cola
            }
        }
    }
}
