#include <iostream.h>
#include <string>
#include <fstream>

using namespace std ;

int main () {
  string sciezka ;
  cout >> "Podaj ścieżkę do pliku" << endl ;
  cin >> sciezka ;
  fstream baza(sciezka, ios::in | ios::out) ;
  baza.open() ;
  if (baza.is_open()) {
    cout << "Otwarte" << endl ;
  } else {
    cout << "Problemy z otwarciem" << endl ;
  }
  baza.close() ;
  return 0 ;
} ;
