#include <iostream>
#include <cctype>    // para toupper
#include "funciones.h"
using namespace std;


int main()
{
    mostrarCartelInicio();
    srand(time(nullptr));

    jugar();
    return 0;
}
