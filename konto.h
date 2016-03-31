#ifndef KONTO_H_INCLUDED
#define KONTO_H_INCLUDED

#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;



class Admin;

class Konto
{
    friend class Admin;
private:
    string imie;
    string nazwisko;
    string numer;
    string login;
    string haslo;
    double stan;
    double dlug;
public:


    Konto(string i,string n,string numb="numer_konta",string l="login",string haslo="haslo",double stan=0,double dlug=0);
    Konto() {}
    void naglowek();
    void wplata();
    void wyplata();
    void pozyczka();
    void splata();
    void zobacz() const;
    void zmianahasla();


    friend void przelew(unsigned int i);
    friend void logowanie();
    friend int sprawdzanie(string l,string h);
    friend int sprawdzanieloginu(string l);
    friend void listaklientow();
    friend void obsluga(int i);
    friend void wczytywanie();
    friend double stopaprocentowa();
    friend ostream& operator <<(ostream& out, const Konto& a)
    {
        out << a.imie << '\n';
        out << a.nazwisko << '\n';
        out << a.numer << '\n';
        out << a.login << '\n';
        out << a.haslo << '\n';
        out << a.stan << '\n';
        out << a.dlug << '\n';
        return out;
    }
    friend istream& operator >>(istream& in, Konto& a)
    {
        string zmiana;
        string podmiana;
        getline(in,a.imie );
        getline(in,a.nazwisko );
        getline(in,a.numer);
        getline(in,a.login );
        getline(in,a.haslo ); // since the name is first and last i have to use getline
        getline(in,zmiana);
        a.stan=atof(zmiana.c_str());
        getline(in,podmiana);
        a.dlug=atof(podmiana.c_str());
        return in;
    }
};


class Admin
{
private:
    string login;
    string haslo;
    double stopa;
public:
    friend class Konto;
    Admin (string l,string h,double s);
    void naglowek();

    double stopaprocentowa();
    friend void administracja();
    friend void logowanieadmin();
    friend void Konto::pozyczka();
};

#endif // KONTO_H_INCLUDED
