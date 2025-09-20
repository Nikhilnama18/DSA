#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination:
 * Space Complexity:
 * Time Complexity:
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

void LinearSearch(vector<int> &arr, int key)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not fount :(" << endl;
}

int main()
{
    vector<int> arr{12, 4, 3, 56, 13, 44, 5};
    LinearSearch(arr, 213);
    return 0;
}
