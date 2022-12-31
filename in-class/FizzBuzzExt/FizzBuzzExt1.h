#include <string>

class FizzBuzzExt : public FizzBuzz
{
	private:
		int* mults;
		string* words;
		int numrules;

	public:
		FizzBuzzExt(){
			mults = new int[100];
			words = new string[100];
			numrules = 0;
		}

		void clear(){
			numrules = 0;
		}

		void addRule(){
			int newnum;
			string newword;

			cout << "Enter the new multiple." << endl;
			cin >> newnum;

			cout << "Enter the new word." << endl;
			cin >> newword;

			mults[numrules] = newnum;
			words[numrules] = newword;
			++numrules;
		}

		int menu(){
			int choice;

			cout << "Menu: " << endl;
			cout << "\t 1. Run the game. "<< endl;
			cout << "\t 2. Set the limit value. "<< endl;
			cout << "\t 3. Add a rule. "<< endl;
			cout << "\t 4. Clear All Rules. "<< endl;
			cout << "\t 5. Quit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			return choice;
		}

		void run(){
   			bool flag;

   			if(numrules == 0){
   				cout << "Sorry, no rules currently exist." << endl;
   				return;
   			}

			for (int i = 1; i <= limit; ++i){
				string output = "";
				flag = false;

				for(int j = 0; j < numrules; ++j){
					if(i % mults[j] == 0){
						output += words[j];
						flag = true;
					}
				}

				if(flag){
					cout << output<< endl;
					flag = false;
				}
				else{
					cout << i << endl;
				}
			}

			return;
   		}
};
