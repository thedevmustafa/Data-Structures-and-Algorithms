// Program for inserting element in the middle of a singly linked list;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

void singly_linked_list::add_middle(int pos, int data)
{
    if (start == NULL)
    {
        cout << "Overflow!" << endl;
        return;
    }
    struct node *ptr, *tmp;
    ptr = new node;
    ptr->info = data;
    tmp = start;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
        {
            cout << "Position don't exist!" << endl;
            return;
        }
    }
    ptr->next = tmp->next;
    tmp->next = ptr;
}

int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(5);
    list.add(9);
    list.add(7);
    list.display();
    list.add_middle(2, 6);
    cout << "Adding 6 after positon 2:" << endl;
    list.display();
    return 0;
}