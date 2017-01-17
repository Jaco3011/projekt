#ifndef funkcje_hpp
#define funkcje_hpp
#include <iostream.h>
#include <string>
#include <fstream>
using namespace std ;
void sciezkanowa(string * tamto) {
  string a ;
  cout << "Podaj sciezke do plików" << endl ;
  cin >> a ;
  tamto=a ;
} ;
bool wszystkodobrze(int a, fstream * dane){
    for(int i=0; i<a; i++){
        if(!dane[i].good()){
          return false ;
        };
    };
    return true ;
};
void wczytajbaze (int a, fstream * pliki, string * sciezki){
    for(int i=0; i<a; i++){
        pliki[i].open(sciezki[i].c_str(), ios::in|ios::out) ;
    };
};
void wczytywanie(fstream * dane, string * sciezka, string * dokad){
  dane.open(sciezka.c_str()), ios::in) ;
   if (dane.is_open()) {
    cout << "Wczytywanie ścieżek do plików" << endl ;
    int i=0 ;
    while (i<3 && !dane.eof()) {
      getline(dane, dokad[i]) ;
      i++ ;
    } ;
    if (dokad[2]=="" && dane.eof()) {
      cout << "Ścieżki nie zostały wczytanie" << endl ;
    } else {
      cout << "Wczytano ścieżki dostępu" << endl ;
    } ;
  dane.clear(goodbit) ;
  dane.close() ;
  } else {
    cout << "Problemy z otwarciem ścieżek do plików" << endl ;
  } ;
} ; //koniec wczytywania
void WypiszMenu(bool czy){
  cout << "Menu główne bazy danych" << endl ;
  if(poprawnie){
    cout << "Baza danych wczytana" << endl ;
  } else {
    cout << "Baza danych nie jest wczytana" << endl ;
  } ;
  cout << "Opcje:" << endl ;
} ;
#endif
