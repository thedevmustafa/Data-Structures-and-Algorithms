// Implementing Merge sort

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

// Function for merging two sorted array
void merge_sort(int array[], int low, int mid, int high)
{
    int l1 = mid - low + 1; // Length for first sub array
    int l2 = high - mid;    // Length for second sub array

    int a[l1];
    int b[l2]; // Temporary arrays

    // Copying the orginal data to temporary arrays
    // First array
    for (int i = 0; i < l1; i++)
    {
        a[i] = array[low + i];
    }
    // Second array
    for (int i = 0; i < l2; i++)
    {
        b[i] = array[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    // Merging the two sorted arrays
    while (i < l1 && j < l2)
    {
        if (a[i] < b[j])
        {
            array[k++] = a[i++];
        }
        else
        {
            array[k++] = b[j++];
        }
    }

    // For remaiing elements in the sub arrays
    while (i < l1)
    {
        array[k++] = a[i++];
    }
    while (j < l2)
    {
        array[k++] = b[j++];
    }
}

// Merge sort
void merge(int array[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;            // Divide array into two parts
        merge(array, low, mid);            // Further divide the left part
        merge(array, mid + 1, high);       // Further divide the right part
        merge_sort(array, low, mid, high); // Then Merge....
    }
}

int main()
{
    int array[10] = {5, 78, 45, 15, 13, 1, 3, 2, 4, 83};
    // For calculating the length
    int length = sizeof(array) / sizeof(array[0]);

    cout << "Array before: ";
    display(array, length);

    merge(array, 0, length - 1); // Complexity O(nlogn)

    cout << "Array after: ";
    display(array, length);

    return 0;
}