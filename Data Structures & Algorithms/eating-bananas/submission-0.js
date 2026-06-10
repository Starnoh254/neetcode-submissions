class Solution {
    /**
     * @param {number[]} piles
     * @param {number} h
     * @return {number}
     */
    minEatingSpeed(piles, h) {
        // sort the piles first 
        
        let left = 1;
        let right = Math.max(...piles);
        // let minimumK = Number.POSITIVE_INFINITY

        while (left <= right) {
            let mid = Math.floor(left + (right - left ) / 2);
            let total_hours = 0;
            for(let i = 0 ; i < piles.length ; i ++) {
                total_hours += Math.ceil(piles[i]/mid)
            }
            if(total_hours <= h) {
                right = mid - 1 ;
                // minimumK = Math.min(minimumK , mid)
            }
            else {
                left = mid + 1;
            }
            
        }

        return left

    }
}
