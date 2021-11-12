#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionDiameterOfBinaryTree
{
private:
    int res;

public:
    int solveDiameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = solveDiameterOfBinaryTree(root->left);
        int r = solveDiameterOfBinaryTree(root->right);

        int temp = 1 + max(l, r);
        int ans = max(temp, l + r + 1);
        res = max(res, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        res = INT_MIN + 1;
        solveDiameterOfBinaryTree(root);
        return res - 1;
    }
};

class SolutionMaxPathSum
{
private:
    int res;

public:
    int solveMaxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = solveMaxPathSum(root->left);
        int r = solveMaxPathSum(root->right);

        int temp = max(root->val + max(l, r), root->val);
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);

        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        res = INT_MIN;
        solveMaxPathSum(root);
        return res;
    }
};

class SolutionMaxPathSumLeafToLeaf
{
private:
    int res;

public:
    int solveMaxPathSumLeafToLeaf(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = solveMaxPathSumLeafToLeaf(root->left);
        int r = solveMaxPathSumLeafToLeaf(root->right);

        int temp;
        if (root->left && root->right)
        {
            res = max(res, l + r + root->val);
            temp = root->val + max(l, r);
        }
        else if (root->left)
            temp = root->val + l;
        else if (root->right)
            temp = root->val + r;
        else
            temp = root->val;
        return temp;
    }
    int maxPathSumLeafToLeaf(TreeNode *root)
    {
        // code here
        res = INT_MIN;
        solveMaxPathSumLeafToLeaf(root);
        return res;
    }
};
