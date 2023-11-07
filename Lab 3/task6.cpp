// Program for removing element from the ending of a doubly linked list;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

void doubly_linked_list::remove_end()
{
    if (start == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    struct node *tmp = start;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    delete (tmp);
}

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(1);
    list.add(2);
    list.add(10);
    list.display();
    cout << "Removing last element:" << endl;
    list.remove_end();
    list.display();
    return 0;
}