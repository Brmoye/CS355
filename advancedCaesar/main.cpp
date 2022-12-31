#include <iostream>
#include "advancedCaesar.h"

using namespace std;

int main()
{
	advancedCaesar c1;
	advancedCaesar c2(5);
	string message = "cakeinthebreakroom";

	c1.print();

	message = c1.encrypt(message);
	cout << message << endl;

	message = c1.decrypt(message);
	cout << message << endl;

	cout << endl;

	c2.print();

	message = c2.encrypt(message);
	cout << message << endl;

	message = c2.decrypt(message);
	cout << message << endl;

    return 0;
}
