#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std ;
class klient {
  public:
  int numer ;
  string imie;
  string nazwisko ;
  int wiek ;
  public :
} ; //koniec class kilent
class nasze {
  public: 
  int numer ;
  string nazwa ;
} ;
class wypozyczalnia {
  list <klient> ludzie ;
  list <nasze> przedmioty ;
} ;
int main () {
  string sciezka ;
  cout << "Podaj ścieżkę do plików" << endl ;
  cin >> sciezka ;
  fstream dane ;
  string sciezki[3] ;
  fstream baza[3] ;
  sciezka+="dane.txt" ;
  dane.open((sciezka.c_str()), ios::in) ;
  if (dane.is_open()) {
    cout << "Wczytywanie ścieżek do plików" << endl ;
    int i=0 ;
    while (i<3 && !dane.eof()) {
      getline(dane, sciezki[i]) ;
    } ;
    if (sciezki[2]=="" && dane.eof()) {
      cout << "Ścieżki nie zostały wczytanie" << endl ;
    } else {
      cout << "Wczytano ścieżki dostępu" << endl ;
    } ;
  dane.close() ;
  } else {
    cout << "Problemy z otwarciem ścieżek do plików" << endl ;
  } ;
  
  while(true){ //początek pętli głównej
  } ; // koniec pętli głównej
  return 0 ;
} ;
