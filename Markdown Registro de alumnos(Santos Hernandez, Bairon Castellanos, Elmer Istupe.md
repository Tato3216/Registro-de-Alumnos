# *******Sistema de Ingreso de Alumnos*******
##### _Version 1.0_
##### _Fecha de creacion 10/03/2022_
#### Autores
##### _-Santos Genaro Hernandez Gabriel_
##### _-Bairon Ismael Castellanos Valle_
##### _-Elmer Eduardo Istupe Ruiz_
### Librerías para la funcion en general
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

--------------------------------------------------------
##### Dar acceso del espacio de nombre
using namespace std;
#### _________________________________________________
##### Variables Globales
string  correo, estadoaux;
int carnet, ciclo, carnetaux, id, idaux;
char seccion[2];//Creamos las variable globales con si tipo de dato
char estado[2];
char alumno[25];
double promedio, promedioaux;
bool y = false;
char x;
##### ______________________________________________________
## FUNCION NUEVO
_En esta funcion el sistema solicitara datos especificos para nuevos registros_

void nuevo()//Funciom #1: Agregar un nuevo alumno
{
#### _Indicacion de creacion de la instancia(archivo)_
    ofstream archivo;//Crea el archivo, si esta existente lo lee
#### _Indicador para crear la instancia para leer (archivo)_
    ifstream lectura;//Abre el archivo
    do{
    archivo.open("Estudiante.txt", ios::out | ios::app);//abre el archivo
    lectura.open("Estudiante.txt", ios::in);//leemos el archivo

    if (archivo.is_open() && lectura.is_open()){
            bool z =false;
            
            
#### _Se le solicita al usuario el numero de carnet (Identificador para la funcion)_
            cout<<"Ingresa el carnet del alumno:";//El sistema solicita el carnet que sera el identificador para validar su existencia
            cin>>idaux;//ingresamos el identificador
#### _Se ingresara el identificador en la variable id para luego leer el archivo_
            lectura>>id;//Ira a leer el archivo
            while (!lectura.eof()){
                lectura>>alumno>>correo>>seccion>>ciclo>>estado>>promedio;//Lee dato por dato para halle el identificador
#### _Si hay un dato en el archivo igual al identificador, el sistema dira que ya existe_
                if (idaux==id){//Si el identificador es igual al id(carne) me dira que ya existe
                    cout<<"Ya existe el carnet";
                    z=true;
                    break;
                }
                lectura>>id;
            }
#### _Contrario: si el dato no es existente solicitara los siguientes datos_
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
#### _Al tener todos los datos del usuario se ingresaran al archivo en su orden correspondiente_
                archivo<<idaux<<" "<<alumno<<" "<<correo<<" "<<seccion<<" "<<ciclo<<" "<<estado<<" "<<promedio<<endl;//En el orden asi van ingresando
                cout<<"El alumno se agrego correctamente"<<endl;//mensaje de confirmacion
            }
#### _Si se desea agregar un dato el sistema dara opcion (Si/No)_
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
## _"Funcion Buscar registro"_
void encontrar()//Funcion#2: Buscara un alumno y lo mostrara en pantalla
{
    ifstream leer;//me va leer el archivo
    leer.open("Estudiante.txt", ios::out | ios::in);

    y=false;
#### _Se abrira el archivo (este va indicado en codigo) y al ingresar el identificador buscara en el archivo_
    if (leer.is_open()){
        cout<<"Ingresa el carnet del alumno que desea encontrar: ";//El sistema solicita el numero para identifica
        cin>>idaux;//El identifiador se ingresa en nuestra variable
#### _Leera el archivo de inicio a fin_
        leer>>id;
        while(!leer.eof()){//lee el archivo desde el inicio hasta el final
        leer>>alumno>>correo>>seccion>>ciclo>>estado>>promedio;
        if(idaux==id){//Si el identificador es igual a nuestro dato, muestra la informacion de la linea
#### _Mostrara los datos que esten en la linea del identificador que se encuentre_
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
## _Funcion para modificar un registro_
void actualizar()//Funcion#3: Modificara el alumno
{
    ofstream auxiliar;
    ifstream leer;

    y=false;
#### _Creamos un archivo auxiliar al cual pasaran los nuevos datos_
    auxiliar.open("auxiliar.txt", ios::out);
#### _Llamamos (leer) abrir el archivo al cual se le actualizara un registro_
    leer.open("Estudiante.txt", ios::in);

    if (auxiliar.is_open() && leer.is_open()){
#### _Nuevamente solicita el id como identificador_
        cout<<"Ingresa el carnet del alumno que deseas actualizar: ";
        cin>>idaux;
#### _(Leer) Se da lectura al archivo del inicio al final_
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
#### _Solicita el nuevo dato que se introducira_
                    cout<<"Ingresa el nuevo estado del alumno : "<<idaux;
                    cin>>estadoaux;
#### _Llamamos al archivo auxiliar y se introducen los datos ya actualizados_
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
## _Funcion para actualizar (promedio), DEtalles:__funcion anterior___


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

# _Punto de inicio de la ejecucion General_


int main(){
#### _Menu de Opciones_    

	int eleccion=0;//Variable que tomara el numero de eleccion elegida
    do{
        system("cls");
        cout<<"REGISTRO DE ALUMNOS"<<endl;
        cout<<"1 - INGRESAR ALUMNO"<<endl;
        cout<<"2 - BUSCAR ALUMNO"<<endl;
        cout<<"3 - MODIFICAR"<<endl;
        cout<<"4 - SALIR"<<endl;
        cout<<"FAVOR DE ELEGIR UNA OPCION  "<<endl;
        cin>>eleccion;
#### _Para definir multiples casos iniciamos un Switch_  
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
    