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
corobic ab ;
int cd ;
zmiana() ;
~zmiana() ;
} ;
class klient {
  public:
  string imie;
  string nazwisko;
  int wiek ;
  list <int> itemki ;
  klient()
  klient(string s)
  ~klient() ;
  bool czysty()
  void TenKlient()
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
  queue <zmiana> zmienianie;
  static int punkt=(-1) ; //po co ja to dodawałem?
  wypozyczalnia() ;
  ~wypozyczalnia() ;
  void DodajKlienta(klient a) ; 
  bool IstnenieKlienta(int a) ;
  void UsunKlienta(int a) ;
  void DodajKlienta(klient a) ;
  void Zmien(corobic ab, int cd) ;
  void aktualizacja(fstream * baza) ;
} ; // koniec klasy wypożyczalnia
#endif
