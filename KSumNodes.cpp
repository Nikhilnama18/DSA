#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> res;

void getAllKSumNodes(Node *root, vector<int> &curSumVector, int k)
{
    if (!root)
        return;

    curSumVector.push_back(root->data);

    getAllKSumNodes(root->left, curSumVector, k);
    getAllKSumNodes(root->right, curSumVector, k);

    int sum = 0;
    vector<int> cur;
    for (int i = curSumVector.size() - 1; i >= 0; i--)
    {
        cur.push_back(curSumVector[i]);
        sum += curSumVector[i];
        if (sum == k)
        {
            // push from last to cur to r
            res.push_back(cur);
        }
    }

    curSumVector.pop_back();

    return;
}

vector<vector<int>> allKSumNodes(Node *root, int k)
{
    vector<int> curSumVector;
    int curSum = 0;
    getAllKSumNodes(root, curSumVector, k);

    return res;
}

int main()
{
    return 0;
}