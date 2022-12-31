
#include "Country.h"

Country::Country(){}
Country::Country(string s, int p){
    name = s;
    population = p;
}
string Country::getName(){
    return name;
}
int  Country::getPopulation(){
    return population;
}
void Country::setName(string s){
    name = s;
}
void Country::setPopulation(int p){
    population = p;
}
