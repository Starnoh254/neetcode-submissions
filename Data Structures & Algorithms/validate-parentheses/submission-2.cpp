class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char,char> map = {
            {')' , '('},
            {'}' , '{'},
            {']' , '['},

        };

        for(int i = 0 ; i < s.size();i++){
            if(isOpening(s[i])){
                stack.push_back(s[i]);
                continue;
            }
            else{
                if(stack.size() > 0 && map[s[i]] == stack.back()){
                    stack.pop_back();
                }
                else{
                    return false;
                }
            }
        }

        if(stack.size() > 0) return false;

        return true;
    }

    bool isOpening(char s){
        vector<char>validParentheses = {'(','{','['};
        for(int j = 0;j < validParentheses.size();j++){
            if(s == validParentheses[j]) return true;
        }

        return false;
    }
};
