#include <iostream>
#include <cctype>    // para toupper
#include "funciones.h"
#include "menu.h"
using namespace std;


int main()
{

    mostrarCartelInicio();
    srand(time(nullptr));

    menu();
    return 0;
}
