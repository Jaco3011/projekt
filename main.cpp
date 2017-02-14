#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <sstream>
#include "funkcje.hpp"
#inlcude "klasy.hpp"
int main () {
  system("COLOR 02") ;
  string sciezka ;
  fstream dane ;
  string sciezki[3] ;
  fstream baza[3] ;
  wypozyczalnia Ten=new wypozyczalnia() ;
  bool poprawnie=false ;
  bool kont;
  nasze * zaz_przedm=NULL ;
  klient * zaz_kli=NULL ;
  while(true){ //początek pętli głównej
    system("cls") ;
    kont=true;
    WypiszMenu(poprawnie) ;
    switch(getchar()) {
      case 'Q' :
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        wczytajbaze(3, baza, sciezki) ;
        if (wszystkodobrze(3, baza)){
          poprawnie = true ;
          //procedura wczytywania
          string wejs ;
          while(!baza[0].eof()){ //wczytywanie klientów
            getline(baza[0], wejs) ;
            Ten.DodajKlienta(new klient(wejs)) ;
          } ; //koniec while
          while(!baza[1].eof()){ //wczytywanie przedmiotów
            getline(baza[1], wejs) ;
            Ten.przedmioty.push_back(new nasze(wejs)) ;
          } ; //koniec while
          int ii=0;
          list <int> liczby ;
          while(!baza[2].eof()){ //wczytywanie listy wypożyczonych przedmiotów
            getline(baza[2], wejs) ;
            DawajInty(liczby, wejs) ;
            Ten.ludzie[ii].itemki==liczby
            ii++ ;
            if(ii>=Ten.ludzie.size())
              break ;
          } ; //koniec while
        } else {
          poprawnie = false ;
        } ;
        break ; //koniec Q
      case 'w' :
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        dane.close() ;
        poprawnie=false ;
        sciezka=sciezkanowa() ;
        if ( wczytywanie(dane, sciezka, sciezki) ) {
          
        } ;
        break ; //koniec W
      case 'e' :
        
        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        Ten=NULL ;
        cout << "Baza zamknięta" << endl ;
        poprawnie=false ;
        break ;
      case 'r' :
        if(poprawnie){
          klient abc ;
          cout << "Podaj imię klienta" << endl ;
          cin >> abc.imie ;
          cout >> "Podaj nazwisko klienta" << endl ;
          cin >> abc.nazwisko ;
          cout >> "Podaj wiek klienta" << endl ;
          cin >> abc.wiek ;
          cout << "Dane klienta: " << endl ;
          abc.TenKlient() ;
          cout << "Dodać do bazy? Y/N " ;
          char y=getchar() ;
          if(y=='Y' || y=='y'){
            Ten.DodajKlienta(abc) ;
            cout << "Klient został pomyślnie dodany do bazy danych" << endl ;
          } else {
            cout << "Klient nie został dodany do bazy danych" << endl ;
          } ;
        } else{
          kont=false ;
        } ;
        break;
      case 't':
        if(poprawnie){
          int abcd ;
          cout << "Podaj nr. klienta do usunięcia " << endl ;
          cin >> abcd ;
          if (Ten.istnienieKlienta(abcd)){
              (Ten.ludzie[abcd]).TenKlient() ;
            if((Ten.ludzie[abcd]).czysty()){
              cout << "Czy na pewno chcesz usunąć? Y/N " ;
              
            } else {
              cout << "Klient ma wypożyczone przedmioty! " << endl ;
            } ;
          } else {
            cout << "Podany klient nie istnieje! " << endl ;
          } ;
        } else {
          kont=false ;
        } ;
        break ; // koniec T
      case 'y':
        cout << "Funkcja niedostępna w obecnej wersji" << endl ;
        break ; //koniec Y
      case 'u':
        int uu,uuu ;
        cout << "podaj nr klienta: " << endl ;
        cin >> uu ;
        if(Ten.IstnienieKlienta[uu]){
          cout << "Podaj numer przedmiotu. Liczba ujemna oznacza wycofanie operacji" << endl ;
          cin >> uuu ;
          if (uuu>=0){
            if(Ten.przedmioty[uuu]==NULL){
              cout << "Przedmiot o podanym numerze nie istnieje!" endl ;
            } else {
              cout << "Przedmiot nr. " << Ten.przedmioty[uuu].numer << " nazwa: " << Ten.przedmioty[uuu].nazwa << endl ;
              if(Ten.przedmiotwypozyczony(uuu)){
                cout << "Czy chcesz wypożyczyć? Y/N " ;
                char y=getchar() ;
                if(y=='Y' || y=='y'){
                 Ten.ludzie[uu].itemki.push_back[uuu] ;
                 cout << "Wypożyczono" << endl ;
               } else {
                 cout << "nie wypożyczono" << endl ;
               } ;
              } else {
               cout << "Ten przedmiot juest już wypożyczony" << endl ;
            } ;
          } ;
        } else {
          cout << "Podany klient nie istnieje! " << endl ;
        } ;
        break ;
      case 'i':
          int ii ;
          cout << "Podaj numer zwracanego przedmiotu. Liczba ujemna oznacza wycofanie operacji" << endl ;
          cin >> ii ;
          if(Ten.przedmiotwypozyczony(ii)){
            for(int i=0; i<Ten.ludzie.size(); i++){
              if(Ten.ludzie[i]!=NULL){
                Ten.ludzie[i].itemki.remove(ii) ;
              } ;
            } ;
          } else {
            cout << "Podany przedmiot nie istnieje!" << endl ;
          } ;
          break ;
      case 's':
        Ten.aktualizacja() ;
        if(poprawnie){
          for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
        } ;
          cout << "Baza zapisana" << endl ;
        } else {
          kont=false ;
        } ;
        break ; //koniec S   
      case 'd':
        if (poprawnie) {
            int abcd ;
            cout << "Podaj nr klienta: " ;
            cin >> abcd ;
            if(Ten.IstnienieKlienta(abcd)) {
              (Ten.ludzie[abcd]).TenKilent() ;
              if ((Ten.ludzie[abcd]).czysty()){
                cout << "Klient nic nie wypożyczyl" << endl ;
              } else {
                cout << "Klient wypożyczył " << Ten.ludzie[abcd].itemki.size() << " przedmiotów :" << endl ;
                list<int>::iterator it ;
                 for (it=liczby.begin(); it!=liczby.end(); it++){
                   cout << "Przedmiot nr wewn" << Ten.przedmioty[*it].numer << " nazwa: " << Ten.przedmioty[*it].nazwa << endl ;
                 } ;
              } ;
            } else {
              cout << "Klient o podanym numerze nie istnieje!" << endl ;
            } ;
        } else {
          kont=false
        } ;
      default:
        kont=false ;
    } ;
  if (kont) {
  system("pause") ;
  } ;
  } ; //koniec pętli głównej
  return 0 ;
} ;
