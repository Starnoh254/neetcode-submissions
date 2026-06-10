class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        // pacific top
        for(int i = 0 ; i < COLS ; i ++){
            dfs(heights, pacific , dirs , 0 , i);
        }

        // pacific left
        for(int i = 0 ; i < ROWS ; i ++){
            dfs(heights, pacific , dirs , i , 0);
        }

        // atlantic right 
        for(int i = 0 ; i < ROWS ; i ++){
            dfs(heights, atlantic , dirs , i , COLS - 1);
        }

        // atlantic bottom
        for(int i = 0 ; i < COLS ; i ++){
            dfs(heights, atlantic , dirs , ROWS - 1 , i);
        }

        vector<vector<int>> result;
        for(int r = 0 ; r < ROWS ; r ++ ) {
            for(int c = 0 ; c < COLS ; c ++) {
                if(atlantic[r][c] && pacific[r][c]) {
                    result.push_back({r,c});
                }
            }
        }

        return result;

        
    }

    void dfs (
        vector<vector<int>>& heights,
        vector<vector<bool>>& ocean , 
        vector<vector<int>>& dirs,
        int r , 
        int c
        ){
        ocean[r][c] = true;
        int ROWS = heights.size();
        int COLS = heights[0].size();
        for(auto dir : dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];
            if( nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue;
            if(heights[nr][nc] < heights[r][c]) continue;
            if(ocean[nr][nc]) continue;
            dfs(heights , ocean , dirs , nr , nc);


        }


    }
};
