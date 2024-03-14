#include <ctime>
#include <cstdlib>

#include <iostream>
#include <random>

using namespace std;

int main()
{
    int* dyn_muuttujan_osoite = nullptr;
    dyn_muuttujan_osoite = new int(7);
    cout << "Osoite: " << dyn_muuttujan_osoite << endl;
    cout << "Alku:   " << *dyn_muuttujan_osoite << endl;
    *dyn_muuttujan_osoite = *dyn_muuttujan_osoite * 4;
    cout << "Loppu:  " << *dyn_muuttujan_osoite << endl;
    delete dyn_muuttujan_osoite;


    return 0;
}
