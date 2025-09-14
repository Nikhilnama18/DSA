#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination: Select an element & move all smaller to one side & bigger to other side, then place the element in the middle
 * do this for small & bigger one recurisevely
 * Space Complexity: O(N)
 * Time Complexity: O(N log(N))
 */

void printArr(vector<int> &arr)
{
    int n = arr.size();

    cout << "Array elements:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << endl;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < 0 || high >= arr.size() || low > high)
        return;

    int pivot = low, i = low + 1, j = high;

    while (i <j)
    {
        while (arr[pivot] > arr[i] && i <= j)
            i++;
        while (arr[pivot] <= arr[j] && i <= j)
            j--;

        if (i <j)
        swap(arr[i], arr[j]);
            // break;

    }
    swap(arr[j], arr[pivot]);
    printArr(arr);

    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
}

int main()
{
    vector<int> arr{
        100,
        3,
        4,
        612,
        4,
        4512,
        45,
        6,
        12,
        4,
        4,
        5,
        7,
        874,
        3,
        1,
        45,
    };
    int n = arr.size();

    printArr(arr);
    quickSort(arr, 0, n - 1);
    printArr(arr);

    return 0;
}
