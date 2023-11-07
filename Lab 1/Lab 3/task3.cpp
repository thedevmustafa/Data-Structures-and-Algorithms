// Program for inserting element at the ending of a doubly linked list;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

void doubly_linked_list::add_end(int data)
{
    if (start == NULL)
    {
        cout << "Overflow!";
        return;
    }
    struct node *ptr, *tmp;
    ptr = new node;
    ptr->info = data;
    ptr->next = NULL;
    tmp = start;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = ptr;
    ptr->prev = tmp;
}

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(1);
    list.add(4);
    list.add(5);
    list.display();
    list.add_end(2);
    cout << "Adding 2 at the ending:" << endl;
    list.display();
    return 0;
}