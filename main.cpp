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
  list <int> itemki ;
  bool czysty() {
    return itemki.empty() ;
  } ;
} ; //koniec class kilent
class nasze {
  public:
  int numer ;
  string nazwa ;
} ;
class wypozyczalnia {
  public:
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
  while(true){ //początek pętli głównej
    system("cls") ;
    WypiszMenu(poprawnie) ;
    switch(getchar()) {
      case 'Q' :
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        wczytajbaze(3, baza, sciezki) ;
        if (wszystkodobrze(3, baza)){
          poprawnie = true ;
        } else {
          poprawnie = false ;
        } ;
        break ; //koniec Q
      case 'W' :
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        dane.close() ;
        sciezka=sciezkanowa() ;
        wczytywanie(dane, sciezka, sciezki) ;
        break ;
      case 'E' :
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        Ten=new wypozyczalnia() ;
        cout << "Baza zamknięta" << endl ;
        poprawnie=false ;
        break ;
    } ;
  system("pause") ;
  } ; //koniec pętli głównej
  return 0 ;
} ;
