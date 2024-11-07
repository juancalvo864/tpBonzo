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
 //Funcion separador
void separador(char indicador){
    if(indicador == 's'){
        cout <<endl;
        cout << "-------------------------------------------------------" << endl;
        cout <<endl;
    }else if(indicador == 'b'){
        cout <<"BONZO"<<endl;
        cout << "-------------------------------------------------------" << endl;
        cout <<endl;
    }
}

//Funcioon pedir bnombre

void cargarNombres(string &jugador1, string &jugador2,char &continuar) {

    while (continuar == 'N') {
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout << "Antes de comenzar deben registrar sus nombres: "<<endl;
        cout <<endl;
        cout << "Ingrese nombre de jugador 1: ";
        cin >> jugador1;
        cout << "Ingrese nombre de jugador 2: ";
        cin >> jugador2;
        system("cls");
        cout<< "Los jugadores son: "<<endl;
        cout << endl;
        cout << "Nombre jugador numero 1: " << jugador1 << endl;
        cout << "Nombre jugador numero 2: " << jugador2 << endl;
        cout << endl;

        cout << "¿Confirmar nombres? (S/N): ";
        cin >> continuar;
        continuar = toupper(continuar);
        system("cls");
    }
}

//Funcion jugador inicial
void jugadorInicial (int &jugadorActual,int dados[] ){
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
        system("pause");
        cout <<endl;
        dados[0]=lanzarDados();
        cout<< "El numero del dado es: "<<dados[0]<<endl;
        cout <<endl;
        jugadorActual = dados[0] % 2 == 0 ? 2 : 1;
        cout<<"Comienza el jugador nro "<< jugadorActual <<"!!"<< endl;
        cout <<endl;
        system("pause");
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
    int acumNroProhibido[2] = {};
    int acumLanzamiento[2]= {};
    int jugadorActual;
    int lanzamientos;

    cargarNombres(jugador1,jugador2,continuar);
    jugadorInicial(jugadorActual,dados);

    dobleNroProhibido[0] = false;
    dobleNroProhibido[1] = false;


    for(int ronda = 1; ronda <= 6; ronda++){
            system("cls");
            for (int turno = 0; turno < 2; turno++) {
                lanzamientos = 0;
                acumPuntos = 0;
                continuar = 'S';
                bool turnoTerminado = false;
                int nroDados = 3;
                if(dobleNroProhibido[jugadorActual - 1]){
                    nroDados =2;
                }

                int numerosIguales = 0;

                while (continuar == 'S' && !turnoTerminado) {
                        lanzamientos ++;
                        separador('b');
                        acumLanzamiento[jugadorActual - 1] ++;
                        cout<<((jugadorActual == 1 )? jugador1 : jugador2)  <<" tire los dados"<<endl;
                        system("pause");
                        for(int i = 0; i < nroDados; i++){
                            dados[i] = lanzarDados();
                        }
                        system("cls");
                        separador('b');
                        cout <<"PUNTOS GANADOS:" <<endl;
                        cout <<endl;
                        cout <<jugador1<<": "<<puntosJugador1<<" PUNTOS                  "<<jugador2<<": "<<puntosJugador2<<" PUNTOS"<<endl;
                        cout <<endl;
                        cout <<"Turno de: " << ((jugadorActual == 1) ? jugador1 : jugador2) << endl;
                        cout <<endl;
                        cout <<"+--------------------------------------------------+"<<endl;
                        cout <<"|        Ronda #"<<ronda<<"                                  |"<<endl;
                        cout <<"|        PUNTOS DE LA RONDA: "<<acumPuntos<<"                     |"<<endl;
                        cout <<"|        LANZAMIENTOS: "<<lanzamientos<<"                           |"<<endl;
                        cout <<"+--------------------------------------------------+"<<endl;
                        cout <<endl;
                        cout <<"NUMERO PROHIBIDO: "<<acumNroProhibido[jugadorActual-1]<<endl;
                        cout <<endl;
                        cout <<"LANZAMIENTO #" <<acumLanzamiento[jugadorActual-1]<< endl;
                        cout <<endl;
                        for(int i = 0; i < nroDados; i++){
                            mostrarCaraDado(dados[i]);
                        }

                        numerosIguales = numIguales(nroDados,ronda,dados);

                        if(numerosIguales == 1){
                            cout << "Malas noticias, sacaste el numero prohibido, perdiste "<<acumPuntos<< " puntos y pierdes el turno" << endl;
                            dobleNroProhibido[jugadorActual -1] = false;
                            acumNroProhibido[jugadorActual - 1] += 1;
                            ((jugadorActual == 1) ? (puntosJugador1 -= acumPuntos) : (puntosJugador2 -= acumPuntos));
                            turnoTerminado = true;
                             acumPuntos = 0;
                            system("pause");
                        }else if(numerosIguales == 2){
                            cout << "Malas noticias, sacaste dos veces numero prohibido,  perdiste "<<acumPuntos<< " puntos  ,pierdes el turno y un dado para la proxima jugada"<<endl;
                            dobleNroProhibido[jugadorActual - 1] = true;
                            acumNroProhibido[jugadorActual - 1] += 2;
                            ((jugadorActual == 1) ? (puntosJugador1 -= acumPuntos) : (puntosJugador2 -= acumPuntos));
                            turnoTerminado = true;
                            acumPuntos = 0;
                            system("pause");
                        }else if(numerosIguales == 3){
                            cout << "Malas noticias, sacaste tres veces numero prohibido, no sumas puntos ,pierdes el juego " << endl;
                            //llevar al final del juego.
                            system("pause");
                        }else {
                            dobleNroProhibido[jugadorActual - 1] = false;
                            acumPuntos += sumar(nroDados,dados);
                            cout << "Bien! sumaste " <<sumar(nroDados,dados) << " puntos!" << endl;
                            if (jugadorActual == 1) {
                                puntosJugador1 += sumar(nroDados,dados);
                            } else {
                                puntosJugador2 += sumar(nroDados,dados);
                            }
                            cout << "¿Quieres continuar? (S/N): ";
                            cin >> continuar;
                            continuar = toupper(continuar);
                            if (continuar == 'N') {
                                turnoTerminado = true;
                            }
                        }
                        separador('s');
                        system("cls");
                    }

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


