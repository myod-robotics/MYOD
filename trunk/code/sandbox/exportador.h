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
using namespace std;
using namespace space;

int main() {

	string nombre;
	cout << "Introduze el nombre del archivo a cargar" << endl;
	cin >> nombre;
	nombre = nombre + ".txt";
	char *nombreFichero = strdup(nombre.c_str());
	/// Buffer de datos
	char datos[1024];
	int nlineas = 0;
	int npos = 0;
//	char c;

	ifstream fichero;
	fichero.open(nombreFichero,ios::in);
    if(fichero.good()){
		while(!fichero.eof()){
			fichero.getline(datos,1024);
			npos=0;
			for(int i=0;i<1024;i++){
				if(dato[i]=='\n'){
					nlineas++;
				}
				if(dato[i]==','){
					npos++;
				}
			}
		}
		//numero de lineas, tamaño de dato
		char vtime[nlineas][8];
		//numero de lineas, posicion del dato, tamaño de dato
		char vpos[nlineas][npos][4];
		int linea=-1;
		int iterator=0;
		
		int ic=0;
		
		//ponerse al principio del fichero   ??
		fichero.begin();
		
		while(!fichero.eof()){
			fichero.getline(datos,1024);
			ic=0;
			iterator = 0;
			linea = linea++;
			for(int i=0;i<1024;i++){
				if(dato[i]!=','){
					if(dato[i]=='{' || dato[i]=='}'){
						//no hacer nada
					}else{
						//tiempo
						if(ic==0){
							vtime[linea][iterator]=dato[i];
							iterator++;
						//posiciones
						}else{
							vtime[linea][ic-1][iterator] = dato[i];
						}
					}
				}else{
					//aumento la posicion del vector de posiciones o tiempo
					ic++;
					//poscion donde guardo la informacion
					iterator=0;
				}
				
			}
			
			
		}
		//cierro fichero
		fichero.close()
		
		
		// nuevo fichero de salida
		strig nombr_e;
		string robot;
		cout << "Introduze un nombre para exportar el archivo" << endl;
		cin >> nombr_e;
		cout << "Nombre del objeto de la case Robot" << endl;
		cin >> robot;
		nombr_exp= nombr_e + "_exported.txt";
		char *nombreExp = strdup(nombre.c_str());
        ofstream exportar;
        exportar.open(nombreExp,ios::out|ios::trunc);
		
		//nombre de la funcion
		exportar << "void " << nombr_e << "(){" << endl << endl;
		//declaracion
		for(int i= 0; i < nlineas;i++){
		//tiempo
			exportar << "int time_" << i+1 << " = " ;
			for(int x = 0; x < 8; x++){
				exportar << vtime[i][x];
			}	
			exportar << ";" << endl;
			//posiciones
			exportar << "int vector_" << i+1 << "[] = {";
			for(int j=0;j<npos;j++){
				//ultima
				if(j==npos-1){
					for(int y = 0; y < 4; y++){
						exportar << vpos[i][j][y];
					}
					exportar << "};" << endl;
				}else{
					for(int y = 0; y < 4; y++){
						exportar << vpos[i][j][y];
					}
					exportar << "," << endl;
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
		
		cout << "Exportacion finalizada" << endl << endl;
		
		
		

			
	
	}else{
		cout << "Fallo al abrir el archivo" << endl << endl;
	}

return 0;
}



