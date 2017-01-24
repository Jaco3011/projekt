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
  string imie;
  string nazwisko;
  int wiek ;
  list <int> itemki ;
  bool czysty() {
    return this->itemki.empty() ;
  } ;
  void TenKlient(){
    cout << "Imię: " << this->imie << endl ;
    cout << "Nazwisko: "<< this->nazwisko << endl ;
    cout << "wiek: " << this->wiek << endl ;
  } ;
} ; //koniec class kilent
class nasze {
  public:
  int numer ;
  string nazwa ;
} ;
class wypozyczalnia {
  public:
  vector <klient> ludzie ;
  vector <nasze> przedmioty ;
  list <int> zmiana[3] ;
  void DodajKlienta(klient a){
  przedmioty.push_back(a) ;
  } ;
} ;
int main () {
  system("COLOR 02") ;
  string sciezka ;
  fstream dane ;
  string sciezki[3] ;
  fstream baza[3] ;
  wypozyczalnia Ten=new wypozyczalnia() ;
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
          while(!baza[0].eof()){ //wczytywanie klientów
            
          } ; //koniec while
          while(!baza[1].eof()){ //wczytywanie przedmiotów
            
          } ; //koniec while
          while(!baza[2].eof()){ //wczytywanie przedmiotów
            
          } ; //koniec while
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
          klient abc ;
          cout << "Podaj imię klienta" << endl ;
          cin >> abc.imie ;
          cout >> "Podaj nazwisko klienta" << endl ;
          cin >> abc.nazwisko ;
          cout >> "Podaj wiek klienta" << endl ;
          cin >> abc.wiek ;
          cout << "Dane klienta: " << endl ;
          abc.TenKlient() ;
          cout << "Dodać do bazy? Y/N " ;
          char y=getchar() ;
          if(y=='Y' || y=='y'){
            Ten.DodajKlienta(abc) ;
            cout << "Klient został pomyślnie dodany do bazy danych" << endl ;
          } else {
            cout << "Klient nie został dodany do bazy danych" << endl ;
          } ;
        } else{
          kont=false ;
        } ;
        break;
      case 'S':
        
        break ;
      case 'T':
        
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
