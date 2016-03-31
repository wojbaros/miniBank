#include <iostream>
#include<vector>
#include "konto.h"
#include <fstream>
#include <cstdlib>

using namespace std;





int menu();
void wczytywanie();
void zapis();

int main()
{
    wczytywanie();
    menu();
    zapis();

    return 0;
}


