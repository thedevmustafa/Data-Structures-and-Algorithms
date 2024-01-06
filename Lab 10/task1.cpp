//Implementing Pre Order Tree traversing
#include "iostream"
using namespace std;

struct node
{
public:
    int info;
    struct node *left, *right;
    node(int data)
    {
        info = data;
        left = right = NULL;
    }
};

void preOrderTraverse(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->info << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preOrderTraverse(root);
}