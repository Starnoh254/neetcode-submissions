class Solution {
    /**
     * @param {character[][]} board
     * @param {string} word
     * @return {boolean}
     */
    exist(board, word) {
        let rows = board.length;
        let cols = board[0].length;
        for(let i = 0 ; i < rows ; i ++){
            for(let j = 0 ; j < cols ; j++){
                if(this.backtrack(board , word , i , j , 0)){
                    return true;
                }
            }
        }

        return false;

    }

    backtrack(board , word , i , j , index){
        if(index == word.length) return true;

        if(
            i < 0 ||
            i >= board.length || 
            j < 0 || 
            j >= board[0].length || 
            board[i][j] !== word[index]
        )  return false;

        let temp = board[i][j];

        board[i][j] = '#';

        let found = this.backtrack(board , word , i + 1 , j , index + 1) ||
                    this.backtrack(board , word , i - 1 , j , index + 1) ||
                    this.backtrack(board , word , i  , j + 1 , index + 1) ||
                    this.backtrack(board , word , i  , j - 1, index + 1) 

        board[i][j] = temp;

        return found;
    }
}
