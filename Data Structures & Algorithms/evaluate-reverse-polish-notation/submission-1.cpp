class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int,int)>> map = {
            {"+" , [](int a, int b) {return a + b;}},
            {"*" , [](int a, int b) {return a * b;}},
            {"-" , [](int a, int b) {return a - b;}},
            {"/" , [](int a, int b) {return a / b;}},
        };

        stack<int> stack;

        for (const string& token : tokens){
            if(map.count(token)){
                int b = stack.top();stack.pop();
                int a = stack.top();stack.pop();

                stack.push(map[token](a,b));
            }

            else {
                stack.push(stoi(token));
            }
        }

        return stack.top();
        
    }


 };
