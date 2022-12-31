//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>

using namespace std;

    //Definition of the Node
template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

template <class elemType>
class bSearchTreeType
{
public:
    const bSearchTreeType<elemType>& operator=
                 (const bSearchTreeType<elemType>&);
      //Overload the assignment operator.

    bool isEmpty() const;
      //Function to determine whether the binary tree is empty.
      //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.

    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: Nodes are printed in inorder sequence.

    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
      //Postcondition: Nodes are printed in preorder sequence.

    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
      //Postcondition: Nodes are printed in postorder sequence.

    int treeHeight() const;
      //Function to determine the height of a binary tree.
      //Postcondition: Returns the height of the binary tree.

    int treeNodeCount() const;
      //Function to determine the number of nodes in a
      //binary tree.
      //Postcondition: Returns the number of nodes in the
      //               binary tree.

    int treeLeavesCount() const;
      //Function to determine the number of leaves in a
      //binary tree.
      //Postcondition: Returns the number of leaves in the
      //               binary tree.

    void destroyTree();
      //Function to destroy the binary tree.
      //Postcondition: Memory space occupied by each node
      //               is deallocated.
      //               root = nullptr;
    bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the binary
      //search tree.
      //Postcondition: Returns true if searchItem is found in
      //               the binary search tree; otherwise,
      //               returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If there is no node in the binary search
      //               tree that has the same info as
      //               insertItem, a node with the info
      //               insertItem is created and inserted in the
      //               binary search tree.

    void deleteNode(const elemType& deleteItem);
      //Function to delete deleteItem from the binary search tree
      //Postcondition: If a node with the same info as deleteItem
      //               is found, it is deleted from the binary
      //               search tree.
      //               If the binary tree is empty or deleteItem
      //               is not in the binary tree, an appropriate
      //message is printed.

    bSearchTreeType(const bSearchTreeType<elemType>& otherTree);
      //Copy constructor

    bSearchTreeType();
      //Default constructor

    ~bSearchTreeType();
      //Destructor

private:
    nodeType<elemType>  *root;

    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which
      //otherTreeRoot points.
      //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.

    void destroy(nodeType<elemType>* &p);
      //Function to destroy the binary tree to which p points.
      //Postcondition: Memory space occupied by each node, in
      //               the binary tree to which p points, is
      //               deallocated.
      //               p = nullptr;

    void inorder(nodeType<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in inorder sequence.

    void preorder(nodeType<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in preorder
      //               sequence.

    void postorder(nodeType<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in postorder
      //               sequence.

    int height(nodeType<elemType> *p) const;
      //Function to determine the height of the binary tree
      //to which p points.
      //Postcondition: Height of the binary tree to which
      //               p points is returned.

    int max(int x, int y) const;
      //Function to determine the larger of x and y.
      //Postcondition: Returns the larger of x and y.

    int nodeCount(nodeType<elemType> *p) const;
      //Function to determine the number of nodes in
      //the binary tree to which p points.
      //Postcondition: The number of nodes in the binary
      //               tree to which p points is returned.

    int leavesCount(nodeType<elemType> *p) const;
      //Function to determine the number of leaves in
      //the binary tree to which p points
      //Postcondition: The number of leaves in the binary
      //               tree to which p points is returned.

    void deleteFromTree(nodeType<elemType>* &p);
      //Function to delete the node to which p points is
      //deleted from the binary search tree.
      //Postcondition: The node to which p points is deleted
      //               from the binary search tree.
};

//Definition of member functions

template <class elemType>
bSearchTreeType<elemType>::bSearchTreeType()
{
    root = nullptr;
}

template <class elemType>
bool bSearchTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void bSearchTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void bSearchTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void bSearchTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int bSearchTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int bSearchTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int bSearchTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void  bSearchTreeType<elemType>::copyTree
                       (nodeType<elemType>* &copiedTreeRoot,
                        nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void bSearchTreeType<elemType>::inorder
                              (nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void bSearchTreeType<elemType>::preorder
                              (nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void bSearchTreeType<elemType>::postorder
                              (nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

   //Overload the assignment operator
template <class elemType>
const bSearchTreeType<elemType>& bSearchTreeType<elemType>::
        operator=(const bSearchTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)   //if the binary tree is not empty,
                            //destroy the binary tree
            destroy(root);

        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this;
}

template <class elemType>
void  bSearchTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void  bSearchTreeType<elemType>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class elemType>
bSearchTreeType<elemType>::bSearchTreeType
                (const bSearchTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

    //Destructor
template <class elemType>
bSearchTreeType<elemType>::~bSearchTreeType()
{
    destroy(root);
}

template<class elemType>
int bSearchTreeType<elemType>::height
                             (nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int bSearchTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int bSearchTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
    cout << "Write the definition of the function nodeCount."
         << endl;

    return 0;
}

template <class elemType>
int bSearchTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
    cout << "Write the definition of the function leavesCount."
         << endl;

    return 0;
}

template <class elemType>
bool bSearchTreeType<elemType>::search
                    (const elemType& searchItem) const
{
    nodeType<elemType> *current;
    bool found = false;

    if (root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else
    {
       current = root;

       while (current != nullptr && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
    }//end else

    return found;
}//end search

template <class elemType>
void bSearchTreeType<elemType>::insert
                 (const elemType& insertItem)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent = nullptr; //pointer
                                              //behind current
    nodeType<elemType> *newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (root == nullptr)
        root = newNode;
    else
    {
        current = root;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                cout << "The item to be inserted is already ";
                cout << "in the tree -- duplicates are not "
                     << "allowed." << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteNode
                                (const elemType& deleteItem)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent; //pointer behind current
    bool found = false;

    if (root == nullptr)
        cout << "Cannot delete from an empty tree."
             << endl;
    else
    {
        current = root;
        trailCurrent = root;

        while (current != nullptr && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }//end while

        if (current == nullptr)
            cout << "The item to be deleted is not in the tree."
                 << endl;
        else if (found)
        {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree."
                 << endl;
    }
} //end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
                                 (nodeType<elemType>* &p)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent;  //pointer behind current
    nodeType<elemType> *temp;      //pointer to delete the node

    if (p == nullptr)
        cout << "Error: The node to be deleted does not exist."
             << endl;
    else if (p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = nullptr;

        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == nullptr) //current did not move;
                               //current == p->lLink; adjust p
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;

        delete current;
    }//end else
} //end deleteFromTree

#endif
