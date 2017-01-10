#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

int main () {
  string sciezka ;
  cout << "Podaj ścieżkę do plików" << endl ;
  cin >> sciezka ;
  fstream baza1 ;
  fstream baza2 ;
  fstream baza3 ;
  baza1.open((sciezka.c_str()+"jeden.txt"), ios::in | ios::out) ;
  if (baza1.is_open()) {
    cout << "Otwarte" << endl ;
  } else {
    cout << "Problemy z otwarciem" << endl ;
  } ;
  baza1.flush() ;
  baza1.close() ;
  return 0 ;
} ;
