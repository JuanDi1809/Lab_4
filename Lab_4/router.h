#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include <utility>
#include <string>
#include <map>

using namespace std;

class Router
{
private:
    string nombreEnrutador;
    int distancia;
    bool visitado;

public:
    //Este es un atributo de router
    vector<pair<Router*, int>> vecinos;
    map <string, int> tablaEnrutamiento;


    //Constructor
    Router(string);

    //Metodos
    void nuevoVecino(Router* vecino, int costo);
    void confDistancia(int distancia);
    void reinicio();

    //Getters
    int getDistancia() const;
    bool getVisitado();
    string getNombre() const;

    //Setters
    void setVisitado();
    void actualizarTablaEnrutamiento();
};

void dijkstra(Router* fuente);

#endif // ROUTER_H
