#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string  correo, estadoaux;
int carnet, ciclo, carnetaux, id, idaux;
char seccion[2];//Creamos las variable globales con si tipo de dato
char estado[2];
char alumno[25];
double promedio, promedioaux;
bool y = false;
char x;

void nuevo()//Funciom #1: Agregar un nuevo alumno
{
    ofstream archivo;//Crea el archivo, si esta existente lo lee
    ifstream lectura;//Abre el archivo
    do{
    archivo.open("Estudiante.txt", ios::out | ios::app);//abre el archivo
    lectura.open("Estudiante.txt", ios::in);//leemos el archivo

    if (archivo.is_open() && lectura.is_open()){
            bool z =false;
            cout<<"Ingresa el carnet del alumno:";//El sistema solicita el carnet que sera el identificador para validar su existencia
            cin>>idaux;//ingresamos el identificador
            lectura>>id;//Ira a leer el archivo
            while (!lectura.eof()){
                lectura>>alumno>>correo>>seccion>>ciclo>>estado>>promedio;//Lee dato por dato para halle el identificador
                if (idaux==id){//Si el identificador es igual al id(carne) me dira que ya existe
                    cout<<"Ya existe el carnet";
                    z=true;
                    break;
                }
                lectura>>id;
            }
            if (z==false){
                cout<<"Ingresa el nombre del alumno: "<<endl;//Pide dato por dato 
                cin>>alumno;
                cout<<"Ingresa el correo electronico: "<<endl;
                cin>>correo;
                cout<<"Ingresa la seccion del alumno: "<<endl;
                cin>>seccion;
                cout<<"Ingresa ingrese el ciclo escolar: "<<endl;
                cin>>ciclo;
                cout<<"Ingresa ingrese el estado A = Aprobado y R = reprobado : "<<endl;
                cin>>estado;
                cout<<"Ingresa ingrese el promedio: "<<endl;
                cin>>promedio;
                archivo<<idaux<<" "<<alumno<<" "<<correo<<" "<<seccion<<" "<<ciclo<<" "<<estado<<" "<<promedio<<endl;//En el orden asi van ingresando
                cout<<"El alumno se agrego correctamente"<<endl;//mensaje de confirmacion
            }
            cout<<"Desea agregar otro : "<<endl;
            cout<<"S = si  : "<<endl;
            cout<<"N = no : "<<endl;
            cin>>x;
        }else{
        cout<<"No es posible abrir el documento"<<endl;
    }
    archivo.close();//cierra los archivos
    lectura.close();
    }while (x=='S' or x=='s');
}

void encontrar()//Funcion#2: Buscara un alumno y lo mostrara en pantalla
{
    ifstream leer;//me va leer el archivo
    leer.open("Estudiante.txt", ios::out | ios::in);

    y=false;

    if (leer.is_open()){
        cout<<"Ingresa el carnet del alumno que desea encontrar: ";//El sistema solicita el numero para identifica
        cin>>idaux;//El identifiador se ingresa en nuestra variable

        leer>>id;
        while(!leer.eof()){//lee el archivo desde el inicio hasta el final
        leer>>alumno>>correo>>seccion>>ciclo>>estado>>promedio;
        if(idaux==id){//Si el identificador es igual a nuestro dato, muestra la informacion de la linea
            cout<<"Nombre: "<<alumno<<endl;
            cout<<"Correo "<<correo<<endl;
            cout<<"Seccion: "<<seccion<<endl;
            cout<<"Ciclo escolar: "<<ciclo<<endl;
            cout<<"Estado:"<<estado<<endl;
            cout<<"Promedio: "<<promedio<<endl;
            y=true;
            break;
        }
        leer>>id;
        }
        if (y==false){
            cout<<"El carnet no existe: "<<idaux<<endl;
        }
    }else{
        cout<<"No es posible abrir el documento";
    }
    leer.close();
}

