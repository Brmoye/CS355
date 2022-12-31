#include <iostream>
using namespace std;

#ifndef ullItem
#define ullItem
	#include "ull.h"
	#include "Item.h"
#endif
#include "Area.h"

int main(){
	Item* item1; 
	Area area1;
	
	item1 = new Item;
	item1->setName("item1 name");
	item1->setDesc("item1 desc");
	item1->setSR(1);
	
	area1.items.insertLast(item1);
	
	cout<<"Adding pointer to 1st dynamically allocated item.... ok"<<endl;
	
	item1 = new Item;
	item1->setName("item2 name");
	item1->setDesc("item2 desc");
	item1->setSR(2);
	
	area1.items.insertLast(item1);
	
	cout<<"Adding pointer to 2nd dynamically allocated item.... ok"<<endl;
	
	item1 = new Item;
	item1->setName("item3 name");
	item1->setDesc("item3 desc");
	item1->setSR(3);
	
	area1.items.insertLast(item1);
	
	cout<<"Adding pointer to 3rd dynamically allocated item.... ok"<<endl;
	
	cout<<endl;
	cout<<"We should now see the item names each on their own lines, tabbed over one space."<<endl;
	
	area1.search();
	
	area1.items.initializeList();
	
	cout<<"We should now see that there are no items in the area."<<endl;
	area1.search();
	
	cout<<"TEST FINISHED"<<endl;
	
	return 0;
}
