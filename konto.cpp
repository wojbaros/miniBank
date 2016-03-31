#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include "konto.h"
#include <conio.h>
#include <time.h>
#include <fstream>
using namespace std;
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

format initialState = setFormat();
precis prec = cout.precision(2);

void naglowek();
void obsluga(int i);
extern Admin admin;


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
        cout<<"Nastepnym razem kierwa podaj kwote jak liczbe dodatnia, bo zal...";
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
        cout<<"Nie masz tyle na koncie biedaku";

        getchar();;
    }
    else
    {


        cout<<"Nastepnym razem kierwa podaj kwote jak liczbe dodatnia, bo zal...";
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


        cout<<"Nastepnym razem kierwa podaj kwote jak liczbe dodatnia, bo zal...";
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


        cout<<"Nastepnym razem kierwa podaj kwote jak liczbe dodatnia, bo zal...";
        cin.clear();
        getchar();
        cin.sync();

    }
    getchar();
}


void Konto::zobacz() const

{

    cout<<"\n        Imie: ";
    cout.width( 26 );
    cout<<imie;
    cout<<"\n        Nazwisko: ";
    cout.width( 22 );
    cout<<nazwisko;
     cout<<"\n        Numer konta: ";
    cout.width( 19 );
    cout<<numer;
    cout<<"\n        Stan Konta: ";
    cout.width( 17);
    cout<<stan<<" zl";
    cout<<"\n        Dlug: : ";
    cout.width( 21);
    cout<<dlug<<" zl";
    cout<<"\n        ________________________________"<<endl;

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

Admin::Admin(string l,string h,double s)
{
    login=l;
    haslo=h;
    stopa=s;
}
double Admin::stopaprocentowa()
{
    cout<<"Obecna Stopa procentowa wynosi: "<<stopa*100<<" %";
    cout<<" \nZmien ja i podaj nowa stope procentowa w procentach\n\n";
    double s=0;
    cin>>s;
    if (cin.good()&& s>=0)
    {
        cout<<"Elegancko. Ustawiles stope procentowa na "<<s<<" %";
        stopa=s/100;
        getchar();

    }
    else
    {
        cout<<"Nastepnym razem kierwa podaj stope jako liczbe dodatnia, bo zal...";
        cin.clear();
        getchar();
        cin.sync();
    }

    getchar();
}

format setFormat()
{
    // ustawienie formatu na ###.##
    return cout.setf(std::ios_base::fixed,
                     std::ios_base::floatfield);
}
void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);

}

