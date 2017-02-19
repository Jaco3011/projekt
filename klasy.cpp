#define klasy_cpp
#include "klasy.hpp"
#include "funkcje.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cstdlib>
#include <queue>
#include <sstream>
using namespace std ;
zmiana::zmiana() {
} ;
zmiana::zmiana(corobic a, int b){
    ab=a ;
    cd=b ;
};
zmiana::~zmiana(){
} ;
void zmiana::przesuniecie(corobic n) {
    switch (n) {
    case 0:
        cd++ ;
        break ;
    case 1:
        cd-- ;
        break ;
    default:
        {
                   //pusto
        }
    } ;
} ;
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
   }
   catch (...){
   }
} ;
klient::~klient(){
} ;
bool klient::czysty() {
    return itemki.empty() ;
} ;
void klient::TenKlient(){
    cout << "Imię: " << imie << endl ;
    cout << "Nazwisko: "<< nazwisko << endl ;
    cout << "wiek: " << wiek << endl ;
} ;
nasze::nasze(){
} ;
nasze::nasze(string s)
:numer(0)
{
bool b=true ;
   try {
   numer=stoi(s,nullptr,10);
   }
   catch (...){
       b=false ;
   } ;
   if(b){
    while(s[0]!=32){
        s.erase(0,1) ;
    } ;
    while(s[0]==32){
        s.erase(0,1) ;
    } ;
   } ;
   nazwa = s ;
} ;
nasze::~nasze(){
};
wypozyczalnia::wypozyczalnia(){
};
wypozyczalnia::~wypozyczalnia(){
};
void wypozyczalnia::DodajKlienta(klient a){
  ludzie.push_back(a) ;
  this->Zmien(dodaj, (ludzie.size()-1)) ;
} ;
bool wypozyczalnia::IstnienieKlienta(int a) {
    if (ludzie.size()<=a){
      return false ;
    } else {
      return true ;
    } ;
} ;
void wypozyczalnia::UsunKlienta(int a) {
    ludzie.erase(ludzie.begin()+a) ;
    this->Zmien(usun, a) ;
} ;
void wypozyczalnia::Zmien(corobic ab, int cd){
    switch(ab){
case 0:
    for(zmiana x : this->zmienianie){
      if (x.cd>cd){
        x.cd++ ;
      } ;
    };
case 1:
    for(zmiana x : this->zmienianie){
      if (x.cd>cd){
        x.cd-- ;
      } ;
    };
    deafult:
        break;
    } ;
    zmienianie.push_back(zmiana(ab, cd)) ;
  } ;
