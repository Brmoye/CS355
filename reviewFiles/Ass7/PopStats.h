#ifndef INC_COUNTRY
#include "Country.h"
#endif

class PopStats{
    private:
        int numDeaths;
        int numBirths;
        Country c;

    public:
        PopStats(Country, int, int);
        void setBirths(int);
        void setDeaths(int);
        double getBirthRate();
        double getDeathRate();
};
