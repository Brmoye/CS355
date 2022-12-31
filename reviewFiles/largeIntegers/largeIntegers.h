//Specification file largeIntegers.h

class largeIntegers 
{
   friend ostream& operator<< (ostream&, const largeIntegers&);
   friend istream& operator>> (istream&, largeIntegers&);

public:

    largeIntegers operator+(const largeIntegers& num); 
    largeIntegers operator-(const largeIntegers& num);  

    largeIntegers(); 
   
private:
    largeIntegers sumNum(const largeIntegers& num);

    largeIntegers subtractNum(const largeIntegers& num);
      //This function assumes that this number is greater than or
      //equal to num

    int number[100]; 
    int numOfDigits; 
    int maxNumOfDigits;
};


