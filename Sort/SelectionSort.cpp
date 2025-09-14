#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination: Iterate over the arry & on each iteration find the smallest element of array & put it in it's position.
 *
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

void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[small] > arr[j])
                small = j;
        }
        swap(arr[i], arr[small]);
    }
}

int main()
{
    vector<int> arr{4, 3, 6, 1, 2, 5};

    printArr(arr);
    selectionSort(arr);
    printArr(arr);

    return 0;
}
