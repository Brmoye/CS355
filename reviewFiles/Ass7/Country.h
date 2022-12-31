#ifndef INC_COUNTRY
#define INC_COUNTRY
#endif

#include <string>
using namespace std;

class Country{
    private:
        string name;
        int population;
    public:
        Country();
        Country(string, int);
        string getName();
        int getPopulation();
        void setName(string s);
        void setPopulation(int p);
};
