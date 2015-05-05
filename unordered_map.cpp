//
//http://stackoverflow.com/questions/3973659/c-unordered-map-compiling-issue-with-g

//#include <tr1/unordered_map>
//using namespace std::tr1;

//g++ -std=c++0x source.cxx
//#include<unordered_map>
//using namespace std;
/*
bool ifunique(char *s){
  unordered_map<char,bool> h;
  if(s== NULL){
    return true;
  }
  while(*s){
    if(h.find(*s) != h.end()){
      return false;
    }
    h.insert(*s,true);
    s++;
  }
   return false;
}

//to do std::make_pair<char, bool>(*s, true) when inserting.
*/


/*
//http://forums.devshed.com/c-programming-42/tip-about-stl-hash-map-and-string-55093.html
#include <iostream>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;//sin esto no va la linea siguiente (le faltaría ctor a has_map ...
//aún así, no es necesario la opción de compilación -std=c++0x

hash_map <const char *, int> months;
int main(void) {
   months["january"] = 31;
   months["february"] = 28;
   return 0;
}
*/

//
//http://fgda.pl/post/7/gcc-hash-map-vs-unordered-map
// Risky stuff across Compiler versions !!

//---------- USAR unordered_map EN LUGAR DE hash_map --------------
//http://forums.devshed.com/c-programming-42/tip-about-stl-hash-map-and-string-55093.html
//para usar esto tengo que ponerle como opción de compilación -std=c++0x
//g++ -Wall -std=c++0x -o unordered_map unordered_map.cpp
//para usar nuevos container como unordered:map
#include <string>
#include <unordered_map>
#include <iostream> 

std::unordered_map <std::string, int> months;

typedef struct _puntoCampo{
	double componenteX;
	double componenteY;
	double componenteZ;
	char bytes[2048];
}puntoCampo;
std::unordered_map <int, puntoCampo> mapa_PuntosCampo; // -----------<<------------
std::unordered_map <int, puntoCampo> mapa; // -----------<<------------

std::ostream& operator<<(std::ostream&, const puntoCampo&);
std::ostream& operator<<(std::ostream& out, const puntoCampo& obj) {
	return out << '(' << obj.componenteX << ' ' << obj.componenteY << ' ' << obj.componenteZ << ')';
}

int main(void) {
	std::cout<<std::endl<<"unordered_map.exe"<<std::endl;

   puntoCampo strUna, strDos, strTres;
   strUna.componenteX=1;
   strUna.componenteY=1;
   strUna.componenteZ=1;

   strDos.componenteX=2;
   strDos.componenteY=2;
   strDos.componenteZ=2;

   strTres.componenteX=3;
   strTres.componenteY=3;
   strTres.componenteZ=3;

   mapa_PuntosCampo[0]=strUna;
   mapa_PuntosCampo[1]=strDos;
   mapa_PuntosCampo[2]=strTres;


   //for (int i=0 ; i< 16777216; i++){//grid 256x256x256
   for (int i=0 ; i< 262144; i++){//grid 64x64x64  
       puntoCampo str;
       str.componenteX=i;
       str.componenteY=i;
       str.componenteZ=i;
       //std::cout<<"Inserting"<< i<<std::endl;
       mapa[i]=str;
	}

   std::cout<<mapa_PuntosCampo[0]<<std::endl;
   std::cout<<mapa_PuntosCampo[0].componenteX<<std::endl;

   std::cout<<mapa[1]<<std::endl;
   std::cout<<mapa[1].componenteX<<std::endl;
   std::cout<<mapa[mapa.size()]<<std::endl;
   std::cout<<mapa[mapa.size()].componenteX<<std::endl;

   return 0;
}
