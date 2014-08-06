/*
   Esto es un archivo de prueba en desarrollo.

Author: Roberto Herrera Esteban
Date: 28/04/14
Last change: 5/08/14



*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <locale>         // std::locale, std::toupper

using namespace std;


#define PI 3.14159265358979323846
#define sizew 16
#define redondeo 8
#define stringify( name ) # name

#define posreposo 90
//No comprobadas
#define posbrazoizq 165
#define posbrazoder 15

#define maxservos 54
#define deshorizontal 6 //Distancia entre los planos de los servos roll de la cadera y tobillo
#define desvertical 27.5  //Separacion de los servos de la rodilla
#define descadera 81     //separacion entre los servos de la cadera

#define DESFASEBASEROD 180   //desfase del movimiento de la rodilla. 0 o 180
#define DESFASEBASEAVA 90   
#define DESFASEBASECIN 90
#define LIMITECADERA 0.60
#define LIMITEAVANCE 0.82


#define expo 7.5         //exponenestes del seno
#define desCDG -0.0475        //inc angular  / Desplazamiento horizontal para compensar el centro de gravedad + o -

#define movcad       //movimiento de cadera
#define movrod       //movimiento de rodilla
#define movava       //movimiento de avance
#define movcin       //movimiento de la cintura
#define movbraava    //movimiento de brazos con avanze
//#define movbracad    //movimiento de brazos con cadera

//#define debug

enum configuracion {nouso=-1,NeckY=0,HipY,RShoulderR,LShoulderR,RShoulderP,LShoulderP,
                   RElbowP,LElbowP,RHand,LHand,RLegY,LLegY,RLegR,LLegR,RLegP,LLegP,RKnee1,LKnee1,RKnee2,LKnee2,RAnkleP,
                   LAnkleP,RAnkleR,LAnkleR,NeckP};
                   
enum param {cadera=0,rodilla,avance,brazoscadera,brazosavance,cintura};


int calcular(int configuracion, float variacion, int iteracion, int pierna, int mode, int param[7]);
float calcang(int iter, float var);
double round_inf(double x, int d);
float calcavance(int iter, float var);
void showconfig(int conf);

const char* c[] = {stringify(NeckY),stringify(HipY),stringify(RShoulderR),stringify(LShoulderR),stringify(RShoulderP),stringify(LShoulderP),
                  stringify(RElbowP),stringify(LElbowP),stringify(RHand),stringify(LHand),stringify(RLegY),stringify(LLegY),stringify(RLegR),stringify(LLegR),stringify(RLegP),stringify(LLegP),stringify(RKnee1),stringify(LKnee1),stringify(RKnee2),
                  stringify(LKnee2),stringify(RAnkleP),stringify(LAnkleP),stringify(RAnkleR),stringify(LAnkleR),stringify(NeckP),stringify(NoUse)};

//#define inicio   //configuracion por defecto de myod
int parametros[6]={0,0,0,0,0,0};  //enum de param
int lon;                        //longitud de pierna
int config[maxservos];

int nservos;
string nomb;
char dato[sizew];


int main(){



   //cargar Config
   cout << "Teclee el numero de servos(0 para cargar configracion previa)" << endl;
   try{
       cin >> nservos;
       if(cin.fail()){
           throw 0;
       }else{
           if(nservos == 0){
               int carga=0;
               do{

                   cout << "Seleccione una configuracion previa" << endl;
                   cin >>     nomb;
                   nomb = nomb + ".conf";
                   nomb = ".\\config\\"+nomb;
                   char *nombreFichero = strdup(nomb.c_str());

                   ifstream importar;
                   importar.open(nombreFichero,ios::in);

                   if(importar.good()){
                       carga=1;
                       cout << "OK" << endl;
                       //importar.clear();
                       while(!importar.eof()){
                           importar.getline(dato,sizew,';');
                           nservos++;
                       }
                       nservos--;

                       cout << "Numero de servos: "<< nservos << endl;


                       //int config[nservos];
                       cout << "Config de servos: "<< endl;

                       importar.clear();
                       importar.seekg(0,ios::beg);
                       importar.clear();

                       int i=0;
                       while(!importar.eof()){
                           importar.getline(dato,sizeof(int),';');
                           config[i] = atoi(dato);
                           // cout << config[i] <<endl;
                           i++;
                       }
                   }else{
                       cout << "Fail" << endl;
                       carga==0;

                   }
               }while(carga==0);

           }else{
               //int config[nservos];
               cout << "Empezando por la posicion 0..." <<endl;
               try{
                   for(int i=0;i<nservos;i++){
                       cout << "Introduzaca la config del servo " << i << endl;
                       cin >> config[i];
                       if(cin.fail()){
                           throw 0;
                       }
                   }
               }catch(...){
                   cout << "FALLO , parametro incorrecto" << endl;
                   cin.clear();
               }
               cout << "Nombre de la config: ";
               cin >> nomb;
               nomb = nomb + ".conf";
               cout << endl << "El archivo ha sido guardado como " << nomb << endl;
               nomb = ".\\config\\"+ nomb;

               char *nombreExp = strdup(nomb.c_str());
               ofstream exportar;
               exportar.open(nombreExp,ios::out|ios::trunc);
               for(int i=0; i<nservos-1;i++){
#ifdef inicio
                   exportar << i << ";" << '\n';
#else
                   exportar << config[i] << ";" << '\n';
#endif
               }
#ifndef inicio
               exportar << config[nservos-1] << ";";
#else
               exportar << nservos-1 << ";";
#endif
               exportar.close();


           }

           ////////////////////////////////////////////////////////////////////////////////

           for(int i=0;i<nservos;i++){
               cout << "Servo "<< i <<": "<<config[i]<< " -> ";
               if (config[i]==-1){
                   showconfig(23);
               }else{
                   showconfig(config[i]);
               }
           }
           //int pos[nservos];
           int modo=0;

           cout << endl << "Tiempo total(ms): ";
           int t_total;
           cin >> t_total;
           cout << endl << "Numero de intervalos: " ;
           int npasos;
           cin >> npasos;
           int t = t_total/npasos;
           cout << endl<< "Intervalo de tiempo(ms): " << t << endl;

           float var_ang = 2*PI/npasos; // En radianes
           cout << endl << "Long de la pierna estirada (mm): ";
           cin >> lon;

#ifdef movcad
           cout << "Ampitud de movimiento de cadera(mm): " ;
           cin >> parametros[cadera];
           
#endif

#ifdef movrod
           cout << "Distancia maxima entre el pie y el suelo(mm): " ;
           cin >> parametros[rodilla]; 
#endif

#ifdef movava
           cout << "Avance de la pierna medido desde la cadera(mm): " ;
           cin >> parametros[avance];
#endif

#ifdef movcin
           cout << "Giro maximo de cadera (grad): " ;
           cin >> parametros[cintura];
#endif

#ifdef movava
#ifdef movbraava
           cout << "Amplitud maxima del brazo hacia adelante y atras (roll)(grad): " ;
           cin >> parametros[brazosavance];
#endif
#endif

#ifdef movcad
#ifdef movbracad
           cout << "Amplitud maxima del brazo que separa el brazo del cuerpo (pitch)(grad): " ;
           cin >> parametros[brazoscadera];
#endif
#endif


           cout << "PARAMETROS:" << endl;
           for(int i=0;i<7;i++){
               cout << parametros[i] << endl;
           }
           cout <<endl;

           
           
           int posiciones[npasos][nservos];

           parametros[cadera]=int(round_inf(parametros[cadera]/float(LIMITECADERA),0));
           for(int i=0;i<npasos;i++){
               cout << "paso:" <<i << endl;
#ifdef debug
               cout << "Angulo: " << (180/PI)*var_ang*i << endl;
#endif
               for(int j=0;j<nservos;j++){
                   posiciones[i][j] = calcular(config[j],var_ang,i,lon,modo, parametros);
                   if(posiciones[i][j]<100) cout << " ";
                   cout << posiciones[i][j]<< ",";
               }
               cout << endl<< "__________________"<<endl;
           }
           parametros[cadera]=int(round_inf(parametros[cadera]*LIMITECADERA,0));
           string nombr_e;
           string robot;
           cout<< "Introduze un nombre para exportar el archivo" << endl;
           cin >> nombr_e;
           cout<< "Nombre del objeto de la case Robot" << endl;
           cin >> robot;

#ifdef debug
           cout<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" ;
#endif
           string nombr_exp = nombr_e + "_exp.h";
           nombr_exp = ".\\exported\\"+ nombr_exp;
           char *nombreExp = strdup(nombr_exp.c_str());
           ofstream exportar;
           exportar.open(nombreExp,ios::out|ios::trunc);
           locale loc;

           
           exportar << "#ifndef " ;
           for (string::size_type i=0; i<nombr_e.length(); ++i){
               exportar << toupper(nombr_e[i],loc);
           }
           exportar <<  "_H" << endl;
           exportar << "#define ";
           for (string::size_type i=0; i<nombr_e.length(); ++i){
               exportar << toupper(nombr_e[i],loc);
           }
           exportar <<  "_H" << endl << endl;
                      
           exportar << "extern Robot " << robot << ";" << endl << endl;
           //nombre de la funcion
           exportar << "void " << nombr_e << "(){" << endl << endl;
           //parametros
           exportar << "/*-------CONFIG------" << endl;
           exportar << "tiempo total: " << t_total<<endl;
           exportar << "numero de pasos: " << npasos <<endl;
           exportar << "cadera: " << parametros[cadera] <<endl;
           exportar << "rodilla: " << parametros[rodilla] <<endl;
           exportar << "avance: " << parametros[avance] <<endl;
           exportar << "cintura: " << parametros[cintura] <<endl;
           exportar << "brazos avance: " << parametros[brazosavance] <<endl;
           exportar << "brazos cadera: " << parametros[brazoscadera] <<endl;


           exportar << "*/" << endl;
           //tiempo
               exportar << "int inctime = " << t << ";" << endl;
           //declaracion
           for(int i= 0; i < npasos;i++){
               
               //posiciones
               exportar << "int vector_" << i+1 << "[" << nservos << "] = {";
               for(int j=0;j<nservos;j++){
                   //ultima
                   if(j==nservos-1){
                       if (posiciones[i][nservos-1]<100)exportar << " ";
                       exportar << posiciones[i][nservos-1];
                       exportar << "};" << endl;
                   }else{
                       if (posiciones[i][j]<100)exportar << " ";
                       exportar << posiciones[i][j];
                       exportar << ",";
                   }
               }
           }
           // movimientos
           exportar << endl << endl;
           for(int i= 0; i <npasos;i++){
               exportar << robot << ".move";
               if(modo==1){
                   exportar << "Offs";
               }
               exportar << "(inctime, vector_" << i+1 << ");" << endl;
           }
           //fin
           exportar << endl << "}" << endl;
           exportar << "#endif" << endl;
           exportar.close();

           cout<< "Exportacion finalizada" << endl << endl;
       }
   }catch(...){
       cin.clear();
       cin.clear();
       nservos = -1;
       cout << "Ha ocurrido un error" << endl;


   };


   cout << "Programa finalizado, su movimiento esta guardado en la carpeta \"exported\" " << endl;
   system("PAUSE");
   return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////


