class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const result = {}
        for (let i = 0 ; i < nums.length ; i ++) {
            if(nums[i] in result) {
                return true
            }
            result[nums[i]] = 1
        }

        return false
    }
}

// time complexity O (n)