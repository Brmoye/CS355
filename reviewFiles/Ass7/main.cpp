#include <iostream>
#include <string>
using namespace std;

#include "Country.h"
#include "PopStats.h"

int main()
{
    Country kibe("Kibe", 234543);
    PopStats psKibe(kibe, 74432, 43234); //name, number of births, number of deaths

    cout<<"Country: "<<kibe.getName()<<endl;
    cout<<"Birthrate: "<<psKibe.getBirthRate()<<endl;
    cout<<"Deathrate: "<<psKibe.getDeathRate()<<endl<<endl;

    cout<<"UPDATING BIRTH/DEATH NUMBERS"<<endl;
    psKibe.setBirths(13456);
    psKibe.setDeaths(87543);
    cout<<"Country: "<<kibe.getName()<<endl;
    cout<<"Birthrate: "<<psKibe.getBirthRate()<<endl;
    cout<<"Deathrate: "<<psKibe.getDeathRate()<<endl;

    return 0;
}
