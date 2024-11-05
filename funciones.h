#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <ctime>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

//Funcion Lanzar dados.
 int lanzarDados (){
     int nroRand = (rand()%6)+1;
     return nroRand;

 }

 //Funcion dados iguales
 int numIguales(int nroDados,int ronda,int dados[]){
    int contador = 0;
    for(int i = 0;i < nroDados;i++){
        if(dados[i] == ronda){
            contador++;
        }
    }
    return contador;
 }



  //funcion Sumar
 int sumar (int nroDados,int dados[]){
     int suma = 0;
    for(int i = 0;i<nroDados;i++){
        suma+= dados[i];
    }
    return suma;
 }

 //Funcion para dibujar los dados.
 void mostrarCaraDado(int numero) {
    switch (numero) {
        case 1:
            cout << " ------- " << endl;
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            cout << " ------- " << endl;
            break;
        case 2:
            cout << " ------- " << endl;
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            cout << " ------- " << endl;
            break;
        case 3:
            cout << " ------- " << endl;
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            cout << " ------- " << endl;
            break;
        case 4:
            cout << " ------- " << endl;
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            cout << " ------- " << endl;
            break;
        case 5:
            cout << " ------- " << endl;
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            cout << " ------- " << endl;
            break;
        case 6:
            cout << " ------- " << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << " ------- " << endl;
            break;
        default:
            cout << "Numero de cara invalido" << endl;
            break;
    }

}


 //funcion jugar.

 void jugar(){
    string jugador1,jugador2;
    char continuar = 'N';
    char tirarDado;
    int puntosJugador1 = 0;
    int puntosJugador2 = 0;
    int acumPuntos;
    bool bandera = true;
    int  dados[3]={};
    bool dobleNroProhibido[2] = {};

    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout << "Antes de comenzar deben registrar sus nombres: "<<endl;
    cout <<endl;
    while(continuar == 'N'){
        cout << "ingrese nombre de jugador 1: "<<endl;
        cin >> jugador1;
        cout << "ingrese nombre de jugador 2: "<<endl;
        cin >> jugador2;
        cout <<endl;
        cout<< "Nombre jugador numero 1: "<<jugador1<<endl;
        cout <<endl;
        cout<< "Nombre jugador numero 2: "<<jugador2<<endl;
        cout <<endl;
        cout << "¿Confirmar nombres? (S/N) "<<endl;
        cin >> continuar;
        continuar = toupper(continuar);
        cout <<endl;
        system("cls");
    }

        cout <<endl;
        cout <<endl;
        cout<<"Que comience el juego!!"<<endl;
        cout <<endl;
        cout<< "Recuerden que para tirar los dados lo van a hacer precionando la letra `T` + Enter.." <<endl;
        cout <<endl;
        cout<< "Antes de comenzar lancen un dado para ver quien comienza... "<<endl;
        cout <<endl;
        cout<< "Si el resultado es un número impar, inicia el jugador uno; si es un numero par, comienza el jugador dos."<<endl;
        cout <<endl;
        cout<< "Ahora si, que alguien lance un dado!!"<<endl;
        cout <<endl;
        dados[0]=lanzarDados();
        cout<< "El numero del dado es: "<<dados[0]<<endl;
        dobleNroProhibido[0] = false;
        dobleNroProhibido[1] = false;
        cout <<endl;
        int jugadorActual = dados[0] % 2 == 0 ? 2 : 1;
        cout<<"Comienza el jugador nro "<< jugadorActual <<"!!"<< endl;
        cout <<endl;



        for(int ronda = 1; ronda<=6;ronda++){
        cout << "------------------------------------------" << endl;
        cout <<endl;
            for (int turno = 0; turno < 2; turno++) {
                acumPuntos = 0;
                bool turnoTerminado = false;
                continuar = 'S';
                int nroDados = 3;
                if(dobleNroProhibido[jugadorActual - 1]){
                    nroDados =2;
                }

                int numerosIguales = 0;

                while (continuar == 'S' && !turnoTerminado) {
                        for(int i = 0;i<nroDados;i++){
                            dados[i] = lanzarDados();
                        }
                        cout<<"Ronda nro: "<<ronda<<endl;
                        cout << "------------------------------------------" << endl;
                        cout <<endl;
                        cout << "Turno del jugador: " << ((jugadorActual == 1) ? jugador1 : jugador2) << endl;
                        cout << "Los dados que salieron son: " << endl;
                        for(int i = 0;i<nroDados;i++){
                            mostrarCaraDado(dados[i]);
                        }

                        numerosIguales = numIguales(nroDados,ronda,dados);

                        if(numerosIguales == 1){
                            cout << "Malas noticias, sacaste el numero prohibido, perdiste "<<acumPuntos<< " puntos y pierdes el turno" << endl;
                            acumPuntos = 0;
                            dobleNroProhibido[jugadorActual -1]=false;
                            turnoTerminado = true;
                        }else if(numerosIguales == 2){
                            cout << "Malas noticias, sacaste dos veces numero prohibido,  perdiste "<<acumPuntos<< " puntos  ,pierdes el turno y un dado para la proxima jugada"<<endl;
                            acumPuntos = 0;
                            dobleNroProhibido[jugadorActual] = true;
                            turnoTerminado = true;
                        }else if(numerosIguales == 3){
                            cout << "Malas noticias, sacaste tres veces numero prohibido, no sumas puntos ,pierdes el juego " << endl;
                        }
                         else {
                            dobleNroProhibido[jugadorActual - 1] = false;
                            acumPuntos = sumar(nroDados,dados);
                            cout << "Bien! sumaste " << acumPuntos << " puntos!" << endl;
                            if (jugadorActual == 1) {
                                puntosJugador1 += acumPuntos;
                            } else {
                                puntosJugador2 += acumPuntos;
                            }
                            cout << "¿Quieres continuar? (S/N): ";
                            cin >> continuar;
                            continuar = toupper(continuar);
                            if (continuar == 'N') {
                                turnoTerminado = true;
                            }
                        }
                        cout << "*****************************************" << endl;
                        cout <<endl;
                    }
                cout << "------------------------------------------" << endl;
                cout <<endl;
                jugadorActual = (jugadorActual == 1) ? 2 : 1;
            }
        }
    cout<<puntosJugador1<<endl;
    cout<<puntosJugador2<<endl;
}




void mostrarCartelInicio() {

    cout << "****************************************************" << endl;
    cout << "*                                                  *" << endl;
    cout << "*      ____     ___    _   _   _____   ___         *" << endl;
    cout << "*     | __ )   / _ \\  | \\ | | |__  /  / _ \\     *" << endl;
    cout << "*     |  _ \\  | | | | |  \\| |   / /  | | | |     *" << endl;
    cout << "*     | |_) | | |_| | | |\\  |  / /_  | |_| |      *" << endl;
    cout << "*     |____/   \\___/  |_| \\_| /____|  \\___/     *" << endl;
    cout << "*                                                  *" << endl;
    cout << "****************************************************" << endl;
    }

#endif // FUNCIONES_H_INCLUDED


