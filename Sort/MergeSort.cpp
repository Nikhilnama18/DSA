#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination: Merge sort follow divide & conquer rule, where we recursively split array to halfs until we get to 1 element
 * and in the back tracking we re arrage elements in it's sorted position.
 *
 * Space Complexity: O(N) as we create temporary array of max size N
 * Time Complexity: O(N log N)
 */

void printArr(vector<int> &arr, string name = "")
{
    int n = arr.size();

    cout << "Array elements:";
    if (name != "")
        cout << " " << name;
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << endl;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = (mid - low) + 1, n2 = high - mid;

    vector<int> a1(n1), a2(n2);

    for (int i = 0; i < n1; i++)
        a1[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        a2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, pos = low;

    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            arr[pos++] = a1[i++];
        else
            arr[pos++] = a2[j++];
    }

    while (i < n1)
        arr[pos++] = a1[i++];

    while (j < n2)
        arr[pos++] = a2[j++];

    return;
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < 0 || high >= arr.size() || low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr{4, 5, 1, 4, 3, 2, 6, 2};
    printArr(arr);
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);
    return 0;
}
