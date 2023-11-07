// Program for removing element from the middle of a doubly linked list;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

void doubly_linked_list::remove_middle(int data)
{
    if (start == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    struct node *tmp, *ptr;
    tmp = start->next;
    while (tmp->info != data)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
        {
            cout << "Element not found!" << endl;
            return;
        }
    }
    ptr = tmp->prev;
    ptr->next = tmp->next;
    tmp->next->prev = ptr;
    delete (tmp);
}

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(1);
    list.add(5);
    list.add(9);
    list.add(3);
    list.display();
    cout << "Removing 9:" << endl;
    list.remove_middle(9);
    list.display();
    return 0;
}