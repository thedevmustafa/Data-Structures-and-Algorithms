// Program for removing element from the middle of a singly linked list;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

void singly_linked_list::remove_middle(int data)
{
    if (start == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    struct node *pre, *tmp;
    tmp = start->next;
    while (tmp->info != data)
    {
        pre = tmp;
        tmp = tmp->next;
        if (tmp->next == NULL)
        {
            cout << "Element not found!" << endl;
            return;
        }
    }
    pre->next = tmp->next;
    delete (tmp);
}

int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(4);
    list.add(8);
    list.add(3);
    list.add(2);
    list.display();
    cout << "Removing 3:" << endl;
    list.remove_middle(3);
    list.display();
    return 0;
}