void actualizar()//Funcion#3: Modificara el alumno
{
    ofstream auxiliar;
    ifstream leer;

    y=false;

    auxiliar.open("auxiliar.txt", ios::out);
    leer.open("Estudiante.txt", ios::in);

    if (auxiliar.is_open() && leer.is_open()){

    
        cout<<"Ingresa el carnet del alumno que deseas actualizar: ";
        cin>>idaux;

            leer>>id;
            while (!leer.eof()){
                leer>>alumno>>correo>>seccion>>ciclo>>estado>>promedio;
                if (idaux==id){
                    y=true;               
                    cout<<"Nombre: "<<alumno<<endl;
                    cout<<"Correo "<<correo<<endl;
                    cout<<"Seccion: "<<seccion<<endl;
                    cout<<"Ciclo escolar: "<<ciclo<<endl;
                    cout<<"Estado:"<<estado<<endl;
                    cout<<"Promedio: "<<promedio<<endl;
                    cout<<"Ingresa el nuevo estado del alumno : "<<idaux;
                    cin>>estadoaux;

                    auxiliar<<id<<" "<<alumno<<" "<<correo<<" "<<seccion<<" "<<ciclo<<" "<<estadoaux<<" "<<promedio<<endl;
                    cout<<"El estado del alumno fue actualizado";
                    }else{
                    auxiliar<<carnet<<" "<<alumno<<" "<<correo<<" "<<seccion<<" "<<ciclo<<" "<<estado<<" "<<promedio<<endl;
                    }
                leer>>id;
            }
    }else{
        cout<<"No es posible abrir el documento";
    }
    if (y==false){
                cout<<"No se encontro el carnet"<<idaux;
            }
    auxiliar.close();
    leer.close();
    remove ("Estudiante.txt");
    rename("auxiliar.txt", "Estudiante.txt");
}

void actualizarpromedio()
{
    ofstream auxiliar;
    ifstream leer;

    y=false;

    auxiliar.open("auxiliar.txt", ios::out);
    leer.open("Estudiante.txt", ios::in);

    if (auxiliar.is_open() && leer.is_open()){

    
        cout<<"Ingresa el carnet del alumno que deseas actualizar: ";
        cin>>idaux;

            leer>>id;
            while (!leer.eof()){
                leer>>alumno>>correo>>seccion>>ciclo>>estado>>promedio;
                if (idaux==id){
                    y=true;               
                    cout<<"Nombre: "<<alumno<<endl;
                    cout<<"Correo "<<correo<<endl;
                    cout<<"Seccion: "<<seccion<<endl;
                    cout<<"Ciclo escolar: "<<ciclo<<endl;
                    cout<<"Estado:"<<estado<<endl;
                    cout<<"Promedio: "<<promedio<<endl;
                    cout<<"Ingresa el nuevo promedio del alumno : "<<idaux;
                    cin>>promedioaux;

                    auxiliar<<id<<" "<<alumno<<" "<<correo<<" "<<seccion<<" "<<ciclo<<" "<<estado<<" "<<promedioaux<<endl;
                    cout<<"El promedio del alumno fue actualizado";
                    }else{
                    auxiliar<<carnet<<" "<<alumno<<" "<<correo<<" "<<seccion<<" "<<ciclo<<" "<<estado<<" "<<promedio<<endl;
                    }
                leer>>id;
            }
    }else{
        cout<<"No es posible abrir el documento";
    }
    if (y==false){
                cout<<"No se encontro el carnet"<<idaux;
            }
    auxiliar.close();
    leer.close();
    remove ("Estudiante.txt");
    rename("auxiliar.txt", "Estudiante.txt");
}

int main(){
	int eleccion=0;
    do{
        system("cls");
        cout<<"*****REGISTRO DE ALUMNOS*****"<<endl;
        cout<<"1 - INGRESAR ALUMNO"<<endl;
        cout<<"2 - BUSCAR ALUMNO"<<endl;
        cout<<"3 - MODIFICAR"<<endl;
        cout<<"4 - SALIR"<<endl;
        cout<<"FAVOR DE ELEGIR UNA OPCION  "<<endl;
        cin>>eleccion;
    
    switch (eleccion){
	    case 1: nuevo();
        break;

        case 2: encontrar();
            system ("pause");
        break;
        
        case 3: actualizar();
          system ("pause");
          actualizarpromedio();
        break;
        
        case 4:
        cout<<"Saliendo..."; system ("pause");
        break;
        
        default:
        cout<<"opcion Invalida";system ("pause");
         break;    
    }
       }while (eleccion!=4);
    system("cls");
    return 0;
}
    
