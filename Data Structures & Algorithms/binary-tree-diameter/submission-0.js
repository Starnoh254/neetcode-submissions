/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    /**
     * @param {TreeNode} root
     * @return {number}
     */
    diameter = 0;
    diameterOfBinaryTree(root) {
        this.height(root);
        return this.diameter
    }
    height(root) {
        if (!root){
            return 0
        }
        // Get the height of left and right subtrees
        const leftHeight = this.height(root.left);
        const rightHeight = this.height(root.right);

        // Update diameter (longest path through this node)
        this.diameter = Math.max(this.diameter, leftHeight + rightHeight);

        // Return the height of the current subtree
        return 1 + Math.max(leftHeight, rightHeight);

    }
}
