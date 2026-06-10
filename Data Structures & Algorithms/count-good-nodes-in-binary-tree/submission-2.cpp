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
    int goodOnes = 0;
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);

    }

    int dfs (TreeNode* root , int maxValue) {
        
        if(root == nullptr) return 0;
        if(maxValue <= root -> val) {
            goodOnes ++;
            maxValue = root -> val;
        }

        dfs(root -> left , maxValue);
        dfs(root -> right , maxValue);

        return goodOnes;
    }
};
