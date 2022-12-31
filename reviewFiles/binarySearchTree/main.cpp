#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int> bst;

    int temp;

    for(int i=0; i<5; i++){
        cin>>temp;
        bst.insert(temp);
    }

    cout<<"In-Order Traversal"<<endl;
    bst.inorderTraversal();
    cout<<endl<<"Pre-Order Traversal"<<endl;
    bst.preorderTraversal();
    cout<<endl<<"Post-Order Traveral"<<endl;
    bst.postorderTraversal();

    return 0;
}
