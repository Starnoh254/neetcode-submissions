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
     * @param {TreeNode} subRoot
     * @return {boolean}
     */
    isSubtree(root, subRoot) {
        if(!root) {
            return false;
        }

        if(this.sameRoot(root,subRoot)) {
            return true;
        }

        return this.isSubtree(root.left , subRoot) || 
            this.isSubtree(root.right , subRoot);
    }
    sameRoot(root, subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        return (root.val === subRoot.val) && 
            this.sameRoot(root.left , subRoot.left) &&
            this.sameRoot(root.right , subRoot.right);

    }
}
