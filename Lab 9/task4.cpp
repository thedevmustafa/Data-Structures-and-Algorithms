// Implementing Selection sort

#include "iostream"
using namespace std;

// For displaying the array
void display(int array[], int length)
{
    cout << "[";
    for (int i = 0; i < length; i++)
        cout << array[i] << ",";
    cout << "\b]" << endl;
}

// Selection sort
void selection(int array[], int length)
{
    int min;
    // Outer loop for swaping smallest element to correct place
    for (int i = 0; i < length - 1; i++)
    {
        min = i;
        // Inner loop for searching the smallest element
        for (int j = i + 1; j < length; j++)
            if (array[min] > array[j])
                min = j;
        // Avoid swaping if the element is at correct place
        swap(array[min], array[i]);
    }
}

int main()
{
    int array[10] = {16, 4, 3, 45, 1, 72, 68, 89, 43, 10};
    // For calculating the length
    int length = sizeof(array) / sizeof(array[0]);

    cout << "Before sorting: ";
    display(array, length);

    selection(array, length); // Complexity: O(n^2)

    cout << "After sorting:  ";
    display(array, length);

    return 0;
}
