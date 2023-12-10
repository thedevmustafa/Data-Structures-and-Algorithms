// Implementing Bubble sort

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

// Bubble sort
void bubble(int array[], int length)
{
    // Outer loop for total iterations ( 0 to n )
    for (int i = 0; i < length; i++)
        // Inner loop for total checks ( n(n-1)/2 )
        for (int j = 0; j < (length - i) - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

int main()
{
    int array[10] = {23, 69, 45, 14, 54, 15, 50, 9, 4, 13};
    // For calculating the length
    int length = sizeof(array) / sizeof(array[0]);

    cout << "Array before: ";
    display(array, length);

    bubble(array, length); // Complexity O(n^2)

    cout << "Array after: ";
    display(array, length);

    return 0;
}