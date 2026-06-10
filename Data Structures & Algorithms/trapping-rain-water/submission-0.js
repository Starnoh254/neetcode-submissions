class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {
        let volume = 0;
        let leftMaximum = [];
        let rightMaximum = [];
        let left = 0;
        let right = 0;

        // Calculate leftMaximum array
        for (let i = 0; i < height.length; i++) {
            left = Math.max(height[i], left);
            leftMaximum[i] = left; // Use assignment instead of push
        }

        // Calculate rightMaximum array
        for (let j = height.length - 1; j >= 0; j--) {
            right = Math.max(height[j], right);
            rightMaximum[j] = right; // Use assignment instead of push
        }

        // Calculate the trapped water
        for (let i = 0; i < height.length; i++) {
            let min = Math.min(leftMaximum[i], rightMaximum[i]);
            let amount = min - height[i];
            if (amount >= 0) {
                volume += amount;
            }
        }

        return volume;
    }
}
