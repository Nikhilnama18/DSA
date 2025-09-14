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

int main()
{
    return 0;
}
