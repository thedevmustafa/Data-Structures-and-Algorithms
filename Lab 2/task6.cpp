// Program for removing element from the ending of a singly linked list;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

void singly_linked_list::remove_end()
{
    struct node *ptr, *tmp, *pre;
    if (start == NULL)
    {
        cout << "Underflow!" << endl;
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

int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(6);
    list.add(4);
    list.add(0);
    list.display();
    cout << "Removing last element:" << endl;
    list.remove_end();
    list.display();
    return 0;
}