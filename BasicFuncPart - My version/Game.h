/*
 * Brian Moye
 * CS355-01
 * Game engine created by Dr. Ray to load .ifd files for users to play.
 * Parts indicated were modified by me.
 */

#include "Map.h"
#include "Player.h"

class Game{
	private:
		Player player1;
		Map map;

  	public:
		Game(){
			player1.setCurrent(map.getStart());
		}

  		void play(){
      			string userInput;
			//cin.ignore();
      			while(true){
				//check game status
				if(player1.isGameOver() != 0){
					player1.getCurrent()->info.displayArea();
					return;
				}
      				//display area data
				if(player1.playerMoved()){
	    				player1.getCurrent()->info.displayArea();
				}
				else{
					cout<<"There appears to be no way to go that direction."<<endl;
				}

	  			//get movement selection
	  			cout<<"Which way would you like to go?  Enter u, d, l, or r"<<endl;
				getline(cin, userInput);

	  			//update area
	  			if(userInput == "u"){
       				player1.setCurrent(player1.getCurrent()->u);
		 		}
				else if(userInput == "d"){
					player1.setCurrent(player1.getCurrent()->d);
				}
				else if(userInput == "l"){
					player1.setCurrent(player1.getCurrent()->l);
				}
				else if(userInput == "r"){
	  				player1.setCurrent(player1.getCurrent()->r);
				}
        // Assignment #4
				else if(userInput == "iseedeadpeople"){ //issdeadpeople cheat code to reveal map
					//map.print();
					//**Assignment #4 Here** cout<<map;
					cout << map;
				}
        // End Assignment #4
				else if(userInput == "exit"){
					cout<<"Good bye!"<<endl;
					return;
				}

				else if(userInput == "help"){
					cout<<"You may type: "<<endl;
					cout<<"\t u, d, l, or r: to move up, down, left or right on the map,"<<endl;
					cout<<"\t reset: to reset the game,"<<endl;
					cout<<"\t exit: to exit the game."<<endl;
					cout<<endl;
				}

        // Assignment #3
				else if(userInput == "reset")
                {
                    player1.setCurrent(map.getStart());
                }
        // end Assignment #3

				else{
					cout<<"I do not understand: "<<userInput<<endl<<endl;
				}


			}//end while
    		}//end play()
};
