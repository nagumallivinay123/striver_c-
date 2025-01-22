#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count valid merges
int mergeAndCount(vector<int> &arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);
    int count = 0;

    // Merge process with counting logic
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            // Increment count for each element in the left array that gets merged
            count += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of the left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of the right half
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy sorted temp array to the original array
    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }

    return count;
}

// Recursive merge sort function to count
int mergeSortAndCount(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    int count = 0;

    // Count for left and right halves
    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);

    // Count during the merge step
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

// Function to calculate the largest count value
int largestCountValue(vector<int> a)
{
    return mergeSortAndCount(a, 0, a.size() - 1);
}

int main()
{
    vector<int> arr1 = {2, 1 ,3};
    cout << "Result for {2, 3, 1}: " << largestCountValue(arr1) << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 10};
    cout << "Result for {1, 2, 3, 4, 5, 10}: " << largestCountValue(arr2) << endl;

    return 0;
}
