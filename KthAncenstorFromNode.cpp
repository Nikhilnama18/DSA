#include<iostream>
#include<vector>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}


int res = -1;
int KAncenstor(Node* root, int n, int&k)
{
    if(!root)
        return -1;
        
    if(root->data == n)
        return 0;
    int left = KAncenstor(root->left, int n, int k);
    int right = KAncenstor(root->right, int n, int k);

    if(left!=-1)
        left ++;
    if(right != -1)
        right ++;
    
    if(left ==k || right ==k)
        res = root->data;
    
    return max(left, right);

}