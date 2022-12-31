#include <string>
#include <iostream>
#ifndef ullItem
#define ullItem
	#include "ull.h"
	#include "Item.h"
#endif

using namespace std;

class Area{
  public:
    uLList<Item*> items;

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
    void search()
    {
        nodeType<Item*>* tempNode;
        tempNode = items.getFirst();

        if(tempNode == nullptr)
        {
            cout << "No items are in this area." << endl;
        }
        else
        {
            while(tempNode != nullptr)
            {
                cout << "\t" << tempNode->info->getName() << endl;
                tempNode = tempNode->link;
            }
        }
    }
  private:
     string description;
     bool instadeath;
     bool goal;
};
