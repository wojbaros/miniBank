#include <iostream>
#include "konto.h"
#include "admin.h"
#include <algorithm>

void naglowek();
extern vector<Konto> klient;
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
void Admin::listaklientow()
{
    sort(klient.begin(),klient.end());
    for (int i=0;i<klient.size();i++)
    klient[i].zobacz();
    cout<<"        Liczba klientow: "<<klient.size();
    getchar();
    getchar();
}

