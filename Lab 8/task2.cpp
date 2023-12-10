// Implementing Quick sort

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

void quick(int array[], int low, int high)
{
    // If low is greater then high, return from function
    if (low >= high)
        return;
    int pivot = array[high]; // Let the last element is the pivot
    int i = low;             // i is the next pivot element start at low index
    for (int j = low; j <= high; j++)
    {
        // If the element is at correct position then i will increment
        if (array[j] < pivot)
        {
            swap(array[j], array[i]); // Replace the i at correct position i.e. ( n < i > n )
            i++;
        }
    }
    swap(array[i], array[high]); // Replace the i at correct position i.e. ( n < i > n )

    quick(array, low, i - 1);  // Further sort the left part
    quick(array, i + 1, high); // Further sort the right part
}

int main()
{
    int array[10] = {16, 4, 3, 45, 1, 72, 68, 89, 43, 10};
    // For calculating the length
    int length = sizeof(array) / sizeof(array[0]);

    cout << "Before sorting: ";
    display(array, length);

    quick(array, 0, length - 1); // Complexity: O(nlogn)

    cout << "After sorting:  ";
    display(array, length);

    return 0;
}
