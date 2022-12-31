#include <iostream>
using namespace std;

#include "Item.h"

int main(){
	Item item1;

	item1.setName("Item Name");
	item1.setDesc("Item Description Text");
	item1.setSR(34);

	cout<<"Setters: .... ok"<<endl;

	if(item1.getName() == "Item Name"){
		if(item1.getDesc() == "Item Description Text"){
			if(item1.getSR() == 34){
				cout<<"Getters: ... ok"<<endl;
			}
			else{
				cout<<"getSR() ... FAIL"<<endl;
			}
		}
		else{
			cout<<"getDesc() ... FAIL"<<endl;
		}
	}
	else{
		cout<<"getName() ... FAIL"<<endl;
	}

	cout<<"The text \"Item Name\" should be printed out next: .... ";
	item1.displayName();
    cout << endl;

	cout<<"The text \"Item Description Text\" should be printed out next: .... ";
	item1.displayDesc();
    cout << endl;

	cout<<"Testing operator << overloading .... " << endl;
	cout << item1;

    cout << "StrtRm: " << item1.getSR() << endl;

	cout<<"TEST FINISHED"<<endl;

	return 0;
}
