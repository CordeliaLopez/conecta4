//
//  main.cpp
//  TareaIntegradora
//
//  Created by Corde Lopez on 11/2/17.
//  Copyright © 2017 Corde Lopez. All rights reserved.
//



#include <iostream>
using namespace std;

void mostrarTablero (char matriz [][7], int cant, int arr[]){
    for (int cont = 0 ; cont < cant; cont ++){
        cout<<arr[cont]<<" ";
    }
    cout<<endl;
    for (int contR = 0; contR < cant; contR++){
        
        for (int contC=0; contC < cant; contC++ ){
            cout<<matriz[contR][contC]<<" ";
            }
            cout<<endl;
        }
}

void validacion (char board [][7], int invalida, int& fila, int cant){
    do {
        invalida = 0;
        cout<<"Cual fila?"<<endl;
        cin>>fila;
        if (fila < 1 || fila > 7){
            cout<<"Fila inválida! Vuelva a intentar."<<endl;
            invalida++;
        }
    
    }
    while (invalida != 0);
}

void atenderJugador(char board[][7], int fila, int turno, int poner, int& rowt, int cant){
    poner = 0;
    int invalida = 0;
        for (int contR = cant; contR >=0 ; contR--){
            if (board[contR][fila-1] == '-')
                invalida = 0;
            else
                invalida++;
        }
        if (invalida == 0){
            for (int row = 6; row >= 0; row--){
                if(board[row][fila-1] == '-'){
                    if (poner == 0){
                        if (turno % 2 != 0){
                            board[row][fila-1] = 'X';
                            rowt = row;
                        }
                        else{
                            board[row][fila-1] = 'O';
                            rowt = row;
                        }
                poner++;
            }
        }
    }
    }
}
void verificarVertical (char board[][7], int& ocupado, int fila, int cant, int turno){
    ocupado = 0;
    for (int contR = 0; contR < cant; contR++){
        if (ocupado != 4){
        if (turno % 2 != 0){
            if (board[contR][fila-1] == 'X')
                ocupado++;
            else
                ocupado = 0;
        }
        else{
            if (board[contR][fila-1] == 'O')
                ocupado++;
            else
                ocupado = 0;
        }
    }
    }
}

void verificarHorizontal(char board[][7], int&ocupado, int rowt, int cant, int turno){
    ocupado=0;
    for (int contC = 0; contC < cant; contC++){
        if (ocupado !=4){
        if (turno % 2 != 0){
            if (board[rowt][contC] == 'X')
                ocupado++;
            else
                ocupado = 0;
        }
        else{
            if (board[rowt][contC] == 'O')
                ocupado++;
            else
                ocupado = 0;
        }
        }
    }
}

void verificarDiagonalNormal(char board [][7], int fila, int rowt, int& ocupado, int cant, int turno){
    ocupado = 0;
    int conta = 1;
    for (int contR = 0; contR<cant; contR++){
        for (int contC = 0; contC < 4; contC++){
            if ((board[contR][contC] != '-') && (ocupado != 4)){
        ocupado = 1;
        conta = 1;
        do{
            if (board[contR][contC] == board[contR+conta][contC+conta] ){
                        ocupado++;
                }
            conta++;
            
            }
        while(conta < 4);
        }
        }
   }
}

void verificarDiagonalContra(char board [][7], int fila, int rowt, int& ocupado, int cant, int turno){
    ocupado = 0;
    int conta = 1;
    for (int contR = 0; contR<cant; contR++){
        for (int contC = cant-1; contC >= 3; contC--){
            if ((board[contR][contC] != '-') && (ocupado != 4)){
                ocupado = 1;
                conta = 1;
                do{
                    if (board[contR][contC] == board[contR+conta][contC-conta] ){
                        ocupado++;
                    }
                    conta++;
                    
                }
                while(conta < 4);
            }
        }
    }
}


void tableroLleno(char board[][7], int cant, int& ocupado){
    int ralla=0;
    for (int contR=0; contR<cant; contR++){
        for(int contC=0; contC<cant;contC++){
            if (board[contR][contC] == '-'){
                ralla++;
            }
        }
    }
    if (ralla == 0){
        ocupado = 4;
    }
}

int main() {
    char board [7][7], seguir = tolower('n');
    int primerafila[7];
    int cant= 7;
    int turno=1;
    int fila= 0, rowt = 0;
    int invalida = 0;
    int poner = 0;
    int ocupado = 0;
    
    for (int cont = 0 ; cont < cant; cont ++){
        primerafila[cont] = cont+1;
    }
    
    for (int contR = 0; contR < cant; contR++){
    
        for (int contC=0; contC < cant; contC++ ){
            board[contR][contC] = '-';
        }
    }
     mostrarTablero(board, cant, primerafila);
    
    do {
        seguir = 'n';
        validacion(board, invalida, fila, cant);
        atenderJugador(board, fila, turno, poner, rowt, cant);
        verificarVertical(board, ocupado, fila, cant, turno);
        if (ocupado == 4 && turno % 2 == 0){
            mostrarTablero(board, cant, primerafila);
            cout<<"Player Two Wins!"<<endl;
        }
        else if (ocupado == 4 && turno % 2 != 0){
            mostrarTablero(board, cant, primerafila);
            cout<<"Player One Wins!"<<endl;
        }
        
        if (ocupado != 4){
        verificarHorizontal(board, ocupado, rowt, cant, turno);
        
        if (ocupado == 4 && turno % 2 == 0){
            mostrarTablero(board, cant, primerafila);
            cout<<"Player Two Wins!"<<endl;
        }
        else if (ocupado == 4 && turno % 2 != 0){
            mostrarTablero(board, cant, primerafila);
            cout<<"Player One Wins!"<<endl;
            }
        }
        
        if(ocupado != 4){
            verificarDiagonalNormal(board, fila, rowt, ocupado, cant, turno);
            
            if (ocupado == 4 && turno % 2 == 0){
                mostrarTablero(board, cant, primerafila);
                cout<<"Player Two Wins!"<<endl;
            }
            else if (ocupado == 4 && turno % 2 != 0){
                mostrarTablero(board, cant, primerafila);
                cout<<"Player One Wins!"<<endl;
            }
        }
        
        if(ocupado != 4){
            verificarDiagonalContra(board, fila, rowt, ocupado, cant, turno);
            
            if (ocupado == 4 && turno % 2 == 0){
                mostrarTablero(board, cant, primerafila);
                cout<<"Player Two Wins!"<<endl;
            }
            else if (ocupado == 4 && turno % 2 != 0){
                mostrarTablero(board, cant, primerafila);
                cout<<"Player One Wins!"<<endl;
            }

        }
        if (ocupado != 4){
            tableroLleno(board, cant, ocupado);
            if(ocupado==4){
                mostrarTablero(board, cant, primerafila);
                cout<<"Empate"<<endl;
            }
        }
        if (ocupado != 4){
            mostrarTablero(board, cant, primerafila);
            do{
            cout<<"Quiere seguir jugando?"<<endl;
                cin>>seguir;
                seguir = tolower(seguir);
            }
            while (seguir != 's' && seguir != 'n');
            
            turno++;
        }
    }
    while (seguir == 's' && ocupado != 4);
    
    
    
    return 0;
    }
