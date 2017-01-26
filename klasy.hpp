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
#include <queue>
using namespace std ;
enum corobic{
  dodaj,
  usun,
  zmien
} ;
class zmiana{
corobic ab ;
int cd ;
} ;
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
  queue <zmiana> zmienianie;
  static int punkt=(-1) ;
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
  void UsunKlienta(int a) {
    this->ludzie.erase(a) ;
  } ;
  void DodajKlienta(klient a) {
    this->ludzie.push_back(a)
  } ;
  void Zmien(corobic ab, int cd){
    zmiana yyy;
    yyy.ab=ab ;
    yyy.cd=cd ;
    this->zmienianie.push(yyy) ;
  } ;
  //void wypozyczenie
} ; // koniec klasy wypożyczalnia
#endif
