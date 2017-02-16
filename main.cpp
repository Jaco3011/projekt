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
#include "klasy.hpp"
int main () {
  system("COLOR 02") ;
  string sciezka ;
  fstream dane ;
  string sciezki[3] ;
  fstream baza[3] ;
  wypozyczalnia Ten ;
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
            Ten.DodajKlienta(klient(wejs)) ;
          } ; //koniec while
          while(!baza[1].eof()){ //wczytywanie przedmiotów
            getline(baza[1], wejs) ;
            Ten.przedmioty.push_back(nasze(wejs)) ;
          } ; //koniec while
          int ii=0;
          list <int> liczby ;
          while(!baza[2].eof()){ //wczytywanie listy wypożyczonych przedmiotów
            getline(baza[2], wejs) ;
            DawajInty(&liczby, wejs) ;
            Ten.ludzie[ii].itemki==liczby ;
            ii++ ;
            if(ii>=Ten.ludzie.size())
              break ;
          } ; //koniec while
        } else {
          poprawnie = false ;
        } ;
        break ; //koniec Q
      case 'w' :
        Ten.aktualizacja(baza) ;
        for (int i=0; i<3 ; i++) {
                try{
          baza[i].flush() ;
          baza[i].close() ;
                }
                catch(...){
                } ;
        } ;
        dane.close() ;
        poprawnie=false ;
        sciezka=sciezkanowa() ;
        if ( wczytywanie(&dane, &sciezka, sciezki) ) {
            cout << "Wczytano nowe ścieżki, teraz możesz wczytać bazę danych" << endl ;
        } ;
        break ; //koniec W
      case 'e' :

        for (int i=0; i<3 ; i++) {
          baza[i].flush() ;
          baza[i].close() ;
        } ;
        Ten.wyczysc() ;
        cout << "Baza zamknięta" << endl ;
        poprawnie=false ;
        break ;
      case 'r' :
        if(poprawnie){
          klient abc ;
          cout << "Podaj imię klienta" << endl ;
          cin >> abc.imie ;
          cout <<"Podaj nazwisko klienta" << endl ;
          cin >> abc.nazwisko ;
          cout << "Podaj wiek klienta" << endl ;
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
          if (Ten.IstnienieKlienta(abcd)){
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
        if(Ten.IstnienieKlienta(uu)){
          cout << "Podaj numer przedmiotu. Liczba ujemna oznacza wycofanie operacji" << endl ;
          cin >> uuu ;
          if (uuu>=0){
            if(Ten.przedmioty.size()>=uuu){
              cout << "Przedmiot o podanym numerze nie istnieje!" << endl ;
            } else {
              cout << "Przedmiot nr. " << Ten.przedmioty[uuu].numer << " nazwa: " << Ten.przedmioty[uuu].nazwa << endl ;
              if(Ten.przedmiotwypozyczony(uuu)){
                cout << "Czy chcesz wypożyczyć? Y/N " ;
                char y=getchar() ;
                if(y=='Y' || y=='y'){
                 Ten.ludzie[uu].itemki.push_back(uuu) ;
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
        } ;
      case 'i':
          int ii ;
          cout << "Podaj numer zwracanego przedmiotu. Liczba ujemna oznacza wycofanie operacji" << endl ;
          cin >> ii ;
          if(Ten.przedmiotwypozyczony(ii)){
            for(int i=0; i<Ten.ludzie.size(); i++){
              if(Ten.ludzie.size()<=i){
                break ;
              } ;
              Ten.ludzie[i].itemki.remove(ii) ;
            } ;
          } else {
            cout << "Podany przedmiot nie istnieje!" << endl ;
          } ;
          break ;
      case 's':
        Ten.aktualizacja(baza) ;
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
              (Ten.ludzie[abcd]).TenKlient() ;
              if ((Ten.ludzie[abcd]).czysty()){
                cout << "Klient nic nie wypożyczyl" << endl ;
              } else {
                cout << "Klient wypożyczył " << Ten.ludzie[abcd].itemki.size() << " przedmiotów :" << endl ;
                list<int>::iterator it ;
                 for (it=(Ten.ludzie[abcd]).itemki.begin(); it!=(Ten.ludzie[abcd]).itemki.end(); it++){
                   cout << "Przedmiot nr na liście" << *it << "nr wewn" << Ten.przedmioty[*it].numer << " nazwa: " << Ten.przedmioty[*it].nazwa << endl ;
                 } ;
              } ;
            } else {
              cout << "Klient o podanym numerze nie istnieje!" << endl ;
            } ;
        } else {
          kont=false ;
        } ;
      default:
        kont=false ;
    } ; //koniec switcha
  if (kont) {
  system("pause") ;
  } ;
    return 0 ;
  } ; //koniec pętli głównej
} ;