bool wypozyczalnia::ostatni (klient * a){
    return (a==&(ludzie[ludzie.size()-1])) ;
} ;
void wypozyczalnia::aktualizacja(fstream baza[], string sciezki[]){
    for (int i=0; i<3 ; i+=2){
        baza[i].flush() ;
        baza[i].close() ;
        baza[i].open(sciezki[i], ios::trunc| ios::out | ios::app);
    };
    for (klient x : ludzie){
        baza[0] << x.imie << " " << x.nazwisko << " " << x.wiek ;
        for (int y : x.itemki) {
            baza[2] << y ;
            baza[2] << " " ;
        } ;
        if(!this->ostatni(&x)){
            baza[0] << endl ;
            baza[2] << endl ;
        } ;
    } ;
    for (int i=0; i<3; i+=2){
        baza[i].flush() ;
        baza[i].close() ;
        baza[i].open(sciezki[i], ios::in | ios::out);
    } ;
} ;
void wypozyczalnia::aktualizacja(fstream baza[]){
    string bufor0 ;
    string buf0 ;
    string cos=" " ;
      while(!zmienianie.size()>0){
            przesun(zmienianie.front().cd, &(baza[0])) ;
            przesun(zmienianie.front().cd, &(baza[2])) ;
         switch((zmienianie.front()).ab){
            case 0 :
                {
                buf0=dostringa(this->ludzie[zmienianie.front().cd].wiek) ;
                bufor0 = this->ludzie[zmienianie.front().cd].imie.c_str() ;
                bufor0 += cos.c_str() ;
                bufor0 += this->ludzie[zmienianie.front().cd].nazwisko.c_str() ;
                bufor0 += cos.c_str() ;
                bufor0 += buf0.c_str() ;
                baza[0].write(bufor0.c_str(), bufor0.size()) ;
                if (!baza[0].eof()){
                baza[0] << endl ;
                } ;
               baza[2] << endl ;
               (baza[2]).seekg(-2, (baza[2]).cur) ;
               (baza[2]).seekp(-2, (baza[2]).cur) ;
               list<int>::iterator it ;
               for (it=(ludzie[zmienianie.front().cd].itemki.begin()); it!=(ludzie[zmienianie.front().cd].itemki.end()); it++){
                  baza[2] << *it << " " ;
               } ;
                break ;
               } ;
            case 1 :
                {
                int costam=0 ;
                while(baza[0].get()!=10){
                        baza[0].seekg(1, baza[0].cur) ;
                        baza[0].seekp(1, baza[0].cur) ;
                        costam++ ;
                } ;
                for(int i=0 ; i<=costam ; i++){
                    baza[0] <<'' ;
                } ;
                costam=0 ;
                while(baza[2].get()!=10){
                        baza[2].seekg(1, baza[2].cur) ;
                        baza[2].seekp(1, baza[2].cur) ;
                        costam++ ;
                } ;
                for(int i=0 ; i<=costam ; i++){
                    baza[2] << '' ;
                } ;
                break ;
                }
            case 2 :
                {
                int costam=0 ;
                while(baza[0].get()!=10){
                        baza[0].seekg(1, baza[0].cur) ;
                        baza[0].seekp(1, baza[0].cur) ;
                        costam++ ;
                } ;
                for(int i=0 ; i<costam ; i++){
                    baza[0] << '' ;
                } ;
                costam=0 ;
                while(baza[2].get()!=10){
                        baza[2].seekg(1, baza[2].cur) ;
                        baza[2].seekp(1, baza[2].cur) ;
                        costam++ ;
                } ;
                for(int i=0 ; i<costam ; i++){
                    baza[2] << '' ;
                } ;
                buf0=dostringa(this->ludzie[zmienianie.front().cd].wiek) ;
                bufor0 = this->ludzie[zmienianie.front().cd].imie.c_str() ;
                bufor0 += cos.c_str() ;
                bufor0 += this->ludzie[zmienianie.front().cd].nazwisko.c_str() ;
                bufor0 += cos.c_str() ;
                bufor0 += buf0.c_str() ;
                baza[0].write(bufor0.c_str(), bufor0.size()) ;
                list<int>::iterator it ;
               for (it=(ludzie[zmienianie.front().cd].itemki.begin()); it!=(ludzie[zmienianie.front().cd].itemki.end()); it++){
                  baza[2] << *it << " " ;
               } ;
                break ;
                } ;
            default:
                break ;
      } ; // koniec switcha
      list<zmiana>::iterator ii ;
            for(ii=zmienianie.begin(); ii!=zmienianie.end(); ii++){
                    if((*ii).cd>zmienianie.front().cd){
                        (*ii).przesuniecie(zmienianie.front().ab) ;
                    };
            } ;
         (this->zmienianie).pop_front() ;
    } ; //koniec while
    zmienianie.clear() ;
};
bool wypozyczalnia::przedmiotwypozyczony (int a){
    if (przedmioty.size()<a){
      return false ;
   } else {
      list<int>::iterator it ;
      for(int i=0 ; i<(this->ludzie.size()) ; i++){
         for(it=this->ludzie[i].itemki.begin() ; it!=this->ludzie[i].itemki.end(); it++){
            if(*it==a){
               return false ;
            } ;
         } ;
      } ;
   } ;
   return true ;
} ;
void wypozyczalnia::wyczysc(){
    ludzie.clear() ;
    przedmioty.clear() ;
    zmienianie.clear() ;
} ;
