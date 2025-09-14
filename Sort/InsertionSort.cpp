#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination: Iterate over the array N times & on each iteration compare the cur element with all it's previous elements,
 * move previous elements by 1 position if they are larger than cur element.
 * Space Complexity: O(1)
 * Time Complexity: O(N^2)
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

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> arr = {4, 1, 5, 3, 2};
    printArr(arr);
    insertionSort(arr);
    printArr(arr);
    return 0;
}
