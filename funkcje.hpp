#ifndef funkcje_hpp
#define funkcje_hpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std ;
string sciezkanowa() ;
bool wszystkodobrze(int a, fstream * dane[]) ;
void wczytajbaze (int a, fstream * pliki[], string * sciezki[]) ;
bool wczytywanie(fstream * dane, string * sciezka, string * dokad[]) ;
void WypiszMenu(bool czy) ;
void DawajInty(List * <int> liczby, string s) ;
void przesun (int n, fstream * plik) ;
#endif
