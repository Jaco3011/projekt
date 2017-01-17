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
#endif
