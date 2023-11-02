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
 

 //just need a function that can return size of left and right subTree
 //and sum of left and right subTree
//

class Solution {
    int count = 0;
    //pair{sum, size}
    pair<int, int> solve(auto root){
        if(!root) return {0, 0};

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int totalSum = left.first + right.first + root->val;
        int totalSize = left.second + right.second + 1;
        // printf("%d %d %d\n", root->val, totalSum, totalSize);
        if(totalSum / totalSize == root->val){
            count++;
        }

        return {totalSum, totalSize};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        auto p = solve(root);
        return count;
    }
};