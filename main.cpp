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
/*void wczytywanie(fstream * skad, fstream * dalsze){

} ; //koniec wczytywania
*/
void wczytajbaze (int a, fstream * pliki, string * sciezki){
    for(int i=0; i<a; i++){
        pliki[i].open(sciezki[i].c_str(), ios::in|ios::out) ;
    };
};
bool wszystkodobrze(int a, fstream * dane){
    for(int i=0; i<a; i++){
        if(!dane[i].good()){
          return false ;
        };
    };
    return true ;
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
      i++ ;
    } ;
    if (sciezki[2]=="" && dane.eof()) {
      cout << "Ścieżki nie zostały wczytanie" << endl ;
    } else {
      cout << "Wczytano ścieżki dostępu" << endl ;
    } ;
  dane.clear(goodbit) ;
  dane.close() ;
  } else {
    cout << "Problemy z otwarciem ścieżek do plików" << endl ;
  } ;
  wczytajbaze(3, baza, sciezki) ;
  if(wszystkodobrze(3, baza)){
  while(true){ //początek pętli głównej
  } ; // koniec pętli głównej
  } else {
      cout << "Nie można otworzyć co najmniej jednego pliku bazy danych" << endl ;
  } ;
  return 0 ;
} ;
