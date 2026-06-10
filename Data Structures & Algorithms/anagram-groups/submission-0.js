class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {

        const map = {}
        for(const str of strs) {
            let sortedAnagram = str.split('').sort().join('')
            if(!map[sortedAnagram]) {
                map[sortedAnagram] = []
            }

            map[sortedAnagram].push(str)
        }

        return Object.values(map)
    }


}
