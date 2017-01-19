#ifndef funkcje_hpp
#define funkcje_hpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std ;
string sciezkanowa() {
  string a ;
  cout << "Podaj sciezke do plików" << endl ;
  cin >> a ;
  return a ;
} ;
bool wszystkodobrze(int a, fstream * dane[]){
    for(int i=0; i<a; i++){
        if(!(*dane[i]).good()){
          return false ;
        };
    };
    return true ;
};
void wczytajbaze (int a, fstream * pliki[], string * sciezki[]){
    for(int i=0; i<a; i++){
        (*pliki[i]).open((*sciezki[i]).c_str(), ios::in|ios::out) ;
    };
};
void wczytywanie(fstream * dane, string * sciezka, string * dokad[]){
  (*dane).open((*sciezka).c_str(), ios::in) ;
   if ((*dane).is_open()) {
    cout << "Wczytywanie ścieżek do plików" << endl ;
    int i=0 ;
    while (i<3 && !(*dane).eof()) {
      getline((*dane), (*dokad[i])) ;
      i++ ;
    } ;
    if ((*dokad[2])=="" && (*dane).eof()) {
      cout << "Ścieżki nie zostały wczytanie" << endl ;
    } else {
      cout << "Wczytano ścieżki dostępu" << endl ;
    } ;
  (*dane).clear() ;
  } else {
    cout << "Problemy z otwarciem ścieżek do plików" << endl ;
  } ;
  (*dane).close() ;
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
    cout << "O - sprawdź przedmioty" << endl ;
    cout << "P - inwentarz" << endl ;
    cout << "A - lista klientów" << endl ;
    cout << "S - zapisz bazę danych" << endl ;
  } else {
  cout << "Q - spróbuj wczytać bazę danych jeszcze raz (z obecnych ścieżek)" << endl ;
  cout << "W - podaj nowy adres do bazy danych" << endl ;
  } ;
} ;
#endif
