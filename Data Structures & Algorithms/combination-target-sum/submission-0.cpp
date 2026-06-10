class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums , subset , target , res , 0 , 0);

        return res;
    }

// [2,3,6,7] target = 7
    void dfs(
        vector<int>& nums,
        vector<int>& subset,
        int target,
        vector<vector<int>>& res ,
        int index , 
        int sum
        ) {

        if(sum == target) {
            res.push_back(subset);
            return;
        }
        for(int i = index ; i < nums.size(); i ++) {
            if(sum + nums[i] > target) continue;

            subset.push_back(nums[i]);

            dfs(nums , subset , target , res , i , sum + nums[i]);
            subset.pop_back();




        }
    }

};
