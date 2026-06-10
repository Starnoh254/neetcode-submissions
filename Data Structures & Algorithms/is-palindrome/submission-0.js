class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        let newString = s.replace(/[^a-z0-9]/gi, '').toLowerCase();

        let reversedString = newString.split('').reverse().join('');
        return newString === reversedString;
    }
}
