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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> result;  // Final nested list of levels
        
    //     if (root == nullptr) {
    //         return result;  // Return empty if the tree is empty
    //     }
        
    //     queue<TreeNode*> q;  // Queue for level-order traversal
    //     q.push(root);
        
    //     while (!q.empty()) {
    //         vector<int> level;  // Vector to hold the current level's nodes
    //         int levelSize = q.size();  // Number of nodes at this level
            
    //         for (int i = 0; i < levelSize; i++) {
    //             TreeNode* node = q.front();  // Get the first node in the queue
    //             q.pop();  // Remove it from the queue
    //             level.push_back(node->val);  // Add its value to the current level
                
    //             if (node->left) q.push(node->left);   // Add left child if it exists
    //             if (node->right) q.push(node->right); // Add right child if it exists
    //         }
            
    //         result.push_back(level);  // Add the current level to the result
    //     }
        
    //     return result;
    // }

    // DFS solution 
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root , 0);
        return result;
    }

    void dfs (TreeNode* node , int depth) {
        if(node == nullptr) return ;
        if(result.size() <= depth) {
            result.push_back(vector<int>());
        }

        result[depth].push_back(node -> val);
        dfs(node -> left , depth + 1);
        dfs(node -> right , depth + 1);

    }
};
