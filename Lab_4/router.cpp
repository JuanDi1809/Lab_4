#include "router.h"

#include <iostream>
#include "Router.h"
#include <queue>
#include <climits>

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

int Router::getDistancia() const{
    return distancia;
}

bool Router::getVisitado(){
    return visitado;
}


string Router::getNombre() const{
    return nombreEnrutador;
}

void Router::setVisitado(){
    visitado = true;
}

void Router::setNombre(string nombre){
    nombreEnrutador = nombre;
}


void dijkstra(Router* fuente) {
    fuente->confDistancia(0); //(*fuente).confDistancia(0); es equivalente con dereferenciación

    std::priority_queue<std::pair<int, Router*>> pq; //es una cola que tiene un valor adicional(prioridad), el elemento con mayor prio se guarda al inicio
    pq.push({0, fuente});

    while (!pq.empty()) {
        Router* actual = pq.top().second; //Tomo el valor del router del primer elemento de la cola
        pq.pop();

        if (actual->getVisitado()) continue;

        actual->setVisitado(); //si cumple la visita, actual cambia a false

        for (auto& vec : actual->vecinos) { //leo los vecinos del router actual
            Router* sigRouter = vec.first; //vecinos es un vector de pares, el primero es un router
            int costoBorde = vec.second; //lo que cuesta el borde a ese primer vecino
            int nuevaDistancia = actual->getDistancia() + costoBorde; //La distancia es un valor de la fuente al router
            if (nuevaDistancia < sigRouter->getDistancia()) {
                sigRouter->confDistancia(nuevaDistancia);
                pq.push({-nuevaDistancia, sigRouter}); // lo guardo con una prioridad que garantice su lugar en la cola
            }
        }
    }
}
