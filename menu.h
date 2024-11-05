#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "funciones.h"

void creditos();
bool menu();


void creditos(){

    cout<< endl;
    cout<<"----- EQUIPO 11 -----"<< endl;
    cout<< endl;
    cout<<"---- INTEGRANTES-----"<< endl;
    cout<< endl;
    cout<<" JUAN CARLOS CALVO - 31736"<< endl;
    cout<<" GISELA FATIMA CASTILLO - 31745"<< endl;
    cout<<" DANIEL LUNA - 28177"<< endl;
    cout<< endl;



}



bool menu(){

      int opciones;

      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<< "-------  Menu -------"<<endl;
      cout<<endl;
      cout<<"1) - JUGAR "<<endl;
      cout<<"2) - ESTADISTICAS "<<endl;
      cout<<"3) - CREDITOS "<<endl;
      cout<<endl;
      cout<< "---------------------"<<endl;
      cout<<endl;
      cout<<"0) - SALIR "<<endl;
      cout<<endl;
      cout<<"Opcion"<<endl;
      cin>> opciones;

      switch(opciones){

        case 1:
            system("cls");     // opcion para ocultar el menu
            cout<< "- Jugar -"<<endl;
            cout<<endl;
            jugar();
            system("pause");   // genera una pausa entre las opciones
        break;
        case 2:
            system("cls");
            cout<< "- Estadistica -"<<endl;
            cout<<endl;
            //estadisticas();
            cout<<"Seccion estadistica";
            system("pause");
        break;
        case 3:
            system("cls");
            cout<< "- Creditos -"<<endl;
            cout<<endl;
            creditos();
            system("pause");
        break;
        case 0:
            return 0;
        break;
        default:
            cout<<"Opcion incorrecta, ingrese una opcion valida "<<endl;
            system("pause");
        break;


    }
  }












#endif // MENU_H_INCLUDED
