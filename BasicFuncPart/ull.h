#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};


template <class Type>
class uLList
{
public:
    	const uLList<Type>& operator= (const uLList<Type>& otherList)
	{ 
		if (this != &otherList) //avoid self-copy
	    	{
	        	copyList(otherList);
	    	}//end else
	
	     	return *this; 
	}

    	void initializeList()
	{
		destroyList(); //if the list has any nodes, delete them
	}

    	bool isEmptyList() const
	{
    		return (first == NULL);
	}

    	void print() const
	{
	    	nodeType<Type> *current; //pointer to traverse the list
	    	current = first;    //set current so that it points to 
	        
	        //the first node
		if(first == NULL){
			cout<<"No items in list."<<endl;
		}
	    	while (current != NULL) //while more data to print
	    	{
	        	cout << current->info << " ";
	        	current = current->link;
	    	}
			
	}//end print
	
	void printNames() const
	{
	    	nodeType<Type> *current; //pointer to traverse the list
	    	current = first;    //set current so that it points to 
	        
	        //the first node
		if(first == NULL){
			cout<<"No items in list."<<endl;
		}
	    	while (current != NULL) //while more data to print
	    	{
	    		cout<<"\t";
	        	current->info->displayName();
	        	current = current->link;
	    	}
			
	}//end print


    	int length() const
	{
		return count;
	}  //end length

    	void destroyList()
	{
	   	nodeType<Type> *temp;   //pointer to deallocate the memory
	                            //occupied by the node
	    	while (first != NULL)   //while there are nodes in the list
	    	{
	        	temp = first;        //set temp to the current node
	        	first = first->link; //advance first to the next node
	        	delete temp;   //deallocate the memory occupied by temp
	    	}
		last = NULL; //initialize last to NULL; first has already
	                 //been set to NULL by the while loop
	    	count = 0;
	}

    	Type front() const
	{   
		assert(first != NULL);

		return first->info; //return the info of the first node	
	}//end front

    	Type back() const
	{   
		assert(last != NULL);

		return last->info; //return the info of the last node	
	}//end back

    	bool search(const Type& searchItem) 
	{
		nodeType<Type> *current; //pointer to traverse the list
    		bool found = false;
    
	    	current = first; //set current to point to the first 
  	                   //node in the list
	  	while (current != NULL && !found)    //search the list
  	      		if (current->info == searchItem) //searchItem is found
  	          		found = true;
  	      		else
  	          		current = current->link; //make current point to
  	                                   //the next node
  	  	return found; 
	}

    	void insertFirst(const Type& newItem)
	{
	    nodeType<Type> *newNode; //pointer to create the new node
	
	    newNode = new nodeType<Type>; //create the new node
	
	    newNode->info = newItem;    //store the new item in the node
	    newNode->link = first;      //insert newNode before first
	    first = newNode;            //make first point to the
	                                //actual first node
	    count++;                    //increment count
	
	    if (last == NULL)   //if the list was empty, newNode is also 
	                        //the last node in the list
	        last = newNode;
	}//end insertFirst

    	void insertLast(const Type& newItem)
	{
		nodeType<Type> *newNode; //pointer to create the new node

    		newNode = new nodeType<Type>; //create the new node

    		newNode->info = newItem;  //store the new item in the node
    		newNode->link = NULL;     //set the link field of newNode
      	                        //to NULL

    		if (first == NULL)  //if the list is empty, newNode is 
      	                  //both the first and last node
    		{
      	  		first = newNode;
      	  		last = newNode;
      	  		count++;        //increment count
    		}
    		else    //the list is not empty, insert newNode after last
    		{
      	  		last->link = newNode; //insert newNode after last
      	  		last = newNode; //make last point to the actual 
      	                  //last node in the list
      	  		count++;        //increment count
    		}
	}//end insertLast

    	void deleteNode(const Type& deleteItem)
	{
  	  	nodeType<Type> *current; //pointer to traverse the list
  	  	nodeType<Type> *trailCurrent; //pointer just before current
  	  	bool found;
	
  	  	if (first == NULL)    //Case 1; the list is empty. 
  	      		cout << "Cannot delete from an empty list."<< endl;
  	  	else
  	  	{
  	      		if (first->info == deleteItem) //Case 2 
  	      		{
  	          		current = first;
  	          		first = first->link;
  	          		count--;
  	          		if (first == NULL)    //the list has only one node
  	              			last = NULL;
  	          			delete current;
  	      		}
  	      		else //search the list for the node with the given info
  	      		{
  	          		found = false;
  	          		trailCurrent = first;  //set trailCurrent to point
  	                                 //to the first node
  	          		current = first->link; //set current to point to 
  	                                 //the second node
	
  	          		while (current != NULL && !found)
  	          		{
  	              			if (current->info != deleteItem) 
  	              			{
  	                  			trailCurrent = current;
  	                  			current = current-> link;
  	              			}
  	              			else
  	                  			found = true;
  	          		}//end while
	
  	          		if (found) //Case 3; if found, delete the node
  	          		{
  	              			trailCurrent->link = current->link;
  	              			count--;
	
  	              			if (last == current)   //node to be deleted 
  	                                     //was the last node
  	                  			last = trailCurrent; //update the value 
  	                                       //of last
  	              			delete current;  //delete the node from the list
  	          		}
  	          		else
  	              			cout << "The item to be deleted is not in the list." << endl;
  	      		}//end else
  	  	}//end else
	}//end deleteNode


    	uLList()
	{
		first = NULL;
	    	last = NULL;
	    	count = 0;
	} 

    	uLList(const uLList<Type>& otherList)
	{
	   	first = NULL;
	    	copyList(otherList);
	}//end copy constructor

    	~uLList()
	{
		destroyList();
	}//end destructor

	nodeType<Type>* getFirst(){
		return first;
	}

protected:
    int count; //variable to store the number of list elements
                 // 
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last;  //pointer to the last node of the list

private: 
    	void copyList(const uLList<Type>& otherList)
	{
	    nodeType<Type> *newNode; //pointer to create a node
	    nodeType<Type> *current; //pointer to traverse the list
	
	    if (first != NULL) //if the list is nonempty, make it empty
	       destroyList();
	
	    if (otherList.first == NULL) //otherList is empty
	    {
	        first = NULL;
	        last = NULL;
	        count = 0;
	    }
	    else
	    {
	        current = otherList.first; //current points to the 
	                                   //list to be copied
	        count = otherList.count;
	
	            //copy the first node
	        first = new nodeType<Type>;  //create the node
	
	        first->info = current->info; //copy the info
	        first->link = NULL;        //set the link field of 
	                                   //the node to NULL
	        last = first;              //make last point to the
	                                   //first node
	        current = current->link;     //make current point to
	                                     //the next node
	
	           //copy the remaining list
	        while (current != NULL)
	        {
	            newNode = new nodeType<Type>;  //create a node
	            newNode->info = current->info; //copy the info
	            newNode->link = NULL;       //set the link of 
	                                        //newNode to NULL
	            last->link = newNode;  //attach newNode after last
	            last = newNode;        //make last point to
	                                   //the actual last node
	            current = current->link;   //make current point 
	                                       //to the next node
	        }//end while
	    }//end else
	}//end copyList
}; 
