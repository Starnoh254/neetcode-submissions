class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    // maxArea(heights) {
    //     // brute force 

    //     let maxVolume = 0;
    //     for(let i = 0 ; i < heights.length ; i ++) {
    //         for(let j = i + 1; i < heights.length; j++){
    //             let volume = Math.min(heights[i],heights[j]) * (j - i)
    //             maxVolume = Math.max(maxVolume , volume)
    //         }
    //     }

    //     return maxVolume;
    // }

    maxArea(heights) {
        let left = 0;
        let right = heights.length - 1;
        let maxVolume = 0;

        while (left < right) {
            let height = Math.min(heights[left],heights[right])
            let volume = height * (right - left);
            maxVolume = Math.max(maxVolume , volume);

            if(heights[left] < heights[right]) {
                left ++
            }
            else {
                right --
            }
        }

        return maxVolume;
    }
}
