#include "iostream"
using namespace std;

int main()
{
    int int_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float float_array[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    string string_array[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    double double_array[10] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.10};
    cout << "int:" << int_array[0] << endl
         << "float:" << float_array[1] << endl
         << "string:" << string_array[2] << endl
         << "double:" << double_array[3] << endl;
    return 0;
}