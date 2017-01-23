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
  void Dodaj_Klienta(){
  } ;
} ;
int main () {
  system("COLOR 02") ;
  string sciezka ;
  fstream dane ;
  string sciezki[3] ;
  fstream baza[3] ;
  wypozyczalnia Ten=new wypożyczalnia() ;
  bool poprawnie=false ;
  bool kont;
  while(true){ //początek pętli głównej
    system("cls") ;
    kont=true;
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
          //procedura wczytywania
          
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
        poprawnie=false ;
        sciezka=sciezkanowa() ;
        if ( wczytywanie(dane, sciezka, sciezki) ) {
          
        } ;
        break ; //koniec W
      case 'E' :
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        Ten=NULL ;
        cout << "Baza zamknięta" << endl ;
        poprawnie=false ;
        break ;
      case 'R' :
        if(poprawnie){
          
        } else{
          kont=false ;
        } ;
        break;
      case 'S':
        
        break ;
      default:
        kont=false ;
    } ;
  if (kont) {
  system("pause") ;
  } ;
  } ; //koniec pętli głównej
  return 0 ;
} ;
