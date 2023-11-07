// Program for inserting element at the beginning of a singly linked list;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

void singly_linked_list::add_begin(int data)
{
    if(start == NULL){
        cout<<"Overflow!"<<endl;
        return;
    }
    struct node *ptr;
    ptr = new node();
    ptr->info = data;
    ptr->next = start;
    start = ptr;
}

int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(1);
    list.add(4);
    list.add(0);
    list.display();
    list.add_begin(8);
    cout << "Adding 8 at the beginning:" << endl;
    list.display();
    return 0;
}