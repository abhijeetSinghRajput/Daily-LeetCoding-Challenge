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
    int mx = 0;
    int vector<int> ans;

    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        int curr = root->val;
        if(currFreq > maxFreq){
            maxFreq = currFreq;
            ans.clear();
            ans.push_back(curr);
        }
        else if(currFreq == maxFreq){
            ans.push_back(curr);
        }
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
    }
};