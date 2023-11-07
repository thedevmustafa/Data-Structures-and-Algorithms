// Program for inserting element at the middle of a doubly linked list;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

void doubly_linked_list::add_middle(int pos, int data)
{
    if (start == NULL)
    {
        cout << "Overflow!";
        return;
    }
    else
    {
        struct node *ptr, *tmp;
        ptr = new node;
        ptr->info = data;
        tmp = start;
        for (int i = 1; i < pos; i++)
        {
            tmp = tmp->next;
            if (tmp->next == NULL)
            {
                cout << "Positon don't exist!" << endl;
                return;
            }
        }

        ptr->next = tmp->next;
        tmp->next = ptr;
        ptr->prev = tmp;
        ptr->next->prev = ptr;
    }
}

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(1);
    list.add(2);
    list.add(5);
    list.display();
    list.add_middle(2, 10);
    cout << "Adding 10 after positon 2:" << endl;
    list.display();
    return 0;
}