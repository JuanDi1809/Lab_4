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

public:
    //Atributos publicos
    int distancia;
    bool visitado;


    //Vector que tiene a sus vecinos y sus respectivos costos
    vector<pair<Router*, int>> vecinos;

    //Mapa que contiene el minimo costo a todos los enrutadores de la red
    map <string, int> tablaEnrutamiento;

    //Constructor
    Router(string);

    //Getters
    string getNombre() const;
    int getCantVecions() const;

    //Getter para obtner al vecino
    Router* getVecino(int);

    //Metodos
    void nuevoVecino(Router* vecino, int costo);
    void confDistancia(int distancia);
    void reinicio();

    //Muestra la tabla de enrutamiento
    void mostrarTablaEnrutamiento();

    //Ingresa los datos a la tabla de enrutamiento
    void datoTablaEnrutamiento(string, int);

    //Menor costo a enrutador
    int menorCosto(string);

    //Verifica si el enrutador tiene mas de dos enlaces
    bool esCrucialParaConectividad();

};

void dijkstra(Router* fuente);

#endif // ROUTER_H
