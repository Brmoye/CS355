#include <iostream>
#include <string>

using namespace std;

class Item
{
    private:
        string itemName, itemDesc;
        int startingRoom;

    public:
        void setName(string str)
        {
            itemName = str;
        }
        void setDesc(string str)
        {
            itemDesc = str;
        }
        void setSR(int room)
        {
            startingRoom = room;
        }
        string getName()
        {
            return itemName;
        }
        string getDesc()
        {
            return itemDesc;
        }
        int getSR()
        {
            return startingRoom;
        }
        void displayName()
        {
            cout << itemName;
        }
        void displayDesc()
        {
            cout << itemDesc;
        }

        friend ostream& operator<<(ostream& os, Item& thisItem);
};

ostream& operator<<(ostream& os, Item& thisItem)
{
    cout << "Name: " << thisItem.getName() << endl;
    cout << "Desc: " << thisItem.getDesc() << endl;

    return os;
}
