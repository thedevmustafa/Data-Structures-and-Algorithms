// Singly linked list;

#include "iostream"
using namespace std;

class singly_linked_list
{
    struct node
    {
        string info;
        struct node *next;
    };
    struct node *start;

public:
    singly_linked_list()
    {
        start = NULL;
    }

    // Core Operations
    void add(string);
    string last();
    string toString();
    void remove_end();
    bool isEmpty();
};

// Function for adding data to the list

void singly_linked_list::add(string data)
{
    struct node *ptr, *tmp;
    ptr = new node();
    ptr->info = data;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        tmp = start;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = ptr;
    }
}

// Function for accessing last element

string singly_linked_list::last()
{
    struct node *tmp;
    if (start == NULL)
    {
        return "";
    }
    else
    {
        tmp = start;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        return tmp->info;
    }
}

// Function for removing end

void singly_linked_list::remove_end()
{
    struct node *ptr, *tmp, *pre;
    if (start == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    if (start->next == NULL)
    {
        delete (start);
        start = NULL;
        return;
    }
    tmp = start;
    while (tmp->next != NULL)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    pre->next = NULL;
    delete (tmp);
}

// For checking if the list is empty

bool singly_linked_list::isEmpty()
{
    return start == NULL ? true : false;
}

// For converting list into string

string singly_linked_list::toString()
{
    struct node *tmp;
    string data;
    if (start == NULL)
    {
        return "";
    }
    else
    {
        tmp = start;
        while (tmp != NULL)
        {
            data += tmp->info + " ";
            tmp = tmp->next;
        }
        return data;
    }
}
