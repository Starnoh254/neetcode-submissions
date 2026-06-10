class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int , int>> q;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int distance = 0;

        while(!q.empty()){
            int size = q.size();
            distance++;

            for(int i = 0 ; i < size ; i++){
                pair<int,int> cell = q.front();
                int r = cell.first;
                int c = cell.second;
                q.pop();

                for(auto dir : directions){
                    int dr = dir.first;
                    int dc = dir.second;                    
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == INT_MAX){
                        grid[nr][nc] = distance;
                        q.push({nr,nc});
                    }

                }
            }

        }



    }


};
