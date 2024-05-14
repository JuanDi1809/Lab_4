#include "router.h"
#include "red.h"
#include "menu.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <QCoreApplication>
#include <QTextStream>
#include <QLocale>

using namespace std;

int main(){

    while(true){
        Menu menu1;

        cout << "Bienvenido a la creacion de de una red de enrutadores\n";

        menu1.menuPrincipal();
        int opcionMenuPrincipal = menu1.validOpcion(3);

        cout << endl;

        if(opcionMenuPrincipal == 1){
            Red red1;

            while(true){
                Menu menu2;

                menu2.menuRedManual();
                int opcionMenuRedManual = menu2.validOpcion(5);

                cout << endl;

                if(opcionMenuRedManual == 1){ //Agregar enrutador

                    string nameRouter;

                    if(red1.getCantRouters() == 0){ //Al primer router no se le piden vecinos
                        nameRouter = red1.verificarRouter();
                        Router* router = new Router(nameRouter);

                        //Agrego el router creado a la red
                        red1.agregarRouter(router);
                    }
                    else{ //Apartir del segundo router

                        nameRouter = red1.verificarRouter();
                        Router* router = new Router(nameRouter);

                        //Agrego el router creado a la red
                        red1.agregarRouter(router);

                        while(true){ //Si selecciona nuevamente el mismo router es como si volviera a actualizar los datos
                            cout << "Selecciona el vecino para el router\n";
                            red1.listarRouters(nameRouter);

                            int opcionRouter = menu2.validOpcion(red1.getCantRouters());
                            Router* routerVecino = red1.getObjetoRouter(opcionRouter);

                            int costo;
                            cout << "Ingresa el costo hacia el router " << routerVecino->getNombre() << ": ";
                            cin >> costo;

                            //Actualizando los vecinos de los routers}
                            routerVecino->nuevoVecino(router, costo);
                            router->nuevoVecino(routerVecino, costo);

                            cout << endl;

                            cout << "Desea ingresar mas vecinos\n";
                            cout << "1. Si\n";
                            cout << "2. No\n";
                            int opcionVecino = menu2.validOpcion(2);

                            cout << endl;

                            if(opcionVecino == 2) break;
                        }
                    }

                    cout << endl;
                }
                else if(opcionMenuRedManual == 2){//Remover enrutador

                    red1.listarRouters("");

                    cout << "Selecciona el router que deseas eliminar\n";
                    int opcion = menu2.validOpcion(red1.getCantRouters());

                    Router* router = red1.getObjetoRouter(opcion);

                    if(router->esCrucialParaConectividad()){
                        cout << "No es prosible emliminar este enrutador, puede generar fallas en la red\n";
                    }
                    else{
                        red1.eliminarVecinos(opcion); //Con esto elimino al router de los routers a los cuales es vecino
                    }
                    router->tablaEnrutamiento.clear();

                }
                else if(opcionMenuRedManual == 3){ //Costo envio

                    red1.listarRouters("");

                    cout << "Selecciona el router de origen\n";
                    int opcionOrigen = menu2.validOpcion(red1.getCantRouters());
                    red1.crearTablaEnrutamiento(opcionOrigen);

                    Router* routerOrigen = red1.getObjetoRouter(opcionOrigen);

                    cout << "Selecciona el router de destino\n";
                    int opcionDestino = menu2.validOpcion(red1.getCantRouters());

                    Router* routerDestino = red1.getObjetoRouter(opcionDestino);

                    int menorCosto = routerOrigen->menorCosto(routerDestino->getNombre());

                    cout << "El menor costo para ir  del router " << routerOrigen->getNombre() << " al router " << routerDestino->getNombre() << " es de " << menorCosto << endl;

                    routerOrigen->tablaEnrutamiento.clear();

                    cout << endl;

                }
                else if(opcionMenuRedManual == 4){//Mostrar tabla

                    cout << "De que enrutador desea saber su tabla de enrutamiento\n";
                    red1.listarRouters("");

                    int routerTabla = menu2.validOpcion(red1.getCantRouters());
                    red1.crearTablaEnrutamiento(routerTabla);


                    Router* router = red1.getObjetoRouter(routerTabla);

                    router->mostrarTablaEnrutamiento();
                    router->tablaEnrutamiento.clear();

                    cout << endl;

                }
                else{
                    break;
                }
            }
        }
        else if(opcionMenuPrincipal == 2){
            Red red2;

            string nombreArchivo = red2.verificarArchivo();

            ifstream archivo; //Creo el objeto

            archivo.open(nombreArchivo, ios::in); //Abro el archivo

            string linea;
            while(getline(archivo, linea)){
                if(linea.substr(0,7) == "Routers"){
                    string nombreRouter;
                    string routers = linea.substr(linea.find(" ") + 1);
                    int inicio = 0;
                    while(routers.find(",") != string::npos){
                        nombreRouter = routers.substr(inicio, routers.find(","));

                        Router* router = new Router(nombreRouter);
                        //Agrego el router creado a la red
                        red2.agregarRouter(router);

                        routers = routers.substr(routers.find(",") + 1);
                    }
                    //Esta parte es para agregar el nombre del final
                    Router* router = new Router(routers);
                    red2.agregarRouter(router);
                }
                else{

                }
            }



        }
        else{
            break;
        }
    }

    return 0;
}
