class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res; 
        vector<string>subset;

        backtracking(res , subset , 0 , s);
        return res;

    }

    void backtracking (
        vector<vector<string>> &res,
        vector<string> &subset,
        int index,
        string s

    ){
        // base case 
        if(index == s.size()){
            res.push_back(subset);
            return;
        }

        for(int i = index; i < s.size(); i++){
            // choose to add the character 
            string sub = s.substr(index, i - index + 1); // Extract substring

            if(isPalindrome(sub)) {
                subset.push_back(sub);
                backtracking(res , subset , i + 1 , s );
                subset.pop_back(); // Backtrack to explore other possibilities

            }

        }
    }

    bool isPalindrome(string s){
        int left = 0 , right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) return false;
            left ++;
            right --;
        }
        return true;
    }
};
