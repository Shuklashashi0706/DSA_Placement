#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;
    int height;
    Node(int value)
    {
        this->data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

// right Notation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;
    // update height
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    child->height = 1 + max(getHeight(child->left) , getHeight(child->right));

    return child;
}
// left Notation
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    // update height
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    child->height = 1 + max(getHeight(child->left) , getHeight(child->right));

    return child;
}

Node *insert(Node *root, int key)
{
    // doesnt exist
    if (!root)
        return new Node(key);

    // exists
    if (key < root->data)
    {
        root->left = insert(root->left, key); // left side
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key); // right side
    }
    else
    {
        return root; // duplicate elements are not allowed
    }
    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // balance check
    int balance = getBalance(root);

    // left left case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    // left right case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right right case
    else if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }
    // right left case
    else if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // no unbalancing case
    else
    {
        return root;
    }
}

void preorder(Node *root){
    if(!root) return;
    preorder(root->left);
    cout<<root->data<<"\t";
    preorder(root->right);
}

int main()
{
    // duplicate elements are not allowed
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 90);
    root = insert(root, 150);
    preorder(root);
    return 0;
}