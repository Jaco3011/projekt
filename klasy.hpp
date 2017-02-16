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
  dodaj = 0 ,
  usun = 1 ,
  zmien = 2
} ;
class zmiana{
public:
corobic ab ;
int cd ;
zmiana() ;
~zmiana() ;
void przesuniecie(corobic n) ;
} ;
class klient {
  public:
  string imie;
  string nazwisko;
  int wiek ;
  list <int> itemki ;
  klient() ;
  klient(string s) ;
  ~klient() ;
  bool czysty() ;
  void TenKlient() ;
} ; //koniec class kilent
class nasze {
  public:
  int numer ;
  string nazwa ;
  nasze() ;
  nasze(string s) ;
  ~nasze() ;
} ;
class wypozyczalnia {
  public:
  vector <klient> ludzie ;
  vector <nasze> przedmioty ;
  list <zmiana> zmienianie;
  //static int punkt=(-1) ; //po co ja to dodawałem?
  wypozyczalnia() ;
  ~wypozyczalnia() ;
  void DodajKlienta(klient a) ;
  bool IstnienieKlienta(int a) ;
  void UsunKlienta(int a) ;
  void Zmien(corobic ab, int cd) ;
  void aktualizacja(fstream baza[]) ;
  bool przedmiotwypozyczony(int a) ;
  void wyczysc() ;
} ; // koniec klasy wypożyczalnia
#endif
