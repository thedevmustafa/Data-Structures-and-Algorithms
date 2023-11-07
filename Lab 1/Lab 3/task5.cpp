// Program for removing element from the beginning of a doubly linked list;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

void doubly_linked_list::remove_begin()
{
    if (start == NULL)
    {
        cout << "Underflow!";
        return;
    }
    struct node *tmp;
    tmp = start;
    start = tmp->next;
    start->prev = NULL;
    delete (tmp);
}

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(1);
    list.add(3);
    list.add(5);
    list.display();
    cout << "Removing first element:" << endl;
    list.remove_begin();
    list.display();
    return 0;
}