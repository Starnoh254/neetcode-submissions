class Solution {
    /**
     * @param {number[]} piles
     * @param {number} h
     * @return {number}
     */
    // minEatingSpeed(piles, h) {
    //     // sort the piles first 
        
    //     let left = 1;
    //     let right = Math.max(...piles);
    //     // let minimumK = Number.POSITIVE_INFINITY

    //     while (left <= right) {
    //         let mid = Math.floor(left + (right - left ) / 2);
    //         let total_hours = 0;
    //         for(let i = 0 ; i < piles.length ; i ++) {
    //             total_hours += Math.ceil(piles[i]/mid)
    //         }
    //         if(total_hours <= h) {
    //             right = mid - 1 ;
    //             // minimumK = Math.min(minimumK , mid)
    //         }
    //         else {
    //             left = mid + 1;
    //         }
            
    //     }

    //     return left

    // }

    // brute force solution 
    minEatingSpeed(piles , h) {
        let eatingSpeed = 1;
        while (true) {
            let totalHours = 0;
            for(let pile of piles) {
                totalHours += Math.ceil(pile / eatingSpeed)
            }

            if(totalHours <= h) {
                return eatingSpeed
            }

            eatingSpeed ++;
        }
    }
}
