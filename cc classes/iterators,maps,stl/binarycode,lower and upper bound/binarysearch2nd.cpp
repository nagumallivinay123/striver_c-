#include <iostream>
using namespace std;
int binarysearch(int arr[], int lower, int upper, int key)
{
    while (lower <= upper)
    {
    int mid = (lower + upper) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            upper = mid - 1;
        }
        else
        {
            lower = mid + 1;
        }
    }
    return -1;
}
int main()
{

    int arr[] = {1, 2, 4, 5, 7, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarysearch(arr, 0, n - 1, 6);

    return 0;
}