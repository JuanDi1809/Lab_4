#ifndef RED_H
#define RED_H

#include <vector>
#include "Red.h"
#include "Router.h"

class Red
{
public:
    vector <Router*> routers;

     //Constructor
     Red();

     //destructor
     ~Red();

     //Getter
     int getCantRouters() const;

     //Geetter para obtener un objeto Router con posicion
     Router* getObjetoRouter(int) const;

     //Getter para obtenejr un onjeto router con el nombre
     Router* getObjetoRouter2(string);

     //Meotodo para verificar que los nombres de los routers no esten repetidos
     string verificarRouter();

     //Metodo para agregar un router
     void agregarRouter(Router*);

     //Metodo para listar los routers menos el nombre del router que agrego
     void listarRouters(string);

     //Metodo para crear tabla de enrutamiento
     void crearTablaEnrutamiento(int);

     //Metodo par aeliminar enrutador
     void eliminarEnrutador(int);

    //Metodo para eliminar el enrutador de la tabla de enrutamiento y de los routers con el que son vecinos
     void eliminarVecinos(int);

    //METODOS PARA CREAR LA RED DESDE UN ARCHIVO

     //Metodo para verificar el nombre de archivo
     string verificarArchivo();

};

#endif // RED_H
