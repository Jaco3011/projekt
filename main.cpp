#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

int main () {
  string sciezka ;
  cout << "Podaj ścieżkę do pliku" << endl ;
  cin >> sciezka ;
  fstream baza ;
  baza.open(sciezka.c_str(), ios::in | ios::out) ;
  if (baza.is_open()) {
    cout << "Otwarte" << endl ;
  } else {
    cout << "Problemy z otwarciem" << endl ;
  } ;
  baza.flush() ;
  baza.close() ;
  return 0 ;
} ;
