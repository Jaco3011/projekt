#include "funkcje.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <sstream>
using namespace std ;
string sciezkanowa() {
  string a ;
  cout << "Podaj sciezke do plików" << endl ;
  cin >> a ;
  return a ;
} ;
bool wszystkodobrze(int a, fstream dane[]){
    for(int i=0; i<a; i++){
        if(!(dane[i]).good()){
          return false ;
        };
    };
    return true ;
};
void wczytajbaze (int a, fstream pliki[], string sciezki[]){
    for(int i=0; i<a; i++){
        (pliki[i]).open((sciezki[i]).c_str(), ios::in|ios::out) ;
    };
};
bool wczytywanie(fstream * dane, string * sciezka, string dokad[]){
  bool wynik ;
  (*dane).open((*sciezka).c_str(), ios::in) ;
   if ((*dane).is_open()) {
    cout << "Wczytywanie ścieżek do plików" << endl ;
    int i=0 ;
    while (i<3 && !(*dane).eof()) {
      getline((*dane), (dokad[i])) ;
      i++ ;
    } ;
    if ((dokad[2])=="" && (*dane).eof()) {
      cout << "Ścieżki nie zostały wczytanie" << endl ;
      wynik=false ;
    } else {
      cout << "Wczytano ścieżki dostępu" << endl ;
      wynik=true ;
    } ;
  (*dane).clear() ;
  } else {
    cout << "Problemy z otwarciem ścieżek do plików" << endl ;
     wynik=false ;
  } ;
  (*dane).close() ;
  return wynik ;
} ; //koniec wczytywania
void WypiszMenu(bool czy){
  cout << "Menu główne bazy danych" << endl ;
  if(czy){
    cout << "Baza danych wczytana" << endl ;
  } else {
    cout << "Baza danych nie jest wczytana" << endl ;
  } ;
  cout << "Opcje:" << endl ;
  if (czy) {
    cout << "Q - wczytaj bazę danych jeszcze raz (z obecnych ścieżek)" << endl ;
    cout << "W - podaj nowy adres do bazy danych (i zamknij obecną)" << endl ;
    cout << "E - zamknij bazę danych" << endl ;
    cout << "R - dodaj klienta" << endl ;
    cout << "T - usuń klienta" << endl ;
    cout << "Y - modyfikuj dane klienta" << endl ;
    cout << "U - wypożycz przedmiot" << endl ;
    cout << "I - zwróc przedmiot" << endl ;
    cout << "O - sprawdź przedmiot" << endl ;
    cout << "P - inwentarz" << endl ;
    cout << "A - lista klientów" << endl ;
    cout << "S - zapisz bazę danych" << endl ;
    cout << "D - sprawdź klienta" << endl ;
  } else {
  cout << "Q - spróbuj wczytać bazę danych jeszcze raz (z obecnych ścieżek)" << endl ;
  cout << "W - podaj nowy adres do bazy danych" << endl ;
  } ;
} ;
void DawajInty (list <int> * liczby, string s){
  (*liczby).clear();
  stringstream ss(s) ;
  list <string> aa ;
  string a ;
  while (ss >> a) {
    ss >> a;
    aa.push_back(a) ;
  } ;
  int nn ;
  bool m ;
  list<string>::iterator it ;
  for (it=aa.begin(); it!=aa.end(); it++){
    m=true ;
    try
    {
      nn=stoi((*it), nullptr, 10) ;
    }
   catch (...)
   {
       m=false ;
   }
   if(m) {
     (*liczby).push_back(nn) ;
   } ;
  } ;
  (*liczby).unique() ;
} ;
void przesun (int n, fstream * plik) {
  (*plik).seekg(0) ;
  (*plik).seekp(0) ;
  int a=0 ;
  while(a<n){
    if ((*plik).get()==10){
      a++ ;
    } ;
    (*plik).seekg(1, (*plik).cur) ;
    (*plik).seekp(1, (*plik).cur) ;
  } ;
} ;
