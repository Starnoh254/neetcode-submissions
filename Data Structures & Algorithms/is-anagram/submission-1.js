class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if(s.length !== t.length){
            return false;
        }

        let charCountS = {}
        let charCountT = {}

        for(let i = 0 ; i < s.length; i ++) {
            charCountS[s[i]] = (charCountS[s[i]] || 0) + 1;
            charCountT[t[i]] = (charCountT[t[i]] || 0) + 1;
        }

        for(let char in charCountS) {
            if(charCountS[char] !== charCountT[char]){
                return false;
            }
        }

        return true;
    }
}
