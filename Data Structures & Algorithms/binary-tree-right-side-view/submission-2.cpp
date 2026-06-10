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
    vector<int> res;
    // vector<int> rightSideView(TreeNode* root) {
    //     dfs(root,0);
    //     return res;
    // }

    // void dfs(TreeNode* node, int depth) {
    //     if(node == nullptr) return;

    //     if(res.size() == depth) {
    //         res.push_back(node -> val);
    //     }
        
    //     dfs(node -> right , depth + 1);
    //     dfs(node -> left , depth + 1);
    // }

    // bfs solution 
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return res;

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(i == levelSize - 1) {
                    res.push_back(node -> val);
                }

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }


        }
        return res;
    }
};
