/*
 * Brian Moye
 * CS355-01
 * Game engine created by Dr. Ray to load .ifd files for users to play.
 * Parts indicated were modified by me.
 */

class Player{
  public:
    Player(){
		lastLocation = NULL;
		currentLocation = NULL;
	}

	void setCurrent(areaNode* loc){
        lastLocation = currentLocation;
		currentLocation = loc;
	}

	bool playerMoved(){
		return !(lastLocation == currentLocation);
	}
	areaNode* getCurrent(){
		return currentLocation;
	}

	//isGameOver should return: 0 for continue, 1 for win, 2 for lose
// Assignment #1
	int isGameOver(){
         int gameState = 0;

		 if(currentLocation-> info.getID() == 1)
         {
             gameState = 2;
         }
         else if(currentLocation-> info.getGoal() == 1)
         {
             gameState = 1;
         }
         else
         {
             // do nothing
         }

		 return gameState;
	}
// end Assignment #1

  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};
