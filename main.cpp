#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>
#include "funkcje.hpp"
using namespace std ;
class klient {
  public:
  int numer ;
  string imie;
  string nazwisko ;
  int wiek ;
  public :
} ; //koniec class kilent
class nasze {
  public:
  int numer ;
  string nazwa ;
} ;
class wypozyczalnia {
  list <klient> ludzie ;
  list <nasze> przedmioty ;
} ;
int main () {
  system("COLOR 02") ;
  string sciezka ;
  fstream dane ;
  string sciezki[3] ;
  fstream baza[3] ;
  wypozyczalnia Ten ;
  bool poprawnie=false ;
  while(true){
    WypiszMenu(poprawnie) ;
    while(!kbhit()) {
    } ; 
    
  } ;
  return 0 ;
} ;
