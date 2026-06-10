class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index) {
        // Add the current subset to the result
        result.push_back(subset);
        
        // Iterate through remaining elements
        for (int i = index; i < nums.size(); i++) {
            // Include nums[i] in the subset
            subset.push_back(nums[i]);
            
            // Recursively explore with nums[i] included
            backtrack(nums, result, subset, i + 1);
            
            // Backtrack: Remove nums[i] and explore without it
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        // Start backtracking from index 0
        backtrack(nums, result, subset, 0);
        
        return result;
    }
};
