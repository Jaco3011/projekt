#include <iostream.h>
#include <string>
#include <fstream>
using namespace std ;
int main () {
  string sciezka ;
  cout >> "Podaj ścieżkę do pliku" << endl ;
  cin >> sciezka ;
  fstream baza(sciezka, ios::in | ios::out) ;
  
  return 0 ;
} ;
