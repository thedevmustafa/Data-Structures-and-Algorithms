// Program for inserting element at the beginning of a doubly linked list;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

void ::doubly_linked_list::add_begin(int data)
{
    if (start == NULL)
    {
        cout << "Overflow!" << endl;
        return;
    }
    struct node *ptr;
    ptr = new node;
    ptr->info = data;
    ptr->prev = NULL;
    ptr->next = start;
    start->prev = ptr;
    start = ptr;
}

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(1);
    list.add(2);
    list.add(3);
    list.display();
    list.add_begin(4);
    cout << "Adding 4 at the beginning:" << endl;
    list.display();
    return 0;
}