class Solution {
    /**
     * @param {string} digits
     * @return {string[]}
     */
    letterCombinations(digits) {
        let res = [];
        let map = {
            "2" : ["a","b","c"],
            "3" : ["d","e","f"],
            "4" : ["g","h","i"],
            "5" : ["j","k","l"],
            "6" : ["m","n","o"],
            "7" : ["p","q","r","s"],
            "8" : ["t","u","v"],
            "9" : ["w","x","y","z"]
        }

        function backtrack(i , currentString) {
            if(currentString.length === digits.length){
                res.push(currentString);
                return;
            }

            let possibleChars = map[digits[i]];

            for(let c in possibleChars) {
                backtrack(i + 1 , currentString + possibleChars[c]);
            }
        }

        if (digits) {
            backtrack(0 , '');
        }

        return res;


    }
}
