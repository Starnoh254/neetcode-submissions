class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        // Convert both strings to arrays
        let string_s = s.split('');
        let string_t = t.split('');
        
        // If lengths don't match, they're not anagrams
        if (string_s.length !== string_t.length) {
            return false;
        }
        
        // Loop through each character in string_s
        for (let i = 0; i < string_s.length; i++) {
            // Find the character string_s[i] in string_t
            let index = string_t.indexOf(string_s[i]);
            
            // If the character is not found, they're not anagrams
            if (index === -1) {
                return false;
            }
            
            // Remove the matched character from string_t to avoid duplicate matches
            string_t.splice(index, 1);
        }
        
        return true;
    }
}
