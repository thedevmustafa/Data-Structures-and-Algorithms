//Implementing linear search.

#include "iostream"
using namespace std;

int length; //Global variable for length because length is same for all functions here.

//Function for generating random array.
void getarray(int array[])
{
    srand(time(0));
    cout << "Array generated: [";
    for (int i = 0; i < length; i++)
    {
        array[i] = 1 + (rand() % 100);
        cout << array[i] << ",";
    }
    cout << "\b]" << endl;
}

//Linear search.
int linearSearch(int array[], int data)
{
    int pos = -1;
    for (int i = 0; i < length; i++)
    {
        if (data == array[i])
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{
    cout << "Enter length: ";
    cin >> length;
    int array[length];
    getarray(array);

    int data;
    cout << "Enter element: ";
    cin >> data;
    int pos = linearSearch(array, data);

    if (pos == -1)
        cout << "Unsuccessful linear search: -1" << endl;
    else
        cout << "Successful linear search: " << pos << endl;

    return 0;
}