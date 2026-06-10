class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0 ; i < grid.size() ; i ++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid , i , j);
                    if(area > maxArea){
                        maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid , int i , int j){
        int w = grid.size();
        int h = grid[0].size();
        int area = 0;

        if(i < 0 || i >= w || j < 0 || j >= h || grid[i][j] == 0){
            return 0;
        }

        area += 1;
        grid[i][j] = 0;

        int totalArea = 
        dfs(grid , i + 1 , j) + 
        dfs(grid , i - 1 , j) + 
        dfs(grid , i  , j + 1) + 
        dfs(grid , i , j - 1);

        area += totalArea;

        return area;


    }
};
