#ifndef caesarCipher_h
#define caesarCipher_h
#include "caesarCipher.h"
#endif

using namespace std;

class advancedCaesar : public caesarCipher
{
    private:
        string encodedCharacters[26] = {"a","b","c","d","e","f","g","h","i",
			"j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    public:
        advancedCaesar() : caesarCipher()
        {
			constructorHelper();
        }

        advancedCaesar(int sv) : caesarCipher(sv)
        {
			constructorHelper();
		}

		void constructorHelper()
		{
			for(int i = 0; i < 26; ++i)
			{
				encodedCharacters[i] = encrypt(encodedCharacters[i]);
			}
		}

		void print()
		{
			cout << "Shift value: ";
			caesarCipher :: print();

			cout << "Encrypted alphabet: ";
			for(int i = 0; i < 26; ++i)
			{
				cout << encodedCharacters[i];
			}
			cout << endl << endl;
		}
};
