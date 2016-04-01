#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED


#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Konto;
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
    friend void administracja();
    double stopaprocentowa();
    friend void logowanieadmin();
    void listaklientow();
    friend void Konto::pozyczka();
};
#endif // ADMIN_H_INCLUDED
