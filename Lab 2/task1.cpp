// Program for traversing a singly linked list, featuring addition of elements;
// Declarations are imported from singly_linked_list file;

#include "singly_linked_list.cpp"

int main()
{
    singly_linked_list list = singly_linked_list();
    list.add(3);
    list.add(5);
    list.add(8);
    list.add(11);

    int sum = 0;

    for (int i = 1; i <= 4; i++)
        sum += list.item(i);

    list.display();

    cout << "Sum is: " << sum;

    return 0;
}