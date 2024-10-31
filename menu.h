#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED




void pedirNombres();
void creditos();
bool menu();



void pedirNombres (){ //funcion jugar

    string jugador1,jugador2;
    string confirmacion = "no";

    while (confirmacion != "si"){
        system("cls");
        cout<<"Ingrese el nombre del jugador 1: ";
        cin>>jugador1;
        cout<<endl;
        cout<<"Ingrese el nombre del jugador 2: ";
        cin>>jugador2;
        cout<<endl;

        cout<<"Jugador 1: "<< jugador1<<", Jugador 2: "<<jugador2<<endl;
        cout<<endl;
        cout<<"¿Confirmar nombres? (si/no): "<<endl;
        cout<<endl;

        cin>>confirmacion;
        if (confirmacion == "no") {

            cout<<endl;
            cout << "Por favor, ingrese los nombres nuevamente"<<endl;
            cout<<endl;
            system("pause");

        }

    }
    cout<<"Comienza el juego entre: "<<jugador1<<" y "<<jugador2<<endl;
    cout<<endl;

}

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
  while(true){
      system("cls");
      cout<<"BONZO"<<endl;
      cout<<endl;
      cout<< "----Menu Bonzo----"<<endl;
      cout<<endl;
      cout<<"1) - JUGAR "<<endl;
      cout<<"2) - ESTADISTICAS "<<endl;
      cout<<"3) - CREDITOS "<<endl;
      cout<<endl;
      cout<< "------------------"<<endl;
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
            pedirNombres();
            system("pause");   // genera una pausa entre las opciones
        break;
        case 2:
            system("cls");
            cout<< "- Estadistica -"<<endl;
            cout<<endl;
            //estadisticas();
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




}







#endif // MENU_H_INCLUDED
