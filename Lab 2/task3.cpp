// Program for inserting element at the ending of a singly linked list;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

void singly_linked_list::add_end(int data)
{
    if (start == NULL)
    {
        cout << "Overflow!" << endl;
        return;
    }
    struct node *tmp, *ptr;
    ptr = new node();
    ptr->info = data;
    ptr->next = NULL;
    tmp = start;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = ptr;
}

int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(6);
    list.add(4);
    list.add(8);
    list.display();
    list.add_end(9);
    cout << "Adding 9 at the ending:" << endl;
    list.display();
    return 0;
}