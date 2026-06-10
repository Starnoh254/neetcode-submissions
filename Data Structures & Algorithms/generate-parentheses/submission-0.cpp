class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(n,result,0,0,current);
        return result;
    }


    void backtrack(
        int n , 
        vector<string>& result,
        int close , 
        int open,
        string current 
    ){
        if(current.size() == (2*n)){
            result.push_back(current);
            return;
        }

        if(open < n){
            current.push_back('(');
            backtrack(n,result,close,open + 1 , current);
            current.pop_back();
        }
        if(close < open){
            current.push_back(')');
            backtrack(n,result,close + 1,open , current);
            current.pop_back();
        }
    }
};
