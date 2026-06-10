class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    // trap(height) {
    //     let volume = 0;
    //     let leftMaximum = [];
    //     let rightMaximum = [];
    //     let left = 0;
    //     let right = 0;

    //     // Calculate leftMaximum array
    //     for (let i = 0; i < height.length; i++) {
    //         left = Math.max(height[i], left);
    //         leftMaximum[i] = left; // Use assignment instead of push
    //     }

    //     // Calculate rightMaximum array
    //     for (let j = height.length - 1; j >= 0; j--) {
    //         right = Math.max(height[j], right);
    //         rightMaximum[j] = right; // Use assignment instead of push
    //     }

    //     // Calculate the trapped water
    //     for (let i = 0; i < height.length; i++) {
    //         let min = Math.min(leftMaximum[i], rightMaximum[i]);
    //         let amount = min - height[i];
    //         if (amount >= 0) {
    //             volume += amount;
    //         }
    //     }

    //     return volume;
    // }

trap(height) {
    if(!height || height.length === 0) return 0;
    let l = 0;
    let r = height.length - 1;
    let volume = 0;
    let lMax = height[l];
    let rMax = height[r];

    while (l < r) {
        if (lMax <= rMax) {
            l++; // Move the left pointer
            // Update lMax to reflect the maximum height seen so far
            lMax = Math.max(lMax, height[l]);
            volume  += lMax - height[l];
            
        } else {
            r--; // Move the right pointer
            // Update rMax to reflect the maximum height seen so far
            rMax = Math.max(rMax, height[r]);
            volume += rMax - height[r];
            
        }
    }

    return volume;
}


}
