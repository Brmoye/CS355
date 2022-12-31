#include <iostream>

using namespace std;

class LinkData{
	public:
		static const int SIZE = 4;

		void setDigits(int u, int d, int l, int r){
			//u,l,d,r
			digits[0] = u;
			digits[1] = d;
			digits[2] = l;
			digits[3] = r;
		}
		int getDigit(int pos){
			return digits[pos];
		}

	private:
		int digits[4];
};
