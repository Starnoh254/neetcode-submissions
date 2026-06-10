class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> res;

        // ✅ Sort the array to group duplicates together
        sort(candidates.begin(), candidates.end());

        dfs(target, 0, candidates, subset, res);
        return res;
    }

    void dfs(
        int target,
        int start,
        vector<int>& nums,
        vector<int>& subset,
        vector<vector<int>>& res
    ) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // ✅ Correct duplicate skipping logic
            if (i > start && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break;  // Stop early since array is sorted

            // Choose to pick the number
            subset.push_back(nums[i]);
            dfs(target - nums[i], i + 1, nums, subset, res);

            // Undo the choice (backtracking)
            subset.pop_back();
        }
    }
};
