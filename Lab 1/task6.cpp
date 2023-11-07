#include "iostream"
using namespace std;
int main()
{
    int array[8] = {1, 22, 43, 14, 65, 16, 27, 48};

    for (int i = 0; i < 8; i++)
        cout << array[i] << ' ';
    cout << endl;

    int length = 8;
    int index;
    int element;
    cout << "Enter Index and Element: ";
    cin >> index >> element;

    int array2[length + 1]; // declaring 1 space extended array

    for (int i = 0; i < length; i++)
        array2[i] = array[i]; // copying orignal array elements into the new one

    for (int i = length; i >= index; i--)
        array2[i + 1] = array2[i]; // shifting elements for creating space for the element to insert

    array2[index] = element; // assigning element to the free space

    for (int i = 0; i <= length; i++)
        cout << array2[i] << ' '; // displaying the new array

    return 0;
}