#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include "konto.h"
#include "admin.h"
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>


using namespace std;
vector<Konto> klient;
Admin admin("admin","haslo",0);

string nowehaslo(int len);
void nowekonto();
void listaklientow();
int sprawdzanie(string l, string h);
int sprawdzanieloginu(string l);
void logowanie();
void logowanieadmin();
void obsluga(int i);
void administracja();
void przelew(unsigned int i);

void wczytywanie()
{
    fstream file;
    file.open( "lista_klientow.txt", std::ios::in );
    Konto temp;
    while(file >> temp)
    {
        klient.push_back(temp);
    }
    file.close();
}

void naglowek()
{
    for (int i=1; i<50; i++)
        cout<<"*";
    cout<<"\n*               miniBank    v 1.0               *\n";
    time_t czas;
    time(&czas);
    cout<<"           "<<ctime(&czas);
    for (int i=1; i<50; i++)
        cout<<"*";
        cout<<endl;
}

int menu()
{

    char wybor=0;
    for(;;)
    {
        system("cls");
        naglowek();
        cout<<"\n    Witaj w banku miniBank,\n    Wybierz pozycje i korzystaj z naszych uslug\n\n";
        cout<<"    1.    Zakladam nowe konto\n";
        cout<<"    2.    Logowanie uzytkownika\n";
        cout<<"    3.    Panel administratora\n";
        cout<<"    4.    Chce do domu, pa\n";
        wybor=getch();
        switch(wybor)
        {
        case '1':

            system("cls");
            naglowek();
            nowekonto();
            break;
        case '2':

            system("cls");
            naglowek();
            logowanie();

            break;
        case '3':

            system("cls");
            naglowek();
            logowanieadmin();
            break;
        case '4':
            system("cls");
            naglowek();
            cout<<"\n\n   Zmiany w aplikacji wlasnie zostaja zapisane";
            cout<<"\n      Narazicho i do zobaczenia in future\n";
            return 0;
            break;
        default:
            cout<<"\nWcisnij dowolny klawicz i wybierz 1,2,3 lub 4 aby wyjsc\n";
            wybor=getch();
        }
    }
}

void logowanieadmin()
{
    system("cls");
    naglowek();
    cout<<"Logowanie administratora.\n";
    string l,h;
    cout<<"Podaj login: ";
    cin>>l;
    cout<<"Podaj haslo: ";
    cin>>h;

    if(l==admin.login && h==admin.haslo)
    {
        administracja();
    }
    else
    {
        cout<<"Nieprawidlowe login lub haslo administratora...";
        cout<<"\n1. Chce sprobowac podownie\n";
        cout<<"2. Chce wrocic do glownego Menu\n";
        char wybor;
        wybor=getch();
        switch(wybor)
        {

        case '1':
            logowanieadmin();
            break;

        case '2':
            break;

        default:
            cout<<"\nWcisnij dowolny klawicz i wybierz 1,2";
            wybor=getch();
        }
    }
}
void administracja()
{

    char wybor=0;
    for(;;)
    {
        system("cls");
        naglowek();
        cout<<"\n        Panel Administratora\n";
        cout<<"    1.    Zobacz konta klientow\n";
        cout<<"    2.    Zmien stopy procentowe\n";
        cout<<"    3.    Wyjdz\n";
        wybor=getch();
        switch(wybor)
        {
        case '1':

            system("cls");
            naglowek();
            admin.listaklientow();
            break;
        case '2':

            system("cls");
            naglowek();
            admin.stopaprocentowa();
            getchar();

            break;
        case '3':

            cout<<"\nDo widzenia Panie Administratorze";
            getchar();
            getchar();
            return;
            break;

        default:
            cout<<"\nWcisnij dowolny klawicz i wybierz 1,2,3 aby wyjsc\n";
            wybor=getch();
        }
    }
}

int sprawdzanieloginu(string l)

{
    unsigned i;
    for (i =0; i<klient.size(); i++)
    {
        if(l == klient[i].login)
            return i;
    }
    return i;
}

string nowehaslo(int len)
{
    srand(time(0));
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int pos;
    while(str.size() != len)
    {
        pos = ((rand() % (str.size() - 1)));
        str.erase (pos, 1);
    }
    return str;
}
string generatornumeru()
{

    srand(time(0));
    int pos;
    string a="26";
    pos = ((rand() % 100000000)+10000000);
    stringstream ss;
    ss << pos;
    string str = ss.str();
    string b=a+str;
    return b;
}
void nowekonto()
{
    system("cls");
    naglowek();
    cout<<"Witam serdecznie w naszym banku: \n";
    string i,n,numb,l,h;

    cout<<"Podaj imie: ";
    cin>>i;
    cout<<"Podaj nazwisko: ";
    cin>>n;
    cout<<"Podaj login: ";
    cin>>l;
    h=nowehaslo(6);
    numb=generatornumeru();

    if(sprawdzanieloginu(l)==klient.size())
    {
        klient.push_back( Konto( i, n,numb,l,h,0,0) );
        system("cls");
        naglowek();
        cout<<"Gratuluje! Wlasnie zalozyles u nas konto! \n";
        cout<<"\nOto twoj nr konta: ";
        for(int i=0;i<10;i++)
    {
        if (i==2||i==6) cout<<" ";
        cout<<numb[i];
    }
        cout<<"\nOto twoj login: "<<l<<"\nTwoje haslo: "<<h<<"\nHaslo moze zmienic w kazdej chwili";
        cout<<"\n\nKliknij dowolny klawisz by wejsc w panel logowania";
        getchar();
    }
    else
    {
        cout<<"\nLogin zajety...Nastepnym razem Ci sie uda";
        getchar();
    }
    getchar();
}

