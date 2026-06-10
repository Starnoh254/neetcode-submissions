class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let cache = {}
        for(let i = 0 ; i < nums.length ; i++) {
            let compliment = target - nums[i]
            if(cache[compliment] !== undefined){
                return [cache[compliment], i]
            }
            cache[nums[i]] = i;
        }
    }
}
