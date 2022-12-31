#ifndef MAP_H
#define MAP_H
	#include "Map.h"
#endif

using namespace std;

class MapV2 : public Map
{
    protected:
        vector<Item*> itemsVec;

	public:
        MapV2(){
			ifderr = false;
			parser.tokenIt();

			nextToken = parser.getNext();

			if(nextToken == "<game>"){
				parser.eatToken();
				nextToken = parser.getNext();
				while(nextToken != "</game>"){  //consider what happens when run out of tokens && not error state
					if(nextToken == "<area>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeArea();
					}
					else if(nextToken == "<links>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeLinks();
					}
		// begin itemParsing
					else if(nextToken == "<item>")
					{
                        parser.eatToken();
                        nextToken = parser.getNext();
                        makeItem();
					}
		// end itemParsing
					else{
						cout<<"Parse Error Location 1"<<endl;
						ifderr = true;
						break;
					}
					parser.eatToken();
					nextToken = parser.getNext();
				}// while !</game>

				if(ifderr){
					cout<<" :: ERROR :: IF Document Formatting Error"<<endl;
					cout<<"Game Loading Failed"<<endl;
					cout<<"General Area of Parsing Failure:"<<endl;
					cout<<"-------------------------------------"<<endl;
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					cout<<"-------------------------------------"<<endl;
					return;
				}
				//cout<<"::Found </game>::"<<endl;
			}
			else{
				cout<<" :: ERROR :: No \"<game>\" tag found."<<endl;
				cout<<"Game Loading Failed"<<endl;
			}

			//link up areas
			linkLinks();
			insertItems();
			/*
			for(int i = 0; i < itemsVec.size(); ++i){
                itemsVec[i]->displayName();
                cout << " is in area " << itemsVec[i]->getSR() << endl;

                cout << boolalpha << areasVec[itemsVec[i]->getSR()]->info.items.search(itemsVec[i]) << endl;
			}
			*/
		}//constructor

// copied most of the code for makeItem from makeArea with some changes
        void makeItem()
        {
			string xstr;

			Item* tempItemPtr = new Item;

			while(nextToken != "</item>")
			{
                if(nextToken == "<name>")
                {
                    parser.eatToken();
					nextToken = parser.getNext();

					tempItemPtr->setName(nextToken);
                }
				else if(nextToken == "<desc>")
				{
					parser.eatToken();
					nextToken = parser.getNext();

					tempItemPtr->setDesc(nextToken);
				}
				else if(nextToken == "<star>")
				{
					parser.eatToken();
					nextToken = parser.getNext();

					istringstream ss(nextToken);
          				getline(ss, xstr, ',');
          				tempItemPtr->setSR(atoi(xstr.c_str()));
				}
				else if(nextToken == "</name>" || nextToken == "</desc>" || nextToken == "</star>")
				{
				  //do nothing
				}
				else
				{
					cout<<"Parse Error Location 2"<<endl;
					ifderr = true;
					break;
				}

				parser.eatToken();
				nextToken = parser.getNext();
			}//while !</area>

			//add item to vector
			itemsVec.push_back(tempItemPtr);
		} //end makeItems()

        void insertItems()
        {
            for(int i = 0; i < itemsVec.size(); ++i)
            {
                areasVec[itemsVec[i]->getSR() - 1]->info.items.insertLast(itemsVec[i]);
			}
        }

		void resetItems()
		{
            for(int i = 0; i < areasVec.size(); ++i)
            {
                areasVec[i]->info.items.destroyList();
            }
            insertItems();
		}

		void print()
		{
		    nodeType<Item*>* tempItem;

		    Map::print();

		    cout<<"******************************************************************"<<endl;
            cout<<"CHEATING!!!! ITEM LOCATIONS FOR ALL NON-INVENTORY ITEMS."<<endl;
            cout<<"******************************************************************"<<endl;

            for(int i = 0; i < areasVec.size(); ++i)
            {
                tempItem = areasVec[i]->info.items.getFirst();

                cout <<"Items for area " << i + 1 << ": ";
                cout << areasVec[i]->info.getDescription() << endl;
                if(tempItem == nullptr)
                {
                    cout << "No items in list." << endl;
                }
                else
                {
                    for(int j = 0; j < areasVec[i]->info.items.length(); ++j)
                    {
                        cout << "\t" << tempItem->info->getName() << endl;
                        tempItem = tempItem->link;
                    }
                }
            }
		}

        friend ostream& operator<<(ostream& os, MapV2& gameMap);
};

ostream& operator<<(ostream& os, MapV2& gameMap)
{
    gameMap.print();

    return os;
}
