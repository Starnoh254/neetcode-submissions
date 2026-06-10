class Solution {
    /**
     * @param {number[]} nums1
     * @param {number[]} nums2
     * @return {number}
     */
    findMedianSortedArrays(nums1, nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.length > nums2.length) {
            return this.findMedianSortedArrays(nums2, nums1);
        }

        const m = nums1.length;
        const n = nums2.length;
        let low = 0;
        let high = m;

        while (low <= high) {
            // Partition indices
            const partitionX = Math.floor((low + high) / 2);
            const partitionY = Math.floor((m + n + 1) / 2) - partitionX;

            // Left and right elements of partitions
            const maxLeftX = partitionX === 0 ? -Infinity : nums1[partitionX - 1];
            const minRightX = partitionX === m ? Infinity : nums1[partitionX];

            const maxLeftY = partitionY === 0 ? -Infinity : nums2[partitionY - 1];
            const minRightY = partitionY === n ? Infinity : nums2[partitionY];

            // Check if the partitions are correct
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total number of elements is even
                if ((m + n) % 2 === 0) {
                    return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
                }
                // If total number of elements is odd
                else {
                    return Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Move partitionX to the left
                high = partitionX - 1;
            } else {
                // Move partitionX to the right
                low = partitionX + 1;
            }
        }

        throw new Error("Input arrays are not sorted");
    }
}
