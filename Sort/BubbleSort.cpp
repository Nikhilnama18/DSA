#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination: Iterate over array for N times & on each iteration sort one element of the array by comparing with the 
 * reamining elements of the array.
 *
 * Space Complexity: O(1) as we can sort in the given array
 * Time Complexity: O(N^2) as we need to interate over array for each element
 */

// void swap(vector<int> &arr, int i, int j)
// {
//     int k = arr[i];
//     arr[i] = arr[j];
//     arr[j] = k;
// }

void bubbleSort(vector<int> &arr)
{
    int n = arr.size(), count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "Count is " << count << endl;
    return;
}

int main()
{
    vector<int> arr{3, 4, 1};

    cout << "Array size: " << arr.size() << endl;
    cout << "Array elements before sort:" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << " " << arr[i];
        if (i != arr.size() - 1)
            cout << ",";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "Array elements after sort:" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << " " << arr[i];
        if (i != arr.size() - 1)
            cout << ",";
    }
    cout << endl;

    return 0;
}
