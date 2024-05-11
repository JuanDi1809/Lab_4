#include "router.h"
#include "red.h"
#include "menu.h"

#include <iostream>
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
        int opcionMenuPrincipal = menu1.validOpcion(4);

        cout << endl;

        if(opcionMenuPrincipal == 1){
            Red red1;

            while(true){
                Menu menu2;

                menu2.menuRedManual();
                int opcionMenuRedManual = menu2.validOpcion(4);

                cout << endl;

                if(opcionMenuRedManual == 1){ //Agregar enrutador

                    string nameRouter;

                    if(red1.getCantRouters() == 0){ //Al primer router no se le piden vecinos
                        nameRouter = red1.verificarRouter();
                        Router* router = new Router(nameRouter);
                        red1.agregarRouter(router);
                    }
                    else{ //Apratir del segundo router
                        nameRouter = red1.verificarRouter();
                        Router* router = new Router(nameRouter);

                        red1.agregarRouter(router);//Esto despues se elimina

                        while(true){ //Si selecciona nuevamente el mismo router es como si volviera a actualizar los datos
                            cout << "Selecciona el vecino para el router\n";
                            red1.listarRouters();

                            int opcionRouter = menu2.validOpcion(red1.getCantRouters());
                            Router* routerVecino = red1.getObjetoRouter(opcionRouter);

                            int costo;
                            cout << "Ingresa el costo hacia el router";
                            cin >> costo;

                            router->nuevoVecino(routerVecino, costo);




                            cout << endl;

                            cout << "Desea ingresar mas vecinos\n";
                            cout << "1. Si\n";
                            cout << "2. No\n";
                            int opcionVecino = menu2.validOpcion(2);

                            if(opcionVecino == 2) break;
                        }
                    }

                    cout << endl;
                }
                else if(opcionMenuRedManual == 2){//Remover enrutador
                    break;
                }
                else if(opcionMenuRedManual == 3){ //Costo envio
                    break;
                }
                else{
                    break;
                }
            }
        }
        else if(opcionMenuPrincipal == 2){

        }
        else if(opcionMenuPrincipal == 3){

        }
        else{
            break;
        }
    }

    return 0;
}
