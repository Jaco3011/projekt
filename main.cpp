#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
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
  char ster ;
  while(true){
    gotoxy(0,0) ;
    WypiszMenu(poprawnie) ;
    ster=getchar() ;
    switch(ster) {
    } ;
  } ;
  return 0 ;
} ;
