// Program for removing element from the beginning of a singly linked list;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

void singly_linked_list::remove_begin()
{
    struct node *ptr;
    if (start == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
        ptr = start;
        start = start->next;
        delete (ptr);
}
int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(5);
    list.add(8);
    list.add(7);
    list.display();
    cout << "Removing first element:" << endl;
    list.remove_begin();
    list.display();
    return 0;
}