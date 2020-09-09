/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int x, int &sum) {
        if(!root)   return;
        x *= 2; x += root->val;
        if(!root->left and !root->right) sum += x;
        traverse(root->left, x, sum);
        traverse(root->right, x, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        traverse(root, 0, sum);
        return sum;
    }
};
