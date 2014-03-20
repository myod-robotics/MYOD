/*
	Esto es un archivo de prueba en desarrollo.

Author: Roberto Herrera Esteban
Date: 18/03/14
Last change: 18/03/14



*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#define size 126
#define sizew 8

//#define debug
using namespace std;
//using namespace space;

char dato[size];
int nlineas=0;
int nservos=0;
int di=0;
int contador=0;
int linea=0;
int iter = 0;


int main() {

	string nombre;
	cout << "Introduze el nombre del archivo a cargar" << endl;
	cin >> nombre;
	nombre = nombre + ".txt";
	char *nombreFichero = strdup(nombre.c_str());
	/// Buffer de datos
	ifstream importar;
	importar.open(nombreFichero,ios::in);
	
	if(importar.good()){
       while(importar.eof()!=1){
          nlineas++;
          importar.getline(dato,size,'\n');
          do{
             if (dato[di] == ','){
                nservos++;
             }
             #ifdef debug
             cout << dato[di];
             #endif
             di++;
          }while(dato[di]!= '\0');
          #ifdef debug
          cout << di << endl;
          #endif
          di=0;
       }
	nservos= nservos/nlineas;
	
	cout << endl << "Numero de movimientos: " << nlineas << endl;
	cout << endl << "Numero de servos: " << nservos << endl << endl;
	
	char vector[nlineas][nservos+1][sizew];
	for(int i=0;i<nlineas;i++){
       for(int j=0;j<nservos+1;j++){
          for(int k=0;k<sizew;k++){
                  vector[i][j][k]=' ';
                  #ifdef debug
                  //cout<< i << j  << "-" << k << endl;
                  #endif
          }
       }
    }
 // Guardar datos en el programa
	importar.seekg(0,ios::beg);
	importar.clear();
	
	di=0;
	contador=0;
	linea=0;
	#ifdef debug
	cout << "Guardando datos" << endl;
	#endif
	while(importar.eof()!=1){
       importar.getline(dato,size,'\n');
       
       do{
          if(dato[di]!=','){
            if((dato[di]=='{')){
            }else if(dato[di]=='}'){
               vector[linea][contador][iter]='\0';
            }else{
               vector[linea][contador][iter]=dato[di];
               #ifdef debug
               //cout << dato[di];
               cout << vector[linea][contador][iter];
               #endif
               iter++; 
            }
          }else {
             vector[linea][contador][iter]='\0'; 
             contador++;
             iter=0;
             #ifdef debug
             cout << " ";
             #endif
          }
          #ifdef debug
          //cout << di;
          #endif
          di++;

       }while(dato[di]!='\0');
       #ifdef debug
       cout << endl;
       cout << di << endl;            
       #endif          
       di=0;
       contador=0;
       linea++; 
    }
    #ifdef debug
    cout << "---------------" <<endl;
    #endif
    
    linea=0;
	iter=0;
	di=0;
	contador=0;
	do{
       do{
               #ifdef debug
               //cout <<"contador->" << contador << " ";
               #endif
          while(vector[linea][contador][iter]!='\0'){
                                                     #ifdef debug
             cout << vector[linea][contador][iter];
             #endif
             iter++;
          }
          iter=0;
          contador++;
          #ifdef debug
          cout << " ";
          #endif
       }while(contador<nservos+1);
       contador=0;
       linea++;
       #ifdef debug
       cout << endl;
       #endif
    }while(linea<nlineas);
    linea=0;
	di=0;
	iter=0;
	contador=0;
	
	
	for(int x=0;x<nlineas;x++){
	int i=0;
	   while(vector[x][nservos][i]!='\0'){
          if(vector[x][nservos][i]==' '){
                            vector[x][nservos][i]='\0'; 
                            #ifdef debug                                         
	      cout << vector[x][nservos][i] ;
	      #endif
       }
	   i++;
       }
    }
    #ifdef debug
    cout<< endl;
    #endif
	
	
	
	//fichero de salida
		string nombr_e;
		string robot;
		cout<< "Introduze un nombre para exportar el archivo" << endl;
		cin >> nombr_e;
		cout<< "Nombre del objeto de la case Robot" << endl;
		cin >> robot;
		
		#ifdef debug
		cout<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" ; 
		#endif
		string nombr_exp = nombr_e + "_exported.txt";
		char *nombreExp = strdup(nombr_exp.c_str());
        ofstream exportar;
        exportar.open(nombreExp,ios::out|ios::trunc);
		
		//nombre de la funcion
		exportar << "void " << nombr_e << "(){" << endl << endl;
		//declaracion
		for(int i= 0; i < nlineas;i++){
		//tiempo
			exportar << "int time_" << i+1 << " = " ;
			int x=0;
			while(vector[i][0][x]!='\0'){
                    #ifdef debug
                    cout<< vector[i][0][x];
                    #endif
				exportar << vector[i][0][x];
				x++;
			}
            x=0;	
			exportar << ";" << endl;
			//posiciones
			exportar << "int vector_" << i+1 << "[" << nservos << "] = {";
			for(int j=1;j<nservos+1;j++){
				//ultima
				if(j==nservos){
				    int y = 0;          // 	for(int y = 0; y < 8; y++){
                    while(vector[i][j][y]!='\0'){
						exportar << vector[i][nservos][y];
						y++;
					}
					exportar << "};" << endl;
				}else{
                      int y =0;
					while(vector[i][j][y]!='\0'){
						exportar << vector[i][j][y];
						y++;
					}
					exportar << ",";
				}
			}
		}
		// movimientos
		exportar << endl << endl;
		for(int i= 0; i <nlineas;i++){
			exportar << robot << ".move(time_" << i+1 << ", vector_" << i+1 << ");" << endl;
		}
		//fin
		exportar << endl << "}" ;
		
		exportar.close();
		
		cout<< "Exportacion finalizada" << endl << endl;
		
		
		

			
	
	}else{
		cout<< "Fallo al abrir el archivo" << endl << endl;
	}
	

return 0;
}



