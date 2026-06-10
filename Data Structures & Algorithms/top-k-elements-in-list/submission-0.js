class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        // Step 1: Count frequency of each element
        const cache = {};
        for (let i = 0; i < nums.length; i++) {
            cache[nums[i]] = (cache[nums[i]] || 0) + 1;
        }

        // Step 2: Convert cache into an array of [element, frequency] pairs
        const freqArray = Object.entries(cache);

        // Step 3: Sort the array by frequency in descending order
        freqArray.sort((a, b) => b[1] - a[1]);

        // Step 4: Extract the top k frequent elements
        const result = [];
        for (let i = 0; i < k; i++) {
            result.push(freqArray[i][0]); // Push the element (not frequency) into the result
        }

        return result;
    }
}
