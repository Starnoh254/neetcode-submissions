class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin() , nums.end());
        dfs(0 , subset , res , nums);

        return res;
    }

    void dfs (
        int index,
        vector<int>& subset,
        vector<vector<int>>& res,
        vector<int>& nums
    ){
        res.push_back(subset);
        for(int i = index ; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) continue;

            // choose the number 
            subset.push_back(nums[i]);
            dfs(i + 1 , subset , res , nums);

            // dont choose the number 
            subset.pop_back();
        }
    }
};
