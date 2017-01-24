#ifndef klasy_hpp
#define klasy_hpp
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
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
  bool IstnenieKlienta(int a) {
    if (ludzie.a==NULL){
      return false ;
    } else {
      return true ;
    } ;
  } ;
} ;
#endif
