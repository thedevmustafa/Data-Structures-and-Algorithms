// Doubly linked list;
// Declarations are made for other tasks;

#include "iostream"
using namespace std;

class doubly_linked_list
{
    struct node
    {
        int info;
        struct node *prev;
        struct node *next;
    };
    struct node *start;

public:
    doubly_linked_list()
    {
        start = NULL;
    }

    // Core Operations
    void add(int);
    int item(int);
    void display();

    // For other tasks
    void add_begin(int);
    void add_end(int);
    void add_middle(int, int);
    void remove_begin();
    void remove_end();
    void remove_middle(int);
};

// Function for adding data to the list

void doubly_linked_list::add(int data)
{
    struct node *ptr, *tmp;
    ptr = new node();
    ptr->info = data;
    ptr->next = NULL;
    if (start == NULL)
    {
        ptr->prev = NULL;
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
        ptr->prev = tmp;
    }
}

// Function for accessing each element

int doubly_linked_list::item(int pos)
{
    struct node *tmp;
    if (start == NULL)
    {
        return -1;
    }
    else
    {
        tmp = start;
        for (int i = 1; i < pos; i++)
        {
            if (tmp->next == NULL)
            {
                return -1;
            }
            tmp = tmp->next;
        }
        return tmp->info;
    }
}

// Function for displaying the list

void doubly_linked_list::display()
{
    struct node *tmp;
    if (start == NULL)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    cout << "List: [";
    tmp = start;
    while (tmp != NULL)
    {
        cout << tmp->info << ",";
        tmp = tmp->next;
    }
    cout << "\b]" << endl;
}