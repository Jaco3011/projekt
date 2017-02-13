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
  klient()
  klient(string s)
  bool czysty()
  void TenKlient()
} ; //koniec class kilent
class nasze {
  public:
  int numer ;
  string nazwa ;
  nasze() ;
  nasze(string s) ;
} ;
class wypozyczalnia {
  public:
  vector <klient> ludzie ;
  vector <nasze> przedmioty ;
  queue <zmiana> zmienianie;
  static int punkt=(-1) ; //po co ja to dodawałem?
  void DodajKlienta(klient a) ; 
  bool IstnenieKlienta(int a) ;
  void UsunKlienta(int a) ;
  void DodajKlienta(klient a) ;
  void Zmien(corobic ab, int cd) ;
  void aktualizacja(fstream * baza) ;
} ; // koniec klasy wypożyczalnia
#endif
