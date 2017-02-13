#define klasy_cpp
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cstdlib>
#include <conio>
#include <stdio>
#include <queue>
#include <sstream>
using namespace std ;
klient::klient(){
} ;
klient::klient(string s)
:wiek(0)
{
   stringstream ss(s) ;
   string k ;
   ss >> imie >> nazwisko >> k ;
   try{
   wiek=stoi(k, nullptr, 10) ;
   } ;
   catch (invalid_argument e){
   } ;
   catch (out_of_range ee){
   } ;
} ;
bool klient::czysty() {
    return this->itemki.empty() ;
} ;
void klient::TenKlient(){
    cout << "Imię: " << this->imie << endl ;
    cout << "Nazwisko: "<< this->nazwisko << endl ;
    cout << "wiek: " << this->wiek << endl ;
} ;
nasze::nasze(){
} ;
nasze::nasze(string s)
:numer(0)
{
   try {
   numer=stoi(s,nullptr,10);
   } ;
   catch (invalid_argument e){
   } ;
   catch (out_of_range ee){
   } ;
   while(s[0]!=36){
      s.erase(0) ;
   } ;
    while(s[0]==36){
      s.erase(0) ;
   } ;
   nazwa = s ;
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
void wypozyczalnia::aktualizacja(fstream * baza){
   
} ;
