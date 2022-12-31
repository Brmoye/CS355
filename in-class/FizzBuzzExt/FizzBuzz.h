class FizzBuzz
{
   protected:
    	int limit;

   public:
	FizzBuzz(){
		limit = 100;
	}
   	void run(){
   		for(int i = 1; i <= limit; ++i){
      		if(i % 3 == 0 && i % 5 == 0){
           		cout << "FizzBuzz" << endl;
      		}
       		else if(i % 3 == 0){
	           	cout << "Fizz" << endl;
	          }
          	else if(i % 5 == 0){
           		cout << "Buzz" << endl;
           	}
          	else{
 				cout << i << endl;
 			}
   		}
   	}
	void setLimit(){
   		cout << endl;
   		cout << "Enter the new limit of the game: ";
   		cin >> limit;
   		cout << "Limit set to: " << limit << endl;
   		cout << endl;
	}
	int menu(){
		int choice;
		cout << "Menu: " << endl;
		cout << "\t 1. Run the game. "<< endl;
		cout << "\t 2. Set the limit value. "<< endl;
		cout << "\t 3. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		return choice;
	}
};
