class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS , false));
        queue<pair<int,int>> q;
        

        int minutes = -1;
        int fresh = 0;

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh ++;
                }
            }
        }

        if(fresh == 0) return 0;

        vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size = q.size();

            for(int k = 0 ; k < size; k++){
                auto cod = q.front();
                q.pop();
                

                int i = cod.first;
                int j = cod.second;

                for(auto dir : directions){
                    int nr = i + dir[0];
                    int nc = j + dir[1];

                    if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }

            minutes += 1;
        }

        return fresh == 0 ? minutes : -1;
    }

};
