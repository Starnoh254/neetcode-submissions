class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        function<void(int)> dfs = [&](int i) { 
            if(i >= nums.size()) {
                res.push_back(subset);
                // Print the current subset added to res
                cout << "Added subset: [";
                for (int num : subset) cout << num << " ";
                cout << "]\n";
                return;
            }

            // Decision to include nums[i]
            subset.push_back(nums[i]);
            dfs(i + 1);

            // Decision not to include nums[i]
            subset.pop_back();
            dfs(i+1);
        };

        dfs(0);
        return res;

    }
};
