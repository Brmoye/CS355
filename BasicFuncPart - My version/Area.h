#include <string>
#include <iostream>

using namespace std;

class Area{
  public:
    void setDescription (string desc){
    	description = desc;
    }
    void setGoal(bool g){
	goal = g;		
    }
    void setID(bool id){
	instadeath = id;		
    }
    string getDescription(){
    	return description;
    }
    bool getID(){
    	return instadeath;
    }
    bool getGoal(){
	return goal;
    }
    void displayArea(){
	cout<<description<<endl;		
    }
  private:
     string description;
     bool instadeath;
     bool goal;	
};
