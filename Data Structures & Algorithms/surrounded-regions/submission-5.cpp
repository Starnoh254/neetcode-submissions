class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int ROWS = board.size();
        int COLS = board[0].size();


        // border check 
        for(int i = 0 ; i < COLS; i ++){
            if(board[0][i] == 'O'){
                dfs(board , 0 , i);
            }
        }

        int lastROW = ROWS - 1;
        int lastCOL = COLS - 1;

        for(int i = 0 ; i < COLS; i ++){
            if(board[lastROW][i] == 'O'){
                
                dfs(board , lastROW , i);
            }
        }

        for(int i = 0 ; i < ROWS; i ++){
            if(board[i][0] == 'O'){
                
                dfs(board , i , 0);
            }
        }

        for(int i = 0 ; i < ROWS; i ++){
            if(board[i][lastCOL] == 'O'){
               
                dfs(board , i , lastCOL);
            }
        }

        for(int i = 0 ; i < ROWS ; i++){
            for(int j = 0 ; j < COLS ; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

            }
        }
        
    }

    void dfs(vector<vector<char>>& board , int i , int j){
        int ROWS = board.size();
        int COLS = board[0].size();

        if(i < 0 || i >= ROWS || j < 0 || j >= COLS || board[i][j] != 'O'){
            return;
        }

        board[i][j] = '#';
        vector<vector<int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        for(auto direction : directions){
            dfs(board , i + direction[0] , j + direction[1]);
        }

    }
};
