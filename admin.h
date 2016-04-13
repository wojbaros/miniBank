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
    Admin (string l,string h,double s);
    void naglowek();
    friend void administracja();
    void stopaprocentowa();
    friend void logowanieadmin();
    void listaklientow();
    friend void Konto::pozyczka();
};
#endif // ADMIN_H_INCLUDED
