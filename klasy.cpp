#define klasy_cpp
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <queue>
using namespace std ;
klient::klient(){
} ;
klient::klient(string s)
:wiek(0)
{
   //TODO
} ;
bool klient::czysty() {
    return this->itemki.empty() ;
} ;
void klient::TenKlient(){
    cout << "Imię: " << this->imie << endl ;
    cout << "Nazwisko: "<< this->nazwisko << endl ;
    cout << "wiek: " << this->wiek << endl ;
} ;
void wypozyczalnia::DodajKlienta(klient a){
  przedmioty.push_back(a) ;
} ;
bool wypozyczalnia::IstnenieKlienta(int a) {
    if (ludzie.a==NULL){
      return false ;
    } else {
      return true ;
    } ;
} ;
void wypozyczalnia::UsunKlienta(int a) {
    this->ludzie.erase(a) ;
  } ;
void wypozyczalnia::DodajKlienta(klient a) {
    this->ludzie.push_back(a)
 } ;
void wypozyczalnia::Zmien(corobic ab, int cd){
    zmiana yyy;
    yyy.ab=ab ;
    yyy.cd=cd ;
    this->zmienianie.push(yyy) ;
  } ;
