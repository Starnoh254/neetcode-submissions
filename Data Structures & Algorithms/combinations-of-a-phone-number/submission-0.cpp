class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};  
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string current = "";

        backtrack(0 , digits , phoneMap , current , result);

        return result;

    }
    void backtrack(
    int index ,
    string& digits ,
    unordered_map<char , string>& phoneMap,
    string& current,
    vector<string>& result
    ){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        string possibleLetters = phoneMap[digits[index]];

        for(char letter : possibleLetters) {
            current.push_back(letter); // choose a letter 
            backtrack(index + 1 , digits , phoneMap , current , result);
            current.pop_back(); // undo the choice (backtrack)
        }
    }
};
