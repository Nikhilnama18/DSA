#include <iostream>
#include <vector>

using namespace std;

/**
 * Defination: If the given array is sorted then we can find the element by checking the mid value
 * of the array & decide whether it's towards the left or right & continue this process
 * Space Complexity: O(1)
 * Time Complexity: O(log N)
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

int binarySearch(vector<int> &arr, int key)
{
    int n = arr.size(), l = 0, h = n - 1;
    do
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    } while (l <= h);

    return -1;
}

int main()
{
    vector<int> arr{2, 4, 5, 6, 7, 32, 64, 111};
    int pos = binarySearch(arr, 111);

    if (pos != -1)
        cout << "Element fount at pos " << pos << endl;
    else
        cout << "Element doesn't exist" << endl;

    return 0;
}
