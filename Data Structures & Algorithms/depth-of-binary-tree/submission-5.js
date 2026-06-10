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
    // maxDepth(root) {
    //     if(!root) {
    //         return 0;
    //     }

    //     return 1 + Math.max(this.maxDepth(root.left) , this.maxDepth(root.right));
    // }

    maxDepth(root) {
        let res = 0;

        let stack = [[root , 1]];
        while (stack.length > 0) {
            let [node , depth] = stack.pop();
            if (node) {
                res = Math.max(res,depth);
                stack.push([node.left , depth + 1 ]);
                stack.push([node.right, depth + 1 ]);
            }
        }


        return res;
    }
}
