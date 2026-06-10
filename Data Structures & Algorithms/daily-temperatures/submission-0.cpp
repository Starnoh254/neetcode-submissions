class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> result(temperatures.size(),0);
        for(int i = 0 ; i < temperatures.size(); i++){

            while(!stack.empty() && temperatures[stack.top()] < temperatures[i]){
                int prevIndex = stack.top();
                stack.pop();
                result[prevIndex] = i - prevIndex;
            }

            stack.push(i);
        }


        return result;
    }
};
