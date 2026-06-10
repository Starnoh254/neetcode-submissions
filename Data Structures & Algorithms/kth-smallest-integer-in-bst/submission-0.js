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
     * @param {number} k
     * @return {number}
     */
    counter = 0;
    kthSmallest(root, k) {
        let stack = [];
        let currentNode = root;

        while (currentNode || stack.length > 0) {
            while(currentNode) {
                stack.push(currentNode);
                currentNode = currentNode.left;
            }

            let node = stack.pop()
            this.counter ++;

            if(this.counter === k) {
                return node.val;
            }

            currentNode = node.right;
            
        }
    }
}
