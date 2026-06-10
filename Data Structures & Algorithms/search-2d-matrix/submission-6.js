class Solution {
    /**
     * @param {number[][]} matrix
     * @param {number} target
     * @return {boolean}
     */
    // searchMatrix(matrix, target) {
    //     let m = matrix.length; // number of rows
    //     let n = matrix[0].length; // number of columns

    //     let left = 0;
    //     let right = (m * n) - 1;

    //     while (left <= right ) {
    //         let mid = left + Math.floor((right - left) / 2);
    //         let row = Math.floor(mid / n);
    //         let col = mid % n;

    //         let midValue = matrix[row][col]

    //         if(midValue === target) {
    //             return true;
    //         }
    //         else if (midValue < target){
    //             left = mid + 1
    //         }
    //         else {
    //             right = mid - 1;
    //         }
    //     }

    //     return false;

    // }

    searchMatrix(matrix , target) {
        let left = 0 
        let right = matrix.length - 1;

        while(left <= right ) {
            let mid = left + Math.floor((right - left) / 2);
            let lastIndex = matrix[mid].length - 1;
            let lastValue = matrix[mid][lastIndex];

            if(target > lastValue ) {
                left = mid + 1;
            }

            else if (target <= lastValue && target >= matrix[mid][0]) {
                if (target === matrix[mid][0] || target === lastValue) {
                    return true;
                }
                return this.binary_search(matrix[mid], target);
            }


            else {
                right = mid - 1;
            }
        }

        return false
        
        
    }

    binary_search(array , target) {
        let left = 0;
        let right = array.length - 1;

        while (left <= right) {
            let mid = left + Math.floor((right - left) / 2);

            if(array[mid] === target) {
                return true;
            }
            else if(array[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }


}
