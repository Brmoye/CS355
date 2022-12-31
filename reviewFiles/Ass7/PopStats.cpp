#include "PopStats.h"

PopStats::PopStats(Country cc, int nB, int nD){
    numDeaths = nD;
    numBirths = nB;
    c = cc;
}

void PopStats::setBirths(int nB){
    numBirths = nB;
}

void PopStats::setDeaths(int nD){
    numDeaths = nD;
}

double PopStats::getBirthRate(){
    return (double)numBirths / c.getPopulation();
}

double PopStats::getDeathRate(){
    return (double)numDeaths / c.getPopulation();
}
