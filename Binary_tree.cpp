#include<iostream>
#include<queue>
using namespace std;


struct node {
    int data;
    struct node *left;
    struct node *right;
};
class BinTree
{
   private:
       node *right;
       node *left;
   public:
       BinTree ();
       node *root;
       void addnode (int data);
       void BreadthTraverse ();
};
BinTree::BinTree() {
    root = NULL;
    right = NULL;
    left =NULL;
}

void BinTree::addnode(int data) {
    node *newNode;
    node *nodePtr = NULL;

    newNode = new node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (!root) {
        root = newNode;
        cout <<" Root" << newNode->data <<endl;
    } else {
        nodePtr = root;
    }

    while (nodePtr != NULL)
    {
        if (data < nodePtr->data){
            if (nodePtr->left) {
                nodePtr = nodePtr->left;
            }
            else
            {
                nodePtr->left = newNode;
                break;
            }
        } else if (data > nodePtr->data)
        {
            if (nodePtr->right) {
                nodePtr = nodePtr->right;
            }
            else
            {
                nodePtr->right = newNode;
                break;
            }
        }
        else
        {
            cout << "Duplicate value found in tree.\n";
            break;
        }
    }
}

void BinTree::BreadthTraverse() {
    if (root == NULL) return;
    queue<node*> Queue;
    Queue.push(root);
    while(!Queue.empty()) {
        node *current = Queue.front();
        cout <<"-->"<<current->data;
        if (current->left !=NULL) Queue.push(current->left);
        if (current->right !=NULL) Queue.push(current->right);
        Queue.pop();

    }
}

int main ()
{
    BinTree Tree;
    cout << "Adding nodes to Binary Tree \n";
    cout<< "Adding 10"<<endl;
    Tree.addnode(10);
    cout<< "Adding 8"<<endl;
    Tree.addnode(8);
    cout<< "Adding 3"<<endl;
    Tree.addnode(3);
    cout<< "Adding 2"<<endl;
    Tree.addnode(2);
    cout<< "Adding 5"<<endl;
    Tree.addnode(5);
    cout<< "Adding 1"<<endl;
    Tree.addnode(1);
    cout<< "Adding 9"<<endl;
    Tree.addnode(9);
    cout<< "Adding 22"<<endl;
    Tree.addnode(22);
    cout<< "Adding 15"<<endl;
    Tree.addnode(15);
    cout<< "Adding 23"<<endl;
    Tree.addnode(23);
    cout << "\nPrinting Breadth Traversal:\n";
    Tree.BreadthTraverse();
    return 0;
}
