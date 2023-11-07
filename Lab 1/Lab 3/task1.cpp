// Program for traversing a doubly linked list, featuring addition of elements;
// Declarations are imported from doubly_linked_list file;

#include "doubly_linked_list.cpp"

int main()
{
    doubly_linked_list list = doubly_linked_list();
    list.add(5);
    list.add(8);
    list.add(3);
    list.add(2);

    int sum = 0;

    for (int i = 1; i <= 4; i++)
        sum += list.item(i);

    list.display();

    cout << "Sum is: " << sum;

    return 0;
}