int calcular(int configuracion, float variacion, int iteracion, int pierna, int mode, int param[7]){  
   double angulo;
   angulo = calcang(iteracion, variacion);
   int val;
   if (mode==0){
      val = posreposo;}
   else if(mode==1){
      val = 0 ;}
#ifdef movcad //--------------------------------------------
       float alfa, beta, fi;
       if(angulo>LIMITECADERA){ //Acoto el angulo entre (-LIMITECADERA,+LIMITECADERA) , Limite <= 1
          angulo = LIMITECADERA;}
       if(angulo<-LIMITECADERA){
          angulo = -LIMITECADERA;}
       angulo= angulo + desCDG;
       alfa=0;
       for(int i=0;i<100;i++){ //Formula recursiva, itero para obtener alfa
          alfa=asin(deshorizontal*(cos(alfa)-1)/pierna + angulo*param[cadera]/float(pierna) - descadera*(cos(asin(2.0*deshorizontal*sin(alfa)/descadera))-1)/(2.0*pierna));
       }
       beta=asin(2.0*deshorizontal*sin(alfa)/descadera);   
       fi=atan(float(deshorizontal)/pierna);   
       if(0==configuracion){
       cout << endl;        //Los angulos estan en rad, pero los muestro en grados
       cout << "Cadera: " << param[cadera]*LIMITECADERA << endl;
       cout << "Cadera transf: " << param[cadera] << endl;
       cout << "Alfa: " << alfa*180/PI << endl;   //GIRO de tobillos
       cout << "Beta: " << beta*180/PI << endl;   //Diferencia entre el giro de los tobillos y la cadera
       cout << "Fi: " << fi*180/PI << endl;       //Angulo producido por el desplazamiento horizontal de la cadera
       
       }
      // angulo=calcang(iteracion, variacion);
#endif
   
   switch (configuracion){
   case nouso:
       //vacio
       break;
   case NeckY:
#ifdef movcin
       angulo = sin(iteracion*variacion - (DESFASEBASECIN*(PI/180.0)));
       val= val + int(round_inf((angulo*param[cintura]*1.0),0));
#endif
       break;
   case RShoulderR:
       if (mode==0){
           val = posbrazoder;
       }else if(mode==1){
           val =0;
       }
#ifdef movcad
#ifdef movbracad
       val = val + param[brazoscadera]*(0.5) +int(round_inf(angulo*param[brazoscadera]);
#endif
#endif
       break;
   case RShoulderP:

#ifdef movava
#ifdef movbraava
       angulo = sin(iteracion*variacion + (DESFASEBASEAVA*(PI/180.0)));
       val =  val + int(round_inf(angulo*(-param[brazosavance]),0)) + int(round_inf(param[brazosavance]*(0.5),0));
#endif
#endif
       break;
   case LShoulderR:
       if (mode==0){
           val = posbrazoizq;
       }else if(mode==1){
           val = 0;
       }
#ifdef movcad
#ifdef movbracad
       val = val + param[brazoscadera]*(0.5)  - int(round_inf(angulo*param[brazoscadera]),0);
#endif
#endif
       break;
   case LShoulderP:

#ifdef movava
#ifdef movbraava
       angulo = sin(iteracion*variacion + (DESFASEBASEAVA*(PI/180.0)));
       val = val - int(round_inf(angulo*(param[brazosavance]),0)) - int(round_inf(param[brazosavance]*(0.5),0));
#endif
#endif
       break;
   case RElbowP:
#ifdef movava
#ifdef movbraava
       //angulo = sin(iteracion*variacion + (DESFASEBASEAVA*(PI/180.0)));
       //val = val + int(round_inf(angulo*(param[brazosavance]),0)) + param[brazosavance]/2;
#endif
#endif
       break;
   case LElbowP:
#ifdef movava
#ifdef movbraava
       //angulo = sin(iteracion*variacion + (DESFASEBASEAVA*(PI/180.0)));
       //val = val - int(round_inf(angulo*(param[brazosavance]),0)) - param[brazosavance]/2;
#endif
#endif
       break;
   case HipY:
#ifdef movcin
       angulo = sin(iteracion*variacion - (DESFASEBASECIN*(PI/180.0)));
       val= val + int(round_inf(angulo*param[cintura],0));
#endif
       break;
   case RLegY:
#ifdef movcin
       angulo = sin(iteracion*variacion - (DESFASEBASECIN*(PI/180.0)));
       val= val - int(round_inf(angulo*param[cintura],0));
#endif
       break;
   case LLegY:
#ifdef movcin
       angulo = sin(iteracion*variacion - (DESFASEBASECIN*(PI/180.0)));
       val = val - int(round_inf(angulo*param[cintura],0));
#endif
       break;
   case RLegR:
#ifdef movcad///////////////////////////////////////////////
       val = val + int(round_inf((180.0/PI)*(alfa-beta),0));
#endif
       break;
   case RLegP:

        
#ifdef movrod
       //angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD+param[desfase])*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD+param[desfase])*PI/180.0))))),expo-1);
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo>0){
           //ESTA ES LA BUENA
           val = val + int(round_inf(acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
#ifdef debug
           
           cout << endl << "Angulo grad: " << variacion*iteracion + param[desfase]+DESFASEBASEROD << endl;  
           cout << "Angulo grad: " << (variacion*iteracion + param[desfase]+DESFASEBASEROD)*180.0/PI << endl;     
           cout << "Seno: " << angulo << endl;
           cout << "Pierna: " << pierna << endl;
           cout << "Levantar: "  << param[rodilla] << endl;
           cout << "Diferencia: " << pierna-param[rodilla] << endl;
           cout << "deshorizontal de rodilla: " << desvertical << endl; 
           cout << "Division: " << ((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical) << endl;
           cout << "Arcoseno: " << acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical)) << endl;
           cout << "Arcoseno grad: " << acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI)<< endl;
           cout << "Final: " <<  val + int(round_inf(acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0)) << endl << endl;
#endif
       }
       angulo = calcang(iteracion,variacion);
#endif

#ifdef movava
       angulo = calcavance(iteracion,variacion);
       val = val  + int(round_inf(180.0*atan(angulo*param[avance]/pierna)/PI,0));
       angulo = calcang(iteracion,variacion);
#endif
       break;
       
   case LLegR:
#ifdef movcad/////////////////////////////////////////
          val = val + int(round_inf((180.0/PI)*(alfa-beta),0));
#endif
       break;
   case LLegP:       

#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo<0){
           val = val - int(round_inf(acos(((pierna-desvertical)+param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
       }
       angulo = calcang(iteracion, variacion);
#endif

#ifdef movava
       angulo = calcavance(iteracion,variacion);
       val = val  + int(round_inf(180.0*atan(angulo*param[avance]/pierna)/PI,0));
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case RKnee1:
#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo>0){
           val = val + int(round_inf(acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
       }
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case RKnee2:
#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo>0){
           val = val - int(round_inf(acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
       }
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case LKnee1:  
#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo<0){
           val = val - int(round_inf(acos(((pierna-desvertical)+param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
       }
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case LKnee2:
#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo<0){
  /*                  cout << endl << "Angulo: " << angulo << endl;
                    cout << "Parcial: " << ((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical) << endl;
                    cout<< "Resultado: " << acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI) << endl;
    */
           val = val + int(round_inf(acos(((pierna-desvertical)+param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
       }
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case RAnkleP:
#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo>0){
           val = val - int(round_inf(acos(((pierna-desvertical)-param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0)); 
       }
       angulo = calcang(iteracion, variacion);
#endif
#ifdef movava
       angulo = calcavance(iteracion,variacion);
       val = val  + int(round_inf(180.0*atan(angulo*param[avance]/pierna)/PI,0));
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case RAnkleR:
#ifdef movcad///////////////////////////////////////////////
          val = val + int(round_inf(alfa*(180.0/PI),0));
#endif
       break;
   case LAnkleP:
#ifdef movrod
       angulo =  sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0)) * pow(abs(double((sin(float(variacion*iteracion) + float((DESFASEBASEROD)*PI/180.0))))),expo-1);
       if(angulo<0){
           val = val + int(round_inf(acos(((pierna-desvertical)+param[rodilla]*angulo)/(pierna-desvertical))*(180.0/PI),0));
       }
       angulo = calcang(iteracion, variacion);
#endif
#ifdef movava
       angulo = calcavance(iteracion,variacion);
       val = val  + int(round_inf(180.0*atan(angulo*param[avance]/pierna)/PI,0));
       angulo = calcang(iteracion, variacion);
#endif
       break;
   case LAnkleR:
#ifdef movcad ///////////////////////////////////////////////
          val = val + int(round_inf((180.0/PI)*alfa,0));
#endif
       break;
   default:
       ;
   }
   return val;

}

double round_inf(double x, int d){
   if (d==0)
       return x < 0.0 ? std::ceil(x-0.5) : std::floor(x+0.5);
   double m = std::pow(10.0,d);
   return x<0.0 ? std::ceil(x*m-0.5)/m : std::floor(x*m-0.5)/m;
}

void showconfig(int conf){
   cout << c[conf]<<endl;
}
float calcang(int iter, float var){
      return sin(iter*var);
}
float calcavance(int iter, float var){
      float x,x_1;
      int max,min;
      float result;
      int npas, desf, medionpas;
      npas = (int)round_inf(2*PI/var,0);
      desf= (int)round_inf(DESFASEBASEAVA/(360)*npas,0);
      x_1=-10.0;
      for(int i=0; i<npas;i++){
         x=sin(i*var + (DESFASEBASEAVA*(PI/180.0)));
         if(x>x_1){
            max=i;}
         x_1=x;
      }
      x_1=10.0;
      for(int i=0; i<npas;i++){
         x=sin(i*var + (DESFASEBASEAVA*(PI/180.0)));
         if(x<x_1){
            min=i;}
         x_1=x;
      }
      medionpas = npas/2;
      if(max>medionpas)
         max=max-npas;
      if(min>medionpas)
         min=min-npas;
      
      if(sin(iter*var + (DESFASEBASEAVA*(PI/180.0)))<=sin((iter+1)*var + (DESFASEBASEAVA*(PI/180.0)))){ //Pendiente positiva
         result= (2/(PI))*(iter-min)*var    - 1;
      }else{
         result= 1 - (2/(PI))*(iter-max)*var;
      }
/*      cout << endl << result << endl;
      cout << max << endl;
      cout << min << endl;
      cout << npas << endl;
 */     
      if(result>=LIMITEAVANCE){
         result=LIMITEAVANCE;
      }else if(result<=-LIMITEAVANCE){
         result=-LIMITEAVANCE;
      }
      result=result/LIMITEAVANCE;
      return result;
}
