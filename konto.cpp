#include <iostream>
#include <cstdlib>
#include "konto.h"
#include "admin.h"
#include <conio.h>
#include <time.h>
#include <fstream>
using namespace std;

void naglowek();
void obsluga(int i);
extern Admin admin;
extern vector<Konto> klient;

Konto::Konto(string i,string n,string numb,string l,string h,double s,double d)
{
    imie=i;
    nazwisko=n;
    numer=numb;
    login=l;
    haslo=h;
    stan=0;
    dlug=0;
}

void Konto::zobacz() const
{

    cout<<"\n        Imie: ";
    cout.width( 26 );
    cout<<imie;
    cout<<"\n        Nazwisko: ";
    cout.width( 22 );
    cout<<nazwisko;
    cout<<"\n        Numer konta:        ";
    for(int i=0;i<10;i++)
    {
        if (i==2||i==6) cout<<" ";
        cout<<numer[i];
    }
    cout<<"\n        Stan Konta: ";
    cout.width( 17);
    cout<<stan<<" zl";
    cout<<"\n        Dlug: : ";
    cout.width( 21);
    cout<<dlug<<" zl";
    cout<<"\n        ________________________________"<<endl;
}

void Konto::wplata()
{
    double kwota;
    cout<<"Podaj jaka kwote chcesz wplacic: ";

    cin>>kwota;
    if (cin.good()&& kwota>0)
    {
        stan+=kwota;
        cout<<"Wplata zakonczona pieniadze juz czekaja na koncie";
        getchar();

    }
    else
    {
        cout<<"Nastepnym razem podaj kwote jak liczbe dodatnia, bo zal...";
        cin.clear();
        getchar();
        cin.sync();
    }
    getchar();
}

void Konto::wyplata()
{
    double kwota;
    cout<<"Podaj jaka kwote chcesz wyplacic: ";

    cin>>kwota;
    if (cin.good()&& kwota<=stan)
    {
        stan-=kwota;
        cout<<"Prosze bardzo oto twoje "<<kwota<<" zl";
        getchar();
    }
    else if (cin.good()&&kwota>=stan)
    {
        cout<<"Nie masz tyle na koncie ";

        getchar();
    }
    else
    {
        cout<<"Nastepnym razem podaj kwote jak liczbe dodatnia, bo zal...";
        cin.clear();
        getchar();
        cin.sync();
    }
    getchar();
}

void Konto::pozyczka()
{
    double kwota;
    double procent=admin.stopa;
    cout<<"Stopa procentowa przy pozyczce wynosi "<<procent*100<<" %\n";
    cout<<"Podaj jaka kwote chcesz pozyczyc: ";
    cin>>kwota;
    if (cin.good()&& kwota<=100000)
    {
        dlug=dlug+kwota+procent*kwota;
        stan+=kwota;
        cout<<"Pozyczka udzielona. Na twoje konto przelalismy "<<kwota<<" zl\n";
        cout<<"Doliczono rowniez odsetki od pozyczki w wysokosci "<<procent*kwota<<" zl";
        getchar();
    }
    else if (cin.good()&&kwota>=100000)
    {
        cout<<"Nie zaslugujesz na tyle";

        getchar();;
    }
    else
    {
        cout<<"Nastepnym razem podaj kwote jak liczbe dodatnia, bo zal...";
        cin.clear();
        getchar();
        cin.sync();
    }
    getchar();
}

void Konto::splata()
{
    double kwota;
    cout<<"Podaj jaka kwote chcesz splacic: ";

    cin>>kwota;
    if (cin.good()&& kwota>dlug)
    {
        cout<<"Masz mniejszy dlug";
        getchar();
    }
    else if (cin.good()&& kwota<=stan)
    {
        dlug-=kwota;
        stan-=kwota;
        cout<<"Wlasnie splaciles "<<kwota<<" zl";
        getchar();

    }
    else if (cin.good()&&kwota>=stan)
    {
        cout<<"Nie masz tyle na koncie biedaku";

        getchar();;
    }
    else
    {
        cout<<"Nastepnym razem podaj kwote jak liczbe dodatnia, bo zal...";
        cin.clear();
        getchar();
        cin.sync();

    }
    getchar();
}

void Konto::zmianahasla()
{
    string temp,nowe;
    cout<<"Podaj stare haslo: ";
    cin>>temp;
    if (temp==haslo)
    {
        cin.sync();
        cout<<"Podaj nowe haslo: ";
        cin>>nowe;
        haslo=nowe;
        cout<<"Haslo zostalo zmienione";
        getchar();
    }
    else
    {
        cin.sync();
        cout<<"Musisz podaj prawidlowe haslo";
        getchar();
    }
    getchar();
}

void usunkonto() {}


