/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        while(root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2) {
            s2.push(root2);
            root2 = root2->left;
        }
        while(!s1.empty() and !s2.empty()) {
            TreeNode *node1 = s1.top(), *node2 = s2.top();
            if(node1->val <= node2->val) {
                res.push_back(node1->val);
                s1.pop();
                node1 = node1->right;
                while(node1) {
                    s1.push(node1);
                    node1 = node1->left;
                }
            } else {
                res.push_back(node2->val);
                s2.pop();
                node2 = node2->right;
                while(node2) {
                    s2.push(node2);
                    node2 = node2->left;
                }
            }
        }
        while(!s1.empty()) {
            TreeNode *node1 = s1.top();
            res.push_back(node1->val);
            s1.pop();
            node1 = node1->right;
            while(node1) {
                s1.push(node1);
                node1 = node1->left;
            }
        }
        while(!s2.empty()) {
            TreeNode *node2 = s2.top();
            res.push_back(node2->val);
            s2.pop();
            node2 = node2->right;
            while(node2) {
                s2.push(node2);
                node2 = node2->left;
            }
        }
        return res;
    }
};
