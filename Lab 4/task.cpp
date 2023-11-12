// Stack using Linked List

#include "iostream"
using namespace std;

class stack
{
    struct node
    {
        int info;
        struct node *next;
    };
    struct node *Top;

public:
    stack()
    {
        Top = NULL;
    }
    void push(int);
    void pop();
    int top();
    void show();
    bool isEmpty();
    int size();
};

// Implementing push operation

void stack::push(int data)
{
    struct node *newNode;
    newNode = new node();
    newNode->info = data;
    newNode->next = Top;
    Top = newNode;
}

// Implementing pop operation

void stack::pop()
{
    struct node *tmp;

    if (Top == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    tmp = Top;
    Top = Top->next;
    delete (tmp);
}

// Implementing top operation

int stack::top()
{
    if (Top == NULL)
        return 0;
    else
        return Top->info;
}

// Implementing sho operation

void stack::show()
{
    struct node *tmp;
    if (Top == NULL)
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    tmp = Top;
    cout << "Stack: Top-> [";
    while (tmp != NULL)
    {
        cout << tmp->info << ",";
        tmp = tmp->next;
    }
    cout << "\b] <-Bottom" << endl;
}

// Impleting size operation

bool stack::isEmpty()
{
    return Top != NULL ? false : true;
}

// Impleting size opeation

int stack::size()
{
    struct node *tmp;
    if (Top == NULL)
        return 0;
    else
    {
        int i = 0;
        tmp = Top;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            i++;
        }
        return i;
    }
}

// Main function

int main()
{
    stack myStack = stack();
    cout << "\nPushing 4 1 and 9 in stack: " << endl;
    myStack.push(4);
    myStack.push(1);
    myStack.push(9);
    myStack.show();

    myStack.pop();
    cout << "\nPoping top element: " << endl;
    myStack.show();

    cout<<"\nSize of stack is: "<<myStack.size()<<endl;

    cout<<"\nIs empty: "<<myStack.isEmpty()<<endl;

    cout<<"\nTop element: "<<myStack.top()<<endl;
    
    return 0;
}