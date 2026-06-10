class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        if(nums.length === 0) return 0;
        const numSet = new Set(nums);
        let maxLength = 0;

        for(let num of numSet) {
            if(!numSet.has(num - 1)) {
                let currentStreak = 1;
                let currentNum = num;

                while(numSet.has(currentNum + 1)){
                    currentStreak ++;
                    currentNum ++;
                }

                maxLength = Math.max(maxLength , currentStreak)
            }
        }

        return maxLength;




    }

}
