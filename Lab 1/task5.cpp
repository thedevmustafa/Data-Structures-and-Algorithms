#include "iostream"
using namespace std;
int main()
{
    double sum = 0;
    double average = 0;
    double array[6] = {1, 3.5, 8, 10, 25, 4.5};

    // calculate sum

    for (int i = 0; i < 6; i++)
        sum += array[i];

    // calculate average

    average = sum / 6;

    cout << "Sum: " << sum << endl
         << "Average: " << average << endl;

    return 0;
}