int sprawdzanie(string l, string h)

{
    unsigned i;
    for (i =0; i<klient.size(); i++)
    {
        if(l == klient[i].login && h == klient[i].haslo)
            return i;
    }
    return i;
}

void logowanie()
{

    system("cls");
    naglowek();
    cout<<"Logowanie uzytkownika.\n";
    string l,h;
    cout<<"Podaj login: ";
    cin>>l;
    cout<<"Podaj haslo: ";
    cin>>h;

    if(sprawdzanie(l,h)<klient.size())
    {
        system("cls");
        naglowek();
        int i=sprawdzanie(l,h);
        obsluga(i);
        getchar();
        getchar();
    }
    else
    {
        cout<<"Nieprawidlowe login lub haslo...";
        cout<<"\n1. Chce sprobowac podownie\n";
        cout<<"2. Chce zalozyc nowe konto\n";
        cout<<"3. Powrot do glownego menu\n";
        char wybor;
        wybor=getch();
        switch(wybor)
        {

        case '1':
            logowanie();
            break;
        case '2':
            nowekonto();

        case '3':
            return;
            break;

        default:
            cout<<"\nWcisnij dowolny klawicz i wybierz 1,2 lub 3";
            wybor=getch();
        }
    }
    return;
}
void obsluga(int i)
{
    char wybor=0;
    for(;;)
    {
        system("cls");
        naglowek();
        cout<<"          Konto osobiste w miniBank\n";
        klient[i].zobacz();
        cout<<"\n\n\n        Witaj!\n        Wybierz rodzaj uslugi:\n\n";
        cout<<"        1.    Wplac gotowke\n";
        cout<<"        2.    Wyplac gotowke\n";
        cout<<"        3.    Zmien haslo\n";
        cout<<"        4.    Wez pozyczke\n";
        cout<<"        5.    Splac pozyczke\n";
        cout<<"        6.    Dokonaj przelewu\n";
        cout<<"        7.    Wyloguj sie\n";
        wybor=getch();
        switch(wybor)
        {
        case '1':

            system("cls");
            naglowek();
            klient[i].wplata();
            break;
        case '2':

            system("cls");
            naglowek();
            klient[i].wyplata();

            break;
        case '3':

            system("cls");
            naglowek();
            klient[i].zmianahasla();
            break;
        case '4':

            system("cls");
            naglowek();
            klient[i].pozyczka();
            break;
        case '5':

            system("cls");
            naglowek();
            klient[i].splata();
            break;
        case '6':

            system("cls");
            naglowek();
            przelew(i);
            break;

        case '7':


            cout<<"\nDziekujemy za skorzystanie z naszych uslug.\nNastapi powrot do menu glownego.\nDo zobaczenia!";

            return ;


            break;

        default:
            cout<<"\nWcisnij dowolny klawicz i wybierz 1,2,3,4,5,6,7\n";
            wybor=getch();
        }
    }
}

void przelew(unsigned int i)
{
    unsigned int id=klient.size();
    double kwota;
    string im,nazw;
    cout<<"Przelew wewnetrzny\n";
    cout<<"Podaj imie klienta: ";
    cin>>im;
    cout<<"Podaj nazwisko klienta: ";
    cin>>nazw;
    cout<<"Podaj kwote: ";
    cin>>kwota;

    for (int j=0; j<klient.size(); j++)
    {
        if (im==klient[j].imie && nazw==klient[j].nazwisko)
            id=j;
    }

    if (cin.good()&& kwota<=klient[i].stan&&id<klient.size())
    {
        for(;;)
        {
            system("cls");
            naglowek();
            cout<<"Adresat przelewu: \n"<<klient[id].imie<<" "<<klient[id].nazwisko;;
            cout<<"\nKwota: "<<kwota<<" zl\n";
            cout<<"Aby potwierdzic wcisnij klawisz T, by anulowac wcisnij N\n";
            char g;
            cin>>g;
            if (g=='T'||g=='t')
            {
                klient[i].stan-=kwota;
                klient[id].stan+=kwota;
                cout<<"Przelew dokonany\n";
                cout<<klient[id].imie<<" "<<klient[id].nazwisko<<" otrzymal "<<kwota<<" zl";
                getchar();getchar();
                return;
            }
            else if (g=='n'||g=='N')
            {
                cout<<"Dyspozycje anulowano, milego dzionka!";
                getchar(); getchar();
                return;
            }
            else
            {
                cout<<"Ale widzisz jaki masz wybor czy nie?";
                getchar();getchar();
            }
        }
    }
    else if (cin.good()&&kwota>=klient[i].stan)
    {
        cout<<"Nie masz tyle na koncie biedaku";

        getchar();;
    }
    else if (cin.good()&&id==klient.size())
    {
        cout<<"Nie ma takiego klienta, sprobuj ponownie";

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

void zapis()
{
    fstream file;
    file.open( "lista_klientow.txt", std::ios::out );
    file.clear();
    for(int i=0; i<klient.size(); i++)
        file<<klient[i];
    file.close();
}
