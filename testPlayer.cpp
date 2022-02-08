#include <iostream>
using namespace std;



#ifndef ullItem
#define ullItem
	#include "ull.h"
	#include "Item.h"
#endif
#include "Area.h"
#include "areaNode.h"
#include "Player.h"


int main(){
	Player p1;
	areaNode aN1;
	areaNode* ptrAN;
	Area a1;
	Item* i1;
	
	aN1.info = a1;
	ptrAN = &aN1;
	
	i1 = new Item;
	i1->setName("Telephone");
	i1->setDesc("An old-style AT&T phone from the 1970s");
	i1->setSR(1);
	
	aN1.info.items.insertFirst(i1);
	p1.setCurrent(ptrAN);
	
	cout<<"**The following is the result of searching the current area.**"<<endl;
	aN1.info.search();
	cout<<"**The following is what happens when listing an empty inventory.**"<<endl;
	p1.inventory();
	cout<<"**The following is what happens when examine an empty inventory.**"<<endl;
	p1.examine();
	cout<<"**Next: Enter a name that doesn't exist.**"<<endl;
	p1.take();
	cout<<"**Next: Enter the correct name.**"<<endl;
	p1.take();
	
	cout<<"Just trying to reach the description in another way"<<endl;
	nodeType<Item*>* temp = NULL;
	temp = p1.items.getFirst();
	cout<<temp->info->getDesc()<<endl;
	cout<<"***"<<endl;
	
	cout<<"**The following is what happens when take from an empty area.**"<<endl;
	p1.take();
	cout<<"**The following is what happens when inventory has items.**"<<endl;
	p1.inventory();
	cout<<"**Next: Enter a name that doesn't exist.**"<<endl;
	p1.examine();
	cout<<"**Next: Enter the correct name.**"<<endl;
	p1.examine();
	cout<<"**Next: Enter a name that doesn't exist.**"<<endl;
	p1.leave();
	cout<<"**Next: Enter the correct name.**"<<endl;
	p1.leave();
	cout<<"**The following is what happens when inventory has no items. (enter any name)**"<<endl;
	p1.leave();		
}
