class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);

        dfs(nums , subset , used , res);
        return res;
    }

    void dfs(
        vector<int>& nums,
        vector<int>& subset,
        vector<bool>& used,
        vector<vector<int>>& res
    ){
        if(subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }


        for(int i = 0; i < nums.size() ; i++) {
            
            if(used[i]) continue;
            // choose to pick the number 
            subset.push_back(nums[i]);
            used[i] = true;
            dfs(nums , subset , used ,  res);

            // choose not to pick the number 
            subset.pop_back();
            used[i] = false;
            


        }
    }
};
