//Implementing binary search.

#include "iostream"
using namespace std;

int length; //Global variable for length because length is same for all functions here.

//Function for generating random sorted array.
void getsortedarray(int array[])
{
    srand(time(0));

    for (int i = 0; i < length; i++)
        array[i] = 1 + (rand() % 100);

    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }

    cout << "Array generated: [";
    for (int i = 0; i < length; i++)
        cout << array[i] << ",";
    cout << "\b]" << endl;
}

//Binary search.
int binarySearch(int array[], int data)
{
    int pos = -1;
    int lb = 0, ub = length, mid = (ub + lb) / 2;
    while (lb <= ub)
    {
        if (data == array[mid])
        {
            pos = mid;
            break;
        }
        else if (data < array[mid])
        {
            ub = mid - 1;
            mid = (lb + ub) / 2;
        }
        else
        {
            lb = mid + 1;
            mid = (lb + ub) / 2;
        }
    }

    return pos;
}

int main()
{
    cout << "Enter length: ";
    cin >> length;
    int array[length];
    getsortedarray(array);

    int data;
    cout << "Enter element: ";
    cin >> data;
    int pos = binarySearch(array, data);

    if (pos == -1)
        cout << "Unsuccessful binary search: -1" << endl;
    else
        cout << "Successful binary search: " << pos << endl;

    return 0;
}