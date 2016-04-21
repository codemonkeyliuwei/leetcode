#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root)
        {
            TreeNode* tmp = root->left;
            root->left    = root->right;
            root->right   = tmp;
            
            invertTree(root->left);
            invertTree(root->right);
        }

        return root;
    }
};

void PrintTree(TreeNode* root)
{
    if (NULL == root) {
        return;
    }

    PrintTree(root->left);
    cout << root->val << endl;
    PrintTree(root->right);
}

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n9(9);
    n2.left = &n1;
    n2.right = &n3;
    n7.left = &n6;
    n7.right = &n9;
    n4.left = &n2;
    n4.right = &n7;

    PrintTree(&n4);

    Solution s;
    s.invertTree(&n4);

    PrintTree(&n4);
    
    return 0;
}