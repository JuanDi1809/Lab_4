#ifndef RED_H
#define RED_H

#include <vector>
#include "Red.h"
#include "Router.h"

class Red
{

private:
    vector <Router*> routers;

public:
     //Constructor
     Red();

     //destructor
     ~Red();

     //Getter
     int getCantRouters() const;

     //Geetter para obtner un onjeto Router
     Router* getObjetoRouter(int) const;

     //Meotodo para verificar que los nombres de los routers no esten repetidos
     string verificarRouter();

     //Metodo para agregar un router
     void agregarRouter(Router*);

     //Metodo para mostrar la tabla de routers
     void mostrarTabla(string);

     //Metodo para listar los routers
     void listarRouters();
};

#endif // RED_H
