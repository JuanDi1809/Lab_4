#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

int Menu::validOpcion(int cantOpciones){
    string opcionIni;
    int opcion;

    while(true){
        try{
            cout << "Ingresa una opcion: ";
            cin >> opcionIni;

            if(opcionIni.size() > 1 || opcionIni.size() == 0 ) throw out_of_range("solo es un caracter");

            opcion = stoi(opcionIni);

            if(opcion < 1 || opcion > cantOpciones) throw out_of_range("no esta dentro de las opciones");

            break;

        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
        catch(...){
            cerr << "Error: opcion no valida" << endl;
        }
    }

    return opcion;
}

void Menu::menuPrincipal(){
    cout << "1. Crear red(forma manual)\n";
    cout << "2. Crear red(topografia desde archivo)\n";
    cout << "3. crear red(forma aleatoria)\n";
    cout << "4. salir del sistema\n";
}

void Menu::menuRedManual(){
    cout << "1. Agregar enrutador\n";
    cout << "2. Remover enrutador\n";
    cout << "3. Costo de envio\n";
    cout << "4. Volver al menu principal\n";
}
