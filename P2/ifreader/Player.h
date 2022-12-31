/*
 * Brian Moye
 * CS355-01
 * Game engine created by Dr. Ray to load .ifd files for users to play.
 * Parts indicated were modified by me.
 */

#ifndef ullItem
#define ullItem
	#include "ull.h"
	#include "Item.h"
#endif

class Player{
  public:
    uLList<Item*> items;

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

// Code below modified by me
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


// Assignment 3
    void inventory()
    {
        nodeType<Item*>* tempNode = items.getFirst();

        if(tempNode == nullptr)
        {
            cout << "No items are in your inventory." << endl;
        }
        else
        {
            cout << "You have the following items:" << endl;
            while(tempNode != nullptr)
            {
                cout << "\t" << tempNode->info->getName() << endl;
                tempNode = tempNode->link;
            }
        }
    }

    void take()
    {
        string itemToTake;
        Item* takenItem;
        nodeType<Item*>* tempNode = currentLocation->info.items.getFirst();

        cout << "Take what item?" << endl;
        getline(cin, itemToTake);

        if(currentLocation->info.items.length() == 0)
        {
            cout << "No items are in this area to take." << endl;
        }
        else
        {
            while(tempNode != nullptr && tempNode->info->getName() != itemToTake)
            {
                tempNode = tempNode->link;
            }
            if(tempNode != nullptr)
            {
                takenItem = tempNode->info;
                items.insertLast(takenItem);
                currentLocation->info.items.deleteNode(tempNode->info);

                if(!currentLocation->info.items.search(takenItem))
                {
                    cout << "You have taken: " << takenItem->getName() << endl;
                }
            }
            else
            {
                cout << "No item by that name here." << endl;
            }
        }
    }

    void leave()
    {
        string itemToLeave;
        Item* leftItem;
        nodeType<Item*>* tempNode = items.getFirst();

        if(items.isEmptyList())
        {
            cout << "You have no items in your inventory." << endl;
        }
        else
        {
            cout << "Leave what item?" << endl;
            getline(cin, itemToLeave);

            while(tempNode != nullptr && tempNode->info->getName() != itemToLeave)
            {
                tempNode = tempNode->link;
            }
            if(tempNode != nullptr)
            {
                leftItem = tempNode->info;
                currentLocation->info.items.insertLast(leftItem);
                items.deleteNode(leftItem);

                if(!items.search(leftItem))
                {
                cout << "You have left: " << leftItem->getName() << endl;
                }
            }
            else
            {
                cout << "No item by that name in your inventory." << endl;
            }
        }
    }

    void examine()
    {
        string itemToExamine;
        nodeType<Item*>* tempNode = items.getFirst();

        if(items.isEmptyList())
        {
            cout << "You have no items in your inventory to examine." << endl;
        }
        else
        {
            cout << "Examine what item?" << endl;
            getline(cin, itemToExamine);

            while(tempNode != nullptr && tempNode->info->getName() != itemToExamine)
            {
                tempNode = tempNode->link;
            }
            if(tempNode != nullptr)
            {
                tempNode->info->displayDesc();
                cout << endl;
            }
            else
            {
                cout << "No item by that name in your inventory." << endl;
            }
        }
    }
// end Assignment 3

  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};
